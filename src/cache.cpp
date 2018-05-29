#include"../include/cache.hpp"

Cache::Cache(){
	
}

Cache::Cache(string linhasCache,string tamBloco){
	tamLinha = (int) stoi(linhasCache)*stoi(tamBloco);
	linha = new Bloco[tamLinha];
}

Cache::~Cache(){
	delete[] linha;
}

int Cache::getTamLinha(){
	return tamLinha;
}

Bloco * Cache::getLinha(){
	return linha;
}
