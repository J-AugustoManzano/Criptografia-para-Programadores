#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cifraCaesar(string mensagem, int chv = 3, bool cifrar = true)
{
    string resultado = "";

    for (char& c : mensagem)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            if (cifrar)
                c = (c - base + chv) % 26 + base;
            else
                c = (c - base - chv + 26) % 26 + base;
        }
        resultado += c;
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: CAESAR" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraCaesar(mensagemOriginal, 3, true);
    string mensagemDecifrada = cifraCaesar(mensagemCifrada, 3, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
