#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
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

void quebraCifraCaesar(const string& mensagem)
{
    cout << "Possiveis mensagens decifradas:" << endl;
    cout << endl;

    for (int desloc = 1; desloc <= 26; ++desloc)
    {
        string mensDecifrada = cifraCaesar(mensagem, desloc, false);
        cout << "Chave " << setfill('0') << setw(2) << desloc << ": " << mensDecifrada << endl;
    }
}

int main(void)
{
    string mensagem;

    cout << "CRIPTOLOGIA: ATAQUE POR FORCA BRUTA" << endl;
    cout << endl;

    cout << "Entre mensagem cifrada: ";
    getline(cin, mensagem);
    transform(mensagem.begin(), mensagem.end(), mensagem.begin(), ::toupper);
    cout << endl;

    quebraCifraCaesar(mensagem);

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}

