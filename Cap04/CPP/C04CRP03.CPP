#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
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

string cifraTextualNumerical(const string &num, bool cifrar = true)
{
    string vlr;
    string numerico = "0123456789";
    string cifrador = "AWQRCXEZYG";

    for (int i = 0; i <= num.length() - 1; ++i)
    {
        if (cifrar)
        {
            if (num[i] == '.')
            {
                vlr += 'I';
                i++;
            }
            if (num[i] == ',')
            {
                vlr += 'K';
                i++;
            }
            if (num[i] >= '0' and num[i] <= '9')
                vlr += cifrador[strpos(numerico, num[i])];
        }
        else
        {
            if (num[i] == 'I')
            {
                vlr += '.';
                i++;
            }
            if (num[i] == 'K')
            {
                vlr += ',';
                i++;
            }
            if (num[i] >= 'A' and num[i] <= 'Z')
                vlr += numerico[strpos(cifrador, num[i])];
        }
    }

    return vlr;
}

int main(void)
{
    string numeroOriginal, numeroCifrado, numeroDecifrado;

    cout << "CRIPTOGRAFIA: TEXTUAL NUMERICAL" << endl;
    cout << endl;

    cout << "Informe numero a ser cifrado ..: ";
    getline(cin, numeroOriginal);

    numeroCifrado = cifraTextualNumerical(numeroOriginal, true);
    numeroDecifrado = cifraTextualNumerical(numeroCifrado, false);

    cout << endl;
    cout << "Numero com cifragem ..: " << numeroCifrado << endl;
    cout << "Numero sem cifragem ..: " << numeroDecifrado << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
