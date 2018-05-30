#include"../include/config.hpp"

Config::Config(){

}

Config::Config(string path){
	string line;
	int counter = 0;
	ifstream file(path);
	
	if(file.is_open() == 0 || file.bad() || !file){
		cerr << "Não foi possível abrir o arquivo" << endl;
	}
	else{
		cout << "Informações lidas do .config:" << endl;
		while(file >> line){
			switch(counter){
				case 0:
					tamBloco = stoi(line);
				break;
				case 1:
					linhasCache = stoi(line);
				break;
				case 2:
					blocosMemoria = stoi(line);
				break;
				case 3:
					tipoMap = stoi(line);
				break;
				case 4:
					qtdConjuntos = stoi(line);
				break;
				case 5:
					tipoSubs = stoi(line);
				break;
			}
			cout << line << endl;
			counter++;
		}
	}
	file.close();
}

Config::~Config(){

}

int Config::getLinhasCache(){
	return linhasCache;
}

int Config::getTamBloco(){
	return tamBloco;
}

int Config::getBlocosMemoria(){
	return blocosMemoria;
}

int Config::getTipoMap(){
	return tipoMap;
}