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
	private:
		Bloco *linha;
	public:
		Cache();
		Cache(string linhasCache,string tamBloco);
		~Cache();
};

#endif