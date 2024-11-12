#include "Conta.h"
#include <iostream>

//int Conta::getTipo() const { return tipo; }

int Conta::countercontaID = 1;


Conta::Conta(int _clienteId, float _saldo) :clienteId(_clienteId), saldo(_saldo) {
    contaId = countercontaID++;
    setNib(343, _clienteId, contaId);
    if (validarNib(nibConta) != true) cout << "Nib invalido!" << endl;
}

Conta::Conta(string _nib) :nibConta(_nib) {}


int Conta::getCliente() { return clienteId; };

float Conta::getSaldo() const {
    return saldo;
}
bool Conta::operator<(const Conta& other) const {
    return nibConta < other.nibConta;
}

void Conta::setNib(int _bancoId, int _clienteId, int _contaId) {
    char _nib[] = "AAAABBBBCCCCD";
    snprintf(_nib, sizeof(_nib), "%04d%04d%04d", _bancoId, _clienteId, _contaId);
    _nib[12] = static_cast<char>((sumDigits(_nib) % 9 + 1) + '0');
    nibConta = _nib;
}

bool Conta::validarNib(string _nib) {
    return (sumDigits(_nib) - (_nib[12] - '0')) % 9 + 1 == _nib[12] - '0';
}

int Conta::sumDigits(const string& str) {
    int sum = 0;
    for (char c : str) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

string Conta::getNib() const { return nibConta; }

bool Conta::depositar(float valorDeposito) {
    if (valorDeposito > 0) {
        saldo += valorDeposito;
        return true;
    }
    return false;
}

