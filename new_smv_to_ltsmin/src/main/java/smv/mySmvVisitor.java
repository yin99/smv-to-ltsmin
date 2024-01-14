package smv;
import analysis.*;
import analysis.Module;

import java.util.Arrays;

public class mySmvVisitor extends smvBaseVisitor<Object> {
    public Smv_file smv = new Smv_file();


    @Override
    public Object visitModule(smvParser.ModuleContext ctx) {
        smv.module_num++;
        Module module = new Module();
        module.module_name = ctx.IDENTIFIER().toString();
        if(ctx.para_list()==null)
            module.havePara = false;
        else
            visitPara_list(ctx.para_list(),module);
        visitModule_body(ctx.module_body(),module);
        module.smv = smv;
        smv.module_list.add(module);
        return 0;
    }
    //maybe ok
    public Object visitPara_list(smvParser.Para_listContext ctx, Module module){
        module.formal_para.addAll(Arrays.asList(ctx.getText().split(",")));
        return 0;
    }
    //maybe ok
    public Object visitModule_body(smvParser.Module_bodyContext ctx,Module module){
        if(ctx.module_body()!=null)
            visitModule_body(ctx.module_body(),module);
        visitModule_element(ctx.module_element(),module);

        return 0;
    }

    public Object visitModule_element(smvParser.Module_elementContext ctx,Module module){
        if(ctx.var_declaration()!=null){
            visitVar_list(ctx.var_declaration().var_list(),module);
        }
        if(ctx.ivar_declaration()!=null){

        }
        if(ctx.frozenvar_declaration()!=null){

        }
        if(ctx.define_declaration()!=null){
            visitDefine_body(ctx.define_declaration().define_body(),module);
        }
        if(ctx.constants_declaration()!=null){

        }
        if(ctx.assign_constraint()!=null){
            visitAssign_list(ctx.assign_constraint().assign_list(),module);
        }
        if(ctx.trans_constraint()!=null){
            visitTrans_constraint(ctx.trans_constraint(),module);
        }
        if(ctx.init_constraint()!=null){
            visitInit_constraint(ctx.init_constraint(),module);
        }
        if(ctx.invar_constraint()!=null){

        }
        if (ctx.fairness_constraint()!=null){
            visitFairness_constraint(ctx.fairness_constraint(),module);
        }
        return 0;
    }

    public Object visitVar_list(smvParser.Var_listContext ctx,Module module){
        if(ctx.var_list()!=null)
            visitVar_list(ctx.var_list(),module);
        Var var = new Var();
        var.name = ctx.IDENTIFIER().getText();
        visitType_sepcifier(ctx.type_sepcifier(),var);
        module.var_list.add(var);
        return 0;
    }
    //maybe ok
    public Object visitType_sepcifier(smvParser.Type_sepcifierContext ctx,Var var){
        if(ctx.simple_type_specifier()!=null)
            visitSimple_type_specifier(ctx.simple_type_specifier(),var);
        else
            visitModule_type_specifier(ctx.module_type_specifier(),var);
        return 0;
    }
    //maybe ok
    public Object visitSimple_type_specifier(smvParser.Simple_type_specifierContext ctx, Var var){
        if(ctx.getText().equals("boolean"))
            var.set_var_info("boolean");
        if(ctx.enumeration_type_body()!=null)
            var.set_var_info(ctx.enumeration_type_body().getText().split(","));
        if(ctx.integer_range()!=null)
            var.set_var_info(Integer.parseInt(ctx.integer_range().INTEGER(0).getText()),Integer.parseInt(ctx.integer_range().INTEGER(1).getText()));
        if(ctx.simple_type_specifier()!=null){
            int min_num =Integer.parseInt(ctx.integer_range().INTEGER(0).getText());
            int max_num =Integer.parseInt(ctx.integer_range().INTEGER(1).getText());
            if(ctx.simple_type_specifier().getText().equals("boolean")){
                var.set_var_info(min_num,max_num,"boolean");

            }else {
                var.set_var_info(ctx.simple_type_specifier().enumeration_type_body().getText().split(","));
                var.set_var_info(min_num,max_num,"smv_"+var.name+"_enum_t");
            }


        }

        return 0;
    }
    //maybe ok
    public Object visitModule_type_specifier(smvParser.Module_type_specifierContext ctx,Var var){
            smvParser.Para_listContext para;
            if(ctx.para_list()!=null)
                para = ctx.para_list();
            else
                para = null;
            var.set_var_info(ctx.IDENTIFIER().getText(),ctx.getChild(0).getText().equals("process"),para);

        return 0;
    }
    //maybe ok
    public Object visitDefine_body(smvParser.Define_bodyContext ctx, Module module){
        if(ctx.define_body()!=null)
            visitDefine_body(ctx.define_body(),module);
        Var tmp = new Var();
        Expr expr = new Expr();
        for(int i=0;i<ctx.getChildCount();i++){
            if(ctx.getChild(i).getText().equals(":=")){
                expr.expr = ctx.getChild(i+1);
                break;
            }
        }
        visitBasic_next_expr(ctx.basic_next_expr(),expr);
        tmp.set_var_info(ctx.var().getText(),expr);
        module.define_list.add(tmp);
        return 0;
    }

    public void visitBasic_next_expr(smvParser.Basic_next_exprContext ctx,Expr expr){
        if(ctx.basic_next_expr()!=null){
            for(int i=0;ctx.basic_next_expr(i)!=null;i++)
                visitBasic_next_expr(ctx.basic_next_expr(i),expr);
        }
        if(ctx.set_next_body()!=null)
            visitSet_next_body(ctx.set_next_body(),expr);
        if(ctx.case_expr()!=null)
            visitCase_next_body(ctx.case_expr().case_next_body(),expr);
        if(ctx.var()!=null){
            expr.symbol_list.add(ctx.var().getText());
        }

    }
    //maybe okk
    public void visitSet_next_body(smvParser.Set_next_bodyContext ctx ,Expr expr){
        if(ctx.set_next_body()!=null)
            visitSet_next_body(ctx.set_next_body(),expr);
        visitBasic_next_expr(ctx.basic_next_expr(),expr);
    }
    public void visitCase_next_body(smvParser.Case_next_bodyContext ctx,Expr expr){
        if(ctx.case_next_body()!=null)
            visitCase_next_body(ctx.case_next_body(),expr);
        visitBasic_next_expr(ctx.case_cond().basic_next_expr(),expr);
        visitBasic_next_expr(ctx.case_value().basic_next_expr(),expr);
    }
    //maybeokk
    public void visitAssign_list(smvParser.Assign_listContext ctx,Module module){
        if(ctx.assign_list()!=null)
            visitAssign_list(ctx.assign_list(),module);
        Assign assign = new Assign();
        if(ctx.assign().next_assign()!=null){
            assign.var_name = delete_bracket(ctx.assign().next_assign().var().getText());
            assign.instance_var_name = assign.var_name;
            assign.type = Assign_type.next;
        }else if(ctx.assign().init_assign()!=null){
            assign.var_name = delete_bracket(ctx.assign().init_assign().var().getText());
            assign.instance_var_name = assign.var_name;
            assign.type = Assign_type.init;
        }else {
            assign.var_name = delete_bracket(ctx.assign().var().getText());
            assign.instance_var_name = assign.var_name;
            assign.type = Assign_type.current;
        }

        Expr expr = new Expr();
        expr.expr = ctx.assign().getChild(2);
        visitBasic_next_expr(ctx.assign().basic_next_expr(),expr);
        assign.expr = expr;
        module.assign_list.add(assign);
    }

    public void visitTrans_constraint(smvParser.Trans_constraintContext ctx, Module module){
        Expr e= new Expr();
        visitBasic_next_expr(ctx.basic_next_expr(),e);
        e.expr = ctx.basic_next_expr();
        module.trans_list.add(e);
    }

    public void visitInit_constraint(smvParser.Init_constraintContext ctx,Module module){
        Expr e= new Expr();
        visitBasic_next_expr(ctx.basic_next_expr(),e);
        e.expr = ctx.basic_next_expr();
        module.init_list.add(e);
    }

    public void visitFairness_constraint(smvParser.Fairness_constraintContext ctx,Module module){
        Expr e= new Expr();
        visitBasic_next_expr(ctx.basic_next_expr(),e);
        e.expr = ctx.basic_next_expr();
        module.fairness_list.add(e);
    }


    public String delete_bracket(String s){
        s = s.replace("[","");
        return s.replace("]","");
    }
}
