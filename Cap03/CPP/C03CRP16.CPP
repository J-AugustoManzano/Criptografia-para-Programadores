#include <iostream>
#include <string>
#include <cctype>
using namespace std;

long strpos(const string &mensagem, char c)
{
    for (long i = 0; mensagem[i]; ++i)
    {
        if (mensagem[i] == c)
            return i;
    }
    return -1;
}

string cifraLexLuthor(const string &texto, bool cifrar = true)
{
    string mensagem;
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cifrador = "UZYXOWVTISRQPNEMLKJHAGFDCB";

    for (char c : texto)
    {
        if (c == ' ')
            mensagem += ' ';

        if (isupper(c))
        {
            if (cifrar)
                mensagem += cifrador[strpos(alfabeto, c)];
            else
                mensagem += alfabeto[strpos(cifrador, c)];
        }
    }
    return mensagem;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: LEX LUTHOR" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraLexLuthor(mensagemOriginal);
    string mensagemDecifrada = cifraLexLuthor(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
