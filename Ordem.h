#pragma once
#include "Conta.h"
#include "string"


class Ordem : public Conta {
protected:
	float plafond;
public:
	Ordem(int _clienteId, float _saldo);
	Ordem(string _nib);
	bool operator<(const Ordem& other)const;
	float getPlafond()const;
	void levantar(float montante);
	int getClienteID()const;
	float setPlafond(float _saldo);
};