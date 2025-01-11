#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cifraAutokey(string texto, string chv, bool cifra = true)
{
    string resultado = "";
    string chvAtual = chv;

    for (int i = 0; i < texto.length(); ++i)
    {
        if (isalpha(texto[i]))
        {
            char base = isupper(texto[i]) ? 'A' : 'a';
            int textoInd = texto[i] - base;
            int chvAjustada = chvAtual[i] - base;

            char caractere;
            if (cifra)
                caractere = (textoInd + chvAjustada) % 26 + base;
            else
                caractere = (textoInd - chvAjustada + 26) % 26 + base;

            resultado += caractere;
            chvAtual += (cifra ? texto[i] : caractere);
        }
        else
            resultado += texto[i];
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: AUTOKEY" << endl;
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

    string mensagemCifrada = cifraAutokey(mensagemOriginal, chave, true);
    string mensagemDecifrada = cifraAutokey(mensagemCifrada, chave, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
