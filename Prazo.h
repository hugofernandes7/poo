#pragma once
#include "Conta.h"
#include <string>
using namespace std;


class Prazo : public Conta{
protected:
	float taxaJuro;
public:
	Prazo(int _clienteId, float _saldo);
	Prazo(string _nib);
	bool operator<(const Prazo& other)const;
	float getTaxaJuro()const;
	int getClienteID()const;
	void setTaxaJuro(float _taxaJuro);
};