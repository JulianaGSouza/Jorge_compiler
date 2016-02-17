#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

#include "Jorge_t_define.h"
#include "Jorge_parser.tab.h"
#include "Jorge_asemantic.h"
#include "Jorge_print_arvore.h"

int main (void){
	std::shared_ptr<T_exp> raiz(std::shared_ptr<T_exp> (new T_exp()));
	yyparse (raiz);
	//semantico(std::move(raiz));
	//gerar codigo llvm
	//print no llvm::module
}
