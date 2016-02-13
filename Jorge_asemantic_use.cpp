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

//Tipos primitidos: int, float, string, nil
//Funções primitivas: print, flush, getchar, ord, chr, size, substring, concat, not, exit

class Ts_item_tipo : public Ts_item{
public:
	enum tipo_list {tipo_id, tipo_rec,tipo_array,tipo_funfun};
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

std::shared_ptr<Ts_item> procura_item(std::string &nome, shared_ptr<Ts> ts){
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
std::shared_ptr<Ts> tb_global(new Ts());
std::shared_ptr<Ts> tb_atual(tb_global);

void analisa_lvalue(T_lvalue* no){
	if (no->exp){
		analisa_lvalue((no->lvalue).get());
		//analisa_exp(no->exp);
	}else if(no->lvalue){
		//verificar id
		analisa_lvalue((no->lvalue).get());		
	}else {
		//verifica id
	};
};

void analisa_exp_seq(T_exp_seq* no){
	std::vector<std::shared_ptr<T_exp>> exp_seq (no->exp_seq);
	for(std::shared_ptr<T_exp> exp: exp_seq){
		//analisa_exp(exp);
	}
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
		//analisa_ty(ty);
	}
}

void analisa_ty(std::shared_ptr<T_ty> no, std::shared_ptr<Ts_item_tipo> item){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_id>::element_type*>(no.get())){
		shared_ptr<Ts_item> ts_item(procura_item(no_ty->id,tb_atual));
		if (ts_item){
			//item->tipo = "tipo_id";
			item->valor_id = no_ty->id;
		} else {
			std::cout << "Semantic Error: "<< no_ty->id << "não é um tipo declarado" << std::endl;
			exit(0);
		};
		
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_rec>::element_type*>(no.get())){
		//item->tipo = "tipo_rec";
		item->valor_rec = no_ty->tyfields;
		analisa_tyfields((no_ty->tyfields).get());
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_array>::element_type*>(no.get())){
		shared_ptr<Ts_item> ts_item(procura_item(no_ty->id,tb_atual));
		if (ts_item){
			//item->tipo = "tipo_array";
			item->valor_id = no_ty->id;
		} else {
			std::cout << "Semantic Error: "<< no_ty->id << "não é um tipo declarado" << std::endl;
			exit(0);
		};	
	} if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_funfun>::element_type*>(no.get())){
		//Criar novo escopo
		std::shared_ptr<Ts> tb_novo(new Ts(tb_atual));
		std::shared_ptr<Ts> tb_atual(tb_novo);
		
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
		shared_ptr<Ts_item> ts_item(tb_atual->procura_no_escopo(no_ty->id));
		if(ts_item){
			std::cout << "Semantic Error: O tipo " << no_ty->id << " já existe neste escopo!";
			exit(0);
		} else {
			std::shared_ptr<Ts_item_tipo> item (new Ts_item_tipo());
			item->nome = no_ty->id;						
			analisa_ty(no_ty->ty,item);
			tb_atual->inserir(item);
		};
	} else if (auto no_var = dynamic_cast<typename std::shared_ptr<T_vardec>::element_type*>(no.get())){
		shared_ptr<Ts_item> ts_item1(tb_atual->procura_no_escopo(no_var->nome));
		if(ts_item1){
			std::cout << "Semantic Error: A variável " << no_ty->id << " já existe neste escopo!" << std::endl;
			exit(0);
		} else {
			std::shared_ptr<Ts_item_var> item (new Ts_item_var());
			item->nome = no_var->nome;
			std::string tipo_exp = analisa_exp(no_var->exp);
			if (no_var->tipo){
				shared_ptr<Ts_item> ts_item2(procurar_item(no_ty->tipo,tb_atual));
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
			tb_atual->inserir(item);
		};
					
	} else if (auto no_fun = dynamic_cast<typename std::shared_ptr<T_fundec>::element_type*>(no.get())){
		//Criar novo escopo
		std::shared_ptr<Ts> tb_novo(new Ts(tb_atual));
		std::shared_ptr<Ts> tb_atual(tb_novo);
		//verifica id id
		analisa_tyfields((no_fun->tyfields).get());
		//analisa_exp(exp);
	} else {
		//erro
	}	
};

void analisa_declist(T_declist* no){
	std::vector<std::shared_ptr<T_dec>> declist (no->declist);
	for(std::shared_ptr<T_dec> dec: declist){
		analisa_dec(dec);
	}
};

void analisa_it(T_enum_it* no){
	//verifica id
	//analisa_exp(no->exp);
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
		//analisa_exp(exp);
	}
}

void analisa_chamada(T_chamada* no){
	if(no->exp){
		//analisa_exp(no->exp);
	} else {
		//verifica id
	}
	analisa_exp_list((no->exp_list).get());
};

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
	} else if (auto no_subunario = dynamic_cast<typename std::shared_ptr<T_subunario>::element_type*>(no.get())  ){
		return analisa_exp(no_subunario->exp);
	} else if (auto no_chamada = dynamic_cast<typename std::shared_ptr<T_chamada>::element_type*>(no.get())  ){
		return analisa_chamada(no_chamada);
	} else if (auto no_operacao = dynamic_cast<typename std::shared_ptr<T_operacao>::element_type*>(no.get())  ){
		std::string etipo = analisa_exp(no_operacao->eexp);
		std::string dtipo = analisa_exp(no_operacao->dexp);
		if (etipo != dtipo){
			std::cout << "Semantic Error: Incompatibilidade de tipos. A expressão à esquerda do operador; "
			std::cout << no_operacao->op << " é do tipo " << etipo;
			std::cout << ", e a expressão à direita é do tipo " << dtipo << std::endl;
			exit(0);
		} else {
			return etipo;
		};
	} else if (auto no_def_array = dynamic_cast<typename std::shared_ptr<T_def_array>::element_type*>(no.get())  ){
		shared_ptr<Ts_item> ts_item(procura_item(no_def_array->tipo,tb_atual));
		std::string tipo_exp1;
		std::string tipo_exp2;
		if (ts_item){
			if(ts_item->tipo == tipo_array){
				tipo_exp1 = analisa_exp(no_def_array->exp1);
				if(tipo_exp1 == "int"){
					tipo_exp2 = analisa_exp(no_def_array->exp2);
					if(tipo_exp2 == no_def_array->tipo){
						return "array of "+ no_def_array->tipo;
					} else {
						std::cout << "Semantic Error: A expressão após 'OF' deve possuir o mesmo tipo do array: ";
						std::cout << no_def_array->tipo <<", mas possui o tipo " << tipo_exp2 << "!" << std::endl;
						exit(0);
					};
				} else {
					std::cout << "Semantic Error: A expressão entre couchetes deve possuir um valor inteiro, não ";
					std::cout << tipo_exp1 <<"!" << std::endl;
					exit(0);
				};
			} else {
				std::cout << "Semantic Error: O tipo " << no_def_array->tipo;
				std::cout << " não é um array!" << std::endl;
				exit(0);
			};
		} else {
			std::cout << "Semantic Error: O tipo array " << no_def_array->tipo;
			std::cout << " não existe!" << std::endl;
			exit(0);
		};
	} else if (auto no_def_rec = dynamic_cast<typename std::shared_ptr<T_def_rec>::element_type*>(no.get())  ){
		shared_ptr<Ts_item> ts_item(procura_item(no_def_rec->tipo,tb_atual));
		if (ts_item){
			if(ts_item->tipo == tipo_rec){
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
	} else if (auto no_if_else = dynamic_cast<typename std::shared_ptr<T_if_else>::element_type*>(no.get())  ){
		//verificar se o que tem no if é do mesmo tipo do que tem no else
		analisa_exp(no_if_else->exp1);
		analisa_exp(no_if_else->exp2);
		analisa_exp(no_if_else->exp3);
	} else if (auto no_if = dynamic_cast<typename std::shared_ptr<T_if>::element_type*>(no.get())  ){
		analisa_exp(no_if->exp1);
		analisa_exp(no_if->exp2);
	} else if (auto no_let = dynamic_cast<typename std::shared_ptr<T_let>::element_type*>(no.get()) ){
		//Cria novo escopo
		std::shared_ptr<Ts> tb_novo(new Ts(tb_atual));
		std::shared_ptr<Ts> tb_atual(tb_novo);
		analisa_declist((no_let->declist).get());
		analisa_exp_seq((no_let->exp_seq).get());
	} else {
		//erro
	};
};

void semantico(std::shared_ptr<T_exp> raiz){
	analisa_exp(raiz);	
};

int main(void){
	std::shared_ptr<T_float> p_int(new T_float(8));
	semantico(p_int);
};
