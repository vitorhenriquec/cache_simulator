#include"../include/cache.hpp"

Cache::Cache(){
	
}

Cache::Cache(string linhasCache,string tamBloco){
	int tam = (int) stoi(linhasCache)*stoi(tamBloco);
	linha = new Bloco[tam];
}

Cache::~Cache(){
	delete[] linha;
}
