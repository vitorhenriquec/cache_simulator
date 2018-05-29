#ifndef BLO_H
#define BLO_H

#include <string>
using std::string;

class Bloco{
	private:
		string idBloco,endereco,conteudo;
	public:
		Bloco();
		~Bloco();
		string getEndereco();
};

#endif