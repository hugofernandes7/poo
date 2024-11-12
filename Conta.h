#pragma once
#include <string>
using namespace std;



class Conta {
protected:
	int clienteId;
	string nomeCliente;
	string nibConta;
	static int countercontaID;
	int contaId;
	float saldo;
	int tipo;
public:
	Conta(int _clienteId, float _saldo);
	Conta(string _nib);
	bool operator < (const Conta& other)const;
	float getSaldo()const;
	//int getTipo()const;
	bool depositar(float valorDeposito);
	void setNib(int _bancoId, int _clienteId, int _contaId);
	string getNib()const;
	int getCliente();
	bool validarNib(string _nib);
	int sumDigits(const string& str);
};