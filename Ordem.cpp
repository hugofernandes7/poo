#include "Ordem.h"
#include "Conta.h"
#include <iostream>


Ordem::Ordem(int _clienteId, float _saldo) : Conta(_clienteId, _saldo) {
    clienteId = _clienteId;
    saldo = _saldo;
    plafond = setPlafond(_saldo);
}

Ordem::Ordem(string _nib) :Conta(_nib) {}

bool Ordem::operator<(const Ordem& other)const {
    return nibConta < other.nibConta;
}

float Ordem::getPlafond() const{
    return plafond;
}
float Ordem::setPlafond(float _saldo) {
    plafond = _saldo * -1;
    return plafond;
}
int Ordem::getClienteID()const {
    return clienteId;
}
void Ordem::levantar(float montante) {
    if ((saldo - montante) < plafond) {
        cout << "Valor de levantamento excede o plafond!" << endl;
    }
    else {
        saldo -= montante;
        cout << "Foram retirados " << montante << " EUR da sua conta!" << endl;
    }
}
