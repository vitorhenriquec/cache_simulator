#include"../include/cache.hpp"

Cache::Cache(){
	
}

Cache::Cache(string linhasCache){
	linha = new int[stoi(linhasCache)] {};
}

Cache::~Cache(){
	delete linha;
}
