#ifndef MEM_H
#define MEM_H

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::stoi;
using std::to_string;

#include "bloco.hpp"

class MemoriaPrincipal{
	private:
		Bloco *bloco;
		int tamBloco;
	public:
		MemoriaPrincipal();
		MemoriaPrincipal(int blocosMemoria, int tamBloco);
		~MemoriaPrincipal();
		Bloco * getBloco();
		int getTamBloco();
		void printMemoria();
	};
#endif