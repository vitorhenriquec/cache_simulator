#include"../include/simulador.hpp"

int Simulador::ciclo = 0;

Simulador::Simulador(){
	
}

Simulador::~Simulador(){

}

void Simulador::readInstrucao(string endereco, Cache &c, Config &config, MemoriaPrincipal &mem){
	//Acrescente 1 ao ciclo toda vez que ele lê algo
	ciclo++;

	bool hit = 0;
	int linhaMap, blocoEndereco, tamBloco = config.getTamBloco(), j = 0;
	Bloco * tmp1 = c.getLinha();
	Bloco * tmp2 = mem.getBloco();

	//Esses ponteiros podem ser criados somente para esse método
	int * tempo = c.getRefTemporal();
	int * freq = c.getFreq();
	int * FIFO = c.getFIFO();

	//Salva a escolha de mapeamento e de substituição em variaveis
	int configMap = config.getTipoMap(), configSubs = config.getTipoSubs();

	//Verifica se a instrução está na cache
	for(int i = 0; i < c.getTamLinha(); i++){
		if(endereco == tmp1[i].getEndereco()){
			hit = 1;
			cout << "HIT" << endl;
			if(configSubs == 4){
				tempo[i/tamBloco] = ciclo;
			}
			if(configSubs == 3){
				freq[i/tamBloco]+=1;
			}
			break;
		}
	}
	if(!hit){
		cout << "MISS" << endl;
		//Defino qual bloco é referente ao endereco
		blocoEndereco = stoi(endereco)/tamBloco;

		//Verifica o tipo de mapeamento
		if(configMap == 1){ //Mapeamente Direto

			//Defino para qual linha da cache esse endereço vai
			linhaMap = blocoEndereco%config.getLinhasCache();
			cout << "Alocado na linha:" << linhaMap << endl;

			j = 0;
			//Percorro a memória para substituir os valores
			for(int i = 0; i < mem.getTamBloco(); i++){
				if(tmp2[i].getIdBloco() == to_string(blocoEndereco) && j < tamBloco){
					//Quando eu acho as posições em que o id bloco é bloco endereço, transfiro as informações para um posicao da cache
					tmp1[(tamBloco*linhaMap) + j] = tmp2[i];
					j++;						
				}
				if(j >= tamBloco){
					break;
				}
			}
		}
		else if(configMap == 2){ //Mapeamento Totalmente Associativo
			int indice = 0,menorCiclo, indiceMenorCiclo = 0, menorFreq, indiceMenorFreq = 0;
			bool existe = 0;

			//Procuro se há uma linha disponível
			while(indice < c.getTamLinha()){
				//Caso exista alguma linha não preenchida, vou substituir essa. 
				if(tmp1[indice].getEndereco() == "N"){
					linhaMap = indice/tamBloco;
					existe = 1;
					break;
				}
				indice++;
			}

			//Se existe algum campo que não foi alocado
			if(existe){
				cout << "Alocado na linha:" << linhaMap << endl;
				if(configSubs == 2){
					for(int k = config.getLinhasCache() - 1; k >= 1; k--){
						FIFO[k] = FIFO[k-1];
					}
					FIFO[0] = linhaMap;
				}
			}
			else{ // Caso contrário, verifico as politicas de substituição
				switch(configSubs){
					//OBS: ADD: Quando o antigo valor sair da cache, seu valor tem ser escrito na memória;
					case 1: //Caso Aletório
						srand(time(NULL));
						linhaMap = rand()%config.getLinhasCache();			
					break;
					case 2: //FIFO
						linhaMap = FIFO[config.getLinhasCache() - 1]; 
						for(int k = config.getLinhasCache() - 1; k >= 1; k--){
							FIFO[k] = FIFO[k-1];
						}
						FIFO[0] = linhaMap;
					break;
					case 3: //LFU
						//Digo que a menor frequência é a primeira
						menorFreq = freq[0];
						//Verifico se há uma frequência menor do que a dele;
						for(int k = 1; k < config.getLinhasCache(); k++){
							if(menorFreq > freq[k]){
								menorFreq = freq[k];
								indiceMenorFreq = k;
							}
							cout << freq[k] << endl;
						}
						cout << "menroFreq" << menorFreq << endl;
						linhaMap = indiceMenorFreq;
					break;
					case 4: //LRU
						//Estabeleço que o menor ciclo é o primeiro do pointeiro
						menorCiclo = tempo[0];
						//Procuro saber se há um ciclo menor do que o dele
						for(int k = 1; k < config.getLinhasCache(); k++){
							if(menorCiclo > tempo[k]){
								menorCiclo = tempo[k];
								indiceMenorCiclo = k;
							}
						}
						//cout << "menorCiclo:" << menorCiclo << "indiceMenorCiclo:" << indiceMenorCiclo << endl;
						linhaMap = indiceMenorCiclo;
					break;
				}
				cout << "Alocado na linha:" << linhaMap << endl;
			}

			j = 0; //Garanto que o j começa de 0
			tempo[linhaMap] = ciclo;
			freq[linhaMap] = 1;
			for(int i = 0; i < mem.getTamBloco(); i++){
				if(tmp2[i].getIdBloco() == to_string(blocoEndereco) && j < tamBloco){
					//Quando eu acho as posições em que o id bloco é bloco endereço, transfiro as informações para um posicao da cache
					tmp1[(tamBloco*linhaMap) + j] = tmp2[i];
					j++;						
				}
				if(j >= tamBloco){
					break;
				}
			}	
		}
		else if(configMap == 3){ //Mapeamento Parcialmente Associativo;

		}
	}

}

void Simulador::showCacheMemoria(Cache &c, MemoriaPrincipal &mem){
	c.printCache();
	mem.printMemoria();
}
