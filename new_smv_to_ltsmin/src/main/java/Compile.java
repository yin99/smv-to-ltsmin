import analysis.Smv_file;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import smv.*;
import analysis.*;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Compile {
    public static List<Smv_file> Smv_files = new ArrayList<>();


    //输出编写代码的函数
    public static void write_code(Smv_file smv) throws IOException {
        String outPath ="C:\\Users\\ztb\\Desktop\\new_case\\out";
        File file =new File(outPath+"\\"+smv.filename.split("\\.")[0]+"_out.c");
        if(file.exists())
            file.delete();
        file.createNewFile();
        OutputStream outputStream = new FileOutputStream(file,true);
        //写头文件的代码
        write_head(outputStream);
        //写结构和状态初始代码
        write_strut_declaration(outputStream,smv);
        write_init(outputStream,smv);
        //写module函数代码
        write_action(outputStream,smv);
        //写next函数
        write_next(outputStream,smv);
        //写label的函数
        write_label(outputStream,smv);
        //写依赖矩阵的函数
        write_matrix(outputStream,smv);
        //写接口的函数
        write_pins_model(outputStream,smv);
        //写test代码
        //write_test(outputStream);
    }
    //计算2字符串出现在1字符串中的次数。
    public static int count(String str1, String str2) {
        int count = 0;
        if (str1.equals("") || str2.equals("")) {
        } else {
            for (int i = 0; i <= str1.length() - str2.length(); i++) {
                if (str2.equals(str1.substring(i, str2.length() + i)))
                    count++;
            }
        }
        return count;
    }
    public static void write_init(OutputStream outputStream,Smv_file smv) throws IOException {
        String code = "\r\nstate_t initial_s = (state_t) {\r\n";
        for(State_info s : smv.stateInfos){
            code+="\t."+s.state_vector_name+" ".repeat(39-s.state_vector_name.length())+"= ";
            if(s.state_vector_type.equals("boolean")){
                code += "FALSE,\n";
            }else {
                code += "0,\n";
            }
        }
        State_info vir_init = new State_info();
        vir_init.state_vector_name = "virtual_init";
        vir_init.state_vector_type = "boolean";
        vir_init.value_set.addAll(Arrays.asList("FALSE","TRUE"));
        smv.stateInfos.add(vir_init);
        code += "\t.virtual_init"+" ".repeat(27)+"= TRUE\r\n";
        code +="};\r\n";
        smv.state_size =count(code,"=")-1;
        outputStream.write(("\r\nconst int smv_get_state_size() {\r\n\treturn "+smv.state_size+";\r\n}\r\n").getBytes());
        String state_t ="\r\ntypedef struct state_t {\n";
        for(int i =0;i<smv.stateInfos.size();i++){
            state_t +="\t"+smv.stateInfos.get(i).state_vector_type +" "+smv.stateInfos.get(i).state_vector_name+";\n";
        }
        state_t+="} state_t;\n";
        outputStream.write(state_t.getBytes());
        outputStream.write(code.getBytes());
    }


    public static void write_strut_declaration(OutputStream outputStream, Smv_file smv) throws IOException {
        outputStream.write("\ntypedef enum boolean{\r\n\tFALSE, TRUE\r\n}boolean;\r\n".getBytes());
        /*
        int main_num =0;
        for (int i=0;i<smv.module_list.size();i++){
            if(!smv.module_list.get(i).module_name.equals("main")){
                outputStream.write(smv.module_list.get(i).declaration_code().getBytes());
            }else
                main_num = i;
        }
        outputStream.write(smv.module_list.get(main_num).declaration_code().getBytes());

         */
        if(smv.all_enum_table.size()>0) {
            outputStream.write("\ntypedef enum smv_enum{\n".getBytes());
            outputStream.write("\t".getBytes());
            for (String s : smv.all_enum_table) {
                outputStream.write((" " + s + ",").getBytes());
            }
            outputStream.write("\n}smv_enum;\n".getBytes());
        }
    }


    public static void write_action(OutputStream outputStream,Smv_file smv) throws IOException{
        String code = "";
        int tabcount = 1;
        outputStream.write("\r\nsmv_basic_var basic_var_list[] = {\r\n".getBytes());
        for(State_info s: smv.stateInfos) {
            outputStream.write(("\t{\""+s.state_vector_name+"\","+"1"+",0x0"+"},\r\n").getBytes());
        }
        outputStream.write("};\r\n".getBytes());
        //写不确定性工具函数

        String non_deter ="\nint smv_non_deterministic(char *name ,int num,...){\n" +
                "\tint i,j;\n" +
                "\tva_list args; \n" +
                "\tfor(i=0;i<smv_get_state_size();i++){\n" +
                "\t\tif(strcmp(basic_var_list[i].name,name)==0)\n" +
                "\t\t\tbreak;\n" +
                "\t}\n" +
                "\tbasic_var_list[i].num = num;\n" +
                "\tfree(basic_var_list[i].value);\n" +
                "\tbasic_var_list[i].value = (int *)malloc(sizeof(int)*num);\n" +
                "\tva_start(args, num); \n" +
                "\tfor(j=0;j<num;j++){\n" +
                "\t\tbasic_var_list[i].value[j]= va_arg(args, int);\n" +
                "\t}\n" +
                "\tva_end(args); \n" +
                "\treturn 0;\n" +
                "}\n";
        outputStream.write(non_deter.getBytes());

        //写分支状态提交函数
        String states_emitted = "\r\n";
        states_emitted +="int states_emitted(state_t *out,transition_info_t *transition_info,int cpy[],void (*callback)(void* arg, transition_info_t *transition_info, state_t *out, int *cpy),void *arg,int i){\n" +
                "\tint count =0;\n" +
                "\tfor(;i<smv_get_state_size();i++){\n" +
                "\t\tif(basic_var_list[i].num>1 ){\n" +
                "\t\t\tint j;\n" +
                "\t\t\tfor(j=0;j<basic_var_list[i].num;j++){\n" +
                "\t\t\t\tint *change = (int *)out;\n" +
                "\t\t\t\t*(int*)((char *)change + sizeof(int)*i) = basic_var_list[i].value[j];\n" +
                "\t\t\t\tcount += states_emitted(out,transition_info,cpy,callback,arg,i+1);\n" +
                "\t\t\t}\n" +
                "\t\t\tbreak;\n" +
                "\t\t}\n" +
                "\t}\n" +
                "\tif(i==smv_get_state_size()){\n" +
                "\t\tcallback(arg,transition_info,out,cpy);\n" +
                "\t\tcount++;\n" +
                "\t}else if(i == 0){\n" +
                "\t\tfor(;i<smv_get_state_size();i++){\n" +
                "\t\t\tbasic_var_list[i].num=1; \n" +
                "\t\t}\n" +
                "\t}" +
                "\treturn count;\n" +
                "}\r\n";
        outputStream.write(states_emitted.getBytes());
        //写获得初始状态的函数
        String get_init ="void smv_get_initial_state(int *to){\n" +
                "\tmemcpy(to, (char*)&initial_s, sizeof(state_t));\n" +
                "}\n";
        outputStream.write(get_init.getBytes());
        //写action函数
        outputStream.write("\r\nint smv_get_actions (void* model, int t, state_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_t *out, int *cpy), void *arg) {\r\n".getBytes());
        String action_del = "\tint transition_labels[2] = {0, 0, };\r\n\ttransition_info_t transition_info = { transition_labels, t };\r\n\tstate_t local_state;\r\n\tstate_t* out = &local_state;\r\n";
        action_del+="\tint cpy["+smv.stateInfos.size()+"] = { " + "1,".repeat(smv.stateInfos.size())+"};\r\n";
        outputStream.write(action_del.getBytes());

        code += "\t".repeat(tabcount) + "switch(t) {\r\n";
        int i;
        for(i =0; i<= smv.actiongroups.size();i++){
            boolean[] state_used = new boolean[smv.stateInfos.size()];
            code +="\t".repeat(tabcount) + "case "+i+": {\r\n";
            tabcount++;
            code +="\t".repeat(tabcount) + "memcpy(out, in, sizeof(state_t));\r\n";
            //每组转换
            if(i == 0){

                for(Actiongroup actiongroup : smv.actiongroups){
                    for(basic_var de : actiongroup.deineVars){
                        code += "\t".repeat(tabcount) + "int " +  de.name+";\n";
                    }
                }
                for(Actiongroup actiongroup : smv.actiongroups){
                    for(basic_var de : actiongroup.deineVars){
                        if(de.define_expr !=null){
                            code+="\t".repeat(tabcount) +  de.name+" = " + de.define_expr;
                        }
                    }
                    for(basic_var bv : actiongroup.basicVars){
                        if(bv.init_expr !=null){
                            use_state(bv.name,smv,state_used);
                            code+="\t".repeat(tabcount) +"out->"+bv.name+" = " + bv.init_expr;
                            smv.set_matrix(bv.init_expr,bv.name,0);
                            code+="\t".repeat(tabcount) + "cpy[((int *)&out->"+bv.name+" - (int *)out)] = 0;\r\n";
                        }
                    }
                }
                code+="\t".repeat(tabcount) +"out->virtual_init = FALSE;\n";
                smv.set_matrix("FALSE","virtual_init",0);
                code+="\t".repeat(tabcount) +"cpy[((int *)&out->virtual_init - (int *)out)] = 0;\n";

            }else if(smv.actiongroups.size()==1){
                for(basic_var de : smv.actiongroups.get(0).deineVars){
                    if(de.define_expr !=null){
                        code+="\t".repeat(tabcount) +"int " +  de.name+";\n";
                    }
                }
                for(basic_var de : smv.actiongroups.get(0).deineVars){
                    if(de.define_expr !=null){
                        code+="\t".repeat(tabcount) +  de.name+" = " + de.define_expr;
                    }
                }
                for(basic_var bv : smv.actiongroups.get(0).basicVars) {
                    if (bv.next_expr != null) {
                        use_state(bv.name,smv,state_used);
                        code += "\t".repeat(tabcount) + "out->" + bv.name + " = " + bv.next_expr;
                        smv.set_matrix(bv.next_expr,bv.name,1);
                        code+="\t".repeat(tabcount) + "cpy[((int *)&out->"+bv.name+" - (int *)out)] = 0;\r\n";
                    }
                }

            }else if(smv.actiongroups.size()>1){
                if(i<smv.actiongroups.size()){
                    int m;
                    for(m=0;m<smv.stateInfos.size();m++){
                        state_used[m]=true;
                        for (basic_var use : smv.actiongroups.get(i).basicVars) {
                            if (smv.stateInfos.get(m).state_vector_name.equals(use)){
                                state_used[m]=false;
                                break;
                            }
                        }
                    }
                    for(basic_var de : smv.actiongroups.get(i).deineVars){
                        code+="\t".repeat(tabcount) +"int " +  de.name+";\n";
                    }

                    for(basic_var de : smv.actiongroups.get(i).deineVars){
                        if(de.define_expr !=null){
                            code+="\t".repeat(tabcount) + de.name+" = " + de.define_expr;
                        }
                    }
                    for(basic_var bv : smv.actiongroups.get(i).basicVars){
                        if(bv.next_expr !=null){
                            use_state(bv.name,smv,state_used);
                            code+="\t".repeat(tabcount) +"out->"+bv.name+" = " + bv.next_expr;
                            smv.set_matrix(bv.next_expr,bv.name,i);
                            code+="\t".repeat(tabcount) + "cpy[((int *)&out->"+bv.name+" - (int *)out)] = 0;\r\n";
                        }
                    }

                }
            }
            if(smv.actiongroups.size()>1&&i == smv.actiongroups.size()){
                code+="\t".repeat(tabcount) +"transition_labels[0] = "+i+";\n"+"\t".repeat(tabcount) +"transition_info.group = "+i+";\r\n";
                for (int j = 1;j<smv.actiongroups.size();j++) {
                    code += "\t".repeat(tabcount) + "out->" + smv.actiongroups.get(j).basicVars.get(0).name+ "= TRUE;\n";
                    smv.set_matrix("TRUE",smv.actiongroups.get(j).basicVars.get(0).name,i);
                    code+="\t".repeat(tabcount) + "cpy[((int *)&out->"+smv.actiongroups.get(j).basicVars.get(0).name+" - (int *)out)] = 0;\r\n";
                    code+="\t".repeat(tabcount) + "callback(arg,&transition_info,out,cpy);\n";
                    if(j<smv.actiongroups.size()-1){
                        code += "\t".repeat(tabcount) + "out->" + smv.actiongroups.get(j).basicVars.get(0).name+ "= FALSE;\n";
                        code+="\t".repeat(tabcount) + "cpy[((int *)&out->"+smv.actiongroups.get(j).basicVars.get(0).name+" - (int *)out)] = 1;\r\n";
                    }else {
                        code += "\t".repeat(tabcount) +"return "+(smv.actiongroups.size()-1) + ";\n";
                    }
                }

            }else {
                for (int p = 0; p < state_used.length - 1; p++) {
                    if (!state_used[p] && !smv.stateInfos.get(p).state_vector_name.contains("running")) {
                        smv.set_matrix("",smv.stateInfos.get(p).state_vector_name,i);
                        code += "\t".repeat(tabcount) + "out->" + smv.stateInfos.get(p).state_vector_name + " = " + "smv_non_deterministic(\"" + smv.stateInfos.get(p).state_vector_name + "\"," + smv.stateInfos.get(p).value_set.size();
                        for (String s : smv.stateInfos.get(p).value_set) {
                            code += "," + s;
                        }
                        code += ");\n";
                        code += "\t".repeat(tabcount) + "cpy[((int *)&out->" + smv.stateInfos.get(p).state_vector_name + " - (int *)out)] = 0;\r\n";
                    }
                }
                code+="\t".repeat(tabcount) +"transition_labels[0] = "+i+";\r\n"+"\t".repeat(tabcount) +"transition_info.group = "+i+";\r\n";
                code+="\t".repeat(tabcount) +"return states_emitted(out,&transition_info,cpy,callback,arg,0);\r\n";
            }
            tabcount--;
            code +="\t".repeat(tabcount) +"}\r\n";
            outputStream.write(code.getBytes());
            code = "";
        }
        //以上， 每组的转换
        code += "\t".repeat(tabcount) + "}\r\n";
        code +="}\r\n";
        outputStream.write(code.getBytes());
    }

    public static void use_state(String name, Smv_file smv,boolean[] state_used){
        for(int i=0;i<smv.stateInfos.size();i++){
            if(name.equals(smv.stateInfos.get(i).state_vector_name)){
                state_used[i]= true;
                return;
            }
        }
    }

    public static void write_head(OutputStream outputStream) throws IOException {
        outputStream.write("#include <stdio.h>\r\n#include <stdlib.h>\r\n#include <string.h>\r\n#include <stdarg.h>\r\n".getBytes());
        outputStream.write("#include <ltsmin/pins.h>\n#include <ltsmin/pins-util.h>\n#include <ltsmin/ltsmin-standard.h>\n#include <ltsmin/lts-type.h>\n".getBytes());
        outputStream.write("\r\ntypedef struct basic_var{\r\n\tchar *name;\r\n\tint num;\r\n\tint *value;\r\n}smv_basic_var;\r\n\r\n".getBytes());

    }

    public static void write_next(OutputStream outputStream,Smv_file smv) throws IOException{
        String tmp = "(in->virtual_init == TRUE)";
        String code ="\nint smv_next_state(void* model, int t, state_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_t *out, int *cpy), void *arg){\n";
        code+="\tswitch(t){\n";
        code+="\tcase 0: {\n";
        code += "\t\tif(in->virtual_init){\n" +
                "\t\t\treturn smv_get_actions(model,0,in,callback,arg);\n" +
                "\t\t}\n";
        code+="\t}\n";
        int j=1;
        if(smv.actiongroups.size()>1){
            for(;j<smv.actiongroups.size();j++){
                tmp+="||"+"(in->"+smv.actiongroups.get(j).basicVars.get(0).name+" == TRUE)";
                code+="\tcase "+j+": {\n";
                code+="\t\tif(in->"+smv.actiongroups.get(j).basicVars.get(0).name+" == TRUE){\n" +
                        "\t\t\tsmv_get_actions(model,"+j+",in,callback,arg);\n" +
                        "\t\t}\n";
                code+="\t}\n";
            }
        }
        code+="\tcase "+j+": {\n";
        code+="\t\tif(!("+tmp+")){\n";
        code+="\t\t\treturn smv_get_actions(model,"+j+",in,callback,arg);\n";
        code+="\t\t}\n";
        code+="\t}\n";
        code+="\t}\n";
        code+="}\n";

        outputStream.write(code.getBytes());
        code = "\nint smv_get_transition_groups() {\n" +
                "\treturn "+(j+1)+";\n" +
                "}\n";
        outputStream.write(code.getBytes());
    }

    public static void write_label(OutputStream outputStream,Smv_file smv) throws IOException{
        String tmp = "(in->virtual_init == TRUE)";
        String code ="\nint smv_get_label(void* model, int g, state_t* in){\n";
        code+="\tswitch (g){\n";
        for(int i=0;i<=smv.actiongroups.size();i++){
            if(i==0)
                code+="\t\tcase "+i+": return "+"(in->virtual_init == TRUE)"+"!=0;\n";
            else if(i<smv.actiongroups.size()){
                code+="\t\tcase "+i+": return (in->"+smv.actiongroups.get(i).basicVars.get(0).name+" == TRUE) !=0;\n";
                tmp+="||"+"(in->"+smv.actiongroups.get(i).basicVars.get(0).name+" == TRUE)";
            }else {
                code+="\t\tcase "+i+": return "+"!("+tmp+");\n";
            }
        }
        code+="\t}\n";
        code+="}\n";
        outputStream.write(code.getBytes());
        code = "\nint smv_get_label_count() {\n" +
                "\treturn "+(smv.actiongroups.size()+1)+";\n" +
                "}\n";
        outputStream.write(code.getBytes());
    }

    public static void write_matrix(OutputStream outputStream,Smv_file smv) throws IOException{
        String rm="\nint *read_m["+(smv.actiongroups.size()+1)+"] = {\n";
            for (int i=0;i<smv.actiongroups.size()+1;i++){
                rm+="\t"+"((int[]){"+get_rm(smv,i)+"})";
                if(i<smv.actiongroups.size())
                    rm+=",";
                rm+="\n";
            }
        rm+="};\n";
        String wm="\nint *write_m["+(smv.actiongroups.size()+1)+"] = {\n";
        for (int i=0;i<smv.actiongroups.size()+1;i++){
            wm+="\t"+"((int[]){"+get_wm(smv,i)+"})";
            if(i<smv.actiongroups.size())
                wm+=",";
            wm+="\n";
        }
        wm+="};\n";
        String lm="\nint *label_m["+(smv.actiongroups.size()+1)+"] = {\n";
        for (int i=0;i<smv.actiongroups.size()+1;i++){
            lm+="\t"+"((int[]){"+get_lm(smv,i)+"})";
            if(i<smv.actiongroups.size())
                lm+=",";
            lm+="\n";
        }
        lm+="};\n";

        outputStream.write(rm.getBytes());
        outputStream.write(wm.getBytes());
        outputStream.write(lm.getBytes());

    }
    public static String get_rm(Smv_file smv,int i){
        return count(smv.rm.get(i),",")+smv.rm.get(i);
    }
    public static String get_wm(Smv_file smv,int i){
        return count(smv.wm.get(i),",")+smv.wm.get(i);
    }
    public static String get_lm(Smv_file smv,int i){
        return smv.lm.get(i);
    }

    public static void write_pins_model(OutputStream outputStream,Smv_file smv) throws IOException{
        String code ="\nint state_label_many(void* model, int * src, int * label, int guards_only) {\n" +
                "\t(void)model;\n" +
                "\treturn 0;\n" +
                "}\n" +
                "void sl_group (model_t model, sl_group_enum_t group, int*src, int *label)\n" +
                "\t{\n" +
                "\tstate_label_many (model, src, label, group == GB_SL_GUARDS);\n" +
                "\t(void) group;\n" +
                "\t}\n" +
                "void sl_all (model_t model, int*src, int *label)\n" +
                "\t{\n" +
                "\tstate_label_many (model, src, label, 0);\n" +
                "\t}\n";
        code+= "char pins_plugin_name[] = \""+smv.filename.split("\\.")[0]+"\";";
        code +="\nvoid pins_model_init(model_t m) {\n" +
                "\t// create the LTS type LTSmin will generate\n" +
                "\tlts_type_t ltstype=lts_type_create();\n" +
                "\t// set the length of the state\n" +
                "\tlts_type_set_state_length(ltstype, smv_get_state_size());\n";
        code+="\t"+"// add an int type for a state slot\n";
        code+="\tint int_type = lts_type_add_type(ltstype, \"int\", NULL);\n" +
                "\tlts_type_set_format (ltstype, int_type, LTStypeDirect);\n";
        for(int i=0;i<smv.stateInfos.size();i++){
            code +="\tlts_type_set_state_name(ltstype, "+i+",\""+smv.stateInfos.get(i).state_vector_name+"\");\n" +
                    "\tlts_type_set_state_typeno(ltstype, "+i+",int_type);\n";
        }
        code+="\n\t// add an action type for edge labels\n";
        code+="\tint action_type = lts_type_add_type(ltstype, \"action\", NULL);\n" +
                "\tlts_type_set_format (ltstype, action_type, LTStypeEnum);\n" +
                "\tlts_type_set_edge_label_count (ltstype, 1);\n" +
                "\tlts_type_set_edge_label_name(ltstype, 0, \"action\");\n" +
                "\tlts_type_set_edge_label_type(ltstype, 0, \"action\");\n" +
                "\tlts_type_set_edge_label_typeno(ltstype, 0, action_type);\n";
        code+="\n\t// add bool type for state labels\n" +
                "\tint bool_type = lts_type_put_type (ltstype, \"boolean\", LTStypeBool, NULL);\n" +
                "\tlts_type_set_state_label_count (ltstype, smv_get_label_count());\n";
        String tmp="";
        for(int i=0;i<=smv.actiongroups.size();i++){
            if(i==0) {
                code += "\tlts_type_set_state_label_typeno (ltstype, "+i+", bool_type);\n" +
                        "\tlts_type_set_state_label_name (ltstype, "+i+", \"init\");\n";
                tmp+="\tpins_chunk_put(m, action_type, chunk_str(\"init\"));\n";
            }else if(i<smv.actiongroups.size()){
                code +="\tlts_type_set_state_label_typeno (ltstype, "+i+", bool_type);\n" +
                        "\tlts_type_set_state_label_name (ltstype, "+i+", \""+"now_"+smv.actiongroups.get(i).basicVars.get(0).name+"\");\n";
                tmp+="\tpins_chunk_put(m, action_type, chunk_str(\""+smv.actiongroups.get(i).basicVars.get(0).name+"\"));\n";
            }else{
                if(i==1){
                    code += "\tlts_type_set_state_label_typeno (ltstype, 1, bool_type);\n" +
                            "\tlts_type_set_state_label_name (ltstype, 1, \"next\");\n";
                    tmp+="\tpins_chunk_put(m, action_type, chunk_str(\"next\"));\n";
                }else {
                    code += "\tlts_type_set_state_label_typeno (ltstype, "+i+", bool_type);\n" +
                            "\tlts_type_set_state_label_name (ltstype, "+i+", \"choose_running\");\n";
                    tmp+="\tpins_chunk_put(m, action_type, chunk_str(\"choose_running\"));\n";
                }
            }
        }
        code+="\tlts_type_validate(ltstype);\n" +
                "\tGBsetLTStype(m, ltstype);\n";
        code+=tmp;
        code+="\tint state["+smv.stateInfos.size()+"];\n";
        code+="\tsmv_get_initial_state(state);\n" +
                "\tGBsetInitialState(m,state);\n" +
                "\tGBsetNextStateLong(m, (next_method_grey_t) smv_next_state);\n" +
                "\tGBsetStateLabelLong(m, (get_label_method_t) smv_get_label);\n" +
                "\tmatrix_t *cm = malloc(sizeof(matrix_t));\n" +
                "\tdm_create(cm, smv_get_transition_groups(), smv_get_state_size());\n" +
                "\tmatrix_t *rm = malloc(sizeof(matrix_t));\n" +
                "\tdm_create(rm, smv_get_transition_groups(), smv_get_state_size());\n" +
                "\tfor (int i = 0; i < smv_get_transition_groups(); i++) {\n" +
                "\t\tint sz = read_m[i][0];\n" +
                "\t\tfor (int j = 1; j < sz + 1; j++) {\n" +
                "\t\t\tint indj = read_m[i][j];\n" +
                "\t\t\tdm_set(cm, i, indj);\n" +
                "\t\t\tdm_set(rm, i, indj);\n" +
                "\t\t}\n" +
                "\t}\n" +
                "\tGBsetDMInfoRead(m, rm);\n" +
                "\tmatrix_t *wm = malloc(sizeof(matrix_t));\n" +
                "\tdm_create(wm, smv_get_transition_groups(), smv_get_state_size());\n" +
                "\tfor (int i = 0; i < smv_get_transition_groups(); i++) {\n" +
                "\t\tint sz = write_m[i][0];\n" +
                "\t\tfor (int j = 1; j < sz + 1; j++) {\n" +
                "\t\t\tint indj = write_m[i][j];\n" +
                "\t\t\tdm_set(cm, i, indj);\n" +
                "\t\t\tdm_set(wm, i, indj);\n" +
                "\t\t}\n" +
                "\t}\n" +
                "\tGBsetDMInfoMustWrite(m, wm);\n" +
                "\tGBsetDMInfo(m, cm);\n" +
                "\tmatrix_t *lm = malloc(sizeof(matrix_t));\n" +
                "\tdm_create(lm, smv_get_label_count(), smv_get_state_size());\n" +
                "\tfor (int i = 0; i < smv_get_label_count(); i++) {\n" +
                "\t\tint sz = label_m[i][0];\n" +
                "\t\tfor (int j = 1; j < sz + 1; j++) {\n" +
                "\t\t\tdm_set(lm, i, label_m[i][j]);\n" +
                "\t  }\n" +
                "\t}\n" +
                "\tGBsetStateLabelInfo(m, lm);\n" +
                "\tint sl_size = smv_get_label_count();\n" +
                "\tsl_group_t* sl_group_all = malloc(sizeof(sl_group_t) + sl_size * sizeof(int));\n" +
                "\tsl_group_all->count = sl_size;\n" +
                "\tfor(int i=0; i < sl_group_all->count; i++) sl_group_all->sl_idx[i] = i;\n" +
                "\tGBsetStateLabelGroupInfo(m, GB_SL_ALL, sl_group_all);\n" +
                "\tGBsetStateLabelsGroup(m, sl_group);\n";
        code +="}\n";
        outputStream.write(code.getBytes());
    }


    public static void write_test(OutputStream outputStream) throws  IOException{
        String test ="\nstate_t *new_state;\n" +
                "\n" +
                "void spins_simple_atomic_cb (void* arg, transition_info_t *transition_info, state_t *out, int *cpy){\n" +
                "\tstatic int i =0;\n" +
                "\ti++;\n" +
                "\tnew_state = out;\n" +
                "\tprintf(\"callback:%d\\n\",i);\n" +
                "}\n" +
                "\n" +
                "int main(){\n" +
                "\tvoid * model;\n" +
                "\tvoid * arg;\n" +
                "\tint a= smv_get_actions(model,1,&initial,spins_simple_atomic_cb,arg);\n" +
                "\tint j;\n" +
                "\tprintf(\"test:%d\",a);\n" +
                "\tfor(j=0;j<10;j++){\n" +
                "\t\tprintf(\"---------new_start----------\\n\");\n" +
                "\t\tsmv_get_actions(model,j/3,new_state,spins_simple_atomic_cb,arg);\n" +
                "\t\tprintf(\"---------end----------\\n\");\n" +
                "\t}\n" +
                "}\n";
        outputStream.write(test.getBytes());
    }



    public static void compile(String code,String filename) throws IOException {
        CharStream input = CharStreams.fromString(code);
        smvLexer lexer = new smvLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        smvParser parser = new smvParser(tokens);
        ParseTree parseTree = parser.file();
        mySmvVisitor visitor = new mySmvVisitor();
        visitor.visit(parseTree);
        System.out.print("test"+ visitor.smv.toString());
        visitor.smv.name_correction();
        visitor.smv.filename =filename;
        visitor.smv.init();
        write_code(visitor.smv);
    }

    public static  void main(String[] args) throws IOException {
        File dir = new File("C:\\Users\\ztb\\Desktop\\new_case\\src");

        for (int i = 0; i < dir.listFiles().length; i++) {
            File f = dir.listFiles()[i];
            byte[] buffer = new byte[1024];
            String code = "";
            //读取smv文件内容到code
            try (InputStream inputStream = new FileInputStream(f)) {
                while (true) {
                    int len = inputStream.read(buffer);
                    if (len == -1) {
                        break;
                    }
                    String tmp = new String(buffer, 0, len);
                    code += tmp;
                }
                //测试读取是否正常
                //System.out.println(code);
            } catch (IOException e) {
                e.printStackTrace();
            }
            //编译code
            compile(code, f.getName());
        }
    }
}
