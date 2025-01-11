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

string cifraVigenere(string texto, string chv, bool cifrar = true)
{
    string mensagem;
    int j = 0;

    for (int i = 0; i < texto.length(); ++i)
    {
        if (texto[i] == ' ')
        {
            mensagem += ' ';
            ++i;
        }
        if (isalpha(texto[i]))
        {
            char base = isupper(texto[i]) ? 'A' : 'a';
            if (cifrar)
                mensagem += (texto[i] + chv[j] - 2 * base) % 26 + base;
            else
                mensagem += (texto[i] - chv[j] + 26) % 26 + base;
            j = (j + 1) % chv.length();
        }
        else
            mensagem += texto[i];
    }
    return mensagem;
}

string cifraCaesarVig(const string &texto, string chv, bool cifrar = true)
{
    return cifraCaesarPolialfabetico(cifraVigenere(texto, chv, cifrar), cifrar);
}

int main(void)
{
    cout << "CRIPTOGRAFIA: CAESAR POLIALFABETICO COM VIGENERE" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string chave;
    cout << "Informe a palavra chave .........: ";
    cin >> chave;
    cin.ignore(80, '\n');
    transform(chave.begin(), chave.end(), chave.begin(), ::toupper);

    string mensagemCifrada = cifraCaesarPolialfabetico(mensagemOriginal, true);
    string mensagemDecifrada = cifraCaesarPolialfabetico(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
