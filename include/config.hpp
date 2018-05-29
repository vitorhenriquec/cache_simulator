#ifndef CONF_H
#define CONF_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*
Tamanho do bloco (em número de palavras)
Numero de linhas da cache
Numero de blocos da memória principal
Mapeamento (1 – Direto; 2 – Totalmente Associativo; 3 – Parcialmente Associativo)
Numero de conjuntos (caso não seja Parcialmente Associativo, ler o valor normalmente mas desconsidere-o)
Política de substituição (1 – Aleatório; 2 – FIFO; 3 – LFU; 4 – LRU)s
*/

class Config{
	private:
		string tamBloco, linhasCache, blocosMemoria, qtdConjuntos,tipoMap, tipoSubs;
	public:
		Config();
		Config(string path);
		~Config();
		string getLinhasCache();
		string getTamBloco();
		string getBlocosMemoria();
};

#endif