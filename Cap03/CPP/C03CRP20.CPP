#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cifraTrithemius(const string &mensagem, bool cifrar = true)
{
    string resultado = "";
    int deslocamento = 0;

    for (char c : mensagem)
    {
        if (c == ' ')
            resultado += ' ';
        else
        {
            char caractereCifrado;
            if (cifrar)
                caractereCifrado = ((c - 'A' + deslocamento) % 26) + 'A';
            else
                caractereCifrado = ((c - 'A' - deslocamento + 26) % 26) + 'A';
            resultado += caractereCifrado;
            deslocamento++;
        }
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: TRITHEMIUS (TABULA RECTA)" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraTrithemius(mensagemOriginal);
    string mensagemDecifrada = cifraTrithemius(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ...: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ...: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
