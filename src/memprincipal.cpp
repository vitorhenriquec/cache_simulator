#include"../include/memprincipal.hpp"

MemoriaPrincipal::MemoriaPrincipal(){

}

MemoriaPrincipal::MemoriaPrincipal(string blocosMemoria, string tamBloco){
	this->tamBloco = (int) stoi(blocosMemoria)*stoi(tamBloco);
	bloco = new Bloco[this->tamBloco];

	int counter = 0;
	int valor = 0;

	for(int i = 0; i < this->tamBloco; i++){
		if(counter < stoi(blocosMemoria)){
			counter++;
			//bloco[i].setIdBloc((string) valor); 
		}
		else{
			counter = 0;
		}
	}
}

MemoriaPrincipal::~MemoriaPrincipal(){
	delete[] bloco;
}

/*int MemoriaPrincipal::getTam(){
	return tam;
}*/

