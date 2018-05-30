#include"../include/memprincipal.hpp"

MemoriaPrincipal::MemoriaPrincipal(){

}

MemoriaPrincipal::MemoriaPrincipal(int blocosMemoria, int tamBloco){
	//Calculo o tamanho do bloco para a memoria
	//this->tamBloco = stoi(blocosMemoria)*stoi(tamBloco);
	this->tamBloco = blocosMemoria*tamBloco;

	//Aloco o ponteiro para Bloco
	bloco = new Bloco[this->tamBloco];
	int valor = 0;

	//Inicializo o id e o endereço do bloco na memoria com os seus respectivos números
	for(int i = 0; i < this->tamBloco; i++){
		bloco[i].setIdBloco(to_string(valor));
		bloco[i].setEndereco(to_string(i));	
		if(i%tamBloco == tamBloco-1){
			valor++;
		}	
	}

	/*cout << "Estado da MemoriaPrincipal com " << this->tamBloco << endl;
	for(int i = 0; i < this->tamBloco; i++){
		cout << bloco[i].getIdBloco() << "-" << bloco[i].getEndereco() << endl;
	}*/
}

MemoriaPrincipal::~MemoriaPrincipal(){
	delete[] bloco;
}

Bloco * MemoriaPrincipal::getBloco(){
	return bloco;
}

/*int MemoriaPrincipal::getTam(){
	return tam;
}*/

