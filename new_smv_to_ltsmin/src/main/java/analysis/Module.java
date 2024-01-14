package analysis;

import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNodeImpl;
import smv.smvParser;

import java.util.ArrayList;
import java.util.List;

public class Module {
    public Smv_file smv;
    public String module_name;
    public boolean havePara = true;
    public boolean isProcess = false;
    public List<String> formal_para = new ArrayList<String>();
    public List<smvParser.ParaContext> rel_para;
    public List<String> changed_para = new ArrayList<>();
    public boolean isParaTypeSet = false;
    public String forward = "";
    public List<Var> var_list = new ArrayList<Var>();
    public List<Var> define_list = new ArrayList<Var>();
    public List<Assign> assign_list = new ArrayList<Assign>();
    public List<Expr> trans_list = new ArrayList<Expr>();
    public List<Expr> init_list = new ArrayList<Expr>();
    public List<Expr> fairness_list = new ArrayList<Expr>();
    private ArrayList<Integer> casedgcount =new ArrayList<>();

    public String declaration_code(){
        String code ="";
        for(int i=0;i<var_list.size();i++){
            if(var_list.get(i).type == VarType.array_var){
                if(!var_list.get(i).array_type.equals("boolean")){
                    code +="\r\ntypedef enum "+ var_list.get(i).array_type+" {\r\n\t";
                    for(int j=0;j<var_list.get(i).enum_value.size();j++) {
                        code += var_list.get(i).enum_value.get(j);
                        if(j<var_list.get(i).enum_value.size()-1)
                            code += ", ";
                    }
                    code+="\r\n}"+var_list.get(i).array_type +";\r\n";
                }
            }else if(var_list.get(i).type == VarType.enum_var){
                code +="\r\ntypedef enum smv_"+ module_name+"_"+ var_list.get(i).name+"_enum_t {\r\n\t";
                for(int j=0;j<var_list.get(i).enum_value.size();j++) {
                    code += var_list.get(i).enum_value.get(j);
                    if(j<var_list.get(i).enum_value.size()-1)
                        code += ", ";
                }
                code+="\r\n}"+ "smv_" + module_name+"_"+ var_list.get(i).name +"_enum_t" +";\r\n";
            }
        }
        if(!module_name.equals("main")){
            code +="\r\ntypedef struct smv_" +module_name +"_t {\r\n";
            for (Var var : var_list) {
                /*
                if (var.type == VarType.module_var) {
                    code += "\t" + "smv_" + var.module_name + "_t " + var.name + ";\r\n";
                } else if (var.type == VarType.simple_var) {
                    code += "\t" + "boolean " + var.name + ";\r\n";
                } else if (var.type == VarType.array_var) {
                    code += "\t" + var.array_type + " " + var.name + "[" + (var.max + 1) + "]" + ";\r\n";
                } else if (var.type == VarType.int_range_var) {
                    code += "\t" + "int " + var.name + ";\r\n";
                } else if (var.type == VarType.enum_var) {
                    code += "\t" + "smv_" + var.name + "_enum_t " + var.name + ";\r\n";
                }
                 */
                if(var.type!=VarType.define_var)
                    code+="\t" + var.new_type_name + " " +var.name + ";\r\n";
            }
            if(isProcess)
                code +="\tboolean running;\r\n";
            code += "} smv_"+ module_name +"_t;\r\n";
        }else {
            code +="\r\ntypedef struct state_t {\r\n";
            for (Var var : var_list) {
                if(var.type!=VarType.define_var)
                    code+="\t" + var.new_type_name + " " +var.name + ";\r\n";
            }
            code += "\t"+"boolean virtual_init;\r\n";
            code += "} state_t;\r\n";
        }
        return code;

    }

    public void name_correction(){
        if(module_name.contains("-"))
            module_name = module_name.replace('-','_');
        for(int i=0;i<var_list.size();i++){
            if(var_list.get(i).name.contains("-")){
                var_list.get(i).name = var_list.get(i).name.replace('-','_');
            }
            if(var_list.get(i).type == VarType.module_var){
                if(var_list.get(i).module_name.contains("-"))
                    var_list.get(i).module_name = var_list.get(i).module_name.replace('-','_');
            }
        }
    }

    public String  write_assign(Assign a, String forward,List<smvParser.ParaContext> rel_para){
        this.forward = forward;
        String code = "";
        if(a.type == Assign_type.init){
            code += write_expr(a,a.expr.expr,rel_para) + "\r\n";
        }
        else if(a.type == Assign_type.next){
            code += write_expr(a,a.expr.expr,rel_para) + "\r\n";
        }
        return  code;

    }



    public String  write_expr(Assign a,ParseTree expr,List<smvParser.ParaContext> rel_para){
        String code = write_expr(a,(smvParser.Basic_next_exprContext) expr);
        code +=";";
        return code;
    }

    public void analysis_rele_para(String forward,List<smvParser.ParaContext> rel_para, Module m){
        m.forward = forward;
        m.changed_para.clear();
        if(rel_para!=null){
            for(smvParser.ParaContext ctx : rel_para){
                m.changed_para.add(change_para(ctx.basic_next_expr()));
            }
        }
    }
    public String change_para(smvParser.Basic_next_exprContext ctx){
       return write_expr(null,ctx);
    }

    public String write_expr(Assign a,smvParser.Basic_next_exprContext ctx){
        if(ctx.getChild(0) instanceof TerminalNodeImpl){
            if(ctx.getChild(0).getText().equals("(")){
                return "("+ write_expr(a,ctx.basic_next_expr(0)) +")";
            }
            if(ctx.getChild(0).getText().equals("!")){
                return "!" + write_expr(a,ctx.basic_next_expr(0));
            }
            if(ctx.getChild(0).getText().equals("toint")){
                return  write_expr(a,ctx.basic_next_expr(0));
            }
            if(ctx.getChild(0).getText().equals("{")){

                return "smv_non_deterministic(\""+a.instance_var_name+"\","+set_Count(ctx.set_next_body())+"," +ctx.set_next_body().getText()+")";
            }
            if(ctx.getChild(0).getText().equals("next(")){
                //TODO:next的替换;
            }
        }
        else if(ctx.getChild(0) instanceof smvParser.Basic_next_exprContext){
            if(!(ctx.getChild(1) instanceof TerminalNodeImpl)) {
                if (ctx.mul() != null) {
                    return write_expr(a,ctx.basic_next_expr(0)) + " " + ctx.mul().getText() + " " + write_expr(a,ctx.basic_next_expr(1));
                } else if (ctx.mod() != null) {
                    return write_expr(a,ctx.basic_next_expr(0)) + " % " + write_expr(a,ctx.basic_next_expr(1));
                } else if (ctx.add() != null) {
                    return write_expr(a,ctx.basic_next_expr(0)) + " " + ctx.add().getText() + " " + write_expr(a,ctx.basic_next_expr(1));
                } else if (ctx.shift() != null) {
                    return write_expr(a,ctx.basic_next_expr(0)) + ctx.shift().getText() + write_expr(a,ctx.basic_next_expr(1));
                } else if (ctx.union() != null) {
                    return "smv_non_deterministic(\""+get_relpara_name(a.instance_var_name)+"\","+"2," +write_expr(a,ctx.basic_next_expr(0))+","+write_expr(a,ctx.basic_next_expr(1))+")";
                } else if (ctx.logicjudge() != null) {
                    if (ctx.logicjudge().getText().equals("="))
                        return write_expr(a,ctx.basic_next_expr(0)) + " == " + write_expr(a,ctx.basic_next_expr(1));
                    else
                        return write_expr(a,ctx.basic_next_expr(0)) + ctx.logicjudge().getText() + write_expr(a,ctx.basic_next_expr(1));
                } else if (ctx.logicand() != null) {
                    return write_expr(a,ctx.basic_next_expr(0)) + " && " + write_expr(a,ctx.basic_next_expr(1));
                } else if (ctx.logicor() != null) {
                    if (ctx.logicor().getText().equals("|"))
                        return write_expr(a,ctx.basic_next_expr(0)) + " || " + write_expr(a,ctx.basic_next_expr(1));
                    else
                        return write_expr(a,ctx.basic_next_expr(0)) + " ^ " + write_expr(a,ctx.basic_next_expr(1));
                }
            }else{
                if(ctx.getChild(1).equals("->")){

                }else if(ctx.getChild(1).equals("in")){

                }
            }

        }
        if(ctx.case_expr()!=null){
            casedgcount.add(0);
            return " ( "+ write_case_expr(a,ctx.case_expr().case_next_body(),0) + " ) ";
        }
        if(ctx.integer_range()!=null){
            int min = Integer.parseInt(ctx.integer_range().INTEGER(0).getText());
            int max = Integer.parseInt(ctx.integer_range().INTEGER(1).getText());
            int num =max-min+1;
            String args=""+min;
            for(int i=min+1;i<=max;i++)
                args+=","+i;
            return "smv_non_deterministic(\""+get_relpara_name(a.var_name)+"\","+num+"," +args+")";
        }
        if(ctx.INTEGER()!=null)
            return ctx.INTEGER().getText();
        if(ctx.var()!=null)
            return write_basicvar_name(ctx.var());
        return "";
    }

    public String write_case_expr(Assign a,smvParser.Case_next_bodyContext ctx,int i){
        if(ctx.case_next_body()==null)
            return write_expr(a,ctx.case_cond().basic_next_expr()) + " ? " + write_expr(a,ctx.case_value().basic_next_expr()) + " : ";
        else{

            if(i!=0){
                casedgcount.set(casedgcount.size() - 1, casedgcount.get(casedgcount.size() - 1) +1);
                return write_case_expr(a,ctx.case_next_body(),i+1) + " ( "+write_expr(a,ctx.case_cond().basic_next_expr()) + " ? " + write_expr(a,ctx.case_value().basic_next_expr()) +" : ";
            }
            else{
                String tmp= write_case_expr(a,ctx.case_next_body(),i+1);
                tmp+= write_expr(a,ctx.case_value().basic_next_expr()) + " ) ".repeat(casedgcount.get(casedgcount.size() - 1));
                casedgcount.remove(casedgcount.size() - 1);
                return tmp;
            }

        }

    }

    public String write_basicvar_name(smvParser.VarContext ctx){
        String code = "";
        boolean find = false;
        for(Var v : var_list){
            if(ctx.getChild(0).getText().equals(v.name)) {
                code += forward + ctx.getChild(0).getText();
                find =true;
                break;
            }
        }
        for(Var v : define_list){
            if(ctx.getChild(0).getText().equals(v.name)) {
                code += forward + ctx.getChild(0).getText();
                find =true;
                break;
            }
        }
        for (int i = 0;!find && i < formal_para.size();i++){
            if(ctx.getChild(0).getText().equals(formal_para.get(i))) {
                code += changed_para.get(i);
                find =true;
                break;
            }
        }
        if(find) {
            for (int j = 1; j < ctx.getChildCount(); j++)
                code += ctx.getChild(j).getText();

        }else
            code = ctx.getText();
        code = code.replace("[","");
        code = code.replace("]","");
        code = code.replace(".","_");
        for(State_info s : smv.stateInfos){
            if(code.equals(s.state_vector_name)){
                code = "in->" + code;
                break;
            }
        }
        return  code;
    }

    public String get_relpara_name(String name){
        String[] tmp = name.split("\\.");
        for(int i=0;i<formal_para.size();i++){
            if(formal_para.get(i).equals(tmp[0]))
                tmp[0]=changed_para.get(i);
        }
        String backname=tmp[0];
        for (int i=1;i<tmp.length;i++){
            backname += "_"+tmp[i];
        }
        return backname;
    }


    public int  set_Count(smvParser.Set_next_bodyContext ctx){
        if(ctx.set_next_body()==null){
            return 1;
        }
        else {
            return set_Count(ctx.set_next_body()) + 1;
        }
    }
}
