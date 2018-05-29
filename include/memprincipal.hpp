#ifndef MEM_H
#define MEM_H

#include <string>
using std::string;
using std::stoi;

#include "bloco.hpp"

class MemoriaPrincipal{
	private:
		Bloco *bloco;
	public:
		MemoriaPrincipal();
		MemoriaPrincipal(string blocosMemoria, string tamBloco);
		~MemoriaPrincipal();
	};
#endif