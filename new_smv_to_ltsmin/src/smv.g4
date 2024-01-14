grammar smv;

file
   :module*
   |ltl*
   ;
ltl
    :'LTLSPEC' ltl_expr
    ;

module:
    'MODULE' IDENTIFIER ('(' para_list ')')? module_body;

para_list
    :para
    |para_list','para
    ;
para
    :basic_next_expr
    ;

module_body
    :module_element
    |module_body module_element
    ;

module_element
    :var_declaration
    |ivar_declaration
    |frozenvar_declaration
    |define_declaration
    |constants_declaration
    |assign_constraint
    |trans_constraint
    |init_constraint
    |invar_constraint
    |fairness_constraint
    ;



fairness_constraint
    :'FAIRNESS' basic_next_expr ';'?
    ;

invar_constraint
    :'INVAR' basic_next_expr ';'?
    ;

init_constraint
    :'INIT' basic_next_expr ';'?
    ;
trans_constraint
    :'TRANS' basic_next_expr ';'?
    ;
assign_constraint
    :'ASSIGN' assign_list
    ;
assign_list
    :assign ';'
    |assign_list assign ';'
    ;
assign
    :next_assign ':=' basic_next_expr
    |init_assign ':=' basic_next_expr
    |var ':=' basic_next_expr
    ;
init_assign
    :'init('var')'
    ;
next_assign
    :'next('var')'
    ;
constants_declaration
    :'CONSTANTS' constants_body
    ;
constants_body
    :IDENTIFIER
    |constants_body ',' IDENTIFIER
    ;
frozenvar_declaration
    :'FROZENVAR' simple_var_list
    ;
//变量定义
var_declaration
    :'VAR' var_list;
ivar_declaration
    :'IVAR' simple_var_list;
var_list
    :IDENTIFIER ':' type_sepcifier ';'
    |var_list IDENTIFIER ':' type_sepcifier ';'
    ;
simple_var_list
    :IDENTIFIER ':' simple_type_specifier ';'
    |simple_var_list IDENTIFIER ':' simple_type_specifier ';'
    ;
var
    :IDENTIFIER
    |IDENTIFIER'['INTEGER']'
    |IDENTIFIER'.'var
    ;
type_sepcifier
    :simple_type_specifier
    |module_type_specifier
    ;
simple_type_specifier
    :'boolean'
    |'{' enumeration_type_body '}'
    |integer_range
    |'array' integer_range 'of' simple_type_specifier
    ;
enumeration_type_body
    :enumeration_type_value
    |enumeration_type_body ',' enumeration_type_value
    ;
enumeration_type_value
    :symbolic_constant
    |INTEGER
    ;
integer_range
    :INTEGER '..'INTEGER;
symbolic_constant
    :IDENTIFIER
    ;
module_type_specifier
    :IDENTIFIER ('(' para_list ')')?
    |'process' IDENTIFIER '(' para_list ')'
    ;

//define
define_declaration
    :'DEFINE' define_body
    ;
define_body
    :var ':=' basic_next_expr ';'?
    |define_body var ':=' basic_next_expr ';'?
    ;


//含下一状态的函数
basic_next_expr
    :var
    |INTEGER
    |'('basic_next_expr')'
    |basic_next_expr'['basic_next_expr ':' basic_next_expr ']'
    |'!'basic_next_expr
    |basic_next_expr mul basic_next_expr
    |basic_next_expr mod basic_next_expr
    |basic_next_expr add basic_next_expr
    |basic_next_expr shift basic_next_expr
    |basic_next_expr union basic_next_expr
    |basic_next_expr logicjudge basic_next_expr
    |basic_next_expr logicand basic_next_expr
    |basic_next_expr logicor basic_next_expr
    |basic_next_expr '?' basic_next_expr ':'basic_next_expr
    |basic_next_expr '<->' basic_next_expr
    |basic_next_expr '->' basic_next_expr
    |'bool('basic_next_expr')'
    |'toint('basic_next_expr')'
    |'{'set_next_body'}'
    |basic_next_expr 'in' basic_next_expr
    |case_expr
    |'next('basic_next_expr')'
    |integer_range
    ;
set_next_body
    :basic_next_expr
    |set_next_body','basic_next_expr
    ;
case_expr
    :'case' case_next_body 'esac'
    ;
case_next_body
    :case_cond ':' case_value ';'
    |case_next_body case_cond ':'case_value';'
    ;

case_cond
    :basic_next_expr
    ;
case_value
    :basic_next_expr
    ;

mul
:'*'|'/';
mod
:'mod';
add
:'+'|'-';
shift
:'<<'|'>>';
union
:'union';
logicjudge
:'='|'!='|'>'|'<'|'>='|'<=';
logicand
:'&';
logicor
:'|'|'xor';







INTEGER
    :DIGHT
    |DIGHT INTEGER
    ;

IDENTIFIER
    :IDENTIFIER_FIRST_CHARACTER(IDENTIFIER_CONSECUTIVE_CHARACTER)*;



IDENTIFIER_FIRST_CHARACTER
    :[a-zA-Z_];

IDENTIFIER_CONSECUTIVE_CHARACTER
    :IDENTIFIER_FIRST_CHARACTER|DIGHT|'$'|'#'|'-';

DIGHT
    :[0-9];


ZHUSHI
    : '--' .*? '\r'? '\n' -> skip
    ;

IGNORE
    : [\t \r\n]+ -> skip
    ;