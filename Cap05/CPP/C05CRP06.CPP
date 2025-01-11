#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

size_t calculaSal(const string &texto)
{
    const int p = 31;
    const int m = 1e9 + 9;

    size_t sal = 0;
    size_t potenciaPrimo = 1;

    for (char c : texto)
    {
        sal = (sal + (c - 'a' + 1) * potenciaPrimo) % m;
        potenciaPrimo = (potenciaPrimo * p) % m;
    }

    return sal;
}

size_t myHash6(const string &texto)
{
    const int p = 31;
    const int m = 1e9 + 9;

    int tamanhoJanela = min(4, static_cast<int>(texto.length()));

    size_t hash = 0;
    size_t potenciaPrimo = 1;

    // Calcular o hash inicial
    for (int i = 0; i < tamanhoJanela; ++i)
    {
        hash = (hash + (texto[i] - 'a' + 1) * potenciaPrimo) % m;
        potenciaPrimo = (potenciaPrimo * p) % m;
    }

    // Adicionar "sal" ao hash inicial
    hash = (hash + calculaSal(texto)) % m;

    // Calcula hash para as janelas subsequentes
    for (int i = tamanhoJanela; i < texto.length(); ++i)
    {
        hash = (hash - (texto[i - tamanhoJanela] - 'a' + 1) * potenciaPrimo) % m;
        hash = (hash * p + (texto[i] - 'a' + 1)) % m;
        if (hash < 0)
            hash += m; // Garante resultado positivo
    }

    // Adicionar "sal" ao hash final
    hash = (hash + calculaSal(texto)) % m;

    return hash;
}

int main(void)
{
    string texto;

    cout << "FUNCAO HASH CRIPTOGRAFADA: MYHASH6" << endl;
    cout << endl;

    cout << "Informe mensagem ..: ";
    getline(cin, texto);

    cout << endl;
    cout << "Hash da mensagem ..: " << hex << setw(16) << setfill('0') << myHash6(texto) << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
