#include"../include/cache.hpp"

Cache::Cache(){
	
}

Cache::Cache(int linhasCache,int tamBloco){
	tamLinha = linhasCache*tamBloco;
	blocosLinha = tamBloco;
	// Aloco um ponteiro para Bloco de acordo com a dimensão de indices para representar as linhas da Cache
	linha = new Bloco[tamLinha];
	//Aloca uma referência temporal e inicializo com 0 para o modo LRU
	refTemporal = new int[linhasCache]{};
	//Aloco um contador de frequências, incializando ele com 0
	freq = new int[linhasCache] {};
	//Aloco e inicializo um ponteiro que referencia qual o primeiro bloco o qual entrou na Cache
	FIFO = new int[linhasCache]{};
}

Cache::~Cache(){
	delete[] linha;
	delete[] refTemporal;
	delete[] freq;
	delete[] FIFO;
}

int Cache::getTamLinha(){
	return tamLinha;
}

int * Cache::getRefTemporal(){
	return refTemporal;
}

int * Cache::getFreq(){
	return freq;
}

int * Cache::getFIFO(){
	return FIFO;
}

Bloco * Cache::getLinha(){
	return linha;
}

void Cache::printCache(){
	cout << "--- Cache ---" << endl;
	cout << "Linha  -  Bloco  - Endereço - Conteúdo" << endl;
	for(int i = 0; i < tamLinha; i++){
		cout << i/blocosLinha << " - " << linha[i] << endl;
	}
	cout << "" << endl;
}
