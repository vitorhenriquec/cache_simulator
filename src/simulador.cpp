#include"../include/simulador.hpp"

int Simulador::ciclo = 0;

Simulador::Simulador(){
	
}

Simulador::~Simulador(){

}

void Simulador::readInstrucao(string endereco, Cache *c, Config * config, MemoriaPrincipal *mem, int &indicemiss){
	//Acrescente 1 ao ciclo toda vez que ele lê algo
	ciclo++;

	//Declara umas variáveis importantes
	bool hit = 0;
	int linhaMap, blocoEndereco, tamBloco = config->getTamBloco(), j = 0, qtdConjuntos = config->getQtdConjuntos();
	Bloco * tmp1 = c->getLinha();
	Bloco * tmp2 = mem->getBloco();

	//Esses ponteiros podem ser criados somente para esse método
	int * tempo = c->getRefTemporal();
	int * freq = c->getFreq();
	int * FIFO = c->getFIFO();

	//Salva a escolha de mapeamento e de substituição em variaveis
	int configMap = config->getTipoMap(), configSubs = config->getTipoSubs();

	//Verifica se a instrução está na cache
	for(int i = 0; i < c->getTamLinha(); i++){
		if(endereco == tmp1[i].getEndereco()){
			hit = 1;
			cout << "HIT" << endl;
			if(configSubs == 3){
				freq[i/tamBloco]+=1;
			}
			else if(configSubs == 4){
				tempo[i/tamBloco] = ciclo;
			}
			break;
		}
	}
	if(!hit){
		cout << "MISS" << endl;
		//Defino qual bloco é referente ao endereco
		blocoEndereco = stoi(endereco)/tamBloco;
		indicemiss = blocoEndereco;

		//Verifica o tipo de mapeamento
		if(configMap == 1){ //Mapeamente Direto

			//Defino para qual linha da cache esse endereço vai
			linhaMap = blocoEndereco%config->getLinhasCache();
			cout << "Alocado na linha:" << linhaMap << endl;
			if(tmp1[linhaMap].getEndereco() != "N"){
				cout << "Bloco " <<  tmp1[linhaMap].getIdBloco() << " substituído" << endl;
			}

			j = 0;
			//Percorro a memória para substituir os valores
			for(int i = 0; i < mem->getTamBloco(); i++){
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
			while(indice < c->getTamLinha()){
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
					for(int k = config->getLinhasCache() - 1; k >= 1; k--){
						FIFO[k] = FIFO[k-1];
					}
					FIFO[0] = linhaMap;
				}
				else if(configSubs == 3){
					freq[linhaMap] = 1;
				}
				else if(configSubs == 4){
					tempo[linhaMap] = ciclo;
				}
			}
			else{ // Caso contrário, verifico as politicas de substituição
				switch(configSubs){
					//OBS: ADD: Quando o antigo valor sair da cache, seu valor tem ser escrito na memória;
					case 1: //Caso Aletório
						srand(time(NULL));
						linhaMap = rand()%config->getLinhasCache();			
					break;
					case 2: //FIFO
						linhaMap = FIFO[config->getLinhasCache() - 1]; 
						for(int k = config->getLinhasCache() - 1; k >= 1; k--){
							FIFO[k] = FIFO[k-1];
						}
						FIFO[0] = linhaMap;
					break;
					case 3: //LFU
						//Digo que a menor frequência é a primeira
						menorFreq = freq[0];
						indiceMenorFreq = 0;
						//Verifico se há uma frequência menor do que a dele;
						for(int k = 1; k < config->getLinhasCache(); k++){
							if(menorFreq > freq[k]){
								menorFreq = freq[k];
								indiceMenorFreq = k;
							}
							cout << freq[k] << endl;
						}
						//cout << "menroFreq" << menorFreq << endl;
						linhaMap = indiceMenorFreq;
						//cout << "A:" << linhaMap << endl;
						freq[linhaMap] = 1;
					break;
					case 4: //LRU
						//Estabeleço que o menor ciclo é o primeiro do pointeiro
						menorCiclo = tempo[0];
						indiceMenorCiclo = 0;
						//Procuro saber se há um ciclo menor do que o dele
						for(int k = 1; k < config->getLinhasCache(); k++){
							if(menorCiclo > tempo[k]){
								menorCiclo = tempo[k];
								indiceMenorCiclo = k;
							}
						}
						//cout << "menorCiclo:" << menorCiclo << "indiceMenorCiclo:" << indiceMenorCiclo << endl;
						linhaMap = indiceMenorCiclo;
						tempo[linhaMap] = ciclo;
					break;
				}
				cout << "Alocado na linha:" << linhaMap << endl;
				cout << "Bloco " <<  tmp1[linhaMap].getIdBloco() << " substituído" << endl;
			}

			j = 0; //Garanto que o j começa de 0
			for(int i = 0; i < mem->getTamBloco(); i++){
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
			int indice = 0,menorCiclo, indiceMenorCiclo = 0, menorFreq, indiceMenorFreq = 0, conjMap, qtdLinhasConj;
			bool existe = 0;

			//Defino para qual conjunto o valor vai ser salvo
			conjMap = blocoEndereco%qtdConjuntos;

			//Define quantas linhas tem cada conjunto
			qtdLinhasConj = config->getLinhasCache()/qtdConjuntos;

			while(indice < c->getTamLinha()){
				//Garanto que a linha faz parte do conjunto que quero verificar se está mapeado
				//cout << (indice/tamBloco)/qtdLinhasConj << endl;
				if(tmp1[indice].getEndereco() == "N" && (indice/tamBloco)/qtdLinhasConj == conjMap){
					linhaMap = (indice/tamBloco);
					existe = 1;
					break;
				}
				indice++;
			}

			if(existe){
				cout << "Alocado na linha " << linhaMap << endl;
				if(configSubs == 2){ 
					for(int k = (qtdLinhasConj*conjMap) + qtdLinhasConj -1; k >= (qtdLinhasConj*conjMap)+1; k--){
						FIFO[k] = FIFO[k-1];
					}
					//O primeiro a entrar no vetor FIFO será a linha que achei disponível
					FIFO[(qtdLinhasConj*conjMap)+0] = linhaMap;
				}
				else if(configSubs == 3){
					freq[linhaMap] = 1;
				}
				else if(configSubs == 4){
					tempo[linhaMap] = ciclo;
				}
			}
			else{
				switch(configSubs){
					case 1: //Caso Aletório
						srand(time(NULL));
						linhaMap = rand()%config->getLinhasCache();
						//Enquanto a linha gerada com o rand nõa estiver no conjunto que deve ser mapeado, gero outro linha.
						while((linhaMap/qtdLinhasConj) != conjMap){
							linhaMap = rand()%config->getLinhasCache();
						}			
					break;
					case 2: //FIFO 
						//Estabeleço o último como o que vai ser mapeado, já que ele foi o primeiro a ser mapeadao do conjunto
						linhaMap = FIFO[(qtdLinhasConj*conjMap) + qtdLinhasConj -1]; 
						for(int k = (qtdLinhasConj*conjMap) + qtdLinhasConj -1; k >= (qtdLinhasConj*conjMap)+1; k--){
							FIFO[k] = FIFO[k-1];
						}
						//O primeiro elemento do vetor FIFO recebe
						FIFO[0] = linhaMap;
					break;
					case 3: //LFU
						//Digo que a menor frequência é o valor da primeira linha do conjunto mapeado
						menorFreq = freq[(qtdLinhasConj*conjMap) + 0];
						indiceMenorFreq = (qtdLinhasConj*conjMap) + 0;

						//Verifico se há uma frequência menor do que a dele;
						for(int k = (qtdLinhasConj*conjMap) + 1; k < (qtdLinhasConj*conjMap) + qtdLinhasConj; k++){
							if(menorFreq > freq[k]){
								menorFreq = freq[k];
								indiceMenorFreq = k;
							}
						}
						linhaMap = indiceMenorFreq;
						freq[linhaMap] = 1;
					break;
					case 4: //LRU
						//Estabeleço que o menor ciclo é o valor da primeira linha do conjunto mapeado
						menorCiclo = tempo[(qtdLinhasConj*conjMap) + 0];
						indiceMenorCiclo = (qtdLinhasConj*conjMap) + 0;
						
						//Procuro saber se há um ciclo menor do que o dele dentro do conjunto
						for(int k = (qtdLinhasConj*conjMap) +1; k < (qtdLinhasConj*conjMap) + qtdLinhasConj; k++){
							if(menorCiclo > tempo[k]){
								menorCiclo = tempo[k];
								indiceMenorCiclo = k;
							}
						}
						linhaMap = indiceMenorCiclo;
						tempo[linhaMap] = ciclo;
					break;
				}
				cout << "Alocado na linha " << linhaMap << endl;
				cout << "Bloco " <<  tmp1[linhaMap].getIdBloco() << " substituído" << endl;
			}

			j = 0; //Garanto que o j começa de 0
			for(int i = 0; i < mem->getTamBloco(); i++){
				if(tmp2[i].getIdBloco() == to_string(blocoEndereco) && j < tamBloco){
					if((((tamBloco*linhaMap) + j)/tamBloco)/qtdLinhasConj == conjMap)	
						//Quando eu acho as posições em que o id bloco é bloco endereço, transfiro as informações para um posicao da cache 
						tmp1[(tamBloco*linhaMap) + j] = tmp2[i];
						j++;						
				}
				if(j >= tamBloco){
					break;
				}
			}
		}
	}

}

int Simulador::searchInstrucao(string instrucao,Cache *c){
	Bloco * tmp1 = nullptr;
	if(c->getLinha() != nullptr){
		tmp1 = c->getLinha();
		for(int i = 0; i < c->getTamLinha(); i++){
			if(tmp1[i].getEndereco() == instrucao){
				return i;
			}
		}
	}
	return -1;
}

//FIX: For some reason segmentation fault 
void Simulador::writeInstrucao(string instrucao, string valor,Cache *c,MemoriaPrincipal *mem, int &indice){
	//Salvo os ponteiros da memória e cache em ponteiros temporários
	Bloco * tmp2 = nullptr, *tmp1 = nullptr;
	if(c->getLinha() != nullptr && mem->getBloco() != nullptr){
		tmp2 = mem->getBloco();
		tmp1 = c->getLinha();
	
		cout << "HIT linha" << indice/c->getBlocosLinha() << "-> novo valor do endereço" << instrucao << "= " << valor << endl;
		tmp1[indice].setConteudo(valor);
		tmp2[stoi(instrucao)/c->getBlocosLinha()].setConteudo(valor);
	}
}

void Simulador::showCacheMemoria(Cache *c, MemoriaPrincipal *mem){
	c->printCache();
	mem->printMemoria();
}
