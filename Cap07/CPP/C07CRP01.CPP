#include <iostream>
#include <string>
using namespace std;

string cifraBloco(const string &bloco, int chave, bool cifrar = true)
{
    string resultado = bloco;

    for (char &caractere : resultado)
        if (cifrar)
            caractere = (caractere + chave) % 128;
        else
            caractere = (caractere - chave + 128) % 128;

    return resultado;
}

int main(void)
{
    int chave = 3;

    cout << "CRIPTOGRAFIA DE BLOCO: SIMPLES" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string blocoOriginal;
    getline(cin, blocoOriginal);
    transform(blocoOriginal.begin(), blocoOriginal.end(), blocoOriginal.begin(), ::toupper);

    string blocoCifrado = cifraBloco(blocoOriginal, chave);
    string blocoDecifrado = cifraBloco(blocoCifrado, chave, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << blocoCifrado << endl;
    cout << "Mensagem sem cifragem ..: " << blocoDecifrado << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
