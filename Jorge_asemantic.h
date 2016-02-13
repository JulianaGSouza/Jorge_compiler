#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

#include "Jorge_t_define.h"

// criar classe dos tipos
class ty{
	std::string nome;
public:
	ty(std::string nome) : nome(nome) {}
};

//criar classe de itens da tabela
class ts_item {
public:
	std::string nome;
	std::shared_ptr<ty> tipo;
	std::string valor;

	ts_item(std::string nome, std::shared_ptr<ty> tipo, std::string valor) 
	: nome(nome), tipo(std::move(tipo)) {}
};



//criar tabela de simbolos
class ts {
	std::map<std::string,std::shared_ptr<ts_item>> tabela_simbolos;
public:

	/*void inserir(std::shared_ptr<ts_item> item){
		tabela_simbolos.insert(item->nome, item);
	}*/

	/*std::shared_ptr<ts_item> procurar(std::string &nome){
		return tabela_simbolos.find(nome);	
	}*/

	void iniciarEscopo() {}
	
	void finalizarEscopo(){}

};

//tabela = arvore de tabelas

//lista de tabelas hash

//popular tipos basicos
//popular tabela com as funcoes primitivas

void checar_tipos(std::unique_ptr<T_exp> raiz){
	//erro: mistura de tipos
	//erro: tipo nao declarado
	std::cout << typeid(raiz.get()).name() << std::endl;
}; 

void semantico(std::unique_ptr<T_exp> raiz){
	checar_tipos(std::move(raiz));	
};



void analisa_exp(<exp> no){}
	switch typeid(raiz.nome()):
	case "T_int":
		break;
	case "T_float":
		break;
	case "T_string":
		break;
	case "T_nil":
		break;
	case "T_lvalue":
		analisa_lvalue(no);
		break;
	case "T_exp_seq":
		analise_exp_seq(no->exp_seq);
		break;
	case "T_subunario":
		break;
	case "T_chamada":
		break;
	case "T_operacao":
		analisa_exp(no->eexp);
		analise_exp(no->dexp);
		break;
	case "T_def_array":
		//verificar tipo em no->tipo
		analisa_exp(no->exp1);//que fica entre  []
		analisa_exp(no->exp2);//depois de OF
		break;
	case "T_def_rec":
		//verificar tipo em no->tipo
		analise_rec_enum(no->rec_enum);
		break;
	case "T_if_else": //verificar se o que tem no if é do mesmo tipo do que tem no else
		analisa_exp(no->exp1)
		analisa_exp(no->exp2)
		analisa_exp(no->exp3)
		break;
	case "T_if":
		analisa_exp(no->exp1)
		analisa_exp(no->exp2)
		break;
	case "T_let":
		analisa_declist(no->declist);
		analisa_exp(no->exp_seq);
		break;
	default:
		print(erro);

};

void analisa_lvalue(<lvalue> no){
	if (atual_exp->id == NULL){
		analisa_lvalue(no->lvalue);
		analisa_exp(no->exp);
	}else if(atual_exp->lvalue == NULL){
		//verificar tipo id		
	}else {
		//verifica id
		analisa_lvaleu(no->lvalue);
	}
}

void analisa_exp_seq(std::vector<T_exp_seq> exp_seq){
	for (exp& i :exp_seq){
		analisa_exp(exp);
	}
}

// verificar um lado da exp, verificar o outro e ver se os tipos são os mesmos

// testar com: dynamic_cast //dynamic_cast<FunExpAST>(ExpAST) - falha retorna 0
