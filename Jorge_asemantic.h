#include <iostream>
#include <memory>
#include <vector>
#include <map>

using namespace std;

#include "Jorge_funcoes_primitivas.h"

enum enum_tipo_list {id,rec,array,funcao, funcional};

class Tabela_tipos_item{
public:
	enum_tipo_list tipo;
	std::string nome;
	std::shared_ptr<Tabela_tipos_item> tipo_relacionado;
	std::map<std::string,std::shared_ptr<Tabela_tipos_item>> enum_rec;
	std::vector<std::shared_ptr<Tabela_tipos_item>> lista_tipos_fun;
	
	Tabela_tipos_item() {}

	Tabela_tipos_item(std::string nome) 
	: nome(nome) {}

	Tabela_tipos_item(enum_tipo_list tipo, std::string nome) 
	: tipo(tipo), nome(nome) {}
};

class Parametro{
public:
	std::string nome;
	std::shared_ptr<Tabela_tipos_item> tipo;

	Parametro(std::string nome, std::shared_ptr<Tabela_tipos_item> tipo)
	: nome(nome), tipo(tipo){}
};

class Tabela_var_fun_item{
public:
	std::string nome;
	std::vector<std::shared_ptr<Parametro>> parametros;
	std::shared_ptr<Tabela_tipos_item> tipo;

	Tabela_var_fun_item(std::string nome) : nome(nome) {}
};

class Tabela_simbolos {
public:
	std::map<std::string, std::shared_ptr<Tabela_tipos_item>> tabela_tipos;
	std::map<std::string, std::shared_ptr<Tabela_var_fun_item>> tabela_var_fun;
	std::shared_ptr<Tabela_simbolos> pai;

	Tabela_simbolos() {}

	Tabela_simbolos(std::shared_ptr<Tabela_simbolos> pai) : pai(pai){}	
	
	void inserir_tipo(std::shared_ptr<Tabela_tipos_item> item){
		std::pair<std::string,std::shared_ptr<Tabela_tipos_item>> par (item->nome,item);
		tabela_tipos.insert(par);
	}

	void inserir_var_fun(std::shared_ptr<Tabela_var_fun_item> item){
		std::pair<std::string,std::shared_ptr<Tabela_var_fun_item>> par (item->nome,item);
		tabela_var_fun.insert(par);
	}

	std::shared_ptr<Tabela_tipos_item> procura_tipo_no_escopo(std::string &nome){
		auto got = tabela_tipos.find(nome);
		if (got == tabela_tipos.end()) {
			return NULL;
		}else{
			return got->second;
		}
	}

	std::shared_ptr<Tabela_var_fun_item> procura_var_fun_no_escopo(std::string &nome){
		auto got = tabela_var_fun.find(nome);
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

std::shared_ptr<Tabela_tipos_item> procura_tipo(std::string &nome, shared_ptr<Tabela_simbolos> tabela_simbolos = tabela_atual){
	std::shared_ptr<Tabela_tipos_item> item = tabela_simbolos->procura_tipo_no_escopo(nome);

	if (item) 
		return item;
	else if(tabela_simbolos->pai) 
		return procura_tipo(nome,tabela_simbolos->pai);
	else 
		return NULL;	
};

std::shared_ptr<Tabela_var_fun_item> procura_var_fun(std::string &nome, shared_ptr<Tabela_simbolos> tabela_simbolos = tabela_atual){
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
	shared_ptr<Tabela_tipos_item> item(procura_tipo(nome));
	if (item){
		return item;
	} else {
		std::string msg = nome + " não é um tipo declarado";
		print_erro_semantico(no, msg);
	};
};

shared_ptr<Tabela_var_fun_item> verifica_var_fun(T_no* no, std::string nome){
	shared_ptr<Tabela_var_fun_item> item(procura_var_fun(nome));
	if (item){
		return item;
	} else {
		std::string msg =  nome + " não é uma variável ou função declarada!";
		print_erro_semantico(no, msg);
	};
};

std::shared_ptr<Tabela_tipos_item> verifica_var(T_no* no, std::string nome){
	shared_ptr<Tabela_var_fun_item> item(verifica_var_fun(no,nome));
	if ((item->parametros).empty()){
		return item->tipo;		
	} else {
		std::string msg =  nome + " é uma função, não uma variável!";
		print_erro_semantico(no, msg);
	};
};

std::shared_ptr<Tabela_var_fun_item> verifica_fun(T_no* no, std::string nome){
	std::shared_ptr<Tabela_var_fun_item> item(verifica_var_fun(no,nome));
	if ((item->parametros).empty()){
		std::string msg =  nome + " é uma variável, não uma função!";
		print_erro_semantico(no, msg);
	} else {
		return item;
	};
};

//redeclaração de função para funções escritas acima conseguirem acessar;
std::shared_ptr<Tabela_tipos_item> analisa_exp(std::shared_ptr<T_exp> no);
std::shared_ptr<Tabela_tipos_item> analisa_lvalue(T_lvalue* no);
void analisa_ty(std::shared_ptr<T_ty> no, std::shared_ptr<Tabela_tipos_item> novo_tipo);

std::shared_ptr<Tabela_tipos_item> analisa_lvalue_array(T_lvalue* no){
	std::shared_ptr<Tabela_tipos_item> tipo_exp= analisa_exp(no->exp);		
	if(tipo_exp->nome.compare("int") == 0 and tipo_exp->tipo == enum_tipo_list::id){
		std::shared_ptr<Tabela_tipos_item> tipo_lvalue = analisa_lvalue((no->lvalue).get());
		if(tipo_lvalue->tipo != enum_tipo_list::array){
			std::string msg = "A variável não é um array!";
			print_erro_semantico(no, msg);		
		};
		
		return tipo_lvalue->tipo_relacionado;
	} else {
		std::string msg = "O valor entre colchetes deve ser inteiro!";
		print_erro_semantico(no, msg);
	};
};

std::shared_ptr<Tabela_tipos_item> analisa_lvalue_rec(T_lvalue* no){
	std::shared_ptr<Tabela_tipos_item> tipo_lvalue = analisa_lvalue((no->lvalue).get());
	if(tipo_lvalue->tipo != enum_tipo_list::rec){
		std::string msg = "A variável não é um record!";
		print_erro_semantico(no, msg);
	};		

	auto tyfields = tipo_lvalue->enum_rec;

	auto got = tyfields.find(no->id);
	if (got == tyfields.end()) {
		std::string msg = "O campo "+no->id+" não pertence ao record";
		print_erro_semantico(no,msg);
	};

	return got->second;
};

std::shared_ptr<Tabela_tipos_item> analisa_lvalue(T_lvalue* no){
	if (no->exp){
		return analisa_lvalue_array(no);
	}else if(no->lvalue){
		return analisa_lvalue_rec(no);
	}else {
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
	if(tipo_exp->tipo == enum_tipo_list::id and 
		(tipo_exp->nome.compare("int") == 0 or tipo_exp->nome.compare("float") == 0 )){
		return tipo_exp;
	}else{
		std::string msg = "A expressão que segue o sinal de '-' deve ser um inteiro ou float, não " +tipo_exp->nome+"!";
		print_erro_semantico(no,msg);
	};
}

std::shared_ptr<Tabela_tipos_item> analisa_chamada(T_chamada* no){
	std::shared_ptr<Tabela_var_fun_item> fun = verifica_fun(no,no->id);

	std::vector<std::shared_ptr<T_exp>> exp_list = no->parametros->exp_list;

	for(int i = 0; i = exp_list.size();i++){
		std::shared_ptr<Tabela_tipos_item> tipo_exp = analisa_exp(exp_list[i]);
		if(tipo_exp != fun->parametros[i]->tipo){
			std::string msg = "O parametro "+std::to_string(i)+" deve ser do tipo "
				+fun->parametros[i]->tipo->nome+" e não do tipo "+tipo_exp->nome+"!";
			print_erro_semantico(no, msg);
		};
	};

	return fun->tipo;
};

std::shared_ptr<Tabela_tipos_item> analisa_if(T_if* no){
	std::shared_ptr<Tabela_tipos_item> tipo_exp1 = analisa_exp(no->exp1);
	if (tipo_exp1->nome.compare("int") != 0){
		std:string msg = "A expressão após 'IF' deve possuir um valor inteiro, não " +tipo_exp1->nome +"!";
		print_erro_semantico(no,msg);
	};
		
	std::shared_ptr<Tabela_tipos_item> tipo_exp2 = analisa_exp(no->exp2);
	if(no->exp3){
		std::shared_ptr<Tabela_tipos_item> tipo_exp3 = analisa_exp(no->exp3);
		if (tipo_exp2 != tipo_exp3){
			std::string msg = "Tipos incompatíveis. O tipo da expressão após 'THEN' é " + tipo_exp2->nome +
				" e o tipo da expressão após 'ELSE' é " + tipo_exp3->nome + "!";
			print_erro_semantico(no,msg);
		};
	};
	std::string tipo_retorno = "nil";
	return procura_tipo(tipo_retorno);
};

void analisa_ty_id(T_ty_id* no, std::shared_ptr<Tabela_tipos_item> novo_tipo){
	std::shared_ptr<Tabela_tipos_item> tipo_relacionado = verifica_tipo(no,no->id);
	novo_tipo->tipo = enum_tipo_list::id;
	novo_tipo->tipo_relacionado = tipo_relacionado;
};

void analisa_ty_rec(T_ty_rec* no, std::shared_ptr<Tabela_tipos_item> novo_tipo){
	novo_tipo->tipo = enum_tipo_list::rec;

	for (auto it = (no->tyfields->tyfields).begin(); 
		it != (no->tyfields->tyfields).end(); ++it){ 

		std::string tipo_item_name = it->second;
		std::shared_ptr<Tabela_tipos_item> tipo_item =  verifica_tipo(no,tipo_item_name);		
		std::pair<std::string,std::shared_ptr<Tabela_tipos_item>> par (it->first,tipo_item);
		(novo_tipo->enum_rec).insert(par); 
	};
};

void analisa_ty_array(T_ty_array* no, std::shared_ptr<Tabela_tipos_item> novo_tipo){
	std::shared_ptr<Tabela_tipos_item> tipo_relacionado = verifica_tipo(no,no->id);
	novo_tipo->tipo = enum_tipo_list::array;
	novo_tipo->tipo_relacionado = tipo_relacionado;
};

void analisa_ty_funfun(T_ty_funfun* no, std::shared_ptr<Tabela_tipos_item> novo_tipo){
	novo_tipo->tipo = enum_tipo_list::funcional;

	std::shared_ptr<Tabela_tipos_item> novo_tipo_fun;
	if(no->tylist){
		for(std::shared_ptr<T_ty> ty : no->tylist->tylist){
			novo_tipo_fun  = std::shared_ptr<Tabela_tipos_item>(new Tabela_tipos_item());
			analisa_ty(ty,novo_tipo_fun);
			(novo_tipo->lista_tipos_fun).push_back(novo_tipo_fun);
		};
	}else {
		novo_tipo_fun  = std::shared_ptr<Tabela_tipos_item>(new Tabela_tipos_item());
		analisa_ty(no->ty1,novo_tipo_fun);
		(novo_tipo->lista_tipos_fun).push_back(novo_tipo_fun);
	};

	novo_tipo_fun = std::shared_ptr<Tabela_tipos_item>(new Tabela_tipos_item());
	analisa_ty(no->ty2,novo_tipo_fun);
	novo_tipo->tipo_relacionado = novo_tipo_fun;
};

void analisa_ty(std::shared_ptr<T_ty> no, std::shared_ptr<Tabela_tipos_item> novo_tipo){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_id>::element_type*>(no.get())){
		analisa_ty_id(no_ty, novo_tipo);	
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_rec>::element_type*>(no.get())){
		analisa_ty_rec(no_ty,novo_tipo);
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_array>::element_type*>(no.get())){
		analisa_ty_array(no_ty,novo_tipo);
	} if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_funfun>::element_type*>(no.get())){
		analisa_ty_funfun(no_ty, novo_tipo);	
	};
};

void analisa_tydec(T_tydec* no){
	std::shared_ptr<Tabela_tipos_item> item = tabela_atual->procura_tipo_no_escopo(no->id);

	if(item){
		std::string msg = "O tipo " + no->id + " já existe neste escopo!";
		print_erro_semantico(no,msg);
	};

	std::shared_ptr<Tabela_tipos_item> novo_tipo (new Tabela_tipos_item(no->id));
	tabela_atual->inserir_tipo(novo_tipo);
	analisa_ty(no->ty,novo_tipo);
};

void analisa_vardec(T_vardec* no){
	std::shared_ptr<Tabela_var_fun_item> item = tabela_atual->procura_var_fun_no_escopo(no->nome);
	if(item){
		std::string msg = no->nome +" já existe neste escopo!";
		print_erro_semantico(no,msg);
	};
	
	std::shared_ptr<Tabela_var_fun_item> nova_var (new Tabela_var_fun_item(no->nome));

	std::shared_ptr<Tabela_tipos_item> tipo_exp = analisa_exp(no->exp);

	if (!(no->tipo).empty()){
		std::shared_ptr<Tabela_tipos_item> tipo_relacionado = verifica_tipo(no,no->tipo);
		nova_var->tipo = tipo_relacionado;

		if(tipo_exp != tipo_relacionado){
			std::string msg = "Incompatibilidade de tipos. O tipo declarado é " + 
				tipo_relacionado->nome +" e o tipo da expressão é " + tipo_exp->nome + "!";
			print_erro_semantico(no, msg);
		};
	} else {
		nova_var->tipo = tipo_exp;
	};						

	tabela_atual->inserir_var_fun(nova_var);
};

void insere_parametros_no_escopo(std::shared_ptr<Tabela_var_fun_item> nova_fun){
	for(std::shared_ptr<Parametro> p: nova_fun->parametros){
		std::shared_ptr<Tabela_var_fun_item> nova_var (new Tabela_var_fun_item(p->nome));
		nova_var->tipo = p->tipo;
		tabela_atual->inserir_var_fun(nova_var);
	};

};

void insere_tipo_retorno_fun(T_fundec* no, std::shared_ptr<Tabela_var_fun_item> nova_fun){
	std::shared_ptr<Tabela_tipos_item> tipo_exp = analisa_exp(no->exp);
	if (!(no->tipo).empty()){
		std::shared_ptr<Tabela_tipos_item> tipo_relacionado = verifica_tipo(no,no->tipo);
		nova_fun->tipo = tipo_relacionado;

		if(tipo_exp != tipo_relacionado){
			std::string msg = "Incompatibilidade de tipos. O tipo declarado é " + 
				tipo_relacionado->nome +" e o tipo retornado é " + tipo_exp->nome + "!";
			print_erro_semantico(no, msg);
		};
	} else {
		std::string tipo_nil = "nil";
		nova_fun->tipo = procura_tipo(tipo_nil);
	};
};

void insere_parametros_fun(T_fundec* no, std::shared_ptr<Tabela_var_fun_item> nova_fun){
	for (auto it = (no->tyfields->tyfields).begin(); 
		it != (no->tyfields->tyfields).end(); ++it){ 

		std::string tipo_item_name = it->second;
		std::shared_ptr<Tabela_tipos_item> tipo_item =  verifica_tipo(no,tipo_item_name);

		(nova_fun->parametros).push_back(std::shared_ptr<Parametro>(new Parametro(it->first,tipo_item))); 
	};
};

void analisa_fundec(T_fundec* no){
	std::shared_ptr<Tabela_var_fun_item> item = tabela_atual->procura_var_fun_no_escopo(no->nome);
	if(item){
		std::string msg = no->nome +" já existe neste escopo!";
		print_erro_semantico(no,msg);
	};
	
	std::shared_ptr<Tabela_var_fun_item> nova_fun (new Tabela_var_fun_item(no->nome));
	
	insere_parametros_fun(no,nova_fun);

	//adiciona função ao escopo atual
	tabela_atual->inserir_var_fun(nova_fun);

	//Criar novo escopo
	tabela_atual = std::shared_ptr<Tabela_simbolos>(new Tabela_simbolos(tabela_atual));
	insere_parametros_no_escopo(nova_fun);

	//analisa o conteudo da funcao e o retorno
	insere_tipo_retorno_fun(no, nova_fun);

	//destroi escopo??
	Tabela_simbolos aux = tabela_atual;
	tabela_atual = tabela_atual->pai;
};

void analisa_dec(std::shared_ptr<T_dec> no){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_tydec>::element_type*>(no.get())){
		analisa_tydec(no_ty);
	} else if (auto no_var = dynamic_cast<typename std::shared_ptr<T_vardec>::element_type*>(no.get())){
		analisa_vardec(no_var);
	} else if (auto no_fun = dynamic_cast<typename std::shared_ptr<T_fundec>::element_type*>(no.get())){
		analisa_fundec(no_fun);
	};
};

void analisa_declist(std::shared_ptr<T_declist> no){
	std::vector<std::shared_ptr<T_dec>> declist (no->declist);
	for(std::shared_ptr<T_dec> dec: declist){
		analisa_dec(dec);
	};
};

std::shared_ptr<Tabela_tipos_item> analisa_let(T_let* no){
	tabela_atual = std::shared_ptr<Tabela_simbolos>(new Tabela_simbolos(tabela_atual));

	analisa_declist(no->declist);
	return analisa_exp_seq((no->exp_seq).get());
};

std::shared_ptr<Tabela_tipos_item> analisa_def_array(T_def_array* no){
	std::shared_ptr<Tabela_tipos_item> tipo_relacionado = verifica_tipo(no,no->tipo);

	if(tipo_relacionado->tipo != enum_tipo_list::array){
		std::string msg = "O tipo " + no->tipo +" não é um array!";
		print_erro_semantico(no,msg);
	};

	std::shared_ptr<Tabela_tipos_item> tipo_exp1 = analisa_exp(no->exp1);
	if (tipo_exp1->nome.compare("int") != 0){
		std:string msg = "A expressão entre colchetes deve possuir um valor inteiro, não "+ tipo_exp1->nome+"!";
		print_erro_semantico(no,msg);
	};

	std::shared_ptr<Tabela_tipos_item> tipo_exp2 = analisa_exp(no->exp2);
	if(tipo_exp2 != tipo_relacionado->tipo_relacionado){
		std::string msg = "O valor de inicialização deve possuir o mesmo tipo do array: "+tipo_relacionado->tipo_relacionado->nome +
			", mas possui o tipo " + tipo_exp2->nome + "!";
		print_erro_semantico(no,msg);
	};

	return tipo_relacionado;
};

std::shared_ptr<Tabela_tipos_item> analisa_def_rec(T_def_rec* no){
	std::shared_ptr<Tabela_tipos_item> tipo_relacionado = verifica_tipo(no,no->tipo);

	if(tipo_relacionado->tipo != enum_tipo_list::rec){
		std::string msg = "O tipo " + no->tipo +" não é record!";
		print_erro_semantico(no,msg);
	};

	for(std::shared_ptr<T_enum_it> it : no->rec_enum->rec_enum){
		auto got = tipo_relacionado->enum_rec.find(it->id);
		if (got == tipo_relacionado->enum_rec.end()) {
			std::string msg = "O campo "+it->id+" não pertence ao record";
			print_erro_semantico(no,msg);
		};
		
		std::shared_ptr<Tabela_tipos_item> tipo_exp = analisa_exp(it->exp);
		
		if(got->second != tipo_exp){
			std::string msg = "O campo "+it->id+" é do tipo "+got->second->nome+
				"e está recebendo um valor do tipo "+tipo_exp->nome;
			print_erro_semantico(no,msg);
		};
	};
	return tipo_relacionado;
};

std::shared_ptr<Tabela_tipos_item> analisa_operacao(T_operacao* no){
	std::shared_ptr<Tabela_tipos_item> eexp_tipo = analisa_exp(no->eexp);
	std::shared_ptr<Tabela_tipos_item> dexp_tipo = analisa_exp(no->dexp);
	if (eexp_tipo != dexp_tipo){
		std::string msg = "Incompatibilidade de tipos. A expressão à esquerda do operador; " + no->operador +
			" é do tipo " + eexp_tipo->nome+ ", e a expressão à direita é do tipo "+dexp_tipo->nome;
		print_erro_semantico(no,msg);
	}

	if((eexp_tipo->nome).compare("int") == 0){
		return eexp_tipo;
	}

	if(no->operador.compare(">") == 0 or
		no->operador.compare(">=") == 0 or 
		no->operador.compare("<") == 0 or 
		no->operador.compare("<+") == 0 or
		no->operador.compare("&") == 0 or 
		no->operador.compare("|") == 0){

		std::string msg = "As expressões usadas com o operador "+no->operador+
			" devem ser do tipo inteiro, não "+eexp_tipo->nome+"!";
		print_erro_semantico(no,msg);
	};

	if(no->operador.compare("+") == 0 or 
		no->operador.compare("-") == 0 or
		no->operador.compare("*") == 0 or
		no->operador.compare("/") == 0){

		if((eexp_tipo->nome).compare("float") == 0){
			return eexp_tipo;
		} else {
			std::string msg = "As expressões usadas com o operador "+no->operador+
			" devem ser do tipo inteiro ou float, não "+eexp_tipo->nome+"!";
			print_erro_semantico(no,msg);
		};
	};

	if(no->operador.compare("=") == 0 or 
		no->operador.compare("<>") == 0){
		return eexp_tipo;
	};
};

std::shared_ptr<Tabela_tipos_item> analisa_exp(std::shared_ptr<T_exp> no){
	if (auto no_int = dynamic_cast<typename std::shared_ptr<T_int>::element_type*>(no.get())){
		std::string tipo = "int";
		return procura_tipo(tipo);
	} else if (auto no_float = dynamic_cast<typename std::shared_ptr<T_float>::element_type*>(no.get())){
		std::string tipo = "float";
		return procura_tipo(tipo);
	} else if (auto no_string = dynamic_cast<typename std::shared_ptr<T_string>::element_type*>(no.get())){
		std::string tipo = "string";
		return procura_tipo(tipo);
	} else if (auto no_nil = dynamic_cast<typename std::shared_ptr<T_nil>::element_type*>(no.get())){
		std::string tipo = "nil";
		return procura_tipo(tipo);
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
		return analisa_def_array (no_def_array);
	} else if (auto no_def_rec = dynamic_cast<typename std::shared_ptr<T_def_rec>::element_type*>(no.get())){
		return analisa_def_rec(no_def_rec);
	} else if (auto no_if = dynamic_cast<typename std::shared_ptr<T_if>::element_type*>(no.get())){
		return analisa_if(no_if);
	} else if (auto no_let = dynamic_cast<typename std::shared_ptr<T_let>::element_type*>(no.get())){
		return analisa_let(no_let);
	};
};

void inicializa(){
	std::shared_ptr<Tabela_tipos_item> tipo_nil(new Tabela_tipos_item(enum_tipo_list::id,"nil"));
	tabela_atual->inserir_tipo(tipo_nil);

	std::shared_ptr<Tabela_tipos_item> tipo_int(new Tabela_tipos_item(enum_tipo_list::id,"int"));
	tabela_atual->inserir_tipo(tipo_int);
	
	std::shared_ptr<Tabela_tipos_item> tipo_float(new Tabela_tipos_item(enum_tipo_list::id,"float"));
	tabela_atual->inserir_tipo(tipo_float);

	std::shared_ptr<Tabela_tipos_item> tipo_string(new Tabela_tipos_item(enum_tipo_list::id,"string"));
	tabela_atual->inserir_tipo(tipo_string);

	//Funções primitivas: print, flush, getchar, ord, chr, size, substring, concat, not, exit
};

void semantico(std::shared_ptr<T_exp> raiz){
	inicializa();
	analisa_exp(raiz);

};
