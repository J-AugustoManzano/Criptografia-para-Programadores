#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

string myHash2(string mensagem)
{
    unsigned long hashCalculado = 0;
    unsigned int peso = 1;

    for (char c : mensagem)
    {
        hashCalculado += static_cast<unsigned long>(c) * peso;
        // Incrementa peso às posições dos caracteres na mensagem.
        peso++;
    }

    stringstream hash;
    hash << setfill('0') << setw(10) << hashCalculado;
    return hash.str();
}

int main(void)
{
    string texto;

    cout << "FUNCAO HASH CRIPTOGRAFADA: MYHASH2" << endl;
    cout << endl;

    cout << "Informe mensagem ..: ";
    getline(cin, texto);

    cout << endl;
    cout << "Hash da mensagem ..: " << myHash2(texto) << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
