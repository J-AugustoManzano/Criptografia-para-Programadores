#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

string myHash5(string mensagem)
{
    unsigned long hashCalculado = 0;
    unsigned int peso = 1;
    const unsigned primo = 2147483647;

    srand(static_cast<unsigned int>(time(nullptr)));
    unsigned int sal = rand() % 1000000;

    for (char c : mensagem)
    {
        hashCalculado = (hashCalculado * primo) + static_cast<unsigned long>(c) * peso;
        peso++;
    }

    hashCalculado += sal;

    stringstream hash;
    hash << setfill('0') << setw(12) << hex << hashCalculado;
    return hash.str();
}

int main(void)
{
    string texto;

    cout << "FUNCAO HASH CRIPTOGRAFADA: MYHASH5" << endl;
    cout << endl;

    // Cadastro do USUÁRIO 1
    cout << "USUARIO 1" << endl;
    cout << "Informe senha para cadastro ..: ";
    getline(cin, texto);
    cout << "Hash gerado  .................: " << myHash5(texto) << endl << endl;

    // Cadastro do USUÁRIO 2
    cout << "USUARIO 2" << endl;
    cout << "Informe senha para cadastro ..: ";
    getline(cin, texto);
    cout << "Hash gerado  .................: " << myHash5(texto) << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
