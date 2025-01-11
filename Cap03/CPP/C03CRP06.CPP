#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cifraCaesarPolialfabetico(string mensagem, bool cifrar = true)
{
    string resultado = "";

    int deslocamento = 3;

    for (int i = 0; i < mensagem.length(); i++)
    {
        char c = mensagem[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';

            if (cifrar)
                c = (c - base + deslocamento) % 26 + base;
            else
                c = (c - base - deslocamento + 26) % 26 + base;

            deslocamento++;
        }
        resultado += c;
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: CAESAR POLIALFABETICO" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraCaesarPolialfabetico(mensagemOriginal, true);
    string mensagemDecifrada = cifraCaesarPolialfabetico(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
