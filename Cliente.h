#pragma once
#include "Colecao.h"
#include "Conta.h"
#include <iostream>
using namespace std;


class Cliente{
	string nomeCliente;
	static int counterclienteID;
	int clienteId;
	int clienteContacto;
	Colecao<Conta>contasOrdem;
	Colecao<Conta>contasPrazo;
public:
	Cliente(string _nomeCliente, int _clienteContacto);
	Cliente(int _clienteId);
	bool operator<(const Cliente& other)const;
	string getNome()const;
	int getClienteID()const;
	int getContacto()const;
	void setNome(string novoNome);
	void setContacto(int novoContacto);
	bool addContaPrazo(Conta cop);
	bool addContaOrdem(Conta coo);
	void printCliente();
};
