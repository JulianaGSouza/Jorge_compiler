# JORGE, Compilador para a linguagem Tiger funcional (FunTiger)
# Fevereiro de 2016
# Desenvolvido por Gustavo Luiz Fernandes e Juliana Gonçalves de Souza
TEST = lexico01.erro.tig
TESTFOLDER = Testes

all: lexico sintatico main

sintatico:
	bison -d Jorge_parser.y
    
lexico:
	flex Jorge_alex.l
    
main:
	g++ -g Jorge_main.cpp Jorge_parser.tab.c lex.yy.c -std=c++11 `llvm-config-3.7 --cxxflags --ldflags --system-libs --libs core`
    
run:
	./a.out < $(TESTFOLDER)/$(TEST)

run-no-test:
	./a.out
