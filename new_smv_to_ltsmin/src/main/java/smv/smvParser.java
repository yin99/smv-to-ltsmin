// Generated from C:/Users/ztb/IdeaProjects/new_smv_to_ltsmin/src\smv.g4 by ANTLR 4.8
package smv;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class smvParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, T__35=36, T__36=37, T__37=38, 
		T__38=39, T__39=40, T__40=41, T__41=42, T__42=43, T__43=44, T__44=45, 
		T__45=46, T__46=47, T__47=48, T__48=49, T__49=50, T__50=51, T__51=52, 
		T__52=53, T__53=54, T__54=55, INTEGER=56, IDENTIFIER=57, IDENTIFIER_FIRST_CHARACTER=58, 
		IDENTIFIER_CONSECUTIVE_CHARACTER=59, DIGHT=60, ZHUSHI=61, IGNORE=62;
	public static final int
		RULE_file = 0, RULE_module = 1, RULE_para_list = 2, RULE_para = 3, RULE_module_body = 4, 
		RULE_module_element = 5, RULE_fairness_constraint = 6, RULE_invar_constraint = 7, 
		RULE_init_constraint = 8, RULE_trans_constraint = 9, RULE_assign_constraint = 10, 
		RULE_assign_list = 11, RULE_assign = 12, RULE_init_assign = 13, RULE_next_assign = 14, 
		RULE_constants_declaration = 15, RULE_constants_body = 16, RULE_frozenvar_declaration = 17, 
		RULE_var_declaration = 18, RULE_ivar_declaration = 19, RULE_var_list = 20, 
		RULE_simple_var_list = 21, RULE_var = 22, RULE_type_sepcifier = 23, RULE_simple_type_specifier = 24, 
		RULE_enumeration_type_body = 25, RULE_enumeration_type_value = 26, RULE_integer_range = 27, 
		RULE_symbolic_constant = 28, RULE_module_type_specifier = 29, RULE_define_declaration = 30, 
		RULE_define_body = 31, RULE_basic_next_expr = 32, RULE_set_next_body = 33, 
		RULE_case_expr = 34, RULE_case_next_body = 35, RULE_case_cond = 36, RULE_case_value = 37, 
		RULE_mul = 38, RULE_mod = 39, RULE_add = 40, RULE_shift = 41, RULE_union = 42, 
		RULE_logicjudge = 43, RULE_logicand = 44, RULE_logicor = 45;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "module", "para_list", "para", "module_body", "module_element", 
			"fairness_constraint", "invar_constraint", "init_constraint", "trans_constraint", 
			"assign_constraint", "assign_list", "assign", "init_assign", "next_assign", 
			"constants_declaration", "constants_body", "frozenvar_declaration", "var_declaration", 
			"ivar_declaration", "var_list", "simple_var_list", "var", "type_sepcifier", 
			"simple_type_specifier", "enumeration_type_body", "enumeration_type_value", 
			"integer_range", "symbolic_constant", "module_type_specifier", "define_declaration", 
			"define_body", "basic_next_expr", "set_next_body", "case_expr", "case_next_body", 
			"case_cond", "case_value", "mul", "mod", "add", "shift", "union", "logicjudge", 
			"logicand", "logicor"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'MODULE'", "'('", "')'", "','", "'FAIRNESS'", "';'", "'INVAR'", 
			"'INIT'", "'TRANS'", "'ASSIGN'", "':='", "'init('", "'next('", "'CONSTANTS'", 
			"'FROZENVAR'", "'VAR'", "'IVAR'", "':'", "'['", "']'", "'.'", "'boolean'", 
			"'{'", "'}'", "'array'", "'of'", "'..'", "'process'", "'DEFINE'", "'!'", 
			"'?'", "'<->'", "'->'", "'bool('", "'toint('", "'in'", "'case'", "'esac'", 
			"'*'", "'/'", "'mod'", "'+'", "'-'", "'<<'", "'>>'", "'union'", "'='", 
			"'!='", "'>'", "'<'", "'>='", "'<='", "'&'", "'|'", "'xor'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, "INTEGER", "IDENTIFIER", 
			"IDENTIFIER_FIRST_CHARACTER", "IDENTIFIER_CONSECUTIVE_CHARACTER", "DIGHT", 
			"ZHUSHI", "IGNORE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "smv.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public smvParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class FileContext extends ParserRuleContext {
		public List<ModuleContext> module() {
			return getRuleContexts(ModuleContext.class);
		}
		public ModuleContext module(int i) {
			return getRuleContext(ModuleContext.class,i);
		}
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterFile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitFile(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitFile(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(95);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0) {
				{
				{
				setState(92);
				module();
				}
				}
				setState(97);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ModuleContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(smvParser.IDENTIFIER, 0); }
		public Module_bodyContext module_body() {
			return getRuleContext(Module_bodyContext.class,0);
		}
		public Para_listContext para_list() {
			return getRuleContext(Para_listContext.class,0);
		}
		public ModuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterModule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitModule(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitModule(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ModuleContext module() throws RecognitionException {
		ModuleContext _localctx = new ModuleContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_module);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(98);
			match(T__0);
			setState(99);
			match(IDENTIFIER);
			setState(104);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__1) {
				{
				setState(100);
				match(T__1);
				setState(101);
				para_list(0);
				setState(102);
				match(T__2);
				}
			}

			setState(106);
			module_body(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Para_listContext extends ParserRuleContext {
		public ParaContext para() {
			return getRuleContext(ParaContext.class,0);
		}
		public Para_listContext para_list() {
			return getRuleContext(Para_listContext.class,0);
		}
		public Para_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_para_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterPara_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitPara_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitPara_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Para_listContext para_list() throws RecognitionException {
		return para_list(0);
	}

	private Para_listContext para_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Para_listContext _localctx = new Para_listContext(_ctx, _parentState);
		Para_listContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_para_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(109);
			para();
			}
			_ctx.stop = _input.LT(-1);
			setState(116);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Para_listContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_para_list);
					setState(111);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(112);
					match(T__3);
					setState(113);
					para();
					}
					} 
				}
				setState(118);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ParaContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public ParaContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_para; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterPara(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitPara(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitPara(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ParaContext para() throws RecognitionException {
		ParaContext _localctx = new ParaContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_para);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(119);
			basic_next_expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Module_bodyContext extends ParserRuleContext {
		public Module_elementContext module_element() {
			return getRuleContext(Module_elementContext.class,0);
		}
		public Module_bodyContext module_body() {
			return getRuleContext(Module_bodyContext.class,0);
		}
		public Module_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterModule_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitModule_body(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitModule_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Module_bodyContext module_body() throws RecognitionException {
		return module_body(0);
	}

	private Module_bodyContext module_body(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Module_bodyContext _localctx = new Module_bodyContext(_ctx, _parentState);
		Module_bodyContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_module_body, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(122);
			module_element();
			}
			_ctx.stop = _input.LT(-1);
			setState(128);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Module_bodyContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_module_body);
					setState(124);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(125);
					module_element();
					}
					} 
				}
				setState(130);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Module_elementContext extends ParserRuleContext {
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Ivar_declarationContext ivar_declaration() {
			return getRuleContext(Ivar_declarationContext.class,0);
		}
		public Frozenvar_declarationContext frozenvar_declaration() {
			return getRuleContext(Frozenvar_declarationContext.class,0);
		}
		public Define_declarationContext define_declaration() {
			return getRuleContext(Define_declarationContext.class,0);
		}
		public Constants_declarationContext constants_declaration() {
			return getRuleContext(Constants_declarationContext.class,0);
		}
		public Assign_constraintContext assign_constraint() {
			return getRuleContext(Assign_constraintContext.class,0);
		}
		public Trans_constraintContext trans_constraint() {
			return getRuleContext(Trans_constraintContext.class,0);
		}
		public Init_constraintContext init_constraint() {
			return getRuleContext(Init_constraintContext.class,0);
		}
		public Invar_constraintContext invar_constraint() {
			return getRuleContext(Invar_constraintContext.class,0);
		}
		public Fairness_constraintContext fairness_constraint() {
			return getRuleContext(Fairness_constraintContext.class,0);
		}
		public Module_elementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module_element; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterModule_element(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitModule_element(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitModule_element(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Module_elementContext module_element() throws RecognitionException {
		Module_elementContext _localctx = new Module_elementContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_module_element);
		try {
			setState(141);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__15:
				enterOuterAlt(_localctx, 1);
				{
				setState(131);
				var_declaration();
				}
				break;
			case T__16:
				enterOuterAlt(_localctx, 2);
				{
				setState(132);
				ivar_declaration();
				}
				break;
			case T__14:
				enterOuterAlt(_localctx, 3);
				{
				setState(133);
				frozenvar_declaration();
				}
				break;
			case T__28:
				enterOuterAlt(_localctx, 4);
				{
				setState(134);
				define_declaration();
				}
				break;
			case T__13:
				enterOuterAlt(_localctx, 5);
				{
				setState(135);
				constants_declaration();
				}
				break;
			case T__9:
				enterOuterAlt(_localctx, 6);
				{
				setState(136);
				assign_constraint();
				}
				break;
			case T__8:
				enterOuterAlt(_localctx, 7);
				{
				setState(137);
				trans_constraint();
				}
				break;
			case T__7:
				enterOuterAlt(_localctx, 8);
				{
				setState(138);
				init_constraint();
				}
				break;
			case T__6:
				enterOuterAlt(_localctx, 9);
				{
				setState(139);
				invar_constraint();
				}
				break;
			case T__4:
				enterOuterAlt(_localctx, 10);
				{
				setState(140);
				fairness_constraint();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Fairness_constraintContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Fairness_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fairness_constraint; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterFairness_constraint(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitFairness_constraint(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitFairness_constraint(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Fairness_constraintContext fairness_constraint() throws RecognitionException {
		Fairness_constraintContext _localctx = new Fairness_constraintContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_fairness_constraint);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(143);
			match(T__4);
			setState(144);
			basic_next_expr(0);
			setState(146);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				{
				setState(145);
				match(T__5);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Invar_constraintContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Invar_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_invar_constraint; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterInvar_constraint(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitInvar_constraint(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitInvar_constraint(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Invar_constraintContext invar_constraint() throws RecognitionException {
		Invar_constraintContext _localctx = new Invar_constraintContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_invar_constraint);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(148);
			match(T__6);
			setState(149);
			basic_next_expr(0);
			setState(151);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				setState(150);
				match(T__5);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Init_constraintContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Init_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_init_constraint; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterInit_constraint(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitInit_constraint(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitInit_constraint(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Init_constraintContext init_constraint() throws RecognitionException {
		Init_constraintContext _localctx = new Init_constraintContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_init_constraint);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153);
			match(T__7);
			setState(154);
			basic_next_expr(0);
			setState(156);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				{
				setState(155);
				match(T__5);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Trans_constraintContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Trans_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_trans_constraint; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterTrans_constraint(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitTrans_constraint(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitTrans_constraint(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Trans_constraintContext trans_constraint() throws RecognitionException {
		Trans_constraintContext _localctx = new Trans_constraintContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_trans_constraint);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
			match(T__8);
			setState(159);
			basic_next_expr(0);
			setState(161);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				{
				setState(160);
				match(T__5);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Assign_constraintContext extends ParserRuleContext {
		public Assign_listContext assign_list() {
			return getRuleContext(Assign_listContext.class,0);
		}
		public Assign_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign_constraint; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterAssign_constraint(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitAssign_constraint(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitAssign_constraint(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Assign_constraintContext assign_constraint() throws RecognitionException {
		Assign_constraintContext _localctx = new Assign_constraintContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_assign_constraint);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(163);
			match(T__9);
			setState(164);
			assign_list(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Assign_listContext extends ParserRuleContext {
		public AssignContext assign() {
			return getRuleContext(AssignContext.class,0);
		}
		public Assign_listContext assign_list() {
			return getRuleContext(Assign_listContext.class,0);
		}
		public Assign_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterAssign_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitAssign_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitAssign_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Assign_listContext assign_list() throws RecognitionException {
		return assign_list(0);
	}

	private Assign_listContext assign_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Assign_listContext _localctx = new Assign_listContext(_ctx, _parentState);
		Assign_listContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_assign_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(167);
			assign();
			setState(168);
			match(T__5);
			}
			_ctx.stop = _input.LT(-1);
			setState(176);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Assign_listContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_assign_list);
					setState(170);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(171);
					assign();
					setState(172);
					match(T__5);
					}
					} 
				}
				setState(178);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class AssignContext extends ParserRuleContext {
		public Next_assignContext next_assign() {
			return getRuleContext(Next_assignContext.class,0);
		}
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Init_assignContext init_assign() {
			return getRuleContext(Init_assignContext.class,0);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public AssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterAssign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitAssign(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitAssign(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AssignContext assign() throws RecognitionException {
		AssignContext _localctx = new AssignContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_assign);
		try {
			setState(191);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__12:
				enterOuterAlt(_localctx, 1);
				{
				setState(179);
				next_assign();
				setState(180);
				match(T__10);
				setState(181);
				basic_next_expr(0);
				}
				break;
			case T__11:
				enterOuterAlt(_localctx, 2);
				{
				setState(183);
				init_assign();
				setState(184);
				match(T__10);
				setState(185);
				basic_next_expr(0);
				}
				break;
			case IDENTIFIER:
				enterOuterAlt(_localctx, 3);
				{
				setState(187);
				var();
				setState(188);
				match(T__10);
				setState(189);
				basic_next_expr(0);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Init_assignContext extends ParserRuleContext {
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public Init_assignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_init_assign; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterInit_assign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitInit_assign(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitInit_assign(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Init_assignContext init_assign() throws RecognitionException {
		Init_assignContext _localctx = new Init_assignContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_init_assign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(193);
			match(T__11);
			setState(194);
			var();
			setState(195);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Next_assignContext extends ParserRuleContext {
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public Next_assignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_next_assign; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterNext_assign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitNext_assign(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitNext_assign(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Next_assignContext next_assign() throws RecognitionException {
		Next_assignContext _localctx = new Next_assignContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_next_assign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(197);
			match(T__12);
			setState(198);
			var();
			setState(199);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constants_declarationContext extends ParserRuleContext {
		public Constants_bodyContext constants_body() {
			return getRuleContext(Constants_bodyContext.class,0);
		}
		public Constants_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constants_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterConstants_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitConstants_declaration(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitConstants_declaration(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Constants_declarationContext constants_declaration() throws RecognitionException {
		Constants_declarationContext _localctx = new Constants_declarationContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_constants_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(201);
			match(T__13);
			setState(202);
			constants_body(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Constants_bodyContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(smvParser.IDENTIFIER, 0); }
		public Constants_bodyContext constants_body() {
			return getRuleContext(Constants_bodyContext.class,0);
		}
		public Constants_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constants_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterConstants_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitConstants_body(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitConstants_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Constants_bodyContext constants_body() throws RecognitionException {
		return constants_body(0);
	}

	private Constants_bodyContext constants_body(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Constants_bodyContext _localctx = new Constants_bodyContext(_ctx, _parentState);
		Constants_bodyContext _prevctx = _localctx;
		int _startState = 32;
		enterRecursionRule(_localctx, 32, RULE_constants_body, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(205);
			match(IDENTIFIER);
			}
			_ctx.stop = _input.LT(-1);
			setState(212);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Constants_bodyContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_constants_body);
					setState(207);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(208);
					match(T__3);
					setState(209);
					match(IDENTIFIER);
					}
					} 
				}
				setState(214);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Frozenvar_declarationContext extends ParserRuleContext {
		public Simple_var_listContext simple_var_list() {
			return getRuleContext(Simple_var_listContext.class,0);
		}
		public Frozenvar_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_frozenvar_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterFrozenvar_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitFrozenvar_declaration(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitFrozenvar_declaration(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Frozenvar_declarationContext frozenvar_declaration() throws RecognitionException {
		Frozenvar_declarationContext _localctx = new Frozenvar_declarationContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_frozenvar_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			match(T__14);
			setState(216);
			simple_var_list(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Var_declarationContext extends ParserRuleContext {
		public Var_listContext var_list() {
			return getRuleContext(Var_listContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterVar_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitVar_declaration(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitVar_declaration(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_var_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(218);
			match(T__15);
			setState(219);
			var_list(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Ivar_declarationContext extends ParserRuleContext {
		public Simple_var_listContext simple_var_list() {
			return getRuleContext(Simple_var_listContext.class,0);
		}
		public Ivar_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ivar_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterIvar_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitIvar_declaration(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitIvar_declaration(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Ivar_declarationContext ivar_declaration() throws RecognitionException {
		Ivar_declarationContext _localctx = new Ivar_declarationContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_ivar_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(221);
			match(T__16);
			setState(222);
			simple_var_list(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Var_listContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(smvParser.IDENTIFIER, 0); }
		public Type_sepcifierContext type_sepcifier() {
			return getRuleContext(Type_sepcifierContext.class,0);
		}
		public Var_listContext var_list() {
			return getRuleContext(Var_listContext.class,0);
		}
		public Var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterVar_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitVar_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitVar_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Var_listContext var_list() throws RecognitionException {
		return var_list(0);
	}

	private Var_listContext var_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Var_listContext _localctx = new Var_listContext(_ctx, _parentState);
		Var_listContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_var_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(225);
			match(IDENTIFIER);
			setState(226);
			match(T__17);
			setState(227);
			type_sepcifier();
			setState(228);
			match(T__5);
			}
			_ctx.stop = _input.LT(-1);
			setState(238);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Var_listContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_var_list);
					setState(230);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(231);
					match(IDENTIFIER);
					setState(232);
					match(T__17);
					setState(233);
					type_sepcifier();
					setState(234);
					match(T__5);
					}
					} 
				}
				setState(240);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Simple_var_listContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(smvParser.IDENTIFIER, 0); }
		public Simple_type_specifierContext simple_type_specifier() {
			return getRuleContext(Simple_type_specifierContext.class,0);
		}
		public Simple_var_listContext simple_var_list() {
			return getRuleContext(Simple_var_listContext.class,0);
		}
		public Simple_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterSimple_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitSimple_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitSimple_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Simple_var_listContext simple_var_list() throws RecognitionException {
		return simple_var_list(0);
	}

	private Simple_var_listContext simple_var_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_var_listContext _localctx = new Simple_var_listContext(_ctx, _parentState);
		Simple_var_listContext _prevctx = _localctx;
		int _startState = 42;
		enterRecursionRule(_localctx, 42, RULE_simple_var_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(242);
			match(IDENTIFIER);
			setState(243);
			match(T__17);
			setState(244);
			simple_type_specifier();
			setState(245);
			match(T__5);
			}
			_ctx.stop = _input.LT(-1);
			setState(255);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_var_listContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_simple_var_list);
					setState(247);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(248);
					match(IDENTIFIER);
					setState(249);
					match(T__17);
					setState(250);
					simple_type_specifier();
					setState(251);
					match(T__5);
					}
					} 
				}
				setState(257);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class VarContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(smvParser.IDENTIFIER, 0); }
		public TerminalNode INTEGER() { return getToken(smvParser.INTEGER, 0); }
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterVar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitVar(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitVar(this);
			else return visitor.visitChildren(this);
		}
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_var);
		try {
			setState(266);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(258);
				match(IDENTIFIER);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(259);
				match(IDENTIFIER);
				setState(260);
				match(T__18);
				setState(261);
				match(INTEGER);
				setState(262);
				match(T__19);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(263);
				match(IDENTIFIER);
				setState(264);
				match(T__20);
				setState(265);
				var();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_sepcifierContext extends ParserRuleContext {
		public Simple_type_specifierContext simple_type_specifier() {
			return getRuleContext(Simple_type_specifierContext.class,0);
		}
		public Module_type_specifierContext module_type_specifier() {
			return getRuleContext(Module_type_specifierContext.class,0);
		}
		public Type_sepcifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_sepcifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterType_sepcifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitType_sepcifier(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitType_sepcifier(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Type_sepcifierContext type_sepcifier() throws RecognitionException {
		Type_sepcifierContext _localctx = new Type_sepcifierContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_type_sepcifier);
		try {
			setState(270);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__21:
			case T__22:
			case T__24:
			case INTEGER:
				enterOuterAlt(_localctx, 1);
				{
				setState(268);
				simple_type_specifier();
				}
				break;
			case T__27:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 2);
				{
				setState(269);
				module_type_specifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_type_specifierContext extends ParserRuleContext {
		public Enumeration_type_bodyContext enumeration_type_body() {
			return getRuleContext(Enumeration_type_bodyContext.class,0);
		}
		public Integer_rangeContext integer_range() {
			return getRuleContext(Integer_rangeContext.class,0);
		}
		public Simple_type_specifierContext simple_type_specifier() {
			return getRuleContext(Simple_type_specifierContext.class,0);
		}
		public Simple_type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_type_specifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterSimple_type_specifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitSimple_type_specifier(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitSimple_type_specifier(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Simple_type_specifierContext simple_type_specifier() throws RecognitionException {
		Simple_type_specifierContext _localctx = new Simple_type_specifierContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_simple_type_specifier);
		try {
			setState(283);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__21:
				enterOuterAlt(_localctx, 1);
				{
				setState(272);
				match(T__21);
				}
				break;
			case T__22:
				enterOuterAlt(_localctx, 2);
				{
				setState(273);
				match(T__22);
				setState(274);
				enumeration_type_body(0);
				setState(275);
				match(T__23);
				}
				break;
			case INTEGER:
				enterOuterAlt(_localctx, 3);
				{
				setState(277);
				integer_range();
				}
				break;
			case T__24:
				enterOuterAlt(_localctx, 4);
				{
				setState(278);
				match(T__24);
				setState(279);
				integer_range();
				setState(280);
				match(T__25);
				setState(281);
				simple_type_specifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Enumeration_type_bodyContext extends ParserRuleContext {
		public Enumeration_type_valueContext enumeration_type_value() {
			return getRuleContext(Enumeration_type_valueContext.class,0);
		}
		public Enumeration_type_bodyContext enumeration_type_body() {
			return getRuleContext(Enumeration_type_bodyContext.class,0);
		}
		public Enumeration_type_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumeration_type_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterEnumeration_type_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitEnumeration_type_body(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitEnumeration_type_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Enumeration_type_bodyContext enumeration_type_body() throws RecognitionException {
		return enumeration_type_body(0);
	}

	private Enumeration_type_bodyContext enumeration_type_body(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Enumeration_type_bodyContext _localctx = new Enumeration_type_bodyContext(_ctx, _parentState);
		Enumeration_type_bodyContext _prevctx = _localctx;
		int _startState = 50;
		enterRecursionRule(_localctx, 50, RULE_enumeration_type_body, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(286);
			enumeration_type_value();
			}
			_ctx.stop = _input.LT(-1);
			setState(293);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Enumeration_type_bodyContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_enumeration_type_body);
					setState(288);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(289);
					match(T__3);
					setState(290);
					enumeration_type_value();
					}
					} 
				}
				setState(295);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Enumeration_type_valueContext extends ParserRuleContext {
		public Symbolic_constantContext symbolic_constant() {
			return getRuleContext(Symbolic_constantContext.class,0);
		}
		public TerminalNode INTEGER() { return getToken(smvParser.INTEGER, 0); }
		public Enumeration_type_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumeration_type_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterEnumeration_type_value(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitEnumeration_type_value(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitEnumeration_type_value(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Enumeration_type_valueContext enumeration_type_value() throws RecognitionException {
		Enumeration_type_valueContext _localctx = new Enumeration_type_valueContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_enumeration_type_value);
		try {
			setState(298);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(296);
				symbolic_constant();
				}
				break;
			case INTEGER:
				enterOuterAlt(_localctx, 2);
				{
				setState(297);
				match(INTEGER);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Integer_rangeContext extends ParserRuleContext {
		public List<TerminalNode> INTEGER() { return getTokens(smvParser.INTEGER); }
		public TerminalNode INTEGER(int i) {
			return getToken(smvParser.INTEGER, i);
		}
		public Integer_rangeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integer_range; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterInteger_range(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitInteger_range(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitInteger_range(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Integer_rangeContext integer_range() throws RecognitionException {
		Integer_rangeContext _localctx = new Integer_rangeContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_integer_range);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(300);
			match(INTEGER);
			setState(301);
			match(T__26);
			setState(302);
			match(INTEGER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Symbolic_constantContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(smvParser.IDENTIFIER, 0); }
		public Symbolic_constantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_symbolic_constant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterSymbolic_constant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitSymbolic_constant(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitSymbolic_constant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Symbolic_constantContext symbolic_constant() throws RecognitionException {
		Symbolic_constantContext _localctx = new Symbolic_constantContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_symbolic_constant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(304);
			match(IDENTIFIER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Module_type_specifierContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(smvParser.IDENTIFIER, 0); }
		public Para_listContext para_list() {
			return getRuleContext(Para_listContext.class,0);
		}
		public Module_type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module_type_specifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterModule_type_specifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitModule_type_specifier(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitModule_type_specifier(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Module_type_specifierContext module_type_specifier() throws RecognitionException {
		Module_type_specifierContext _localctx = new Module_type_specifierContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_module_type_specifier);
		int _la;
		try {
			setState(319);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(306);
				match(IDENTIFIER);
				setState(311);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__1) {
					{
					setState(307);
					match(T__1);
					setState(308);
					para_list(0);
					setState(309);
					match(T__2);
					}
				}

				}
				break;
			case T__27:
				enterOuterAlt(_localctx, 2);
				{
				setState(313);
				match(T__27);
				setState(314);
				match(IDENTIFIER);
				setState(315);
				match(T__1);
				setState(316);
				para_list(0);
				setState(317);
				match(T__2);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Define_declarationContext extends ParserRuleContext {
		public Define_bodyContext define_body() {
			return getRuleContext(Define_bodyContext.class,0);
		}
		public Define_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_define_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterDefine_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitDefine_declaration(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitDefine_declaration(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Define_declarationContext define_declaration() throws RecognitionException {
		Define_declarationContext _localctx = new Define_declarationContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_define_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(321);
			match(T__28);
			setState(322);
			define_body(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Define_bodyContext extends ParserRuleContext {
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Define_bodyContext define_body() {
			return getRuleContext(Define_bodyContext.class,0);
		}
		public Define_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_define_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterDefine_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitDefine_body(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitDefine_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Define_bodyContext define_body() throws RecognitionException {
		return define_body(0);
	}

	private Define_bodyContext define_body(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Define_bodyContext _localctx = new Define_bodyContext(_ctx, _parentState);
		Define_bodyContext _prevctx = _localctx;
		int _startState = 62;
		enterRecursionRule(_localctx, 62, RULE_define_body, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(325);
			var();
			setState(326);
			match(T__10);
			setState(327);
			basic_next_expr(0);
			setState(329);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				{
				setState(328);
				match(T__5);
				}
				break;
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(340);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Define_bodyContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_define_body);
					setState(331);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(332);
					var();
					setState(333);
					match(T__10);
					setState(334);
					basic_next_expr(0);
					setState(336);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
					case 1:
						{
						setState(335);
						match(T__5);
						}
						break;
					}
					}
					} 
				}
				setState(342);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Basic_next_exprContext extends ParserRuleContext {
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public TerminalNode INTEGER() { return getToken(smvParser.INTEGER, 0); }
		public List<Basic_next_exprContext> basic_next_expr() {
			return getRuleContexts(Basic_next_exprContext.class);
		}
		public Basic_next_exprContext basic_next_expr(int i) {
			return getRuleContext(Basic_next_exprContext.class,i);
		}
		public Set_next_bodyContext set_next_body() {
			return getRuleContext(Set_next_bodyContext.class,0);
		}
		public Case_exprContext case_expr() {
			return getRuleContext(Case_exprContext.class,0);
		}
		public Integer_rangeContext integer_range() {
			return getRuleContext(Integer_rangeContext.class,0);
		}
		public MulContext mul() {
			return getRuleContext(MulContext.class,0);
		}
		public ModContext mod() {
			return getRuleContext(ModContext.class,0);
		}
		public AddContext add() {
			return getRuleContext(AddContext.class,0);
		}
		public ShiftContext shift() {
			return getRuleContext(ShiftContext.class,0);
		}
		public UnionContext union() {
			return getRuleContext(UnionContext.class,0);
		}
		public LogicjudgeContext logicjudge() {
			return getRuleContext(LogicjudgeContext.class,0);
		}
		public LogicandContext logicand() {
			return getRuleContext(LogicandContext.class,0);
		}
		public LogicorContext logicor() {
			return getRuleContext(LogicorContext.class,0);
		}
		public Basic_next_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basic_next_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterBasic_next_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitBasic_next_expr(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitBasic_next_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Basic_next_exprContext basic_next_expr() throws RecognitionException {
		return basic_next_expr(0);
	}

	private Basic_next_exprContext basic_next_expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Basic_next_exprContext _localctx = new Basic_next_exprContext(_ctx, _parentState);
		Basic_next_exprContext _prevctx = _localctx;
		int _startState = 64;
		enterRecursionRule(_localctx, 64, RULE_basic_next_expr, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(370);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				{
				setState(344);
				var();
				}
				break;
			case 2:
				{
				setState(345);
				match(INTEGER);
				}
				break;
			case 3:
				{
				setState(346);
				match(T__1);
				setState(347);
				basic_next_expr(0);
				setState(348);
				match(T__2);
				}
				break;
			case 4:
				{
				setState(350);
				match(T__29);
				setState(351);
				basic_next_expr(19);
				}
				break;
			case 5:
				{
				setState(352);
				match(T__33);
				setState(353);
				basic_next_expr(0);
				setState(354);
				match(T__2);
				}
				break;
			case 6:
				{
				setState(356);
				match(T__34);
				setState(357);
				basic_next_expr(0);
				setState(358);
				match(T__2);
				}
				break;
			case 7:
				{
				setState(360);
				match(T__22);
				setState(361);
				set_next_body(0);
				setState(362);
				match(T__23);
				}
				break;
			case 8:
				{
				setState(364);
				case_expr();
				}
				break;
			case 9:
				{
				setState(365);
				match(T__12);
				setState(366);
				basic_next_expr(0);
				setState(367);
				match(T__2);
				}
				break;
			case 10:
				{
				setState(369);
				integer_range();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(428);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(426);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
					case 1:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(372);
						if (!(precpred(_ctx, 18))) throw new FailedPredicateException(this, "precpred(_ctx, 18)");
						setState(373);
						mul();
						setState(374);
						basic_next_expr(19);
						}
						break;
					case 2:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(376);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(377);
						mod();
						setState(378);
						basic_next_expr(18);
						}
						break;
					case 3:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(380);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(381);
						add();
						setState(382);
						basic_next_expr(17);
						}
						break;
					case 4:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(384);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(385);
						shift();
						setState(386);
						basic_next_expr(16);
						}
						break;
					case 5:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(388);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(389);
						union();
						setState(390);
						basic_next_expr(15);
						}
						break;
					case 6:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(392);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(393);
						logicjudge();
						setState(394);
						basic_next_expr(14);
						}
						break;
					case 7:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(396);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(397);
						logicand();
						setState(398);
						basic_next_expr(13);
						}
						break;
					case 8:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(400);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(401);
						logicor();
						setState(402);
						basic_next_expr(12);
						}
						break;
					case 9:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(404);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(405);
						match(T__30);
						setState(406);
						basic_next_expr(0);
						setState(407);
						match(T__17);
						setState(408);
						basic_next_expr(11);
						}
						break;
					case 10:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(410);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(411);
						match(T__31);
						setState(412);
						basic_next_expr(10);
						}
						break;
					case 11:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(413);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(414);
						match(T__32);
						setState(415);
						basic_next_expr(9);
						}
						break;
					case 12:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(416);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(417);
						match(T__35);
						setState(418);
						basic_next_expr(5);
						}
						break;
					case 13:
						{
						_localctx = new Basic_next_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_basic_next_expr);
						setState(419);
						if (!(precpred(_ctx, 20))) throw new FailedPredicateException(this, "precpred(_ctx, 20)");
						setState(420);
						match(T__18);
						setState(421);
						basic_next_expr(0);
						setState(422);
						match(T__17);
						setState(423);
						basic_next_expr(0);
						setState(424);
						match(T__19);
						}
						break;
					}
					} 
				}
				setState(430);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Set_next_bodyContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Set_next_bodyContext set_next_body() {
			return getRuleContext(Set_next_bodyContext.class,0);
		}
		public Set_next_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_set_next_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterSet_next_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitSet_next_body(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitSet_next_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Set_next_bodyContext set_next_body() throws RecognitionException {
		return set_next_body(0);
	}

	private Set_next_bodyContext set_next_body(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Set_next_bodyContext _localctx = new Set_next_bodyContext(_ctx, _parentState);
		Set_next_bodyContext _prevctx = _localctx;
		int _startState = 66;
		enterRecursionRule(_localctx, 66, RULE_set_next_body, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(432);
			basic_next_expr(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(439);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Set_next_bodyContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_set_next_body);
					setState(434);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(435);
					match(T__3);
					setState(436);
					basic_next_expr(0);
					}
					} 
				}
				setState(441);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Case_exprContext extends ParserRuleContext {
		public Case_next_bodyContext case_next_body() {
			return getRuleContext(Case_next_bodyContext.class,0);
		}
		public Case_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_expr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterCase_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitCase_expr(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitCase_expr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Case_exprContext case_expr() throws RecognitionException {
		Case_exprContext _localctx = new Case_exprContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_case_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(442);
			match(T__36);
			setState(443);
			case_next_body(0);
			setState(444);
			match(T__37);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Case_next_bodyContext extends ParserRuleContext {
		public Case_condContext case_cond() {
			return getRuleContext(Case_condContext.class,0);
		}
		public Case_valueContext case_value() {
			return getRuleContext(Case_valueContext.class,0);
		}
		public Case_next_bodyContext case_next_body() {
			return getRuleContext(Case_next_bodyContext.class,0);
		}
		public Case_next_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_next_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterCase_next_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitCase_next_body(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitCase_next_body(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Case_next_bodyContext case_next_body() throws RecognitionException {
		return case_next_body(0);
	}

	private Case_next_bodyContext case_next_body(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Case_next_bodyContext _localctx = new Case_next_bodyContext(_ctx, _parentState);
		Case_next_bodyContext _prevctx = _localctx;
		int _startState = 70;
		enterRecursionRule(_localctx, 70, RULE_case_next_body, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(447);
			case_cond();
			setState(448);
			match(T__17);
			setState(449);
			case_value();
			setState(450);
			match(T__5);
			}
			_ctx.stop = _input.LT(-1);
			setState(460);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Case_next_bodyContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_case_next_body);
					setState(452);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(453);
					case_cond();
					setState(454);
					match(T__17);
					setState(455);
					case_value();
					setState(456);
					match(T__5);
					}
					} 
				}
				setState(462);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Case_condContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Case_condContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_cond; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterCase_cond(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitCase_cond(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitCase_cond(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Case_condContext case_cond() throws RecognitionException {
		Case_condContext _localctx = new Case_condContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_case_cond);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(463);
			basic_next_expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Case_valueContext extends ParserRuleContext {
		public Basic_next_exprContext basic_next_expr() {
			return getRuleContext(Basic_next_exprContext.class,0);
		}
		public Case_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterCase_value(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitCase_value(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitCase_value(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Case_valueContext case_value() throws RecognitionException {
		Case_valueContext _localctx = new Case_valueContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_case_value);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(465);
			basic_next_expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MulContext extends ParserRuleContext {
		public MulContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mul; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterMul(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitMul(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitMul(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MulContext mul() throws RecognitionException {
		MulContext _localctx = new MulContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_mul);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(467);
			_la = _input.LA(1);
			if ( !(_la==T__38 || _la==T__39) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ModContext extends ParserRuleContext {
		public ModContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mod; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterMod(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitMod(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitMod(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ModContext mod() throws RecognitionException {
		ModContext _localctx = new ModContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_mod);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(469);
			match(T__40);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AddContext extends ParserRuleContext {
		public AddContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_add; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterAdd(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitAdd(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitAdd(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AddContext add() throws RecognitionException {
		AddContext _localctx = new AddContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_add);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(471);
			_la = _input.LA(1);
			if ( !(_la==T__41 || _la==T__42) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ShiftContext extends ParserRuleContext {
		public ShiftContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shift; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterShift(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitShift(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitShift(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ShiftContext shift() throws RecognitionException {
		ShiftContext _localctx = new ShiftContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_shift);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(473);
			_la = _input.LA(1);
			if ( !(_la==T__43 || _la==T__44) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnionContext extends ParserRuleContext {
		public UnionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_union; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterUnion(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitUnion(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitUnion(this);
			else return visitor.visitChildren(this);
		}
	}

	public final UnionContext union() throws RecognitionException {
		UnionContext _localctx = new UnionContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_union);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(475);
			match(T__45);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LogicjudgeContext extends ParserRuleContext {
		public LogicjudgeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicjudge; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterLogicjudge(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitLogicjudge(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitLogicjudge(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LogicjudgeContext logicjudge() throws RecognitionException {
		LogicjudgeContext _localctx = new LogicjudgeContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_logicjudge);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(477);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__46) | (1L << T__47) | (1L << T__48) | (1L << T__49) | (1L << T__50) | (1L << T__51))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LogicandContext extends ParserRuleContext {
		public LogicandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicand; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterLogicand(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitLogicand(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitLogicand(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LogicandContext logicand() throws RecognitionException {
		LogicandContext _localctx = new LogicandContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_logicand);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(479);
			match(T__52);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LogicorContext extends ParserRuleContext {
		public LogicorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicor; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).enterLogicor(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof smvListener ) ((smvListener)listener).exitLogicor(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof smvVisitor ) return ((smvVisitor<? extends T>)visitor).visitLogicor(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LogicorContext logicor() throws RecognitionException {
		LogicorContext _localctx = new LogicorContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_logicor);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(481);
			_la = _input.LA(1);
			if ( !(_la==T__53 || _la==T__54) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return para_list_sempred((Para_listContext)_localctx, predIndex);
		case 4:
			return module_body_sempred((Module_bodyContext)_localctx, predIndex);
		case 11:
			return assign_list_sempred((Assign_listContext)_localctx, predIndex);
		case 16:
			return constants_body_sempred((Constants_bodyContext)_localctx, predIndex);
		case 20:
			return var_list_sempred((Var_listContext)_localctx, predIndex);
		case 21:
			return simple_var_list_sempred((Simple_var_listContext)_localctx, predIndex);
		case 25:
			return enumeration_type_body_sempred((Enumeration_type_bodyContext)_localctx, predIndex);
		case 31:
			return define_body_sempred((Define_bodyContext)_localctx, predIndex);
		case 32:
			return basic_next_expr_sempred((Basic_next_exprContext)_localctx, predIndex);
		case 33:
			return set_next_body_sempred((Set_next_bodyContext)_localctx, predIndex);
		case 35:
			return case_next_body_sempred((Case_next_bodyContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean para_list_sempred(Para_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean module_body_sempred(Module_bodyContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean assign_list_sempred(Assign_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean constants_body_sempred(Constants_bodyContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean var_list_sempred(Var_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_var_list_sempred(Simple_var_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean enumeration_type_body_sempred(Enumeration_type_bodyContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean define_body_sempred(Define_bodyContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean basic_next_expr_sempred(Basic_next_exprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 8:
			return precpred(_ctx, 18);
		case 9:
			return precpred(_ctx, 17);
		case 10:
			return precpred(_ctx, 16);
		case 11:
			return precpred(_ctx, 15);
		case 12:
			return precpred(_ctx, 14);
		case 13:
			return precpred(_ctx, 13);
		case 14:
			return precpred(_ctx, 12);
		case 15:
			return precpred(_ctx, 11);
		case 16:
			return precpred(_ctx, 10);
		case 17:
			return precpred(_ctx, 9);
		case 18:
			return precpred(_ctx, 8);
		case 19:
			return precpred(_ctx, 4);
		case 20:
			return precpred(_ctx, 20);
		}
		return true;
	}
	private boolean set_next_body_sempred(Set_next_bodyContext _localctx, int predIndex) {
		switch (predIndex) {
		case 21:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean case_next_body_sempred(Case_next_bodyContext _localctx, int predIndex) {
		switch (predIndex) {
		case 22:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3@\u01e6\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\3\2\7\2`\n\2\f\2\16\2c\13\2\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\5\3k\n\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\7\4u\n\4\f\4\16\4x\13\4"+
		"\3\5\3\5\3\6\3\6\3\6\3\6\3\6\7\6\u0081\n\6\f\6\16\6\u0084\13\6\3\7\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\5\7\u0090\n\7\3\b\3\b\3\b\5\b\u0095\n"+
		"\b\3\t\3\t\3\t\5\t\u009a\n\t\3\n\3\n\3\n\5\n\u009f\n\n\3\13\3\13\3\13"+
		"\5\13\u00a4\n\13\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\7\r\u00b1"+
		"\n\r\f\r\16\r\u00b4\13\r\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\16"+
		"\3\16\3\16\3\16\5\16\u00c2\n\16\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20"+
		"\3\21\3\21\3\21\3\22\3\22\3\22\3\22\3\22\3\22\7\22\u00d5\n\22\f\22\16"+
		"\22\u00d8\13\22\3\23\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\25\3\26\3\26"+
		"\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\7\26\u00ef\n\26\f\26"+
		"\16\26\u00f2\13\26\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3"+
		"\27\3\27\7\27\u0100\n\27\f\27\16\27\u0103\13\27\3\30\3\30\3\30\3\30\3"+
		"\30\3\30\3\30\3\30\5\30\u010d\n\30\3\31\3\31\5\31\u0111\n\31\3\32\3\32"+
		"\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\5\32\u011e\n\32\3\33\3\33"+
		"\3\33\3\33\3\33\3\33\7\33\u0126\n\33\f\33\16\33\u0129\13\33\3\34\3\34"+
		"\5\34\u012d\n\34\3\35\3\35\3\35\3\35\3\36\3\36\3\37\3\37\3\37\3\37\3\37"+
		"\5\37\u013a\n\37\3\37\3\37\3\37\3\37\3\37\3\37\5\37\u0142\n\37\3 \3 \3"+
		" \3!\3!\3!\3!\3!\5!\u014c\n!\3!\3!\3!\3!\3!\5!\u0153\n!\7!\u0155\n!\f"+
		"!\16!\u0158\13!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3"+
		"\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\5\"\u0175\n\"\3"+
		"\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\""+
		"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3"+
		"\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\""+
		"\3\"\7\"\u01ad\n\"\f\"\16\"\u01b0\13\"\3#\3#\3#\3#\3#\3#\7#\u01b8\n#\f"+
		"#\16#\u01bb\13#\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\3%\3%\3%\3%\3%\3%\7%\u01cd"+
		"\n%\f%\16%\u01d0\13%\3&\3&\3\'\3\'\3(\3(\3)\3)\3*\3*\3+\3+\3,\3,\3-\3"+
		"-\3.\3.\3/\3/\3/\2\r\6\n\30\"*,\64@BDH\60\2\4\6\b\n\f\16\20\22\24\26\30"+
		"\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\\2\7\3\2)*\3\2,-\3\2"+
		"./\3\2\61\66\3\289\2\u01f3\2a\3\2\2\2\4d\3\2\2\2\6n\3\2\2\2\by\3\2\2\2"+
		"\n{\3\2\2\2\f\u008f\3\2\2\2\16\u0091\3\2\2\2\20\u0096\3\2\2\2\22\u009b"+
		"\3\2\2\2\24\u00a0\3\2\2\2\26\u00a5\3\2\2\2\30\u00a8\3\2\2\2\32\u00c1\3"+
		"\2\2\2\34\u00c3\3\2\2\2\36\u00c7\3\2\2\2 \u00cb\3\2\2\2\"\u00ce\3\2\2"+
		"\2$\u00d9\3\2\2\2&\u00dc\3\2\2\2(\u00df\3\2\2\2*\u00e2\3\2\2\2,\u00f3"+
		"\3\2\2\2.\u010c\3\2\2\2\60\u0110\3\2\2\2\62\u011d\3\2\2\2\64\u011f\3\2"+
		"\2\2\66\u012c\3\2\2\28\u012e\3\2\2\2:\u0132\3\2\2\2<\u0141\3\2\2\2>\u0143"+
		"\3\2\2\2@\u0146\3\2\2\2B\u0174\3\2\2\2D\u01b1\3\2\2\2F\u01bc\3\2\2\2H"+
		"\u01c0\3\2\2\2J\u01d1\3\2\2\2L\u01d3\3\2\2\2N\u01d5\3\2\2\2P\u01d7\3\2"+
		"\2\2R\u01d9\3\2\2\2T\u01db\3\2\2\2V\u01dd\3\2\2\2X\u01df\3\2\2\2Z\u01e1"+
		"\3\2\2\2\\\u01e3\3\2\2\2^`\5\4\3\2_^\3\2\2\2`c\3\2\2\2a_\3\2\2\2ab\3\2"+
		"\2\2b\3\3\2\2\2ca\3\2\2\2de\7\3\2\2ej\7;\2\2fg\7\4\2\2gh\5\6\4\2hi\7\5"+
		"\2\2ik\3\2\2\2jf\3\2\2\2jk\3\2\2\2kl\3\2\2\2lm\5\n\6\2m\5\3\2\2\2no\b"+
		"\4\1\2op\5\b\5\2pv\3\2\2\2qr\f\3\2\2rs\7\6\2\2su\5\b\5\2tq\3\2\2\2ux\3"+
		"\2\2\2vt\3\2\2\2vw\3\2\2\2w\7\3\2\2\2xv\3\2\2\2yz\5B\"\2z\t\3\2\2\2{|"+
		"\b\6\1\2|}\5\f\7\2}\u0082\3\2\2\2~\177\f\3\2\2\177\u0081\5\f\7\2\u0080"+
		"~\3\2\2\2\u0081\u0084\3\2\2\2\u0082\u0080\3\2\2\2\u0082\u0083\3\2\2\2"+
		"\u0083\13\3\2\2\2\u0084\u0082\3\2\2\2\u0085\u0090\5&\24\2\u0086\u0090"+
		"\5(\25\2\u0087\u0090\5$\23\2\u0088\u0090\5> \2\u0089\u0090\5 \21\2\u008a"+
		"\u0090\5\26\f\2\u008b\u0090\5\24\13\2\u008c\u0090\5\22\n\2\u008d\u0090"+
		"\5\20\t\2\u008e\u0090\5\16\b\2\u008f\u0085\3\2\2\2\u008f\u0086\3\2\2\2"+
		"\u008f\u0087\3\2\2\2\u008f\u0088\3\2\2\2\u008f\u0089\3\2\2\2\u008f\u008a"+
		"\3\2\2\2\u008f\u008b\3\2\2\2\u008f\u008c\3\2\2\2\u008f\u008d\3\2\2\2\u008f"+
		"\u008e\3\2\2\2\u0090\r\3\2\2\2\u0091\u0092\7\7\2\2\u0092\u0094\5B\"\2"+
		"\u0093\u0095\7\b\2\2\u0094\u0093\3\2\2\2\u0094\u0095\3\2\2\2\u0095\17"+
		"\3\2\2\2\u0096\u0097\7\t\2\2\u0097\u0099\5B\"\2\u0098\u009a\7\b\2\2\u0099"+
		"\u0098\3\2\2\2\u0099\u009a\3\2\2\2\u009a\21\3\2\2\2\u009b\u009c\7\n\2"+
		"\2\u009c\u009e\5B\"\2\u009d\u009f\7\b\2\2\u009e\u009d\3\2\2\2\u009e\u009f"+
		"\3\2\2\2\u009f\23\3\2\2\2\u00a0\u00a1\7\13\2\2\u00a1\u00a3\5B\"\2\u00a2"+
		"\u00a4\7\b\2\2\u00a3\u00a2\3\2\2\2\u00a3\u00a4\3\2\2\2\u00a4\25\3\2\2"+
		"\2\u00a5\u00a6\7\f\2\2\u00a6\u00a7\5\30\r\2\u00a7\27\3\2\2\2\u00a8\u00a9"+
		"\b\r\1\2\u00a9\u00aa\5\32\16\2\u00aa\u00ab\7\b\2\2\u00ab\u00b2\3\2\2\2"+
		"\u00ac\u00ad\f\3\2\2\u00ad\u00ae\5\32\16\2\u00ae\u00af\7\b\2\2\u00af\u00b1"+
		"\3\2\2\2\u00b0\u00ac\3\2\2\2\u00b1\u00b4\3\2\2\2\u00b2\u00b0\3\2\2\2\u00b2"+
		"\u00b3\3\2\2\2\u00b3\31\3\2\2\2\u00b4\u00b2\3\2\2\2\u00b5\u00b6\5\36\20"+
		"\2\u00b6\u00b7\7\r\2\2\u00b7\u00b8\5B\"\2\u00b8\u00c2\3\2\2\2\u00b9\u00ba"+
		"\5\34\17\2\u00ba\u00bb\7\r\2\2\u00bb\u00bc\5B\"\2\u00bc\u00c2\3\2\2\2"+
		"\u00bd\u00be\5.\30\2\u00be\u00bf\7\r\2\2\u00bf\u00c0\5B\"\2\u00c0\u00c2"+
		"\3\2\2\2\u00c1\u00b5\3\2\2\2\u00c1\u00b9\3\2\2\2\u00c1\u00bd\3\2\2\2\u00c2"+
		"\33\3\2\2\2\u00c3\u00c4\7\16\2\2\u00c4\u00c5\5.\30\2\u00c5\u00c6\7\5\2"+
		"\2\u00c6\35\3\2\2\2\u00c7\u00c8\7\17\2\2\u00c8\u00c9\5.\30\2\u00c9\u00ca"+
		"\7\5\2\2\u00ca\37\3\2\2\2\u00cb\u00cc\7\20\2\2\u00cc\u00cd\5\"\22\2\u00cd"+
		"!\3\2\2\2\u00ce\u00cf\b\22\1\2\u00cf\u00d0\7;\2\2\u00d0\u00d6\3\2\2\2"+
		"\u00d1\u00d2\f\3\2\2\u00d2\u00d3\7\6\2\2\u00d3\u00d5\7;\2\2\u00d4\u00d1"+
		"\3\2\2\2\u00d5\u00d8\3\2\2\2\u00d6\u00d4\3\2\2\2\u00d6\u00d7\3\2\2\2\u00d7"+
		"#\3\2\2\2\u00d8\u00d6\3\2\2\2\u00d9\u00da\7\21\2\2\u00da\u00db\5,\27\2"+
		"\u00db%\3\2\2\2\u00dc\u00dd\7\22\2\2\u00dd\u00de\5*\26\2\u00de\'\3\2\2"+
		"\2\u00df\u00e0\7\23\2\2\u00e0\u00e1\5,\27\2\u00e1)\3\2\2\2\u00e2\u00e3"+
		"\b\26\1\2\u00e3\u00e4\7;\2\2\u00e4\u00e5\7\24\2\2\u00e5\u00e6\5\60\31"+
		"\2\u00e6\u00e7\7\b\2\2\u00e7\u00f0\3\2\2\2\u00e8\u00e9\f\3\2\2\u00e9\u00ea"+
		"\7;\2\2\u00ea\u00eb\7\24\2\2\u00eb\u00ec\5\60\31\2\u00ec\u00ed\7\b\2\2"+
		"\u00ed\u00ef\3\2\2\2\u00ee\u00e8\3\2\2\2\u00ef\u00f2\3\2\2\2\u00f0\u00ee"+
		"\3\2\2\2\u00f0\u00f1\3\2\2\2\u00f1+\3\2\2\2\u00f2\u00f0\3\2\2\2\u00f3"+
		"\u00f4\b\27\1\2\u00f4\u00f5\7;\2\2\u00f5\u00f6\7\24\2\2\u00f6\u00f7\5"+
		"\62\32\2\u00f7\u00f8\7\b\2\2\u00f8\u0101\3\2\2\2\u00f9\u00fa\f\3\2\2\u00fa"+
		"\u00fb\7;\2\2\u00fb\u00fc\7\24\2\2\u00fc\u00fd\5\62\32\2\u00fd\u00fe\7"+
		"\b\2\2\u00fe\u0100\3\2\2\2\u00ff\u00f9\3\2\2\2\u0100\u0103\3\2\2\2\u0101"+
		"\u00ff\3\2\2\2\u0101\u0102\3\2\2\2\u0102-\3\2\2\2\u0103\u0101\3\2\2\2"+
		"\u0104\u010d\7;\2\2\u0105\u0106\7;\2\2\u0106\u0107\7\25\2\2\u0107\u0108"+
		"\7:\2\2\u0108\u010d\7\26\2\2\u0109\u010a\7;\2\2\u010a\u010b\7\27\2\2\u010b"+
		"\u010d\5.\30\2\u010c\u0104\3\2\2\2\u010c\u0105\3\2\2\2\u010c\u0109\3\2"+
		"\2\2\u010d/\3\2\2\2\u010e\u0111\5\62\32\2\u010f\u0111\5<\37\2\u0110\u010e"+
		"\3\2\2\2\u0110\u010f\3\2\2\2\u0111\61\3\2\2\2\u0112\u011e\7\30\2\2\u0113"+
		"\u0114\7\31\2\2\u0114\u0115\5\64\33\2\u0115\u0116\7\32\2\2\u0116\u011e"+
		"\3\2\2\2\u0117\u011e\58\35\2\u0118\u0119\7\33\2\2\u0119\u011a\58\35\2"+
		"\u011a\u011b\7\34\2\2\u011b\u011c\5\62\32\2\u011c\u011e\3\2\2\2\u011d"+
		"\u0112\3\2\2\2\u011d\u0113\3\2\2\2\u011d\u0117\3\2\2\2\u011d\u0118\3\2"+
		"\2\2\u011e\63\3\2\2\2\u011f\u0120\b\33\1\2\u0120\u0121\5\66\34\2\u0121"+
		"\u0127\3\2\2\2\u0122\u0123\f\3\2\2\u0123\u0124\7\6\2\2\u0124\u0126\5\66"+
		"\34\2\u0125\u0122\3\2\2\2\u0126\u0129\3\2\2\2\u0127\u0125\3\2\2\2\u0127"+
		"\u0128\3\2\2\2\u0128\65\3\2\2\2\u0129\u0127\3\2\2\2\u012a\u012d\5:\36"+
		"\2\u012b\u012d\7:\2\2\u012c\u012a\3\2\2\2\u012c\u012b\3\2\2\2\u012d\67"+
		"\3\2\2\2\u012e\u012f\7:\2\2\u012f\u0130\7\35\2\2\u0130\u0131\7:\2\2\u0131"+
		"9\3\2\2\2\u0132\u0133\7;\2\2\u0133;\3\2\2\2\u0134\u0139\7;\2\2\u0135\u0136"+
		"\7\4\2\2\u0136\u0137\5\6\4\2\u0137\u0138\7\5\2\2\u0138\u013a\3\2\2\2\u0139"+
		"\u0135\3\2\2\2\u0139\u013a\3\2\2\2\u013a\u0142\3\2\2\2\u013b\u013c\7\36"+
		"\2\2\u013c\u013d\7;\2\2\u013d\u013e\7\4\2\2\u013e\u013f\5\6\4\2\u013f"+
		"\u0140\7\5\2\2\u0140\u0142\3\2\2\2\u0141\u0134\3\2\2\2\u0141\u013b\3\2"+
		"\2\2\u0142=\3\2\2\2\u0143\u0144\7\37\2\2\u0144\u0145\5@!\2\u0145?\3\2"+
		"\2\2\u0146\u0147\b!\1\2\u0147\u0148\5.\30\2\u0148\u0149\7\r\2\2\u0149"+
		"\u014b\5B\"\2\u014a\u014c\7\b\2\2\u014b\u014a\3\2\2\2\u014b\u014c\3\2"+
		"\2\2\u014c\u0156\3\2\2\2\u014d\u014e\f\3\2\2\u014e\u014f\5.\30\2\u014f"+
		"\u0150\7\r\2\2\u0150\u0152\5B\"\2\u0151\u0153\7\b\2\2\u0152\u0151\3\2"+
		"\2\2\u0152\u0153\3\2\2\2\u0153\u0155\3\2\2\2\u0154\u014d\3\2\2\2\u0155"+
		"\u0158\3\2\2\2\u0156\u0154\3\2\2\2\u0156\u0157\3\2\2\2\u0157A\3\2\2\2"+
		"\u0158\u0156\3\2\2\2\u0159\u015a\b\"\1\2\u015a\u0175\5.\30\2\u015b\u0175"+
		"\7:\2\2\u015c\u015d\7\4\2\2\u015d\u015e\5B\"\2\u015e\u015f\7\5\2\2\u015f"+
		"\u0175\3\2\2\2\u0160\u0161\7 \2\2\u0161\u0175\5B\"\25\u0162\u0163\7$\2"+
		"\2\u0163\u0164\5B\"\2\u0164\u0165\7\5\2\2\u0165\u0175\3\2\2\2\u0166\u0167"+
		"\7%\2\2\u0167\u0168\5B\"\2\u0168\u0169\7\5\2\2\u0169\u0175\3\2\2\2\u016a"+
		"\u016b\7\31\2\2\u016b\u016c\5D#\2\u016c\u016d\7\32\2\2\u016d\u0175\3\2"+
		"\2\2\u016e\u0175\5F$\2\u016f\u0170\7\17\2\2\u0170\u0171\5B\"\2\u0171\u0172"+
		"\7\5\2\2\u0172\u0175\3\2\2\2\u0173\u0175\58\35\2\u0174\u0159\3\2\2\2\u0174"+
		"\u015b\3\2\2\2\u0174\u015c\3\2\2\2\u0174\u0160\3\2\2\2\u0174\u0162\3\2"+
		"\2\2\u0174\u0166\3\2\2\2\u0174\u016a\3\2\2\2\u0174\u016e\3\2\2\2\u0174"+
		"\u016f\3\2\2\2\u0174\u0173\3\2\2\2\u0175\u01ae\3\2\2\2\u0176\u0177\f\24"+
		"\2\2\u0177\u0178\5N(\2\u0178\u0179\5B\"\25\u0179\u01ad\3\2\2\2\u017a\u017b"+
		"\f\23\2\2\u017b\u017c\5P)\2\u017c\u017d\5B\"\24\u017d\u01ad\3\2\2\2\u017e"+
		"\u017f\f\22\2\2\u017f\u0180\5R*\2\u0180\u0181\5B\"\23\u0181\u01ad\3\2"+
		"\2\2\u0182\u0183\f\21\2\2\u0183\u0184\5T+\2\u0184\u0185\5B\"\22\u0185"+
		"\u01ad\3\2\2\2\u0186\u0187\f\20\2\2\u0187\u0188\5V,\2\u0188\u0189\5B\""+
		"\21\u0189\u01ad\3\2\2\2\u018a\u018b\f\17\2\2\u018b\u018c\5X-\2\u018c\u018d"+
		"\5B\"\20\u018d\u01ad\3\2\2\2\u018e\u018f\f\16\2\2\u018f\u0190\5Z.\2\u0190"+
		"\u0191\5B\"\17\u0191\u01ad\3\2\2\2\u0192\u0193\f\r\2\2\u0193\u0194\5\\"+
		"/\2\u0194\u0195\5B\"\16\u0195\u01ad\3\2\2\2\u0196\u0197\f\f\2\2\u0197"+
		"\u0198\7!\2\2\u0198\u0199\5B\"\2\u0199\u019a\7\24\2\2\u019a\u019b\5B\""+
		"\r\u019b\u01ad\3\2\2\2\u019c\u019d\f\13\2\2\u019d\u019e\7\"\2\2\u019e"+
		"\u01ad\5B\"\f\u019f\u01a0\f\n\2\2\u01a0\u01a1\7#\2\2\u01a1\u01ad\5B\""+
		"\13\u01a2\u01a3\f\6\2\2\u01a3\u01a4\7&\2\2\u01a4\u01ad\5B\"\7\u01a5\u01a6"+
		"\f\26\2\2\u01a6\u01a7\7\25\2\2\u01a7\u01a8\5B\"\2\u01a8\u01a9\7\24\2\2"+
		"\u01a9\u01aa\5B\"\2\u01aa\u01ab\7\26\2\2\u01ab\u01ad\3\2\2\2\u01ac\u0176"+
		"\3\2\2\2\u01ac\u017a\3\2\2\2\u01ac\u017e\3\2\2\2\u01ac\u0182\3\2\2\2\u01ac"+
		"\u0186\3\2\2\2\u01ac\u018a\3\2\2\2\u01ac\u018e\3\2\2\2\u01ac\u0192\3\2"+
		"\2\2\u01ac\u0196\3\2\2\2\u01ac\u019c\3\2\2\2\u01ac\u019f\3\2\2\2\u01ac"+
		"\u01a2\3\2\2\2\u01ac\u01a5\3\2\2\2\u01ad\u01b0\3\2\2\2\u01ae\u01ac\3\2"+
		"\2\2\u01ae\u01af\3\2\2\2\u01afC\3\2\2\2\u01b0\u01ae\3\2\2\2\u01b1\u01b2"+
		"\b#\1\2\u01b2\u01b3\5B\"\2\u01b3\u01b9\3\2\2\2\u01b4\u01b5\f\3\2\2\u01b5"+
		"\u01b6\7\6\2\2\u01b6\u01b8\5B\"\2\u01b7\u01b4\3\2\2\2\u01b8\u01bb\3\2"+
		"\2\2\u01b9\u01b7\3\2\2\2\u01b9\u01ba\3\2\2\2\u01baE\3\2\2\2\u01bb\u01b9"+
		"\3\2\2\2\u01bc\u01bd\7\'\2\2\u01bd\u01be\5H%\2\u01be\u01bf\7(\2\2\u01bf"+
		"G\3\2\2\2\u01c0\u01c1\b%\1\2\u01c1\u01c2\5J&\2\u01c2\u01c3\7\24\2\2\u01c3"+
		"\u01c4\5L\'\2\u01c4\u01c5\7\b\2\2\u01c5\u01ce\3\2\2\2\u01c6\u01c7\f\3"+
		"\2\2\u01c7\u01c8\5J&\2\u01c8\u01c9\7\24\2\2\u01c9\u01ca\5L\'\2\u01ca\u01cb"+
		"\7\b\2\2\u01cb\u01cd\3\2\2\2\u01cc\u01c6\3\2\2\2\u01cd\u01d0\3\2\2\2\u01ce"+
		"\u01cc\3\2\2\2\u01ce\u01cf\3\2\2\2\u01cfI\3\2\2\2\u01d0\u01ce\3\2\2\2"+
		"\u01d1\u01d2\5B\"\2\u01d2K\3\2\2\2\u01d3\u01d4\5B\"\2\u01d4M\3\2\2\2\u01d5"+
		"\u01d6\t\2\2\2\u01d6O\3\2\2\2\u01d7\u01d8\7+\2\2\u01d8Q\3\2\2\2\u01d9"+
		"\u01da\t\3\2\2\u01daS\3\2\2\2\u01db\u01dc\t\4\2\2\u01dcU\3\2\2\2\u01dd"+
		"\u01de\7\60\2\2\u01deW\3\2\2\2\u01df\u01e0\t\5\2\2\u01e0Y\3\2\2\2\u01e1"+
		"\u01e2\7\67\2\2\u01e2[\3\2\2\2\u01e3\u01e4\t\6\2\2\u01e4]\3\2\2\2\37a"+
		"jv\u0082\u008f\u0094\u0099\u009e\u00a3\u00b2\u00c1\u00d6\u00f0\u0101\u010c"+
		"\u0110\u011d\u0127\u012c\u0139\u0141\u014b\u0152\u0156\u0174\u01ac\u01ae"+
		"\u01b9\u01ce";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}