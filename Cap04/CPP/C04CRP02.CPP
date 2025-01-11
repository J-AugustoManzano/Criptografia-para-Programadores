#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

string cifraVigenereNum(string num, string chv, bool cifrar = true)
{
    string numero;
    int j = 0;

    for (int i = 0; i < num.length(); ++i)
    {
        if (num[i] == ' ')
        {
            numero += ' ';
            ++i;
        }
        if (isdigit(num[i]))
        {
            int base = '0';
            int chvNum = chv[j] - '0';
            if (cifrar)
                numero += ((num[i] - base + chvNum) % 10) + base;
            else
                numero += ((num[i] - base - chvNum + 10) % 10) + base;
            j = (j + 1) % chv.length();
        }
        else
            numero += num[i];
    }
    return numero;
}

int main(void)
{
    string numeroOriginal, numeroCifrado, numeroDecifrado;

    cout << "CRIPTOGRAFIA: VIGENERE NUMERICO" << endl;
    cout << endl;

    cout << "Informe numero a ser cifrado ..: ";
    getline(cin, numeroOriginal);

    string chave;
    cout << "Informe chave numerica ........: ";
    cin >> chave;
    cin.ignore(80, '\n');

    numeroCifrado = cifraVigenereNum(numeroOriginal, chave, true);
    numeroDecifrado = cifraVigenereNum(numeroCifrado, chave, false);

    cout << endl;
    cout << "Numero com cifragem ..: " << numeroCifrado << endl;
    cout << "Numero sem cifragem ..: " << numeroDecifrado << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
