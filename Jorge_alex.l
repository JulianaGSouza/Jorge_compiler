%{

#include "Jorge_t_define.h"

#include "Jorge_parser.tab.h"

typedef union{char* i_id; T_exp* i_exp; T_int* i_int; T_float* i_float; T_string* i_string; T_nil* i_nil; T_declist* i_declist; T_dec* i_dec; T_ty* i_ty; T_tylist* i_tylist; T_tyfields* i_tyfields; T_lvalue* i_lvalue; T_operacao* i_operacao; T_exp_list* i_exp_list; T_chamada* i_chamada; T_exp_seq* i_exp_seq; T_rec_enum* i_rec_enum; T_enum_it* i_enum_it; T_def_array* i_def_array; T_def_rec* i_def_rec; T_subunario* i_subunario; T_if* i_if; T_if_else* i_if_else; T_let* i_let;} YYTYPE;

char bf_linha_scanner[500];
unsigned yycolumn = 0;

#define YY_USER_ACTION yycolumn += yyleng;

void yyerror(const char *s){
       printf ("%s\n", s);
};

%}

%option noyywrap

digito [0-9]
inteiro {digito}+
float {inteiro}("."{inteiro})
string_s "\""[a-zA-Z0-9_]+"\""
id [a-zA-Z][a-zA-Z0-9_]*  
comentario "/*"[a-zA-Z0-9_]*"*/"

%%

"type" {return TYPE;}
"array" {return ARRAY;}
"of" {return OF;}
"var" {return VAR;}
"function" {return FUNCTION;}
"let" {return LET;}
"in" {return IN;}
"end" {return END;}
"nil" {return NIL;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}

"{" {return '{';}
"}" {return '}';}
"(" {return '(';}
")" {return ')';}
"[" {return '[';}
"]" {return ']';}
"=" {return IGUAL;}
"<>" {return DIFERENTE;}
">" {return MAIOR;}
"<" {return MENOR;}
">=" {return MAIORIG;}
"<=" {return MENORIG;}
":=" {return ATRIBUICAO;}
"&" {return AND;}
"|" {return OR;}
"," {return ',';}
"." {return PONTO;}
":" {return ':';}
";" {return ';';}
"+" {return ADICAO;}
"-" {return SUBTRACAO;}
"*" {return MULTIPLICACAO;}
"/" {return DIVISAO;}
"->" {return RETORNA;}

inteiro {
	return INT;
}

float {
	return FLOAT;
}

id {
	return ID;
}

string {
	return STRING; 
}

comentario {yycolumn += sizeof(yytext);}

[\t] {yycolumn += 3;}
[ ]+ {yycolumn += 1;}
[\n].* {
	strncpy(bf_linha_scanner, yytext+1, sizeof(bf_linha_scanner));
        yylineno++;
	yycolumn = 0;
        yyless(1);}

%%