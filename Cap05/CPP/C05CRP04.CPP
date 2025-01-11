#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

string myHash4(string mensagem)
{
    unsigned long hashCalculado = 0;
    unsigned int peso = 1;
    const unsigned primo = 2147483647;

    for (char c : mensagem)
    {
        hashCalculado = (hashCalculado * primo) + static_cast<unsigned long>(c) * peso;
        peso++;
    }

    stringstream hash;
    hash << setfill('0') << setw(12) << hex << hashCalculado;
    return hash.str();
}

int main(void)
{
    string texto;

    cout << "FUNCAO HASH CRIPTOGRAFADA: MYHASH4" << endl;
    cout << endl;

    cout << "Informe mensagem ..: ";
    getline(cin, texto);

    cout << endl;
    cout << "Hash da mensagem ..: " << myHash4(texto) << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
