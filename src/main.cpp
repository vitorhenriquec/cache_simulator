#include<iostream>
#include<string>
using namespace std;

#include"../include/config.hpp"
#include"../include/cache.hpp"
#include"../include/memprincipal.hpp"
#include"../include/simulador.hpp"

int main(){
	//Salva as configurações do .txt
	Config * config = new Config("config/.config.txt");

	//Instacia a cache com suas linhas
	Cache *c = new Cache(config->getLinhasCache(),config->getTamBloco(),config->getTipoSubs());

	//Instacia a memoria com seus blocos
	MemoriaPrincipal * mem = new MemoriaPrincipal(config->getBlocosMemoria(),config->getTamBloco());
 	
	//Instacia um simulador para executar as ações
	Simulador s;
	//Pede que o usuário digite algum comando e caso for 'exit' finaliza o programa;
	string op,tmp1,tmp2;
	do{
		cin >> op;
		if(op == "Read"){
			cin >> tmp1;
			s.readInstrucao(tmp1,c,config,mem);
		}
		else if(op == "Write"){
			cin >> tmp1;
			cin >> tmp2;
			s.writeInstrucao(tmp1,tmp2,c,mem);
		}
		else if(op == "Show"){
			s.showCacheMemoria(c,mem);
		}

	}while(op!="Exit");
	delete[] config;
	delete[] c;
	delete[] mem;
	return 0;
}