#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

long strpos(const string mensagem, const char c)
{
    for (int i = 0; mensagem[i]; ++i)
    {
        if (mensagem[i] == c)
            return i;
    }
    return 0;
}

string cifraRot5(string numero)
{
    string valor;
    string numerico = "0123456789";
    string cifrador = "5678901234";

    for (int i = 0; i <= numero.length() - 1; ++i)
    {
        if (numero[i] == '.')
            valor += '.';
        if (numero[i] == ',')
            valor += ',';
        if (numero[i] >= '0' and numero[i] <= '9')
            valor += cifrador[strpos(numerico, numero[i])];
    }

    return valor;
}

int main(void)
{
    string numeroOriginal, numeroCifrado, numeroDecifrado;

    cout << "CRIPTOGRAFIA: ROT5" << endl;
    cout << endl;

    cout << "Informe numero a ser cifrado ..: ";
    getline(cin, numeroOriginal);

    numeroCifrado = cifraRot5(numeroOriginal);
    numeroDecifrado = cifraRot5(numeroCifrado);

    cout << endl;
    cout << "Numero com cifragem ..: " << numeroCifrado << endl;
    cout << "Numero sem cifragem ..: " << numeroDecifrado << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
