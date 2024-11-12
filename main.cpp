#include <iostream>
#include <string>
#include <locale.h>
#include "Banco.h"
using namespace std;



int menu() {
    int opcao;

    cout << "--------------MENU--------------" << endl;
    cout << "# 1) Adicionar cliente." << endl;
    cout << "# 2) Adicionar conta ao cliente." << endl;
    cout << "# 3) Mostrar clientes." << endl;
    cout << "# 4) Fazer um levantamento." << endl;
    cout << "# 5) Fazer um depósito." << endl;
    cout << "# 0) Sair." << endl;
    cout << "--------------------------------" << endl;


    cout << endl;

    cout << "Escolha a opção: ";
    cin >> opcao;

    return opcao;

}

int main() {

    setlocale(LC_ALL, "Portuguese");
    Banco b("Bringantino", 343);
    b.printBanco();
    int opcao;
    string nome;
    int tipoConta;
    int ntelemovel;
    float saldo = 0;
    int idCliente = 0;
    string nib;
    float montante;

    cout << endl;
    while ((opcao = menu()) != 0) {
        switch (opcao) {
        case 1:
            cout << "Insira o nome da Pessoa: ";
            fseek(stdin, 0, SEEK_END);
            cin >> nome;
            fseek(stdin, 0, SEEK_END);
            cout << "Insira o contacto: ";
            cin >> ntelemovel;
            fseek(stdin, 0, SEEK_END);
            b.addCliente(nome, ntelemovel);
            cout << endl;
            break;
        case 2:
            cout << "Insira o id do cliente: "; cin >> idCliente;
            fseek(stdin, 0, SEEK_END);
            cout << "Insira o saldo inicial da conta: "; cin >> saldo;
            fseek(stdin, 0, SEEK_END);
            cout << "Insira o tipo de conta (1 -> Prazo | 2-> Ordem): "; cin >> tipoConta;
            fseek(stdin, 0, SEEK_END);
            b.addContaCliente(idCliente, saldo, tipoConta);
            cout << endl;
            break;
        case 3:
            b.printClientes();
            cout << endl;
            break;
        case 4: cout << "Insira o nib da conta para a qual pretende fazer o levantamento: "; cin >> nib;
            fseek(stdin, 0, SEEK_END);
            cout << "Insira o montante a retirar: "; cin >> montante;
            b.levantamento(montante, nib);
            break;
        case 5: cout << "Insira o nib da conta para a qual pretende fazer o depósito: "; cin >> nib;
            fseek(stdin, 0, SEEK_END);
            cout << "Insira o montante: "; cin >> montante;
            b.deposito(montante, nib);
            break;
        default:
            cout << "Insira uma opcao valida!" << endl;
            break;
        }
    }
    cout << "A sair do programa..." << endl;
    return 0;
}