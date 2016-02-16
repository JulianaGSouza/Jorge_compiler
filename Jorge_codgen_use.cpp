#include "Jorge_t_define.h"

static std::unique_ptr<Module> *TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;

Value *ErrorV(const char *str) {
	Error(str);
	return nullptr;
}

Value *t_int::codegen() {
	return ConstantFP::get(getGlobalContext(), APInt(n));
}

Value *t_float::codegen() {
	return ConstantFP::get(getGlobalContext(), APFloat(n));
}

/*Value *t_string::codegen() {
	return ConstantFP::get(getGlobalContext(), APString(cadeia));
}


Value *t_id::codegen() {
	// Look this variable up in the function.
	Value *v = NamedValues[id];
	if (!v)
		ErrorV("Variável não encontrada");
	return v;
}

Value *t_operacao::codegen() {
	Value *e = eexp->codegen();
	Value *d = dexp->codegen();
	if (!e || !d)
		return nullptr;
	
	switch (op) {
	case "+":
		return Builder.CreateFAdd(e, d, "addtmp");
	case "-":
		return Builder.CreateFSub(e, d, "subtmp");
	case "*":
		return Builder.CreateFMul(e, d, "multmp");
	case "/":
    		return Builder.CreateFMul(e, d, "divtmp");
	case "|":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	case "&":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	case "=":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	case "<>":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	case ">=":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");		
	case "<=":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");	
	case "<":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");
	case ">":
		e = Builder.CreateFCmpULT(e, d, "cmptmp");
		return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),"booltmp");
	default:
		return ErrorV("Operador inválido");
	}
}

/*
Value *CallExprAST::codegen() {
  // Look up the name in the global module table.
  Function *CalleeF = TheModule->getFunction(Callee);
  if (!CalleeF)
    return ErrorV("Unknown function referenced");

  // If argument mismatch error.
  if (CalleeF->arg_size() != Args.size())
    return ErrorV("Incorrect # arguments passed");

  std::vector<Value *> ArgsV;
  for (unsigned i = 0, e = Args.size(); i != e; ++i) {
    ArgsV.push_back(Args[i]->codegen());
    if (!ArgsV.back())
      return nullptr;
  }

  return Builder.CreateCall(CalleeF, ArgsV, "calltmp");
}*/


