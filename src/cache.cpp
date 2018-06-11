#include"../include/cache.hpp"

Cache::Cache(){
	
}

Cache::Cache(int linhasCache,int tamBloco, int tipoSubs){
	tamLinha = linhasCache*tamBloco;
	blocosLinha = tamBloco;
	// Aloco um ponteiro para Bloco de acordo com a dimensão de indices para representar as linhas da Cache
	linha = new Bloco[tamLinha];
	
	//Inicializo os ponteiros para inteiro
	FIFO = nullptr;
	refTemporal = nullptr;
	freq = nullptr;

	//Aloco e inicializo um ponteiro que referencia qual o primeiro bloco o qual entrou na Cache
	if(tipoSubs == 2){
		FIFO = new int[linhasCache]{};
	}
	else if(tipoSubs == 4){
		refTemporal = new int[linhasCache]{};
	}
	else if(tipoSubs == 3){
		freq = new int[linhasCache] {};
	}
}

Cache::~Cache(){
	delete[] linha;
	if(refTemporal!=nullptr){
		delete[] refTemporal;
	}
	if(freq!=nullptr){
		delete[] freq;
	}
	if(FIFO!=nullptr){
		delete[] FIFO;
	}
}

int Cache::getTamLinha(){
	return tamLinha;
}

int Cache::getBlocosLinha(){
	return blocosLinha;
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
