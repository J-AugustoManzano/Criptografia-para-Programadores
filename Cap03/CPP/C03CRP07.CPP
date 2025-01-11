#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cifraAffine(string texto, int a, int b, bool cifrar = true)
{
    string resultado = "";

    for (char &c : texto)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            if (cifrar)
                c = (a * (c - base) + b) % 26 + base;
            else
            {
                int a_inv = 0;
                int flag = 0;

                for (int i = 0; i <= 25; ++i)
                {
                    flag = (a * i) % 26;
                    if (flag == 1)
                        a_inv = i;
                }

                c = (a_inv * (c - base - b + 26) % 26) + base;
            }
        }
        resultado += c;
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: AFFINE" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraAffine(mensagemOriginal, 55, 20);
    string mensagemDecifrada = cifraAffine(mensagemCifrada, 55, 20, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
