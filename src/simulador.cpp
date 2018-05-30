#include"../include/simulador.hpp"

Simulador::Simulador(){
	
}

Simulador::~Simulador(){

}

enum mapeamento{ Direto=1, tAssociativo, pAssociativo};
enum substituicao{Aleatorio=1,FIFO,LFU,LRU};

void Simulador::readInstrucao(string endereco, Cache &c, Config &config, MemoriaPrincipal &mem){
	bool hit = 0;
	int linhaMap, valor, tamBloco = config.getTamBloco();
	Bloco * tmp1 = c.getLinha();
	Bloco * tmp2 = mem.getBloco();

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
		//Converte a escolha da configuração para um tipo do enum mapeamento
		mapeamento m = (mapeamento) config.getTipoMap();

		//Verifica o tipo de mapeamento
		switch(m){
			case Direto:
				//Defino a linha que vai ser mapeada pelo mapeamente direto
				linhaMap = (stoi(endereco))%config.getLinhasCache();
				valor = 0;

				//OBS: Melhorar como o ponteiro para Bloco é definido na Cache, isso para evitar o calculo da linha da cache
				//Substituo diretamente caso esteja vazio
				//for(int i = 0; i < c.TamLinha(); i++){

				//}
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
