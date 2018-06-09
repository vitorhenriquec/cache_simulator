#ifndef CAC_H
#define CAC_H

/*#include<iostream>
using std::cout;
using std::endl;*/

#include <string>
using std::string;
using std::stoi;

#include "bloco.hpp"

class Cache{
	protected:
		Bloco *linha;
		int * refTemporal;
		int * freq;
		int * FIFO;
		int tamLinha,blocosLinha;
	public:
		Cache();
		Cache(int linhasCache,int tamBloco,int tipoSubs);
		~Cache();
		int getTamLinha();
		int getBlocosLinha();
		int * getRefTemporal();
		int * getFreq();
		int * getFIFO();
		Bloco * getLinha();
		void printCache();
};

#endif