#ifndef SIM_H
#define SIM_H

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include"cache.hpp"
#include"memprincipal.hpp"
#include"config.hpp"

class Simulador{
	public:
		Simulador();
		~Simulador();
		void readInstrucao(string instrucao, Cache &c, Config &config, MemoriaPrincipal &mem);
		//void writeInstrucao(string instrucao);
		//void showCacheMemoria();
};

#endif