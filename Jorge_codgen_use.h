//#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
//#include "llvm/IR/Verifier.h"

using namespace llvm;

static std::unique_ptr<Module> TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;

void erro(const char *str){
	std::cout << str << endl;
}

Value *ErrorV(const char *str) {
	erro(str);
	return nullptr;
}

Value *T_int::codegen() {
	return ConstantInt::get(getGlobalContext(), APInt(32,n,true));
}

Value *T_float::codegen() {
	return ConstantFP::get(getGlobalContext(), APFloat(n));
}

Value *T_string::codegen() {
	//return ConstantFP::get(getGlobalContext(), APString(cadeia));
}


/*
Value *T_id::codegen() {
	Value *v = NamedValues[id];
	if (!v)
		ErrorV("Variável não encontrada");
	return v;
}*/


Value *T_operacao::codegen() {
	Value *e = eexp->codegen();
	Value *d = dexp->codegen();
	if (!e || !d)
		return nullptr;

	if(operador.compare("+") == 0)
		return Builder.CreateAdd(e, d, "addtmp");
	else if(operador.compare("-") == 0)
		return Builder.CreateSub(e, d, "subtmp");
	else if(operador.compare("*") == 0)
		return Builder.CreateMul(e, d, "multmp");
	else if(operador.compare("/") == 0)
    		return Builder.CreateSDiv(e, d, "divtmp");
	else if(operador.compare("|") == 0){
		e = Builder.CreateOr(e, d, "ortmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else if(operador.compare("&") == 0){
		e = Builder.CreateAnd(e, d, "andtmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else if(operador.compare("=") == 0){
		e = Builder.CreateICmpEQ(e, d, "eqcomptmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else if(operador.compare("<>") == 0){
		e = Builder.CreateICmpNE(e, d, "necomptmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else if(operador.compare(">=") == 0){
		e = Builder.CreateICmpSGE(e, d, "gecomptmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else if(operador.compare(">") == 0){
		e = Builder.CreateICmpSGT(e, d, "gtcmptmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else if(operador.compare("<=") == 0){
		e = Builder.CreateICmpSLE(e, d, "lecmptmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else if(operador.compare("<") == 0){
		e = Builder.CreateICmpSLT(e, d, "ltcmptmp");
		return Builder.CreateUIToFP(e, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	} else
		return ErrorV("Operador inválido");
};

Value *T_subunario::codegen(){
	Value *e = exp->codegen();
	if (!e)
		return nullptr;

	return Builder.CreateNeg(e,"negtmp");
};

Value *T_chamada::codegen() {
  Function *Chamada = TheModule->getFunction(id);
  if (!Chamada)
    return ErrorV("Essa função na existe");

  if (Chamada->arg_size() != (parametros->exp_list).size())
    return ErrorV("Argumentos # incorretos");

  std::vector<Value *> ArgsV;
  for (unsigned i = 0, e = (parametros->exp_list).size(); i != e; ++i) {
    ArgsV.push_back(parametros->exp_list[i]->codegen());
    if (!ArgsV.back())
      return nullptr;
  }

  return Builder.CreateCall(Chamada, ArgsV, "chamadatmp");
};

Value *T_ty_rec::codegen(){
	StructType* struct_tyfields = StructType::create(TheModule->getContext(), "struct.fields");
	std::vector<Type*> struct_tyfields_fields;
	for(auto it = tyfields->tyfields.begin(); it != tyfields->tyfields.end() ; it++){
		//struct_tyfields_fields.push_back(Type::TygetPrimitiveType(TheModule->getContext(),it->second));
	};
	//struct_tyfields->setBody(struct_tyfields_fields.push_back);
};

Value *T_tydec::codegen(){
	//TYPE ID IGUAL ty

	if (auto ty_id = dynamic_cast<typename std::shared_ptr<T_ty_id>::element_type*>(ty.get())){
		//T_ty_id::codegen();
	} else if (auto ty_rec = dynamic_cast<typename std::shared_ptr<T_ty_rec>::element_type*>(ty.get())){
		//T_ty_rec::codegen();
	} else if (auto ty_array = dynamic_cast<typename std::shared_ptr<T_ty_array>::element_type*>(ty.get())){
		//T_ty_array::codegen();
	} if (auto ty_funfun = dynamic_cast<typename std::shared_ptr<T_ty_funfun>::element_type*>(ty.get())){
		//T_ty_funfun::codegen();
	};
};


Value *T_nil::codegen(){
};

Value *T_declist::codegen(){
};

Value *T_tyfields::codegen(){
};

Value *T_ty_id::codegen(){
};

Value *T_ty_array::codegen(){
};

Value *T_tylist::codegen(){
};

Value *T_ty_funfun::codegen(){
};

Value *T_vardec::codegen(){
};

Value *T_fundec::codegen(){
};

Value *T_lvalue::codegen(){
};

Value *T_exp_list::codegen(){
};

Value *T_exp_seq::codegen(){ 
};

Value *T_enum_it::codegen(){
};

Value *T_rec_enum::codegen(){	
};

Value *T_def_rec::codegen(){
};

Value *T_def_array::codegen(){
};

Value *T_if::codegen(){
};

Value *T_let::codegen(){
};

