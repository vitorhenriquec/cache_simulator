#include<iostream>
#include<string>
using namespace std;

#include"../include/config.hpp"
#include"../include/cache.hpp"
#include"../include/memprincipal.hpp"

enum mapeamento{ Direto=1, tAssociativo, pAssociativo};
enum substituicao{Aleatorio=1,FIFO,LFU,LRU};

int main(){
	//Salva as configurações do .txt
	Config config("config/.config.txt");

	//Instacia a cache com suas linhas
	Cache c(config.getLinhasCache(),config.getTamBloco());

	//Instacia a memoria com seus blocos
	MemoriaPrincipal mem(config.getBlocosMemoria(),config.getTamBloco());

	//Pede que o usuário digite algum comando e caso for 'exit' finaliza o programa;
	string op;
	do{
		cin >> op;
	}while(op!="exit");

	return 0;
}