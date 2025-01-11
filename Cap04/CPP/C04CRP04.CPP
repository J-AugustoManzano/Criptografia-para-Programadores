#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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

int getlet(int letra1, int letra2)
{
    return letra1 + rand() % (letra2 + 1 - letra1);
}

string cifraTelephoneKeypad(string num, bool cifra = true)
{
    string vlr;
    string numeric1 = "0123456789";
    string cifrador = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numeric2 = "22334455667788990011...,,,";
    int letra;

    if (cifra)
    {
        srand(time(NULL));
        for (int i = 0; i <= num.length() - 1; ++i)
        {
            if (num[i] == '.')
                vlr += getlet('U', 'W'), i++;
            if (num[i] == ',')
                vlr += getlet('X', 'Z'), i++;
            if (num[i] >= '0' and num[i] <= '9')
            {
                switch (strpos(numeric1, num[i]))
                {
                    case 0:
                        letra = getlet('Q', 'R');
                        break;
                    case 1:
                        letra = getlet('S', 'T');
                        break;
                    case 2:
                        letra = getlet('A', 'B');
                        break;
                    case 3:
                        letra = getlet('C', 'D');
                        break;
                    case 4:
                        letra = getlet('E', 'F');
                        break;
                    case 5:
                        letra = getlet('G', 'H');
                        break;
                    case 6:
                        letra = getlet('I', 'J');
                        break;
                    case 7:
                        letra = getlet('K', 'L');
                        break;
                    case 8:
                        letra = getlet('M', 'N');
                        break;
                    case 9:
                        letra = getlet('O', 'P');
                        break;
                }
                vlr += letra;
            }
        }
    }
    else
    {
        for (int i = 0; i <= num.length() - 1; ++i)
        {
            if (num[i] == 'U' or num[i] == 'V' or num[i] == 'W')
                vlr += '.', i++;
            if (num[i] == 'X' or num[i] == 'Y' or num[i] == 'Z')
                vlr += ',', i++;
            if (num[i] >= 'A' and num[i] <= 'Z')
                vlr += numeric2[strpos(cifrador, num[i])];
        }
    }

    return vlr;
}

int main(void)
{
    string numeroOriginal, numeroCifrado, numeroDecifrado;

    cout << "CRIPTOGRAFIA: TELEPHONE KEYPAD" << endl;
    cout << endl;

    cout << "Informe numero a ser cifrado ..: ";
    getline(cin, numeroOriginal);

    numeroCifrado = cifraTelephoneKeypad(numeroOriginal);
    numeroDecifrado = cifraTelephoneKeypad(numeroCifrado, false);

    cout << endl;
    cout << "Numero com cifragem ..: " << numeroCifrado << endl;
    cout << "Numero sem cifragem ..: " << numeroDecifrado << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
