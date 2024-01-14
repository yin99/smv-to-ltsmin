package analysis;

import smv.smvParser;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Pattern;

public class Smv_file {
    public String filename;
    public int module_num = 0;
    public List<Module> module_list = new ArrayList<Module>();
    public List<Actiongroup> actiongroups = new ArrayList<Actiongroup>();//改成一个类，记录var的类型、名字、初始值、下一个值规则
    public int main_num;
    public int state_size;
    public static List<String> function_declaration = new ArrayList<String>();
    public List<State_info> stateInfos = new ArrayList<State_info>();

    public List<String> rm = new ArrayList<>();
    public List<String> wm = new ArrayList<>();
    public List<String> lm = new ArrayList<>();
    public List<String> all_enum_table = new ArrayList<String>();
    public void init(){

        get_main_num();
        set_process();
        init(module_list.get(main_num),"");

        set_all_enum_table(module_list.get(main_num));
        Actiongroup actiongroup = new Actiongroup();
        actiongroups.add(actiongroup);
        set_basic_vars(module_list.get(main_num),"",actiongroups.get(0),null);
        set_lm();
    }

    public void set_matrix(String s,String name,int count){
        int i;
        String wm_str ="";
        String rm_str ="";

        if(count>=wm.size())
            wm.add(wm_str);
        else
            wm_str = wm.get(count);
        if(count>=rm.size())
            rm.add(rm_str);
        else
            rm_str=rm.get(count);
        for(i=0;i<stateInfos.size();i++){
            if(s.contains(stateInfos.get(i).state_vector_name)){
                if(iscontain(rm_str,i+""))
                 rm_str += ","+i;
            }
            if(stateInfos.get(i).state_vector_name.equals(name)){
                if(iscontain(wm_str,i+""))
                    wm_str += ","+i;
            }
        }

        rm.set(count,rm_str);
        wm.set(count,wm_str);
    }

    public boolean iscontain(String src,String num){
        String[] tmp =src.split(",");
        for(String s: tmp){
            if(s.equals(num))
                return false;
        }
        return true;
    }

    public void set_lm(){
        if(actiongroups.size()==1){
            lm.add("1,"+stateInfos.size());
            lm.add("1,"+stateInfos.size());
        }else {
            String tmp="";
            lm.add("1,"+stateInfos.size());
            for (int i = 1; i < actiongroups.size(); i++) {
                int m;
                for(m=0;i<stateInfos.size();m++){
                    if(stateInfos.get(m).state_vector_name.equals(actiongroups.get(i).basicVars.get(0).name))
                        break;
                }
                String str ="1,"+m;
                tmp+=","+m;
                lm.add(str);
            }
            lm.add(actiongroups.size()+tmp+","+stateInfos.size());
        }
    }

    public int get_main_num(){
        int i=0;
        for (i=0;!module_list.get(i).module_name.equals("main");i++);
        main_num = i;
        return i;
    }

    public void init(Module module,String forward){

        for(Var var:module.var_list){
            switch (var.type) {
                case module_var: {
                    for (Module m : module_list) {
                        if (m.module_name.equals(var.module_name)) {
                            init(m, forward + var.name + "_");
                            if (m.isProcess) {

                                State_info tmp = new State_info();
                                tmp.state_vector_name = (forward + var.name + "_running");
                                tmp.state_vector_type = "boolean";
                                tmp.value_set.addAll(Arrays.asList("FALSE", "TRUE"));
                                stateInfos.add(tmp);
                            }
                        }

                    }


                }
                break;
                case enum_var: {
                    State_info tmp = new State_info();
                    tmp.state_vector_name = (forward + var.name);
                    tmp.state_vector_type = "smv_enum";
                    tmp.value_set.addAll(var.enum_value);
                    stateInfos.add(tmp);
                    break;
                }
                case array_var:{
                    for(int i = var.min;i<=var.max;i++)
                        if(var.array_type.equals("boolean")) {
                            State_info tmp = new State_info();
                            tmp.state_vector_name = (forward  + var.name + i);
                            tmp.state_vector_type = "boolean";
                            tmp.value_set.addAll(Arrays.asList("FALSE", "TRUE"));
                            stateInfos.add(tmp);
                        }else {
                            State_info tmp = new State_info();
                            tmp.state_vector_name = (forward  + var.name + i);
                            tmp.state_vector_type = "smv_enum";
                            tmp.value_set.addAll(var.enum_value);
                            stateInfos.add(tmp);

                        }
                }break;
                case simple_var:{
                    State_info tmp = new State_info();
                    tmp.state_vector_name = (forward+var.name);
                    tmp.state_vector_type = "boolean";
                    tmp.value_set.addAll(Arrays.asList("FALSE", "TRUE"));
                    stateInfos.add(tmp);
                    break;
                }
                case int_range_var:{
                    State_info tmp = new State_info();
                    tmp.state_vector_name = (forward+var.name);
                    tmp.state_vector_type = "int";
                    for(int i = var.min;i<=var.max;i++)
                        tmp.value_set.add(""+i);
                    stateInfos.add(tmp);
                    break;}
            }
        }

    }


    public void set_process(){
      for(Var var: module_list.get(main_num).var_list){
          if(var.type == VarType.module_var){
              if(var.isProcess){
                  for(Module module:module_list){
                      if(module.module_name.equals(var.module_name))
                          module.isProcess = true;
                  }
              }
          }
      }
    }

    public void name_correction(){
        for(int i=0;i<module_list.size();i++)
            module_list.get(i).name_correction();
    }

    public void set_basic_vars(Module m,String forward, Actiongroup actiongroup,List<smvParser.ParaContext> rel_para){

        for (Var v : m.var_list){
            if(v.isProcess) {
                Actiongroup runningActiongroup = new Actiongroup();
                basic_var runningtmp = new basic_var();
                runningtmp.name = v.name + "_running";
                runningtmp.next_expr = "FALSE;\r\n";
                runningActiongroup.basicVars.add(runningtmp);
                set_a_basicvar(m, v, forward,runningActiongroup,rel_para);
                actiongroups.add(runningActiongroup);
            }else
                set_a_basicvar(m,v,forward,actiongroup,rel_para);
        }
        for(Var d : m.define_list){
            basic_var tmp = new basic_var();
            boolean haspara = false;
            String[] s = d.name.split("\\.");
            for(String str : m.formal_para){
                if(str.equals(s[0]))
                    haspara = true;
            }
            if(haspara)
                tmp.name = m.get_relpara_name(d.name);
            else
                tmp.name = forward + m.get_relpara_name(d.name);
            tmp.define_expr = m.write_expr(null,d.define_expr.expr,rel_para) + "\r\n";
            actiongroup.deineVars.add(tmp);
        }
        for(Assign a :m.assign_list){
            boolean exists=false;
            for(basic_var bv : actiongroup.basicVars){
                if(a.instance_var_name.equals(bv.name)) {
                    if(a.type == Assign_type.init && bv.init_expr== null) {
                        bv.init_expr = m.write_assign(a,forward,rel_para);
                    }else if(a.type == Assign_type.next && bv.next_expr== null){
                        bv.next_expr = m.write_assign(a,forward,rel_para);
                    }else if(a.type == Assign_type.current && bv.define_expr == null){
                        bv.define_expr = m.write_assign(a,forward,rel_para);
                    }else
                        exists =true;
                    break;
                }
            }
            if(!exists){
                basic_var tmp = new basic_var();
                tmp.name = m.get_relpara_name(a.var_name).replace("in->","");
                if(a.type == Assign_type.init)
                    tmp.init_expr =  m.write_assign(a,forward, rel_para);
                else if(a.type == Assign_type.next)
                    tmp.next_expr = m.write_assign(a,forward, rel_para);
                actiongroup.basicVars.add(tmp);
            }
        }
    }

    public void set_a_basicvar(Module m, Var v,String forward,Actiongroup actiongroup,List<smvParser.ParaContext> rel_para){
        if(v.type == VarType.simple_var || v.type==VarType.int_range_var||v.type == VarType.enum_var){
            basic_var tmp = new basic_var();
            tmp.name = forward + v.name;
            for(Assign a : m.assign_list){
                if(a.var_name.equals(v.name)){
                    a.instance_var_name = forward + v.name;
                    if(a.type == Assign_type.init)
                       tmp.init_expr =  m.write_assign(a,forward, rel_para);
                    else if(a.type == Assign_type.next)
                        tmp.next_expr = m.write_assign(a,forward, rel_para);
                }
            }
            actiongroup.basicVars.add(tmp);
        }else  if(v.type == VarType.module_var){
            int i=0;
            for(;i<module_list.size();i++) {
                if (module_list.get(i).module_name.equals(v.module_name))
                    break;
            }
            m.analysis_rele_para(forward + v.name+"_",v.rel_para,module_list.get(i));
            set_basic_vars(module_list.get(i),forward + v.name+"_",actiongroup,v.rel_para);
        }else if(v.type == VarType.array_var){
            for(int i = v.min;i<=v.max;i++){
                basic_var tmp = new basic_var();
                tmp.name = forward + v.name + i;
                for(Assign a : m.assign_list){
                    if(a.var_name.equals(v.name +i)){
                        a.instance_var_name = forward + v.name + i;
                        if(a.type == Assign_type.init)
                            tmp.init_expr =  m.write_assign(a,forward, rel_para);
                        else if(a.type == Assign_type.next)
                            tmp.next_expr = m.write_assign(a,forward, rel_para);
                    }
                }
                actiongroup.basicVars.add(tmp);
            }

        }
    }

    public void set_all_enum_table(Module start){
        for(Var v : start.var_list){
            if(v.type == VarType.module_var){
                int j;
                for(j =0;j<module_list.size();j++){
                    if(module_list.get(j).module_name.equals(v.module_name))
                        break;
                }
                set_all_enum_table(module_list.get(j));
            }else if(v.type==VarType.enum_var){
                for(String s:v.enum_value){
                    String str;
                    if(s.matches("\\d+"))
                        str = "EMPTYENUM"+s;
                    else
                        str = s;
                    if(!all_enum_table.contains(str)){
                            all_enum_table.add(str);
                    }
                }
            }

        }
    }

}
