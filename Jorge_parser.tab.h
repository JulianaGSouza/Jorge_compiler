/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_JORGE_PARSER_TAB_H_INCLUDED
# define YY_YY_JORGE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE = 258,
    ARRAY = 259,
    OF = 260,
    VAR = 261,
    FUNCTION = 262,
    LET = 263,
    IN = 264,
    END = 265,
    NIL = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    IGUAL = 270,
    DIFERENTE = 271,
    MAIOR = 272,
    MENOR = 273,
    MAIORIG = 274,
    MENORIG = 275,
    AND = 276,
    OR = 277,
    PONTO = 278,
    ATRIBUICAO = 279,
    ADICAO = 280,
    SUBTRACAO = 281,
    MULTIPLICACAO = 282,
    DIVISAO = 283,
    RETORNA = 284,
    INT = 285,
    FLOAT = 286,
    STRING = 287,
    ID = 288,
    SUBUNARIO = 289,
    ARRAY_PREC = 290,
    IF_PREC = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 28 "Jorge_parser.y" /* yacc.c:1909  */

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

#line 118 "Jorge_parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<T_exp> raiz);

#endif /* !YY_YY_JORGE_PARSER_TAB_H_INCLUDED  */
