// Generated from C:/Users/ztb/IdeaProjects/new_smv_to_ltsmin/src\smv.g4 by ANTLR 4.8
package smv;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link smvParser}.
 */
public interface smvListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link smvParser#file}.
	 * @param ctx the parse tree
	 */
	void enterFile(smvParser.FileContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#file}.
	 * @param ctx the parse tree
	 */
	void exitFile(smvParser.FileContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#module}.
	 * @param ctx the parse tree
	 */
	void enterModule(smvParser.ModuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#module}.
	 * @param ctx the parse tree
	 */
	void exitModule(smvParser.ModuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#para_list}.
	 * @param ctx the parse tree
	 */
	void enterPara_list(smvParser.Para_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#para_list}.
	 * @param ctx the parse tree
	 */
	void exitPara_list(smvParser.Para_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#para}.
	 * @param ctx the parse tree
	 */
	void enterPara(smvParser.ParaContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#para}.
	 * @param ctx the parse tree
	 */
	void exitPara(smvParser.ParaContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#module_body}.
	 * @param ctx the parse tree
	 */
	void enterModule_body(smvParser.Module_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#module_body}.
	 * @param ctx the parse tree
	 */
	void exitModule_body(smvParser.Module_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#module_element}.
	 * @param ctx the parse tree
	 */
	void enterModule_element(smvParser.Module_elementContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#module_element}.
	 * @param ctx the parse tree
	 */
	void exitModule_element(smvParser.Module_elementContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#fairness_constraint}.
	 * @param ctx the parse tree
	 */
	void enterFairness_constraint(smvParser.Fairness_constraintContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#fairness_constraint}.
	 * @param ctx the parse tree
	 */
	void exitFairness_constraint(smvParser.Fairness_constraintContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#invar_constraint}.
	 * @param ctx the parse tree
	 */
	void enterInvar_constraint(smvParser.Invar_constraintContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#invar_constraint}.
	 * @param ctx the parse tree
	 */
	void exitInvar_constraint(smvParser.Invar_constraintContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#init_constraint}.
	 * @param ctx the parse tree
	 */
	void enterInit_constraint(smvParser.Init_constraintContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#init_constraint}.
	 * @param ctx the parse tree
	 */
	void exitInit_constraint(smvParser.Init_constraintContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#trans_constraint}.
	 * @param ctx the parse tree
	 */
	void enterTrans_constraint(smvParser.Trans_constraintContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#trans_constraint}.
	 * @param ctx the parse tree
	 */
	void exitTrans_constraint(smvParser.Trans_constraintContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#assign_constraint}.
	 * @param ctx the parse tree
	 */
	void enterAssign_constraint(smvParser.Assign_constraintContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#assign_constraint}.
	 * @param ctx the parse tree
	 */
	void exitAssign_constraint(smvParser.Assign_constraintContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#assign_list}.
	 * @param ctx the parse tree
	 */
	void enterAssign_list(smvParser.Assign_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#assign_list}.
	 * @param ctx the parse tree
	 */
	void exitAssign_list(smvParser.Assign_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#assign}.
	 * @param ctx the parse tree
	 */
	void enterAssign(smvParser.AssignContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#assign}.
	 * @param ctx the parse tree
	 */
	void exitAssign(smvParser.AssignContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#init_assign}.
	 * @param ctx the parse tree
	 */
	void enterInit_assign(smvParser.Init_assignContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#init_assign}.
	 * @param ctx the parse tree
	 */
	void exitInit_assign(smvParser.Init_assignContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#next_assign}.
	 * @param ctx the parse tree
	 */
	void enterNext_assign(smvParser.Next_assignContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#next_assign}.
	 * @param ctx the parse tree
	 */
	void exitNext_assign(smvParser.Next_assignContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#constants_declaration}.
	 * @param ctx the parse tree
	 */
	void enterConstants_declaration(smvParser.Constants_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#constants_declaration}.
	 * @param ctx the parse tree
	 */
	void exitConstants_declaration(smvParser.Constants_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#constants_body}.
	 * @param ctx the parse tree
	 */
	void enterConstants_body(smvParser.Constants_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#constants_body}.
	 * @param ctx the parse tree
	 */
	void exitConstants_body(smvParser.Constants_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#frozenvar_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFrozenvar_declaration(smvParser.Frozenvar_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#frozenvar_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFrozenvar_declaration(smvParser.Frozenvar_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVar_declaration(smvParser.Var_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVar_declaration(smvParser.Var_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#ivar_declaration}.
	 * @param ctx the parse tree
	 */
	void enterIvar_declaration(smvParser.Ivar_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#ivar_declaration}.
	 * @param ctx the parse tree
	 */
	void exitIvar_declaration(smvParser.Ivar_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#var_list}.
	 * @param ctx the parse tree
	 */
	void enterVar_list(smvParser.Var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#var_list}.
	 * @param ctx the parse tree
	 */
	void exitVar_list(smvParser.Var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#simple_var_list}.
	 * @param ctx the parse tree
	 */
	void enterSimple_var_list(smvParser.Simple_var_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#simple_var_list}.
	 * @param ctx the parse tree
	 */
	void exitSimple_var_list(smvParser.Simple_var_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#var}.
	 * @param ctx the parse tree
	 */
	void enterVar(smvParser.VarContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#var}.
	 * @param ctx the parse tree
	 */
	void exitVar(smvParser.VarContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#type_sepcifier}.
	 * @param ctx the parse tree
	 */
	void enterType_sepcifier(smvParser.Type_sepcifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#type_sepcifier}.
	 * @param ctx the parse tree
	 */
	void exitType_sepcifier(smvParser.Type_sepcifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#simple_type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterSimple_type_specifier(smvParser.Simple_type_specifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#simple_type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitSimple_type_specifier(smvParser.Simple_type_specifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#enumeration_type_body}.
	 * @param ctx the parse tree
	 */
	void enterEnumeration_type_body(smvParser.Enumeration_type_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#enumeration_type_body}.
	 * @param ctx the parse tree
	 */
	void exitEnumeration_type_body(smvParser.Enumeration_type_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#enumeration_type_value}.
	 * @param ctx the parse tree
	 */
	void enterEnumeration_type_value(smvParser.Enumeration_type_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#enumeration_type_value}.
	 * @param ctx the parse tree
	 */
	void exitEnumeration_type_value(smvParser.Enumeration_type_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#integer_range}.
	 * @param ctx the parse tree
	 */
	void enterInteger_range(smvParser.Integer_rangeContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#integer_range}.
	 * @param ctx the parse tree
	 */
	void exitInteger_range(smvParser.Integer_rangeContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#symbolic_constant}.
	 * @param ctx the parse tree
	 */
	void enterSymbolic_constant(smvParser.Symbolic_constantContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#symbolic_constant}.
	 * @param ctx the parse tree
	 */
	void exitSymbolic_constant(smvParser.Symbolic_constantContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#module_type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterModule_type_specifier(smvParser.Module_type_specifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#module_type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitModule_type_specifier(smvParser.Module_type_specifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#define_declaration}.
	 * @param ctx the parse tree
	 */
	void enterDefine_declaration(smvParser.Define_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#define_declaration}.
	 * @param ctx the parse tree
	 */
	void exitDefine_declaration(smvParser.Define_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#define_body}.
	 * @param ctx the parse tree
	 */
	void enterDefine_body(smvParser.Define_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#define_body}.
	 * @param ctx the parse tree
	 */
	void exitDefine_body(smvParser.Define_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#basic_next_expr}.
	 * @param ctx the parse tree
	 */
	void enterBasic_next_expr(smvParser.Basic_next_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#basic_next_expr}.
	 * @param ctx the parse tree
	 */
	void exitBasic_next_expr(smvParser.Basic_next_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#set_next_body}.
	 * @param ctx the parse tree
	 */
	void enterSet_next_body(smvParser.Set_next_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#set_next_body}.
	 * @param ctx the parse tree
	 */
	void exitSet_next_body(smvParser.Set_next_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#case_expr}.
	 * @param ctx the parse tree
	 */
	void enterCase_expr(smvParser.Case_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#case_expr}.
	 * @param ctx the parse tree
	 */
	void exitCase_expr(smvParser.Case_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#case_next_body}.
	 * @param ctx the parse tree
	 */
	void enterCase_next_body(smvParser.Case_next_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#case_next_body}.
	 * @param ctx the parse tree
	 */
	void exitCase_next_body(smvParser.Case_next_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#case_cond}.
	 * @param ctx the parse tree
	 */
	void enterCase_cond(smvParser.Case_condContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#case_cond}.
	 * @param ctx the parse tree
	 */
	void exitCase_cond(smvParser.Case_condContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#case_value}.
	 * @param ctx the parse tree
	 */
	void enterCase_value(smvParser.Case_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#case_value}.
	 * @param ctx the parse tree
	 */
	void exitCase_value(smvParser.Case_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#mul}.
	 * @param ctx the parse tree
	 */
	void enterMul(smvParser.MulContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#mul}.
	 * @param ctx the parse tree
	 */
	void exitMul(smvParser.MulContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#mod}.
	 * @param ctx the parse tree
	 */
	void enterMod(smvParser.ModContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#mod}.
	 * @param ctx the parse tree
	 */
	void exitMod(smvParser.ModContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#add}.
	 * @param ctx the parse tree
	 */
	void enterAdd(smvParser.AddContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#add}.
	 * @param ctx the parse tree
	 */
	void exitAdd(smvParser.AddContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#shift}.
	 * @param ctx the parse tree
	 */
	void enterShift(smvParser.ShiftContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#shift}.
	 * @param ctx the parse tree
	 */
	void exitShift(smvParser.ShiftContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#union}.
	 * @param ctx the parse tree
	 */
	void enterUnion(smvParser.UnionContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#union}.
	 * @param ctx the parse tree
	 */
	void exitUnion(smvParser.UnionContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#logicjudge}.
	 * @param ctx the parse tree
	 */
	void enterLogicjudge(smvParser.LogicjudgeContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#logicjudge}.
	 * @param ctx the parse tree
	 */
	void exitLogicjudge(smvParser.LogicjudgeContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#logicand}.
	 * @param ctx the parse tree
	 */
	void enterLogicand(smvParser.LogicandContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#logicand}.
	 * @param ctx the parse tree
	 */
	void exitLogicand(smvParser.LogicandContext ctx);
	/**
	 * Enter a parse tree produced by {@link smvParser#logicor}.
	 * @param ctx the parse tree
	 */
	void enterLogicor(smvParser.LogicorContext ctx);
	/**
	 * Exit a parse tree produced by {@link smvParser#logicor}.
	 * @param ctx the parse tree
	 */
	void exitLogicor(smvParser.LogicorContext ctx);
}