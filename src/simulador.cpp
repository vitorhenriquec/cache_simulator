#include"../include/simulador.hpp"

Simulador::Simulador(){
	
}

Simulador::~Simulador(){

}

enum mapeamento{ Direto=1, tAssociativo, pAssociativo};
enum substituicao{Aleatorio=1,FIFO,LFU,LRU};

void Simulador::readInstrucao(string endereco, Cache &c, Config &config){
	bool hit = 0;
	int posMap;
	Bloco * tmp1 = c.getLinha();

	//Verifica se a instrução está na cache
	for(int i = 0; i < c.getTamLinha(); i++){
		if(endereco == tmp1->getEndereco()){
			hit = 1;
			cout << "HIT" << endl;
			break;
		}
	}
	if(!hit){
		cout << "MISS" << endl;
		mapeamento m = (mapeamento) stoi(config.getTipoMap());
		switch(m){
			case Direto:
				posMap = (stoi(endereco))%(stoi(config.getLinhasCache()));
			break;
			case tAssociativo:
			break;
			case pAssociativo:
			break;
		}
		//Mapeamento Direto


		//Totalmente Associativo

		//Parcialmente Associativo;
	}

}
