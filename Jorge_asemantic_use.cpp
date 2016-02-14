#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

using namespace std;

#include "Jorge_t_define.h"
#include "Jorge_funcoes_primitivas.h"

enum enum_tipo_list {id,rec,array,funcao};

class Tabela_tipos_item{
public:
	enum_tipo_list tipo;
	std::string nome;
	std::string valor_id;
	std::shared_ptr<T_tyfields> valor_rec;
};

class Tabela_var_fun_item{
public:
	std::string nome;
	std::shared_ptr<T_tyfields> parametros;
	std::shared_ptr<Tabela_tipos_item> tipo;
};

class Tabela_simbolos {
public:
	std::unordered_map<std::string, std::shared_ptr<Tabela_tipos_item>> tabela_tipos;
	std::unordered_map<std::string, std::shared_ptr<Tabela_var_fun_item>> tabela_var_fun;
	std::shared_ptr<Tabela_simbolos> pai;

	Tabela_simbolos() {}

	Tabela_simbolos(std::shared_ptr<Tabela_simbolos> pai) : pai(pai){}	
	
	void inserir_tipos(std::shared_ptr<Tabela_tipos_item> item){
		std::pair<std::string,std::shared_ptr<Tabela_tipos_item>> par (item->nome,item);
		tabela_tipos.insert(par);
	}

	void inserir_var_fun(std::shared_ptr<Tabela_var_fun_item> item){
		std::pair<std::string,std::shared_ptr<Tabela_var_fun_item>> par (item->nome,item);
		tabela_var_fun.insert(par);
	}

	std::shared_ptr<Tabela_tipos_item> procura_tipo_no_escopo(std::string &nome){
		std::unordered_map<std::string, std::shared_ptr<Tabela_tipos_item>>::const_iterator got = tabela_tipos.find(nome);
		if (got == tabela_tipos.end()) {
			return NULL;
		}else{
			return got->second;
		}
	}

	std::shared_ptr<Tabela_var_fun_item> procura_var_fun_no_escopo(std::string &nome){
		std::unordered_map<std::string, std::shared_ptr<Tabela_var_fun_item>>::const_iterator got = tabela_var_fun.find(nome);
		if (got == tabela_var_fun.end()) {
			return NULL;
		}else{
			return got->second;
		}
	}
};

//Variaveis globais
std::shared_ptr<Tabela_simbolos> tabela_global(new Tabela_simbolos());
std::shared_ptr<Tabela_simbolos> tabela_atual(tabela_global);


std::shared_ptr<Tabela_tipos_item> procura_tipo(std::string &nome, shared_ptr<Tabela_simbolos> tabela_simbolos){
	std::shared_ptr<Tabela_tipos_item> item = tabela_simbolos->procura_tipo_no_escopo(nome);

	if (item) 
		return item;
	else if(tabela_simbolos->pai) 
		return procura_tipo(nome,tabela_simbolos->pai);
	else 
		return NULL;	
};

std::shared_ptr<Tabela_var_fun_item> procura_var_fun(std::string &nome, shared_ptr<Tabela_simbolos> tabela_simbolos){
	std::shared_ptr<Tabela_var_fun_item> item = tabela_simbolos->procura_var_fun_no_escopo(nome);
	
	if (item) 
		return item;
	else if(tabela_simbolos->pai) 
		return procura_var_fun(nome,tabela_simbolos->pai);
	else 
		return NULL;	
};

void print_erro_semantico(T_no* no, std::string msg){
	std::cout << "Semantic Error: (Linha " << no->linha << ", Coluna " << no->coluna <<") : ";
	std::cout << no->linha_codigo << "\n" << msg << std::endl;
	exit(0);
};

shared_ptr<Tabela_tipos_item> verifica_tipo(T_no* no, std::string nome){
	shared_ptr<Tabela_tipos_item> item(procura_tipo(nome,tabela_atual));
	if (item){
		return item;
	} else {
		std::string msg = nome + "não é um tipo declarado";
		print_erro_semantico(no, msg);
	};
};

shared_ptr<Tabela_var_fun_item> verifica_var_fun(T_no* no, std::string nome){
	shared_ptr<Tabela_var_fun_item> item(procura_var_fun(nome,tabela_atual));
	if (item){
		return item;
	} else {
		std::string msg =  nome + "não é uma variável ou função declarada!";
		print_erro_semantico(no, msg);
	};
};

std::shared_ptr<Tabela_tipos_item> verifica_var(T_no* no, std::string nome){
	shared_ptr<Tabela_var_fun_item> item(verifica_var_fun(no,nome));
	if (item->parametros){
		std::string msg =  nome + " é uma função, não uma variável!";
		print_erro_semantico(no, msg);
	} else {
		return item->tipo;
	};
};

std::shared_ptr<Tabela_tipos_item> verifica_fun(T_no* no, std::string nome){
	shared_ptr<Tabela_var_fun_item> item(verifica_var_fun(no,nome));
	if (item->parametros){
		return item->tipo;
	} else {
		std::string msg =  nome + " é uma variável, não uma função!";
		print_erro_semantico(no, msg);
	};
};

//redeclaração de função para funções escritas acima conseguirem acessar;
std::shared_ptr<Tabela_tipos_item> analisa_exp(std::shared_ptr<T_exp> no);
std::shared_ptr<Tabela_tipos_item> analisa_lvalue(T_lvalue* no);

std::shared_ptr<Tabela_tipos_item> verifica_se_numero(T_no* no,std::shared_ptr<Tabela_tipos_item> tipo_exp){
	if(tipo_exp->tipo == enum_tipo_list::id and 
		(tipo_exp->nome.compare("int") == 0 or tipo_exp->nome.compare("float") == 0 )){
		return tipo_exp;
	}else{
		std::string msg = "A expressão que segue o sinal de '-' deve ser um inteiro ou float, não " +tipo_exp->nome+"!";
		print_erro_semantico(no,msg);
	};
}

std::shared_ptr<Tabela_tipos_item> analisa_lvalue_array(T_lvalue* no){
	std::shared_ptr<Tabela_tipos_item> tipo_exp= analisa_exp(no->exp);		
	if(tipo_exp->nome.compare("int") == 0 and tipo_exp->tipo == enum_tipo_list::id){
		std::shared_ptr<Tabela_tipos_item> tipo_lvalue = analisa_lvalue((no->lvalue).get());
		if(tipo_lvalue->tipo == enum_tipo_list::array){
			return procura_tipo(tipo_lvalue->nome,tabela_atual);
		} else {
			std::string msg = "A variável não é um array!";
			print_erro_semantico(no, msg);
		};
	} else {
		std::string msg = "O valor entre couchetes deve ser inteiro!";
		print_erro_semantico(no, msg);
	};
};

std::shared_ptr<Tabela_tipos_item> analisa_lvalue_rec(T_lvalue* no){
	std::shared_ptr<Tabela_tipos_item> tipo_lvalue = analisa_lvalue((no->lvalue).get());
	if(tipo_lvalue->tipo == enum_tipo_list::rec){
		//verificar se id faz parte de record
		//retornar tipo de id
	}else{
		std::string msg = "A variável não é um record!";
		print_erro_semantico(no, msg);
	};
};

std::shared_ptr<Tabela_tipos_item> analisa_lvalue(T_lvalue* no){
	if (no->exp){
		return analisa_lvalue_array(no);
	}else if(no->lvalue){
		return analisa_lvalue_rec(no);
	}else {
		//É uma variavel
		return verifica_var(no,no->id);			
	};
};

std::shared_ptr<Tabela_tipos_item> analisa_exp_seq(T_exp_seq* no){
	std::shared_ptr<Tabela_tipos_item> tipo_exp;
	for(std::shared_ptr<T_exp> exp: no->exp_seq){
		tipo_exp = analisa_exp(exp);
	}
	return tipo_exp;
};

std::shared_ptr<Tabela_tipos_item> analisa_subunario(T_subunario* no){
	std::shared_ptr<Tabela_tipos_item> tipo_exp= analisa_exp(no->exp);
	return verifica_se_numero(no, tipo_exp);
}

std::shared_ptr<Tabela_tipos_item> analisa_chamada(T_chamada* no){
	std::shared_ptr<Tabela_tipos_item> tipo_fun = verifica_fun(no,no->id);
	//verificar se os parametros batem com assinatura---- exp_list
	return tipo_fun;
};

std::shared_ptr<Tabela_tipos_item> analisa_operacao(T_operacao* no){

/*
	std::shared_ptr<Tabela_tipos_item> eexp_tipo = analisa_exp(no->eexp);
	std::shared_ptr<Tabela_tipos_item> dexp_tipo = analisa_exp(no->dexp);
	if (eexp_tipo.compare(dexp_tipo) != 0){
		std::cout << "Semantic Error: Incompatibilidade de tipos. A expressão à esquerda do operador; "
		std::cout << no->operador << " é do tipo " << eexp_tipo;
		std::cout << ", e a expressão à direita é do tipo " << dexp_tipo << std::endl;
		exit(0);
	} else {
		return eexp_tipo;
	};*/
};

/*
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

void analisa_ty_id(T_ty_id* no,std::shared_ptr<Ts_item_tipo> item){
	shared_ptr<Ts_item> ts_item(procura_ts_item(no->id,ts_atual));
	if (ts_item){
		item->tipo = Ts::tipo_list::tipo_id;
		item->valor_id = no->id;
	} else {
		std::cout << "Semantic Error: "<< no->id << "não é um tipo declarado" << std::endl;
		exit(0);
	};
};

void analisa_ty_rec(T_ty_rec* no,std::shared_ptr<Ts_item_tipo> item){
	item->tipo = Ts::tipo_list::tipo_rec;
	item->valor_rec = no->tyfields;
	analisa_tyfields((no->tyfields).get());
};

void analisa_ty_array(T_ty_array* no, std::shared_ptr<Ts_item_tipo> item){
	shared_ptr<Ts_item> ts_item(procura_ts_item(no->id,ts_atual));
	if (ts_item){
		item->tipo = Ts::ts_list::tipo_array;
		item->valor_id = no->id;
	} else {
		std::cout << "Semantic Error: "<< no->id << "não é um tipo declarado" << std::endl;
		exit(0);
	};
};

void analisa_ty_funfun(T_ty_funfun* no, std::shared_ptr<Ts_item_tipo> item){
	//Criar novo escopo
	std::shared_ptr<Ts> ts_novo(new Ts(ts_atual));
	std::shared_ptr<Ts> ts_atual(ts_novo);
	
	//item->tipo = "tipo_funfun";
	
	if(no->tylist){
		//analisa_tylist((no_ty->tylist).get());
	}else {
		//analisa_ty(no_ty->ty1);
	};
	//analisa_ty(no_ty->ty2);
};

void analisa_ty(std::shared_ptr<T_ty> no, std::shared_ptr<Ts_item_tipo> item){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_id>::element_type*>(no.get())){
		analisa_ty_id(no_ty,item);	
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_rec>::element_type*>(no.get())){
		analisa_ty_rec(no_ty,item);
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_array>::element_type*>(no.get())){
		analisa_ty_array(no_ty,item);
	} if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_funfun>::element_type*>(no.get())){
		analisa_ty_funfun(no_ty, item);	
	} else {
		//erro;
	};
};

void analisa_tydec(){
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
};

void analisa_vardec(T_vardec* no){
	shared_ptr<Ts_item> ts_item1(ts_atual->procura_no_escopo(no->nome));
	if(ts_item1){
		std::cout << "Semantic Error: A variável " << no->nome << " já existe neste escopo!" << std::endl;
		exit(0);
	} else {
		std::shared_ptr<Ts_item_var> item (new Ts_item_var());
		item->nome = no->nome;
		std::string tipo_exp = analisa_exp(no->exp);
		if (!(no->tipo).empty()){
			shared_ptr<Ts_item> ts_item2(procurar_item(no->tipo,ts_atual));
			if (ts_item2){
				item->tipo = no->tipo;
			} else {
				std::cout << "Semantic Error: O tipo " << no->tipo  << " atribuído à variável ";
				std::cout << no->nome << " não existe!" << std::endl;
				exit(0);
			};
			if(tipo_exp.compare(no->tipo) != 0){
				std::cout << "Semantic Error: Incompatibilidade de tipos. O tipo declarado é " << no->tipo;
				std::cout << " e o tipo da expressão é " << tipo_exp << "!"<< std::endl;
			};
		};						
		ts_atual->inserir(item);
	};
};

void analisa_fundec(T_vardec* no){
	//Criar novo escopo
	std::shared_ptr<Ts> ts_novo(new Ts(ts_atual));
	std::shared_ptr<Ts> ts_atual(ts_novo);
	//verifica id id
	analisa_tyfields((no->tyfields).get());
	analisa_exp(no->exp);
};

void analisa_dec(std::shared_ptr<T_dec> no){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_tydec>::element_type*>(no.get())){
		analisa_tydec(no_ty);
	} else if (auto no_var = dynamic_cast<typename std::shared_ptr<T_vardec>::element_type*>(no.get())){
		analisa_vardec(no_var);
	} else if (auto no_fun = dynamic_cast<typename std::shared_ptr<T_fundec>::element_type*>(no.get())){
		analisa_fundec(no_fun);
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

std::string analisa_def_array(T_def_array* no){
	std::shared_ptr<Ts_item> ts_item(procura_item(no_def_array->tipo,ts_atual));
	std::string tipo_exp1;
	std::string tipo_exp2;
	if (ts_item){
		if(ts_item->tipo == Ts::tipo_list::tipo_array){
			tipo_exp1 = analisa_exp(no->exp1);
			if(tipo_exp1.compare("int") == 0){
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
	if (tipo_exp1.compare("int")==0){
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
	if (tipo_exp1.compare("int") == 0){
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
	return analisa_exp_seq((no->exp_seq).get());
};*/

std::shared_ptr<Tabela_tipos_item> analisa_exp(std::shared_ptr<T_exp> no){
	if (auto no_int = dynamic_cast<typename std::shared_ptr<T_int>::element_type*>(no.get())){
		std::string tipo = "int";
		return procura_tipo(tipo,tabela_atual);
	} else if (auto no_float = dynamic_cast<typename std::shared_ptr<T_float>::element_type*>(no.get())){
		std::string tipo = "float";
		return procura_tipo(tipo,tabela_atual);
	} else if (auto no_string = dynamic_cast<typename std::shared_ptr<T_string>::element_type*>(no.get())){
		std::string tipo = "string";
		return procura_tipo(tipo,tabela_atual);
	} else if (auto no_nil = dynamic_cast<typename std::shared_ptr<T_nil>::element_type*>(no.get())){
		std::string tipo = "nil";
		return procura_tipo(tipo,tabela_atual);
	} else if (auto no_lvalue = dynamic_cast<typename std::shared_ptr<T_lvalue>::element_type*>(no.get())){
		return analisa_lvalue(no_lvalue);
	} else if (auto no_exp_seq = dynamic_cast<typename std::shared_ptr<T_exp_seq>::element_type*>(no.get())){
		return analisa_exp_seq(no_exp_seq);
	} else if (auto no_subunario = dynamic_cast<typename std::shared_ptr<T_subunario>::element_type*>(no.get())){
		return analisa_subunario(no_subunario);
	} else if (auto no_chamada = dynamic_cast<typename std::shared_ptr<T_chamada>::element_type*>(no.get())){
		return analisa_chamada(no_chamada);
	} else if (auto no_operacao = dynamic_cast<typename std::shared_ptr<T_operacao>::element_type*>(no.get())){
		return analisa_operacao(no_operacao);
	} else if (auto no_def_array = dynamic_cast<typename std::shared_ptr<T_def_array>::element_type*>(no.get())){
		//return analisa_def_array (no_def_array);
	} else if (auto no_def_rec = dynamic_cast<typename std::shared_ptr<T_def_rec>::element_type*>(no.get())){
		//return analisa_def_rec(no_def_rec);
	} else if (auto no_if_else = dynamic_cast<typename std::shared_ptr<T_if_else>::element_type*>(no.get())){
		//return analisa_if_else(no_if_else);
	} else if (auto no_if = dynamic_cast<typename std::shared_ptr<T_if>::element_type*>(no.get())){
		//return analisa_if(no_if);
	} else if (auto no_let = dynamic_cast<typename std::shared_ptr<T_let>::element_type*>(no.get())){
		//return analisa_let(no_let);
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
