void imprime_erro (char const *s){
	std::cerr << "\033[1;37m"  << yyline << ":" << yycolumn << ":\033[1;31m error:" 
            << "\033[1;0m "<< s << " at:" << std::endl;
	std::cerr << bf_linha_scanner << std::endl;
	for (int i = 0; i < yycolumn; i++) 
		std::cerr << " ";
	std::cerr << "\033[1;31m^\033[1;0m" << std::endl;
};

