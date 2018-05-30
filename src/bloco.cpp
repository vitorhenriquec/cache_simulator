#include"../include/bloco.hpp"

Bloco::Bloco(){
	
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

/*ostream& operator<<(ostream &o, Bloco &b){
	o << "Id: " << b.idBloco << endl;
	o << "Endereco" << b.endereco << endl;
	o << "Conteudo: " << b.conteudo << endl;
	return o;
}*/
