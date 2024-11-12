#include "Cliente.h"
#include "Prazo.h"
#include "Ordem.h"

int Cliente::counterclienteID = 1;

Cliente::Cliente(string _nomeCliente, int _clienteContacto): clienteContacto(_clienteContacto), nomeCliente(_nomeCliente) {
	clienteId = counterclienteID++;
}

Cliente::Cliente(int _clienteId) : clienteId(_clienteId) {}


int Cliente::getClienteID()const{return clienteId;}

string Cliente::getNome()const { return nomeCliente;}
int Cliente::getContacto()const { return clienteContacto;}

bool Cliente::operator<(const Cliente& other)const{
	return clienteId < other.clienteId;
}

void Cliente::setContacto(int novoContacto) {
	if (clienteContacto == novoContacto) {
		cout << "Insira um contacto diferente ao ja existente!" <<endl;
	}
	else {
		clienteContacto = novoContacto;
	}
}

void Cliente::setNome(string novoNome) {
	nomeCliente = novoNome;
}

bool Cliente::addContaPrazo(Conta cop) {
	return contasPrazo.insert(cop);
}

bool Cliente::addContaOrdem(Conta coo) {
	return contasOrdem.insert(coo);
}





	