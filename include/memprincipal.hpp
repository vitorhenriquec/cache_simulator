#ifndef MEM_H
#define MEM_H

#include <string>
using std::string;
using std::stoi;

#include "bloco.hpp"

class MemoriaPrincipal{
	private:
		Bloco *bloco;
		int tamBloco;
	public:
		MemoriaPrincipal();
		MemoriaPrincipal(string blocosMemoria, string tamBloco);
		~MemoriaPrincipal();
		//int getTamBloco();
	};
#endif