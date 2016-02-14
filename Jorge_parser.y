%defines 
%error-verbose

%{

#include "Jorge_t_define.h"
#include "Jorge_parser.tab.h"

extern char bf_linha_scanner[500];
extern unsigned yycolumn;
extern int yyline;

#include "utils.h"

void yyerror (std::shared_ptr<T_exp> raiz,char const *s){
	imprime_erro(s);
};

int yylex();

%}

%parse-param {std::shared_ptr<T_exp> raiz}

%token TYPE ARRAY OF VAR FUNCTION LET IN END NIL 
%token IF THEN ELSE 
%token IGUAL DIFERENTE MAIOR MENOR MAIORIG MENORIG AND OR PONTO
%token ATRIBUICAO ADICAO SUBTRACAO MULTIPLICACAO DIVISAO RETORNA
%token INT FLOAT STRING ID

%union{
	char* i_id;
	T_exp* i_exp;
	T_int* i_int;
	T_float* i_float;
	T_string* i_string;
	T_nil* i_nil;
	T_declist* i_declist;
	T_dec* i_dec;
	T_ty* i_ty;	
	T_tylist* i_tylist;
	T_tyfields* i_tyfields;
	T_lvalue* i_lvalue;
	T_operacao* i_operacao;
	T_exp_list* i_exp_list;
	T_chamada* i_chamada;
	T_exp_seq* i_exp_seq;
	T_rec_enum* i_rec_enum;
	T_enum_it* i_enum_it;
	T_def_array* i_def_array;
	T_def_rec* i_def_rec;
	T_subunario* i_subunario;
	T_if * i_if;
	T_if_else* i_if_else;
	T_let* i_let;
}

%type<i_id> ID
%type<i_exp> exp
%type<i_int> INT
%type<i_float> FLOAT
%type<i_string> STRING
%type<i_nil> NIL
%type<i_declist> declist
%type<i_dec> dec tydec vardec fundec
%type<i_ty> ty ty_id ty_rec ty_array ty_funfun
%type<i_tyfields> tyfields
%type<i_tylist> tylist
%type<i_lvalue> lvalue
%type<i_operacao> op_arit op_bool op_comp
%type<i_exp_list> exp_list
%type<i_chamada> chamada
%type<i_exp_seq> exp_seq
%type<i_rec_enum> rec_enum
%type<i_enum_it> enum_it
%type<i_def_rec> def_rec
%type<i_def_array> def_array
%type<i_subunario> subunario
%type<i_if> exp_if
%type<i_if_else> exp_if_else
%type<i_let> exp_let

%right RETORNA
%left OR
%left AND
%nonassoc IGUAL DIFERENTE MENOR MENORIG MAIOR MAIORIG
%left SUBTRACAO ADICAO
%left MULTIPLICACAO DIVISAO
%precedence SUBUNARIO
%precedence '('
%precedence ARRAY_PREC
%precedence IF_PREC
%precedence ELSE

%start inicio

%%

inicio :	exp 			{raiz = std::shared_ptr<T_exp>(new T_exp()); 
					raiz->set_localizacao(yyline,yycolumn,bf_linha_scanner);}

//declaracoes
declist:	dec			{ $$ = new T_declist(); $$->add(std::shared_ptr<T_dec>($1));
						$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		|dec declist		{ $2->add(std::shared_ptr<T_dec>($1)); $$ = $2;}
;

dec:		tydec
		| vardec
		| fundec
;

//tipos
tydec: 		TYPE ID IGUAL ty 	{ $$ = new T_tydec(std::string($2),std::shared_ptr<T_ty>($4));
						$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);};

tylist:		%empty			{ $$ = new T_tylist();
						$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		|ty			{ $$ = new T_tylist(); $$->add(std::shared_ptr<T_ty>($1));
						$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		|ty ',' tylist		{ $3->add(std::shared_ptr<T_ty>($1)); $$ = $3;}
;

ty:		ty_id
		| ty_rec
		| ty_array
		| ty_funfun
;

ty_id:		ID				{ $$ = new T_ty_id(std::string($1));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

ty_rec:		'{' tyfields '}' 		{ $$ = new T_ty_rec(std::shared_ptr<T_tyfields>($2));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);} 
;

ty_array:	ARRAY OF ID			{ $$ = new T_ty_array(std::string($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

ty_funfun:	ty RETORNA ty			{ $$ = new T_ty_funfun(std::shared_ptr<T_ty>($1),std::shared_ptr<T_ty>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| '(' tylist ')' RETORNA ty	{ $$ = new T_ty_funfun(std::shared_ptr<T_tylist>($2),std::shared_ptr<T_ty>($5));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

tyfields:	%empty  			{ $$ = new T_tyfields();
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| ID ':' ID			{ $$ = new T_tyfields(); $$->add(std::string($1),std::string($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| ID ':' ID ',' tyfields	{ $5->add(std::string($1),std::string($3)); $$ = $5;}
;

//variaveis

vardec:		VAR ID ATRIBUICAO exp 		{ $$ = new T_vardec(std::string($2),std::shared_ptr<T_exp>($4));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| VAR ID ':' ID ATRIBUICAO exp	{ $$ = new T_vardec(std::string($2),std::string($4),std::shared_ptr<T_exp>($6));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

//funcoes

fundec:		FUNCTION ID '(' tyfields ')' ':' ID IGUAL exp	{ $$ = new T_fundec(std::string($2),
								std::shared_ptr<T_tyfields>($4), std::string($7),std::shared_ptr<T_exp>($9));
								$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| FUNCTION ID '(' tyfields ')' IGUAL exp	{ $$ = new T_fundec(std::string($2),
								std::shared_ptr<T_tyfields>($4),std::shared_ptr<T_exp>($7));
									$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;
 
//variaveis e expressoes
lvalue:		ID				{ $$ = new T_lvalue(std::string($1));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| lvalue PONTO ID		{ $$ = new T_lvalue(std::shared_ptr<T_lvalue>($1), std::string($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| lvalue '[' exp ']'		{ $$ = new T_lvalue(std::shared_ptr<T_lvalue>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

//Expressoes

op_arit:	exp ADICAO exp			{ $$ = new T_operacao("+", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp SUBTRACAO exp		{ $$ = new T_operacao("-", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp MULTIPLICACAO exp		{ $$ = new T_operacao("*", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp DIVISAO exp		{ $$ = new T_operacao("/", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

op_bool:	exp OR exp			{ $$ = new T_operacao("|", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp AND exp			{ $$ = new T_operacao("&", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

op_comp:	exp IGUAL exp			{ $$ = new T_operacao("=", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp DIFERENTE exp		{ $$ = new T_operacao("<>", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp MENOR exp			{ $$ = new T_operacao("<", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp MENORIG exp		{ $$ = new T_operacao("<=", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp MAIOR exp			{ $$ = new T_operacao(">", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp MAIORIG exp		{ $$ = new T_operacao(">=", std::shared_ptr<T_exp>($1), std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

exp_list:	%empty				{$$ = new T_exp_list();
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp				{$$ = new T_exp_list(); $$->add(std::shared_ptr<T_exp>($1));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp ',' exp_list		{$3->add(std::shared_ptr<T_exp>($1)); $$ = $3;}
;

chamada:	ID '(' exp_list ')'		{$$ = new T_chamada(std::string($1),std::shared_ptr<T_exp_list>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
	//	| exp '(' exp_list ')'		{$$ = new T_chamada(std::shared_ptr<T_exp>($1),std::shared_ptr<T_exp_list>($3));}
;

exp_seq: 	%empty 				{$$ = new T_exp_seq();
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp				{$$ = new T_exp_seq(); $$->add(std::shared_ptr<T_exp>($1));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| exp ';' exp_seq		{$3->add(std::shared_ptr<T_exp>($1)); $$ = $3;}
;

def_array:	ID '[' exp ']' OF exp %prec ARRAY_PREC { $$ = new T_def_array(std::string($1),
						std::shared_ptr<T_exp>($3),std::shared_ptr<T_exp>($6));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

rec_enum: 	%empty				{$$ = new T_rec_enum();
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| enum_it			{$$ = new T_rec_enum(); $$->add(std::shared_ptr<T_enum_it>($1));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| enum_it ',' rec_enum		{$3->add(std::shared_ptr<T_enum_it>($1)); $$ = $3;}
;

enum_it:	ID IGUAL exp			{$$ = new T_enum_it(std::string($1),std::shared_ptr<T_exp>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

def_rec: 	ID '{' rec_enum '}'		{$$ = new T_def_rec(std::string($1), std::shared_ptr<T_rec_enum>($3));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

subunario: 	SUBTRACAO exp %prec SUBUNARIO	{ $$ = new T_subunario(std::shared_ptr<T_exp>($2));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

exp_if:		IF exp THEN exp %prec IF_PREC	{ $$ = new T_if(std::shared_ptr<T_exp>($2),std::shared_ptr<T_exp>($4));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

exp_if_else:	IF exp THEN exp ELSE exp	{ $$ = new T_if_else(std::shared_ptr<T_exp>($2),
						std::shared_ptr<T_exp>($4),std::shared_ptr<T_exp>($6));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

exp_let:	LET declist IN exp_seq END	{ $$ = new T_let(std::shared_ptr<T_declist>($2),std::shared_ptr<T_exp_seq>($4));
							$$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
;

exp:		lvalue
		| NIL				{$$ = new T_nil(); $$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| '(' exp_seq ')'		{$$ = $2;}
		| INT 				{$$ = new T_int(*$1); $$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| FLOAT 			{$$ = new T_float(*$1); $$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| STRING			{$$ = new T_string(*$1); $$->set_localizacao(yyline,yycolumn,bf_linha_scanner);}
		| subunario
		| chamada
		| op_arit			
		| op_bool			
		| op_comp			
		| def_array
		| def_rec
		| exp_if_else 
		| exp_if	
		| exp_let
    | error { $$ = new T_nil(); }
;

%%
