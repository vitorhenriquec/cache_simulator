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
		int tamLinha;
	public:
		Cache();
		Cache(int linhasCache,int tamBloco);
		~Cache();
		int getTamLinha();
		Bloco * getLinha();
};

#endif