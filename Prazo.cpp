#include "Prazo.h"
#include "Conta.h"
#include <iostream>


Prazo::Prazo(int _clienteId, float _saldo): Conta(_clienteId, _saldo) {
	taxaJuro = 5;
}
Prazo::Prazo(string _nib): Conta(_nib) {}

bool Prazo::operator<(const Prazo& other)const {
	return nibConta < other.nibConta;
}

float Prazo::getTaxaJuro() const{
	return taxaJuro;
}
int Prazo::getClienteID()const {
	return clienteId;
}
void Prazo::setTaxaJuro(float _taxaJuro) {
	taxaJuro = _taxaJuro;
}
