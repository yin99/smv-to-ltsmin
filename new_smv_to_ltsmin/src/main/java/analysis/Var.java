package analysis;

import org.antlr.v4.runtime.tree.ParseTree;
import smv.smvParser;

import java.security.PublicKey;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Var {

    public String name;
    public VarType type;
    //simple_var
    public String sim_type;
    //module_var
    public boolean isProcess;
    public boolean havePara;
    public String module_name;
    public List<smvParser.ParaContext> rel_para = new ArrayList<smvParser.ParaContext>();
    //如果是数组，则为数组序号，否则为取值范围
    public int min;
    public int max;
    public int array_size;
    public String array_type;
    //枚举变量
    public List<String> enum_value =new ArrayList<String>();
    //DEFINE类型
    public Expr define_expr;

    public String new_type_name;


    //设置模型类型变量数据
    public void set_var_info(String module_name,boolean process,smvParser.Para_listContext para_list){
        this.type = VarType.module_var;
        this.module_name = module_name;
        this.isProcess = process;
        if(para_list == null)
            this.havePara = false;
        else {
            this.havePara = true;
            getparas(para_list);
        }
    }

    public void getparas(smvParser.Para_listContext ctx){
        if(ctx.para_list()!=null){
            getparas(ctx.para_list());
        }
        rel_para.add(ctx.para());
    }

    //设置简单类型变量数据
    public void set_var_info(String type){
        this.type = VarType.simple_var;
        this.sim_type = type;
    }
    //设置数组类型变量数据
    public void set_var_info(int min,int max,String type){
        this.type = VarType.array_var;
        this.min = min;
        this.max = max;
        this.array_type = type;
    }
    //设枚举类型变量数据
    public void set_var_info(String[] values){
        this.type = VarType.enum_var;
        enum_value.addAll(Arrays.asList(values));
    }
    //设枚举类型变量数据
    public void set_var_info(int a,int b){
        this.type = VarType.int_range_var;
        this.min = a;
        this.max = b;
    }

    public void set_var_info(String def_name,Expr def_expr){
        this.name = def_name;
        this.type = VarType.define_var;
        this.define_expr = def_expr;
    }


}
