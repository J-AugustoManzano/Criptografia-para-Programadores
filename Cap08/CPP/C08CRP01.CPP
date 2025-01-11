#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

long long mdc(long long a, long long b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

bool primo(long long numero)
{
    if (numero < 2)
        return false;

    for (long long i = 2; i <= sqrt(numero); ++i)
        if (numero % i == 0)
            return false;

    return true;
}

long long modExp(long long a, long long b, long long n)
{
    long long resultado = 1;
    a = a % n;

    while (b > 0)
    {
        if (b % 2 == 1)
            resultado = (resultado * a) % n;
        a = static_cast<long long>(pow(a, 2)) % n;
        b /= 2;
    }

    return resultado;
}

long long chavePrivada(long long e, long long phi)
{
    // Algoritmo: Euclides Estendido
    for (long long d = 2; d < phi; ++d)
        if ((e * d) % phi == 1)
            return d;
    return 0; // Para "d" inválido
}

string cifraRSA(const string &texto, long long chv, long long n, bool cifrar = true)
{
    string resultado = "";
    istringstream fluxoCifra(texto);
    string letra;

    if (cifrar)
    {
        for (char c : texto)
        {
            if (isalpha(c) or c == ' ')
            {
                if (c != ' ')
                {
                    long long charNum = toupper(c) - 'A' + 1;
                    long long resultadoCarac;

                    resultadoCarac = modExp(charNum, chv, n);

                    resultado += to_string(resultadoCarac) + " ";
                } else
                    resultado += "0 "; // "0" para espaço em branco
            }
        }
    }
    else
    {
        while (getline(fluxoCifra, letra, ' '))
        {
            if (letra != "0")
            {
                long long cifraNum = stoll(letra);
                long long resultadoNum = modExp(cifraNum, chv, n);
                char resultadoCarac = static_cast<char>(resultadoNum - 1 + 'A');
                resultado += resultadoCarac;
            } else
                resultado += ' ';
        }
    }

    return resultado;
}

int main(void)
{
    long long p = 523, q = 541;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e;
        for (e = 2; e < phi; e++)
        {
            if (mdc(e, phi) == 1)
                break;
        }
    long long d = chavePrivada(e, phi);

    cout << "CRIPTOGRAFIA RSA: SIMPLES" << endl;
    cout << endl;

    cout << "Chave publica gerada (n, e): (" << n << ", " << e << ") - chave \"e\" (" << e << ") - distribuida" << endl;
    cout << "Chave privada gerada (n, d): (" << n << ", " << d << ") - chave \"d\" (" << d << ") - secreta" << endl;
    cout << endl;

    string mensagemOriginal;
    cout << "Digite a mensagem a ser cifrada ..: ";
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    cout << endl;
    long long chvPublica;
    cout << "Entre a chave publica ............: ";
    cin >> chvPublica;
    cin.ignore(80, '\n');

    string mensagemCifrada = cifraRSA(mensagemOriginal, chvPublica, n);

    cout << "Mensagem com cifragem ............: " << mensagemCifrada << endl;

    cout << endl;
    long long chvPrivada;
    cout << "Decifrar - entre a chave privada .: ";
    cin >> chvPrivada;
    cin.ignore(80, '\n');

    string mensagemDecifrada = cifraRSA(mensagemCifrada, chvPrivada, n, false);

    cout << "Mensagem sem cifragem ............: " << mensagemDecifrada << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
