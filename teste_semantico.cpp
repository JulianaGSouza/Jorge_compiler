
#include "Jorge_t_define.h"
#include "Jorge_asemantic.h"
#include "Jorge_print_arvore.h"

/* um tipo array e uma variável array */
/*let
	type  arrtype = array of int
	var arr1:arrtype := arrtype [10] of 0
in
	arr1
end*/


int main(void){
	std::shared_ptr<T_exp> raiz = std::shared_ptr<T_exp>(new T_exp()); 
	raiz->set_localizacao(1,1,"let");
		
	T_ty* ty = new T_ty_array(std::string("int"));
	ty->set_localizacao(1,1,"type  arrtype = array of int");

	T_dec* dec1 = new T_tydec(std::string("arrtype"),std::shared_ptr<T_ty>(ty));
	dec1->set_localizacao(2,2,"type  arrtype = array of int");
	
	T_exp* exp1 = new T_int(10); 
	exp1->set_localizacao(3,20,"arrtype [10] of 0");

	T_exp* exp2 = new T_int(0); 
	exp2->set_localizacao(3,20,"arrtype [10] of 0");

	T_exp* exp =new T_def_array(std::string("arrtype"),std::shared_ptr<T_exp>(exp1),std::shared_ptr<T_exp>(exp2));
	exp->set_localizacao(3,3,"arrtype [10] of 0");

	T_dec* dec2 = new T_vardec(std::string("arr1"),std::string("arrtype"),std::shared_ptr<T_exp>(exp));
	dec2->set_localizacao(3,3,"var arr1:arrtype := arrtype [10] of 0");

	T_declist* declist = new T_declist(); 
	declist->set_localizacao(1,1,"type  arrtype = array of int");	
	declist->add(std::shared_ptr<T_dec>(dec1));
	declist->add(std::shared_ptr<T_dec>(dec2));

	T_exp* exp3 = new T_lvalue(std::string("arr1"));
	exp->set_localizacao(5,5,"arr1");

	T_exp_seq* exp_in = new T_exp_seq(); 
	exp_in->add(std::shared_ptr<T_exp>(exp3));
	exp_in->set_localizacao(5,5,"arr1");

	raiz = std::shared_ptr<T_exp>(new T_let(std::shared_ptr<T_declist>(declist),std::shared_ptr<T_exp_seq>(exp_in)));
	raiz->set_localizacao(6,1,"end");

	semantico(raiz);
	print_arvore(raiz);
};
