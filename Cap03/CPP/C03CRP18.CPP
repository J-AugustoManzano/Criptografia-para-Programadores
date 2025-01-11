#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cifraKeyLess(const string &texto, bool cifrar = true)
{
    string resultado;
    size_t tamanho = texto.length();

    if (cifrar)
    {
        for (size_t i = 0; i < tamanho; i += 2)
            resultado.push_back(texto[i]);
        for (size_t i = 1; i < tamanho; i += 2)
            resultado.push_back(texto[i]);
    }
    else
    {
        for (size_t i = 0; i < tamanho / 2 + tamanho % 2; ++i)
        {
            resultado.push_back(texto[i]);
            if (i + tamanho / 2 + tamanho % 2 < tamanho)
                resultado.push_back(texto[i + tamanho / 2 + tamanho % 2]);
        }
    }
    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: KEYLESS" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraKeyLess(mensagemOriginal);
    string mensagemDecifrada = cifraKeyLess(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
