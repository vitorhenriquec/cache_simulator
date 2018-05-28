#ifndef FUN_H
#define FUN_H

#include<ostream>
#include<istream>
#include<string>
using namespace std;


class Midias{
	protected:
		string id;
		string tipo;
		int anoLancamento;
	public:
		Midias();
		~Midias();
		string getTipo();
		string getId();
	};
#endif