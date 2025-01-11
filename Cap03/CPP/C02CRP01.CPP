#include <iostream>
#include <string>
#include <cctype>  // Para isupper
using namespace std;

string cifraAtbash(const string &texto)
{
    string mensagem;
    for (char c : texto)
    {
        if (c == ' ')
            mensagem += ' ';
        if (isupper(c))
            mensagem += char(155 - c);
    }
    return mensagem;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: ATBASH" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraAtbash(mensagemOriginal);
    string mensagemDecifrada = cifraAtbash(mensagemCifrada);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
