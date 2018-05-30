#include<iostream>
#include<string>
using namespace std;

#include"../include/config.hpp"
#include"../include/cache.hpp"
#include"../include/memprincipal.hpp"
#include"../include/simulador.hpp"


int main(){
	//Salva as configurações do .txt
	Config config("config/.config.txt");

	//Instacia a cache com suas linhas
	Cache c(config.getLinhasCache(),config.getTamBloco());

	//Instacia a memoria com seus blocos
	MemoriaPrincipal mem(config.getBlocosMemoria(),config.getTamBloco());

	
	//Instacia um simulador para executar as ações
	Simulador s;
	//Pede que o usuário digite algum comando e caso for 'exit' finaliza o programa;
	string op,tmp1,tmp2;
	do{
		cin >> op;
		if(op == "Read"){
			cin >> tmp1;
			s.readInstrucao(tmp1,c,config);
		}
		else if(op == "Write"){
			cin >> tmp1;
			cin >> tmp2;
			//s.writeInstrucao(tmp1,tmp2,c,mem);
		}
		else if(op == "Show"){
			//s.show()
		}

	}while(op!="Exit");
	
	return 0;
}