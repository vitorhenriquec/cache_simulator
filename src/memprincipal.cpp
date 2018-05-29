#include"../include/memprincipal.hpp"

MemoriaPrincipal::MemoriaPrincipal(){

}

MemoriaPrincipal::MemoriaPrincipal(string blocosMemoria, string tamBloco){
	int tam = (int) stoi(blocosMemoria)*stoi(tamBloco);
	bloco = new Bloco[tam];
}

MemoriaPrincipal::~MemoriaPrincipal(){
	delete[] bloco;
}

