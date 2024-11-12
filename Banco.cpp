#include "Banco.h"
#include "Cliente.h"
#include "Prazo.h"
#include "Ordem.h"
#include "iostream"


Banco::Banco(string _nomeBanco, int _bancoId) : nomeBanco(_nomeBanco), idBanco(_bancoId){}

int Banco::numClientes(int _idBanco) {return clientes.size();}

bool Banco::addCliente(string _nomeCliente, int _clienteContacto) {
	Cliente c(_nomeCliente,_clienteContacto);
    clientes.insert(c);
    addContaCliente((c.getClienteID()), 50, 2); // Adiciona automaticamente uma conta a Ordem com 200 EUR iniciais.
    cout << "Conta à ordem gerada automaticamente pelo banco com um saldo minimo de 50 EUR." << endl;
    cout << "ID: " << c.getClienteID()<< endl;
	return true;
}

Cliente* Banco::findCliente(int _clienteId) {
	Cliente fc(_clienteId);
	return clientes.find(fc);
}

Ordem* Banco::findContaOrdem(string _nib) {
	Ordem fco(_nib);
	return contasOrdem.find(fco);
}

Prazo* Banco::findContaPrazo(string _nib) {
	Prazo fcp(_nib);
	return contasPrazo.find(fcp);
}

bool Banco::addContaCliente(int _clienteId, float _saldo, int _tipo) {
    Cliente* fcl = findCliente(_clienteId);
    if (fcl != NULL) {
        if (_tipo == 1) {
            Prazo cop(_clienteId, _saldo);
            fcl->addContaPrazo(cop);
            cout << "Conta a Prazo criada com sucesso com o NIB: " << cop.getNib() << endl;
            return contasPrazo.insert(cop);
        }
        else if (_tipo == 2) {
            Ordem coo(_clienteId, _saldo);
            fcl->addContaOrdem(coo);
            cout << "Conta a Ordem criada com sucesso com o NIB: " << coo.getNib() << endl;
            return contasOrdem.insert(coo);
        }
        else {
            cout << "Tipo de conta inválido!" << endl;
            return false;
        }
    }
    else {
        cout << "Cliente nao encontrado !" << endl;
        return false;
    }
}

void Banco::levantamento(float montante, string _nib) {
    Ordem* fc = findContaOrdem(_nib);
    if (fc != NULL) {
        fc->levantar(montante);
        cout << "Saldo: " << fc->getSaldo()<< endl;
    }
    else
        cout << "Conta Ordem nao encontrada!" << endl;
}

void Banco::deposito(float montante, string _nib) {
    Conta* fco = findContaOrdem(_nib);
    Conta* fcp = findContaPrazo(_nib);
    if (fco !=NULL ) {
        fco->depositar(montante);
        cout << "\nForam depositados " << montante << "EUR na sua conta." << endl;
        cout << "Saldo: " << fco->getSaldo() << endl;
        }
    else if (fcp != NULL) {
        fcp->depositar(montante);
        cout << "\nForam depositados " << montante << "EUR na sua conta." << endl;
        cout << "Saldo: " << fcp->getSaldo() << endl;
    }
    else cout << "Conta nao encontrada!" << endl;
}

void Banco::printClientes() {
    Colecao <Ordem> ::iterator o;
    Colecao <Prazo> ::iterator p;
    Colecao <Cliente> ::iterator c;
    if (clientes.size() == 0) {
        cout << "Não existem clientes registados!" << endl;
    }
    else {
        for (c = clientes.begin(); c != clientes.end(); c++) {
            cout << "clienteId: " << c->getClienteID() << endl;
            cout << "Nome: " << c->getNome() << endl;
            cout << "Telemovel: " << c->getContacto() << endl;
            cout << "Contas: " << endl;
            cout << '\t' << "Ordem: " << endl;
            bool temContaOrdem = false;
            for (o = contasOrdem.begin(); o != contasOrdem.end(); o++) {
                if (o->getClienteID() == c->getClienteID()) {
                    temContaOrdem = true;
                    cout << "\t\t-NIB: " << o->getNib() << endl;
                    cout << "\t\tSaldo: " << o->getSaldo() << " EUR (min.: " << o->getPlafond() << " EUR)" << endl;
                }
            }
            if (!temContaOrdem) {
                cout << "\t\tSem contas à ordem para exibir!" << endl;
            }

            cout << '\t' << "Prazo: " << endl;
            bool temContaPrdem = false;
            for (p = contasPrazo.begin(); p != contasPrazo.end(); p++) {
                if (p->getClienteID() == c->getClienteID()) {
                    temContaPrdem = true;
                    cout << "\t\t-NIB: " << p->getNib() << endl;
                    cout << "\t\tSaldo: " << p->getSaldo() << " EUR (Taxa Aplicada: " << p->getTaxaJuro() << " %)" << endl;
                }
            }
            if (!temContaPrdem) {
                cout << "\t\tSem contas prazo para exibir!" << endl;
            }
        }
    }
}


void Banco::printBanco() const {
    cout << "bancoID: " << idBanco << endl;
    cout << "Nome: " << nomeBanco << endl;
}


