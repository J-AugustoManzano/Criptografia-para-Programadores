#include <iostream>
#include <string>
using namespace std;

long strpos(const string mensagem, const char c)
{
    for (int i = 0; mensagem[i]; ++i)
    {
        if (mensagem[i] == c)
            return i;
    }
    return 0;
}

string cifraKamaSutra(string texto, bool cifrar = true)
{
    string mensagem;
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cifrador = "VHMXUWIBGKJRCSQYOLNZEAFDPT";

    for (int i = 0; i <= texto.length() - 1; ++i)
    {
        if (texto[i] == ' ')
            mensagem += ' ';
        if (texto[i] >= 'A' and texto[i] <= 'Z')
        {
            if (cifrar)
                mensagem += cifrador[strpos(alfabeto, texto[i])];
            else
                mensagem += alfabeto[strpos(cifrador, texto[i])];
        }
    }
    return mensagem;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: KAMA-SUTRA" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraKamaSutra(mensagemOriginal, true);
    string mensagemDecifrada = cifraKamaSutra(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
