#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

using namespace std;

#include "Jorge_t_define.h"
#include "Jorge_funcoes_primitivas.h"

class Ts_item{
public:
	std::string nome;
	virtual ~Ts_item() {}
};

class Ts_item_tipo : public Ts_item{
public:
	enum tipo_list {tipo_id, tipo_rec,tipo_array,tipo_funcao};
	tipo_list tipo;
	std::string valor_id;
	std::shared_ptr<T_tyfields> valor_rec;
};

class Ts_item_var : public Ts_item {
public:
	std::shared_ptr<Ts_item_tipo> tipo;
	std::shared_ptr<T_exp> valor;
};

class Ts_item_fun : public Ts_item{
public:
	std::shared_ptr<T_tyfields> parametros;
	std::shared_ptr<Ts_item_tipo> tipo_retorno;
};

class Ts {
public:
	std::unordered_map<std::string, std::shared_ptr<Ts_item>> tabela_simbolos;
	std::shared_ptr<Ts> pai;

	Ts() {}

	Ts(std::shared_ptr<Ts> pai) : pai(pai){}	
	
	void inserir(std::shared_ptr<Ts_item> item){
		std::pair<std::string,std::shared_ptr<Ts_item>> par (item->nome,item);
		tabela_simbolos.insert(par);
	}

	std::shared_ptr<Ts_item> procura_no_escopo(std::string &nome){
		std::unordered_map<std::string, std::shared_ptr<Ts_item>>::const_iterator got = tabela_simbolos.find(nome);
		if (got == tabela_simbolos.end()) {
			return NULL;
		}else{
			return got->second;
		}
	}
};

std::shared_ptr<Ts_item> procura_ts_item(std::string &nome, shared_ptr<Ts> ts){
	std::unordered_map<std::string, std::shared_ptr<Ts_item>>::const_iterator got = ts->tabela_simbolos.find(nome);

	if (got == ts->tabela_simbolos.end()) {
		if(ts->pai){
			return procura_item(nome,ts->pai);
		} else {
			return NULL;
		};
	}else{
		return got->second;
	}
}

//Variaveis globais
std::shared_ptr<Ts> ts_global(new Ts());
std::shared_ptr<Ts> ts_atual(ts_global);

//redeclaração de função para funções escritas acima conseguirem acessar;
std::string analisa_exp(std::shared_ptr<T_exp> no){};

void analisa_lvalue(T_lvalue* no){
	if (no->exp){
		analisa_lvalue((no->lvalue).get());
		analisa_exp(no->exp);
	}else if(no->lvalue){
		//verificar id
		analisa_lvalue((no->lvalue).get());		
	}else {
		//verifica id
	};
};

void analisa_exp_seq(T_exp_seq* no){
	std::vector<std::shared_ptr<T_exp>> exp_seq (no->exp_seq);
	std::string tipo_exp;
	for(std::shared_ptr<T_exp> exp: exp_seq){
		tipo_exp = analisa_exp(exp);
	}
	return tipo_exp;
};

void analisa_tyfields(T_tyfields* no){
	std::vector<std::string> tyfields (no->tyfields);
	for(std::string id: tyfields){
		//cada dois ids formam um tyfield - arrumar q tá  feio
		//o segundo é o tipo que tem que verificar se existe
	}

};

void analisa_tylist(T_tylist* no){
	std::vector<std::shared_ptr<T_ty>> tylist (no->tylist);
	for(std::shared_ptr<T_ty> ty: tylist){
		analisa_ty(ty);
	}
}

void analisa_ty(std::shared_ptr<T_ty> no, std::shared_ptr<Ts_item_tipo> item){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_id>::element_type*>(no.get())){
		shared_ptr<Ts_item> ts_item(procura_item(no_ty->id,ts_atual));
		if (ts_item){
			item->tipo = Ts::ts_list::tipo_id;
			item->valor_id = no_ty->id;
		} else {
			std::cout << "Semantic Error: "<< no_ty->id << "não é um tipo declarado" << std::endl;
			exit(0);
		};
		
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_rec>::element_type*>(no.get())){
		item->tipo = item::tipo_list::tipo_rec;
		item->valor_rec = no_ty->tyfields;
		analisa_tyfields((no_ty->tyfields).get());
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_array>::element_type*>(no.get())){
		shared_ptr<Ts_item> ts_item(procura_item(no_ty->id,ts_atual));
		if (ts_item){
			item->tipo = Ts::ts_list::tipo_array;
			item->valor_id = no_ty->id;
		} else {
			std::cout << "Semantic Error: "<< no_ty->id << "não é um tipo declarado" << std::endl;
			exit(0);
		};	
	} if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_funfun>::element_type*>(no.get())){
		//Criar novo escopo
		std::shared_ptr<Ts> ts_novo(new Ts(ts_atual));
		std::shared_ptr<Ts> ts_atual(ts_novo);
		
		//item->tipo = "tipo_funfun";
		
		if(no_ty->tylist){
			//analisa_tylist((no_ty->tylist).get());
		}else {
			//analisa_ty(no_ty->ty1);
		};
		//analisa_ty(no_ty->ty2);
	} else {
		//erro;
	};
};

void analisa_dec(std::shared_ptr<T_dec> no){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_tydec>::element_type*>(no.get())){
		shared_ptr<Ts_item> ts_item(ts_atual->procura_no_escopo(no_ty->id));
		if(ts_item){
			std::cout << "Semantic Error: O tipo " << no_ty->id << " já existe neste escopo!";
			exit(0);
		} else {
			std::shared_ptr<Ts_item_tipo> item (new Ts_item_tipo());
			item->nome = no_ty->id;						
			analisa_ty(no_ty->ty,item);
			ts_atual->inserir(item);
		};
	} else if (auto no_var = dynamic_cast<typename std::shared_ptr<T_vardec>::element_type*>(no.get())){
		shared_ptr<Ts_item> ts_item1(ts_atual->procura_no_escopo(no_var->nome));
		if(ts_item1){
			std::cout << "Semantic Error: A variável " << no_ty->id << " já existe neste escopo!" << std::endl;
			exit(0);
		} else {
			std::shared_ptr<Ts_item_var> item (new Ts_item_var());
			item->nome = no_var->nome;
			std::string tipo_exp = analisa_exp(no_var->exp);
			if (no_var->tipo){
				shared_ptr<Ts_item> ts_item2(procurar_item(no_ty->tipo,ts_atual));
				if (ts_item2){
					item->tipo = no_var->tipo;
				} else {
					std::cout << "Semantic Error: O tipo " << no_var->tipo  << " atribuído à variável ";
					std::cout << no_var->nome << " não existe!" << std::endl;
					exit(0);
				};
				if(tipo_exp != no_var->tipo){
					std::cout << "Semantic Error: Incompatibilidade de tipos. O tipo declarado é " << no_var->tipo;
					std::cout << " e o tipo da expressão é " << tipo_exp << "!"<< std::endl;
				};
			}						
			ts_atual->inserir(item);
		};
					
	} else if (auto no_fun = dynamic_cast<typename std::shared_ptr<T_fundec>::element_type*>(no.get())){
		//Criar novo escopo
		std::shared_ptr<Ts> ts_novo(new Ts(ts_atual));
		std::shared_ptr<Ts> ts_atual(ts_novo);
		//verifica id id
		analisa_tyfields((no_fun->tyfields).get());
		analisa_exp(exp);
	} else {
		//erro
	};	
};

void analisa_declist(T_declist* no){
	std::vector<std::shared_ptr<T_dec>> declist (no->declist);
	for(std::shared_ptr<T_dec> dec: declist){
		analisa_dec(dec);
	};
};

void analisa_it(T_enum_it* no){
	//verifica id
	analisa_exp(no->exp);
};

void analisa_rec_enum(T_rec_enum* no){
	std::vector<std::shared_ptr<T_enum_it>> rec_enum (no->rec_enum);
	for(std::shared_ptr<T_enum_it> it: rec_enum){
		analisa_it(it.get());
	}
};

void analisa_exp_list(T_exp_list* no){
	std::vector<std::shared_ptr<T_exp>> exp_list (no->exp_list);
	for(std::shared_ptr<T_exp> exp: exp_list){
		analisa_exp(exp);
	}
}

std::string analisa_chamada(T_chamada* no){
	std::shared_ptr<Ts_item> ts_item(procura_item(no->id,ts_atual));
	if (ts_item){
		if(ts_item->tipo == ts_item::tipo_list::tipo_funcao){
			analisa_exp_list((no->exp_list).get());		
			return "nil";
		} else {
			std::cout << "Semantic Error: O tipo " << no->id;
			std::cout << " não é uma função!" << std::endl;
			exit(0);
		};
	} else {
		std::cout << "Semantic Error: A função " << no->id;
		std::cout << " não existe!" << std::endl;
		exit(0);
	};
};

str::string analisa_operacao(T_operacao* no){
	std::string eexp_tipo = analisa_exp(no->eexp);
	std::string dexp_tipo = analisa_exp(no->dexp);
	if (eexp_tipo != dexp_tipo){
		std::cout << "Semantic Error: Incompatibilidade de tipos. A expressão à esquerda do operador; "
		std::cout << no->operador << " é do tipo " << eexp_tipo;
		std::cout << ", e a expressão à direita é do tipo " << dexp_tipo << std::endl;
		exit(0);
	} else {
		return eexp_tipo;
	};
};

std::string analisa_def_array(T_def_array* no){
	std::shared_ptr<Ts_item> ts_item(procura_item(no_def_array->tipo,ts_atual));
	std::string tipo_exp1;
	std::string tipo_exp2;
	if (ts_item){
		if(ts_item->tipo == tipo_array){
			tipo_exp1 = analisa_exp(no->exp1);
			if(tipo_exp1 == "int"){
				tipo_exp2 = analisa_exp(no->exp2);
				if(tipo_exp2 == no->tipo){
					return "array of "+ no->tipo;
				} else {
					std::cout << "Semantic Error: A expressão após 'OF' deve possuir o mesmo tipo do array: ";
					std::cout << no->tipo <<", mas possui o tipo " << tipo_exp2 << "!" << std::endl;
					exit(0);
				};
			} else {
				std::cout << "Semantic Error: A expressão entre couchetes deve possuir um valor inteiro, não ";
				std::cout << tipo_exp1 <<"!" << std::endl;
				exit(0);
			};
		} else {
			std::cout << "Semantic Error: O tipo " << no->tipo;
			std::cout << " não é um array!" << std::endl;
			exit(0);
		};
	} else {
		std::cout << "Semantic Error: O tipo array " << no->tipo;
		std::cout << " não existe!" << std::endl;
		exit(0);
	};
};

std::string analisa_def_rec(T_def_rec* no){
	std::shared_ptr<Ts_item> ts_item(procura_item(no_def_rec->tipo,ts_atual));
	if (ts_item){
		if(ts_item->tipo == Ts::tipo_list::tipo_rec){
			return analisa_rec_enum((no_def_rec->rec_enum).get());
		} else {
			std::cout << "Semantic Error: O tipo " << no_def_rec->tipo;
			std::cout << " não é um record!" << std::endl;
			exit(0);
		};
	} else {
		std::cout << "Semantic Error: O tipo record " << no_def_rec->tipo;
		std::cout << " não existe!" << std::endl;
		exit(0);
	};
};

std::string analisa_if_else(T_if_else* no){
	std::string tipo_exp1 = analisa_exp(no->exp1);
	if (tipo_exp1 == "int"){
		std::string tipo_exp2 = analisa_exp(no->exp2);
		std::string tipo_exp3 = analisa_exp(no->exp3);
		if (tipo_exp2 == tipo_exp3){
			return "nil";
		} else {
			std::cout << "Semantic Error: Tipos incompatíveis. O tipo da expressão após 'THEN' é " << tipo_exp2;
			std::cout << " e o tipo da expressão após 'ELSE' é " << tipo_exp3 <<"!" << std::endl;
			exit(0);
		}
	} else {
		std::cout << "Semantic Error: A expressão após 'IF' deve possuir um valor inteiro, não ";
		std::cout << tipo_exp1 <<"!" << std::endl;
		exit(0);
	};
}

std::string analisa_if(T_if* no){
	std::string tipo_exp1 = analisa_exp(no->exp1);
	if (tipo_exp1 == "int"){
		analisa_exp(no->exp2);
		return "nil";
	} else {
		std::cout << "Semantic Error: A expressão após 'IF' deve possuir um valor inteiro, não ";
		std::cout << tipo_exp1 <<"!" << std::endl;
		exit(0);
	};
};

std::string analisa_let(T_let* no){
	analisa_declist(no->declist);
	return analisa_exp_seq(no->exp_seq);
}

std::string analisa_exp(std::shared_ptr<T_exp> no){
	if (auto no_int = dynamic_cast<typename std::shared_ptr<T_int>::element_type*>(no.get())){
		return "int";
	} else if (auto no_float = dynamic_cast<typename std::shared_ptr<T_float>::element_type*>(no.get())){
		return "float";
	} else if (auto no_string = dynamic_cast<typename std::shared_ptr<T_string>::element_type*>(no.get())){
		return "string";
	} else if (auto no_nil = dynamic_cast<typename std::shared_ptr<T_nil>::element_type*>(no.get())){
		return "nil";
	} else if (auto no_lvalue = dynamic_cast<typename std::shared_ptr<T_lvalue>::element_type*>(no.get())){
		return analisa_lvalue(no_lvalue);
	} else if (auto no_exp_seq = dynamic_cast<typename std::shared_ptr<T_exp_seq>::element_type*>(no.get())){
		return analisa_exp_seq(no_exp_seq);
	} else if (auto no_subunario = dynamic_cast<typename std::shared_ptr<T_subunario>::element_type*>(no.get())){
		return analisa_exp(no_subunario->exp);
	} else if (auto no_chamada = dynamic_cast<typename std::shared_ptr<T_chamada>::element_type*>(no.get())){
		return analisa_chamada(no_chamada);
	} else if (auto no_operacao = dynamic_cast<typename std::shared_ptr<T_operacao>::element_type*>(no.get())){
		return analisa_operacao(no_operacao);
	} else if (auto no_def_array = dynamic_cast<typename std::shared_ptr<T_def_array>::element_type*>(no.get())){
		return analisa_def_array (no_def_array);
	} else if (auto no_def_rec = dynamic_cast<typename std::shared_ptr<T_def_rec>::element_type*>(no.get())){
		return analisa_def_rec(no_def_rec);
	} else if (auto no_if_else = dynamic_cast<typename std::shared_ptr<T_if_else>::element_type*>(no.get())){
		return analisa_if_else(no_if_else);
	} else if (auto no_if = dynamic_cast<typename std::shared_ptr<T_if>::element_type*>(no.get())){
		return analisa_if(no_if);
	} else if (auto no_let = dynamic_cast<typename std::shared_ptr<T_let>::element_type*>(no.get())){
		return analisa_let(no_let);
	} else {
		//erro
	};
};

void inicializa(){
	//coloca tipos e funções primitivos
	//Tipos primitidos: int, float, string, nil
	//Funções primitivas: print, flush, getchar, ord, chr, size, substring, concat, not, exit
};

void semantico(std::shared_ptr<T_exp> raiz){
	inicializa();
	analisa_exp(raiz);	
};

int main(void){
	std::shared_ptr<T_float> p_int(new T_float(8));
	semantico(p_int);
};
