#include <iostream>
#include <string>
#include <bitset>
#include <algorithm> // Para a função transform
using namespace std;

string palavraParaChave(const string &palavra)
{
    int somaAscii = 0;

    for (char c : palavra)
        somaAscii += static_cast<int>(c);

    // Converte a soma ASCII para sequência binária
    string chaveBinaria = bitset<8>(somaAscii).to_string();

    return chaveBinaria;
}

string ajustarChave(const string &chave, size_t tamanhoMensagem)
{
    string chaveAjustada;

    for (size_t i = 0; i < tamanhoMensagem; ++i)
        chaveAjustada += chave[i % chave.length()];

    return chaveAjustada;
}

string cifraXOR(const string &texto, const string &chave)
{
    string chaveAjustada = ajustarChave(chave, texto.length());
    string resultado = "";

    for (size_t i = 0; i < texto.length(); ++i)
    {
        if (texto[i] == ' ')
            resultado += ' ';
        else
            resultado += toupper(texto[i] ^ chaveAjustada[i]);
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: XOR" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string chave;
    cout << "Informe a palavra chave .........: ";
    getline(cin, chave);

    // Obtém a sequência binária da soma ASCII da palavra-chave
    string chvBin = palavraParaChave(chave);

    string mensagemCifrada = cifraXOR(mensagemOriginal, chvBin);
    string mensagemDecifrada = cifraXOR(mensagemCifrada, chvBin);

    cout << endl;
    cout << "Mensagem com cifragem ...: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ...: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
