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
#include "Jorge_codgen_use.h"

int main (void){
	std::shared_ptr<T_exp> raiz;
	yyparse (raiz);
	semantico(raiz);
	//print_arvore(raiz);
	//gerar codigo llvm
	//print no llvm::module
}
