#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cifraVernam(string texto, string chv, bool cifra = true)
{
    string resultado = "";

    for (int i = 0; i < texto.length(); ++i)
    {
        if (isalpha(texto[i]))
        {
            char base = isupper(texto[i]) ? 'A' : 'a';
            int indiceCar = texto[i] - base;
            int indiceChv = chv[i % chv.length()] - base;

            char caractere;
            if (cifra)
                caractere = (indiceCar + indiceChv) % 26 + base;
            else
                caractere = (indiceCar - indiceChv + 26) % 26 + base;

            resultado += caractere;
        }
        else
            resultado += texto[i];
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: VERNAM" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string chave;
    cout << "Informe a chave .................: ";
    cin >> chave;
    cin.ignore(80, '\n');
    transform(chave.begin(), chave.end(), chave.begin(), ::toupper);

    string mensagemCifrada = cifraVernam(mensagemOriginal, chave);
    string mensagemDecifrada = cifraVernam(mensagemCifrada, chave, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
