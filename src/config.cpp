#include"../include/config.hpp"

Config::Config(){

}

Config::Config(string path){
	string line;
	int counter = 0;
	ifstream file(path);
	cout << path << endl;
	if(file.is_open() == 0 || file.bad() || !file){
		cerr << "Não foi possível abrir o arquivo" << endl;
	}
	else{
		while(file >> line){
			switch(counter){
				case 0:
					tamBloco = line;
				break;
				case 1:
					linhasCache = line;
				break;
				case 2:
					blocosMemoria = line;
				break;
				case 3:
					tipoMap = line;
				break;
				case 4:
					qtdConjuntos = line;
				break;
				case 5:
					tipoSubs = line;
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

string Config::getLinhasCache(){
	return linhasCache;
}

string Config::getTamBloco(){
	return tamBloco;
}

string Config::getBlocosMemoria(){
	return blocosMemoria;
}

string Config::getTipoMap(){
	return tipoMap;
}