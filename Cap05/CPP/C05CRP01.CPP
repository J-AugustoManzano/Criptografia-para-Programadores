#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string myHash1(const string &mensagem)
{
    unsigned long hashCalculado = 0;
    for (char c : mensagem)
        hashCalculado += c;

    stringstream hash;
    hash << setfill('0') << setw(10) << hashCalculado;
    return hash.str();
}

int main(void)
{
    string texto;

    cout << "FUNCAO HASH CRIPTOGRAFADA: MYHASH1" << endl << endl;

    cout << "Informe mensagem ..: ";
    getline(cin, texto);

    cout << endl;
    cout << "Hash da mensagem ..: " << myHash1(texto) << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
