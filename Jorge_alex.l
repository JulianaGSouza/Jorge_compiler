%{

#include "Jorge_t_define.h"

#include "Jorge_parser.tab.h"

typedef union{char* i_id; T_exp* i_exp; int i_int; float i_float; char* i_string; T_nil* i_nil; T_declist* i_declist; T_dec* i_dec; T_ty* i_ty; T_tylist* i_tylist; T_tyfields* i_tyfields; T_lvalue* i_lvalue; T_operacao* i_operacao; T_exp_list* i_exp_list; T_chamada* i_chamada; T_exp_seq* i_exp_seq; T_rec_enum* i_rec_enum; T_enum_it* i_enum_it; T_def_array* i_def_array; T_def_rec* i_def_rec; T_subunario* i_subunario; T_if* i_if; T_let* i_let;} YYTYPE;

char bf_linha_scanner[500];
unsigned yycolumn = 0;
unsigned yyline = 1;

#define YY_USER_ACTION yycolumn += yyleng;

%}

%option noyywrap

float {inteiro}("."{inteiro})

%x comment

%%
[\t] {yycolumn += 4;}
[ ]+ {yycolumn += 1;}
[\n].* {
	      strncpy(bf_linha_scanner, yytext+1, sizeof(bf_linha_scanner));
        yyline++;
	      yycolumn = 0;
        yyless(1);}

"\/\*" { BEGIN(comment); }

<comment>[^\*\/|\n]*

<comment>"\*\/" {  BEGIN(INITIAL); }

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

"["|"]"|"{"|"}"|"("|")" { return yytext[0]; }

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

[0-9]+ {
	//yylval.i_int = new T_int(atoi(yytext));
	yylval.i_int = atoi(yytext);
	return INT;
}

float {
	//yylval.i_float = new T_float(atof(yytext));
	yylval.i_float = atof(yytext);
	return FLOAT;
}

[a-zA-Z][a-zA-Z_0-9]* {
  yylval.i_id = yytext;
	return ID;
}

\"[^\"]*\" {
	yylval.i_string = yytext;
	return STRING; 
}

. { printf("Não esperado: [%c]\n", yytext[0]); exit(1); }

<<EOF>> { yyterminate(); }
%%
