#ifndef BIB_H
#define BIB_H

#include<ostream>
#include<istream>
#include<string>
#include <iostream>
#include<vector>
using namespace std;

#include"midias.hpp"
#include"cd.hpp"
#include"livro.hpp"
#include"dvd.hpp"

class Biblioteca{
	private:
		vector<Midias *> acervo;
	public:
		Biblioteca();
		~Biblioteca();
		void adicionarMidia(Midias *m); //Não adicionar elementos repetidos
		void removerMidia(string id);
		void editarMidia(string id);
		void verAcervo();
		void verEstatisticas();
		/*friend istream& operator>>(istream &i, Gerente &f);
		friend ostream& operator<<(ostream &o, const Gerente &f);*/
};

#endif