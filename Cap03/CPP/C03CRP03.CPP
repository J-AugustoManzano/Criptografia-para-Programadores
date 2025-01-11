#include <iostream>
#include <string>
using namespace std;

string cifraAlbam(const string &texto, bool cifrar = true)
{
    string mensagem;
    for (char c : texto)
    {
        if (c == ' ')
            mensagem += ' ';

        if (isupper(c))
        {
            if (cifrar)
            {
                if (c >= 'N' && c <= 'Z')
                    mensagem += c - 13;
                else
                    mensagem += c + 13;
            }
            else
            {
                if (c <= 'M')
                    mensagem += c + 13;
                else
                    mensagem += c - 13;
            }
        }
    }
    return mensagem;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: ALBAM" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraAlbam(mensagemOriginal);
    string mensagemDecifrada = cifraAlbam(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
