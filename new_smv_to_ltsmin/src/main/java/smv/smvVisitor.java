// Generated from C:/Users/ztb/IdeaProjects/new_smv_to_ltsmin/src\smv.g4 by ANTLR 4.8
package smv;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link smvParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface smvVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link smvParser#file}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFile(smvParser.FileContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#module}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule(smvParser.ModuleContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#para_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPara_list(smvParser.Para_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#para}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPara(smvParser.ParaContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#module_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule_body(smvParser.Module_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#module_element}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule_element(smvParser.Module_elementContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#fairness_constraint}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFairness_constraint(smvParser.Fairness_constraintContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#invar_constraint}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInvar_constraint(smvParser.Invar_constraintContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#init_constraint}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInit_constraint(smvParser.Init_constraintContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#trans_constraint}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTrans_constraint(smvParser.Trans_constraintContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#assign_constraint}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign_constraint(smvParser.Assign_constraintContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#assign_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign_list(smvParser.Assign_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#assign}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign(smvParser.AssignContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#init_assign}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInit_assign(smvParser.Init_assignContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#next_assign}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNext_assign(smvParser.Next_assignContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#constants_declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstants_declaration(smvParser.Constants_declarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#constants_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstants_body(smvParser.Constants_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#frozenvar_declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFrozenvar_declaration(smvParser.Frozenvar_declarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#var_declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_declaration(smvParser.Var_declarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#ivar_declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIvar_declaration(smvParser.Ivar_declarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_list(smvParser.Var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#simple_var_list}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSimple_var_list(smvParser.Simple_var_listContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#var}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar(smvParser.VarContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#type_sepcifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_sepcifier(smvParser.Type_sepcifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#simple_type_specifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSimple_type_specifier(smvParser.Simple_type_specifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#enumeration_type_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumeration_type_body(smvParser.Enumeration_type_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#enumeration_type_value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumeration_type_value(smvParser.Enumeration_type_valueContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#integer_range}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInteger_range(smvParser.Integer_rangeContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#symbolic_constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSymbolic_constant(smvParser.Symbolic_constantContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#module_type_specifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule_type_specifier(smvParser.Module_type_specifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#define_declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDefine_declaration(smvParser.Define_declarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#define_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDefine_body(smvParser.Define_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#basic_next_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBasic_next_expr(smvParser.Basic_next_exprContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#set_next_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSet_next_body(smvParser.Set_next_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#case_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCase_expr(smvParser.Case_exprContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#case_next_body}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCase_next_body(smvParser.Case_next_bodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#case_cond}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCase_cond(smvParser.Case_condContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#case_value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCase_value(smvParser.Case_valueContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#mul}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMul(smvParser.MulContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#mod}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMod(smvParser.ModContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#add}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAdd(smvParser.AddContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#shift}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitShift(smvParser.ShiftContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#union}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnion(smvParser.UnionContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#logicjudge}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLogicjudge(smvParser.LogicjudgeContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#logicand}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLogicand(smvParser.LogicandContext ctx);
	/**
	 * Visit a parse tree produced by {@link smvParser#logicor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLogicor(smvParser.LogicorContext ctx);
}