std::string print_exp(std::shared_ptr<T_exp> no);
std::string print_ty(std::shared_ptr<T_ty> no);

std::string print_lvalue(T_lvalue* no){
	std::string inter = "";
	
	if (no->exp) inter = " " + print_lvalue((no->lvalue).get()) + " [ "+ print_exp(no->exp) +" ]";
	else if(no->lvalue) inter = " " + print_lvalue((no->lvalue).get())+ "."+no->id;
	else inter = no->id;			
	
	return "T_lvalue ( " + inter + " )";
};

std::string print_exp_seq(T_exp_seq* no){
	std::string lista = "";
	for(std::shared_ptr<T_exp> exp: no->exp_seq)
		lista += print_exp(exp) + " ; ";
	return lista;
};

std::string print_chamada(T_chamada* no){
	std::string lista = "";
	std::vector<std::shared_ptr<T_exp>> exp_list = no->parametros->exp_list;
	for(int i = 0; i = exp_list.size();i++)
		lista+=print_exp(exp_list[i]) + " ";

	return "T_chamada ( "+no->id+" ( "+ lista+" ) )";
};

std::string print_if(T_if* no){
	std::string else_exp = "";

	if(no->exp3) else_exp = " ELSE "+print_exp(no->exp3)+" ";

	return "T_if (IF " + print_exp(no->exp1) + " THEN "+ print_exp(no->exp2) + else_exp+" )";
};

std::string print_ty_rec(T_ty_rec* no){
	std::string lista;
	for (auto it = (no->tyfields->tyfields).begin(); 
		it != (no->tyfields->tyfields).end(); ++it){ 

		lista+= it->first +":"+it->second+", ";
	};

	return " { "+lista+" }";
};

std::string print_ty_funfun(T_ty_funfun* no){
	std::string lista;
	if(no->tylist){
		lista = " ( ";
		for(std::shared_ptr<T_ty> ty : no->tylist->tylist){
			lista += print_ty(ty)+", ";
		};
		lista += " ) ";
	} else 	lista = print_ty(no->ty1);

	return lista +" -> "+print_ty(no->ty2);
};

std::string print_ty(std::shared_ptr<T_ty> no){
	std::string inter;
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_id>::element_type*>(no.get())){
		inter = no_ty->id;	
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_rec>::element_type*>(no.get())){
		inter = print_ty_rec(no_ty);
	} else if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_array>::element_type*>(no.get())){
		inter = "ARRAY OF "+no_ty->id;
	} if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_ty_funfun>::element_type*>(no.get())){
		inter = print_ty_funfun(no_ty);	
	};

	return "T_ty ( "+inter + " ) ";
};

std::string print_vardec(T_vardec* no){
	std::string tipo;

	if (!(no->tipo).empty()) tipo = "";
	else tipo = " : "+no->tipo+" ";					
	
	return "T_vardec (VAR "+no->nome+tipo+" := "+print_exp(no->exp)+" )";
};

std::string print_fundec(T_fundec* no){
	std::string tipo;
	if (!(no->tipo).empty()) tipo = "";
	else tipo = " : "+no->tipo+" ";
	
	std::string lista = "";
	for (auto it = (no->tyfields->tyfields).begin(); 
		it != (no->tyfields->tyfields).end(); ++it){ 
		
		lista += it->first + ":"+ it->second + ", "; 
	};

	return "T_fundec ( FUNCTION "+no->tipo+" '(' "+lista+" ') '"+ tipo +print_exp(no->exp)+" )";
};

std::string print_dec(std::shared_ptr<T_dec> no){
	if (auto no_ty = dynamic_cast<typename std::shared_ptr<T_tydec>::element_type*>(no.get())){
		return "T_tydec ( TYPE "+no_ty->id+" = "+print_ty(no_ty->ty)+" )";
	} else if (auto no_var = dynamic_cast<typename std::shared_ptr<T_vardec>::element_type*>(no.get())){
		return print_vardec(no_var);
	} else if (auto no_fun = dynamic_cast<typename std::shared_ptr<T_fundec>::element_type*>(no.get())){
		return print_fundec(no_fun);
	};
};

std::string print_declist(std::shared_ptr<T_declist> no){
	std::string lista = " ";
	std::vector<std::shared_ptr<T_dec>> declist (no->declist);
	for(std::shared_ptr<T_dec> dec: declist)
		lista += print_dec(dec) +" ";
	return lista;
};

std::string print_def_rec(T_def_rec* no){
	std::string lista = "";
	for(std::shared_ptr<T_enum_it> it : no->rec_enum->rec_enum)
		lista += it->id + " = " + print_exp(it->exp) + ", ";

	return "T_def_rec ( "+ no->tipo+" { "+ lista +"} )";
};

std::string print_exp(std::shared_ptr<T_exp> no){
	std::string inter;

	if (auto no_int = dynamic_cast<typename std::shared_ptr<T_int>::element_type*>(no.get())){
		inter = "T_int( "+std::to_string(no_int->n)+" )";
	} else if (auto no_float = dynamic_cast<typename std::shared_ptr<T_float>::element_type*>(no.get())){
		inter = "T_float( "+std::to_string(no_float->n)+" )";;
	} else if (auto no_string = dynamic_cast<typename std::shared_ptr<T_string>::element_type*>(no.get())){
		inter = "T_string( "+no_string->cadeia+" )";
	} else if (auto no_nil = dynamic_cast<typename std::shared_ptr<T_nil>::element_type*>(no.get())){
		inter = "nil";
	} else if (auto no_lvalue = dynamic_cast<typename std::shared_ptr<T_lvalue>::element_type*>(no.get())){
		inter = print_lvalue(no_lvalue);
	} else if (auto no_exp_seq = dynamic_cast<typename std::shared_ptr<T_exp_seq>::element_type*>(no.get())){
		inter = print_exp_seq(no_exp_seq);
	} else if (auto no_subunario = dynamic_cast<typename std::shared_ptr<T_subunario>::element_type*>(no.get())){
		inter = "T_m_unario( "+print_exp(no_subunario->exp)+" )";
	} else if (auto no_chamada = dynamic_cast<typename std::shared_ptr<T_chamada>::element_type*>(no.get())){
		inter = print_chamada(no_chamada);
	} else if (auto no_operacao = dynamic_cast<typename std::shared_ptr<T_operacao>::element_type*>(no.get())){
		inter =  "T_operacao ( "+ print_exp(no_operacao->eexp) + no_operacao->operador + print_exp(no_operacao->dexp) +" )";
	} else if (auto no_def_array = dynamic_cast<typename std::shared_ptr<T_def_array>::element_type*>(no.get())){
		inter = "T_def_array ( "+ no_def_array->tipo 
			+" [ "+print_exp(no_def_array->exp1)+" ] OF "+print_exp(no_def_array->exp2)+" ) ";
	} else if (auto no_def_rec = dynamic_cast<typename std::shared_ptr<T_def_rec>::element_type*>(no.get())){
		inter = print_def_rec(no_def_rec);
	} else if (auto no_if = dynamic_cast<typename std::shared_ptr<T_if>::element_type*>(no.get())){
		inter = print_if(no_if);
	} else if (auto no_let = dynamic_cast<typename std::shared_ptr<T_let>::element_type*>(no.get())){
		inter = "T_let ( LET "+ print_declist(no_let->declist); " IN "+print_exp_seq((no_let->exp_seq).get()) +" END )";
	};
	
	return "T_exp ( "+ inter +" )";
};

void print_arvore(std::shared_ptr<T_exp> no){
	std::cout << print_exp(no) << std::endl;
};
