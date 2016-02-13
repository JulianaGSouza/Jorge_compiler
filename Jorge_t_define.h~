#include <memory>
#include <vector>
#include <iostream>

using namespace std;


class T_exp {
public:
	virtual ~T_exp() {}
};

class T_int : public T_exp {
	int n;
public:
	T_int(int n) : n(n){}
};

class T_float : public T_exp {
	float n;
public:
	T_float(float n) : n(n){}
};

class T_string : public T_exp {
	std::string cadeia;
public:
	 T_string (const std::string &cadeia) : cadeia(cadeia) {}
};

class T_nil : public T_exp{
public:
	T_nil() {}
};

class T_dec {
public:
	~T_dec() {}
};

class T_declist {
private:
	std::vector<std::unique_ptr<T_dec>> declist;
public:
	void add(std::unique_ptr<T_dec> dec){
		declist.push_back(std::move(dec));
	}
};

class T_ty {
public:
	~T_ty() {}
};

class T_tydec : public T_dec {
	std::string id;
	std::unique_ptr<T_ty> ty;
public:
	T_tydec(const std::string &id, std::unique_ptr<T_ty> ty) : id(id), ty(std::move(ty)) {}
};

class T_tyfields{
private:
	std::vector<std::string> tyfields;
public:
	void add(std::string id1, std::string id2){
		tyfields.push_back(id1);
		tyfields.push_back(id2);
	}
};

class T_ty_id : public T_ty{
	std::string id;
public:
	T_ty_id(std::string id) : id(id) {}
};

class T_ty_rec : public T_ty {
	std::unique_ptr<T_tyfields> tyfields;
public:
	T_ty_rec(std::unique_ptr<T_tyfields> tyfields) : tyfields(std::move(tyfields)) {}
};

class T_ty_array : public T_ty{
	std::string id;
public:
	T_ty_array(const std::string &id) : id(id){}
};

class T_tylist {
private:
	std::vector<std::unique_ptr<T_ty>> tylist;
public:
	void add(std::unique_ptr<T_ty> ty){
		tylist.push_back(std::move(ty));
	}
};

class T_ty_funfun : public T_ty {
	std::unique_ptr<T_ty> ty1,ty2;
	std::unique_ptr<T_tylist> tylist;
public:
	T_ty_funfun(std::unique_ptr<T_ty> ty1,std::unique_ptr<T_ty> t2)
	: ty1(std::move(ty1)), ty2(std::move(ty2)) {}

	T_ty_funfun(std::unique_ptr<T_tylist> tylist, std::unique_ptr<T_ty> t2)
	: tylist(std::move(tylist)), ty2(std::move(ty2)) {}
};

class T_vardec : public T_dec {
	std::string id1,id2;
	std::unique_ptr<T_exp> exp;
public:
	T_vardec(const std::string &id1, const std::string &id2, std::unique_ptr<T_exp> exp) 
	: id1(id1), id2(id2), exp(std::move(exp)) {}

	T_vardec(const std::string &id, std::unique_ptr<T_exp> exp) 
	: id1(id), exp(std::move(exp)) {}
};

class T_fundec : public T_dec {
	std::string id1, id2;
	std::unique_ptr<T_tyfields> tyfields;
	std::unique_ptr<T_exp> exp;
public:
	T_fundec(const std::string &id1, std::unique_ptr<T_tyfields> tyfields, const std::string &id2, std::unique_ptr<T_exp> exp)
	: id1(id1), tyfields(std::move(tyfields)), id2(id2), exp(std::move(exp)) {}

	T_fundec(const std::string &id1, std::unique_ptr<T_tyfields> tyfields, 
	std::unique_ptr<T_exp> exp) : id1(id1), tyfields(std::move(tyfields)), exp(std::move(exp)) {}		
};

class T_lvalue : public T_exp {
	std::unique_ptr<T_lvalue> lvalue;
	std::string id;
	std::unique_ptr<T_exp> exp;
public:
	T_lvalue(const std::string &id) : id(id){}

	T_lvalue(std::unique_ptr<T_lvalue> lvalue, const std::string &id)
	: lvalue(std::move(lvalue)), id(id){}

	T_lvalue(std::unique_ptr<T_lvalue> lvalue, std::unique_ptr<T_exp> exp)
	: lvalue(std::move(lvalue)), exp(std::move(exp)){}
};

class T_operacao : public T_exp {
	std::string op;
 	std::unique_ptr<T_exp> eexp,dexp;
public:
	T_operacao(const std::string op, std::unique_ptr<T_exp> expe, std::unique_ptr<T_exp> expd)
	: op(op), eexp(std::move(expe)), dexp(std::move(dexp)) {}
};

class T_exp_list{
private:
	std::vector<std::unique_ptr<T_exp>> exp_list;
public:
	void add(std::unique_ptr<T_exp> exp){
		exp_list.push_back(std::move(exp));
	}
};

class T_chamada : public T_exp {
	std::string id;
	std::unique_ptr<T_exp_list> exp_list;
	std::unique_ptr<T_exp> exp;
public:
	T_chamada(const std::string &id, std::unique_ptr<T_exp_list> exp_list)
	: id(id), exp_list(std::move(exp_list)) {}

	T_chamada(std::unique_ptr<T_exp> exp, std::unique_ptr<T_exp_list> exp_list)
	: exp(std::move(exp)), id(id), exp_list(std::move(exp_list)) {}
};

class T_exp_seq : public T_exp { 
private:
	std::vector<std::unique_ptr<T_exp>> exp_seq;
public:
	void add(std::unique_ptr<T_exp> exp){
		exp_seq.push_back(std::move(exp));
	}
};

class T_enum_it {	
	std::string id;
	std::unique_ptr<T_exp> exp;
public:
	T_enum_it(const std::string &id, std::unique_ptr<T_exp> exp) 
	: id(id), exp(std::move(exp)) {}
};

class T_rec_enum {	
private:
	std::vector<std::unique_ptr<T_enum_it>> rec_enum;
public:
	void add(std::unique_ptr<T_enum_it> enum_it){
		rec_enum.push_back(std::move(enum_it));
	}
};

class T_def_rec : public T_exp{
	std::string tipo;
	std::unique_ptr<T_rec_enum> rec_enum;
public:
	T_def_rec(const std::string &id, std::unique_ptr<T_rec_enum> rec_enum)
	: tipo(id), rec_enum(std::move(rec_enum)) {}
};

class T_def_array : public T_exp{
	std::string tipo;
	std::unique_ptr<T_exp> exp1,exp2;
public:
	T_def_array(const std::string &id,std::unique_ptr<T_exp> exp1,std::unique_ptr<T_exp> exp2)
	: tipo(id), exp1(std::move(exp1)),exp2(std::move(exp2)) {}
};

class T_subunario : public T_exp {
	std::unique_ptr<T_exp> exp;
public:
	T_subunario(std::unique_ptr<T_exp> exp) : exp(std::move(exp)) {}
};

class T_if : public T_exp {
	std::unique_ptr<T_exp> exp1,exp2;
public:
	T_if(std::unique_ptr<T_exp> exp1, std::unique_ptr<T_exp> exp2) 
	: exp1(std::move(exp1)),exp2(std::move(exp2)) {}
};

class T_if_else : public T_exp {
	std::unique_ptr<T_exp> exp1,exp2,exp3;
public:
	T_if_else(std::unique_ptr<T_exp> exp1, std::unique_ptr<T_exp> exp2,std::unique_ptr<T_exp> exp3) 
	: exp1(std::move(exp1)),exp2(std::move(exp2)),exp3(std::move(exp3)) {}
};

class T_let : public T_exp {
	std::unique_ptr<T_declist> declist;
	std::unique_ptr<T_exp_seq> exp_seq;
public:
	T_let(std::unique_ptr<T_declist> declist, std::unique_ptr<T_exp_seq> exp_seq) 
	: declist(std::move(declist)), exp_seq(std::move(exp_seq)) {}
};
