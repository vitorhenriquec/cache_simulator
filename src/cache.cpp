#include"../include/cache.hpp"

Cache::Cache(){
	
}

Cache::Cache(int linhasCache,int tamBloco){
	tamLinha = linhasCache*tamBloco;
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
