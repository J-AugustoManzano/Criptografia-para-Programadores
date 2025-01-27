#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string cifraJump5(const string &numeroOriginal, bool cifrar = true)
{
    unordered_map<char, char> mapaCifra = {
        {'1', '9'}, {'2', '8'}, {'3', '7'},
        {'4', '6'}, {'5', '0'}, {'6', '4'},
        {'7', '3'}, {'8', '2'}, {'9', '1'},
        {'0', '5'}};

    string numeroTransformado;
    for (char digito : numeroOriginal)
    {
        if (mapaCifra.find(digito) != mapaCifra.end())
        {
            numeroTransformado.push_back
            (
                cifrar ? mapaCifra[digito] : mapaCifra[digito]
            );
        }
        else
        {
            numeroTransformado.push_back(digito);
        }
    }
    return numeroTransformado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: JUMP 5" << endl;
    cout << endl;

    cout << "Informe numero a ser cifrado ..: ";
    string numeroOriginal;
    getline(cin, numeroOriginal);

    string numeroCifrado = cifraJump5(numeroOriginal, true);
    string numeroDecifrado = cifraJump5(numeroCifrado, false);

    cout << endl;
    cout << "Numero com cifragem ..: " << numeroCifrado << endl;
    cout << "Numero sem cifragem ..: " << numeroDecifrado << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
