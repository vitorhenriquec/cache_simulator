#include"../include/bloco.hpp"

Bloco::Bloco(){
	idBloco = "N";
	endereco = "N";
	conteudo = "0";
}

Bloco::~Bloco(){

}

string Bloco::getEndereco(){
	return endereco;
}

string Bloco::getIdBloco(){
	return idBloco;
}

void Bloco::setIdBloco(string idBloco){
	this->idBloco = idBloco;
}

void Bloco::setEndereco(string endereco){
	this->endereco = endereco;
}

void Bloco::setConteudo(string conteudo){
	this->conteudo = conteudo;
}

ostream& operator<<(ostream &o, Bloco &b){
	o << b.idBloco << " - " << b.endereco << " - " << b.conteudo;
	return o;
}
