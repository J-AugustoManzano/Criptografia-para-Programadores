#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cifraGronsfeld(string texto, string chv, bool cifrar = true)
{
    string mensagem, chvnr;
    int j = 0;

    for (int i = 0; i <= chv.length() - 1; ++i)
        if (chv[i] >= '0' and chv[i] <= '9')
            chvnr += chv[i];

    for (int i = 0; i <= texto.length() - 1; ++i)
    {
        if (texto[i] == ' ')
        {
            mensagem += ' ';
            continue;
        }

        int ajuste = cifrar ? 1 : -1;  // Ajuste para decifrar
        char letra = (texto[i] - 'A' + ajuste * stoi(chvnr.substr(j, 1)) + 26) % 26 + 'A';
        mensagem += letra;
        j = (j + 1) % chvnr.length();
    }

    return mensagem;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: GRONSFELD" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ...: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string chave;
    cout << "Informe a palavra chave numerica .: ";
    cin >> chave;

    string mensagemCifrada = cifraGronsfeld(mensagemOriginal, chave);
    string mensagemDecifrada = cifraGronsfeld(mensagemCifrada, chave, false);

    cout << endl;
    cout << "Mensagem com cifragem ...: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ...: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.ignore();
    cin.get();

    return 0;
}
