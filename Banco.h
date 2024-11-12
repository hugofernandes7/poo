#pragma once
#include "Conta.h"
#include "Prazo.h"
#include "Ordem.h"
#include "Colecao.h"
#include "Cliente.h"
#include <iostream>
using namespace std;

class Cliente;
class Conta;


class Banco {
	string nomeBanco;
	int idBanco;
	Colecao <Ordem> contasOrdem;
	Colecao <Conta> contas;
	Colecao <Prazo> contasPrazo;
	Colecao <Cliente> clientes;
public:
	Banco(string _nomeBanco, int _idBanco);
	bool addCliente(string _nomeCliente, int _clienteContacto);
	Cliente* findCliente(int _clienteId);
	Ordem* findContaOrdem(string _nib);
	Prazo* findContaPrazo(string _nib);
	bool addContaCliente(int _clienteId, float _saldo, int tipo); 
	void levantamento(float _montante, string nib);
	void deposito(float _montante, string nib);
	int numClientes(int _idBanco);
	void printClientes();
	void printBanco()const;
};