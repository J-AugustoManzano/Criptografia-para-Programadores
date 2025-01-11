#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <random>
using namespace std;

long long mdc(long long a, long long b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
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

bool millerRabinTeste(long long d, long long n)
{
    long long a = 2 + rand() % (n - 4);
    long long x = modExp(a, d, n);

    if (x == 1 or x == n - 1)
        return true;

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    return false;
}

bool validaMillerRabinPrime(long long n, int k)
{
    if (n <= 1 or n == 4)
        return false;
    if (n <= 3)
        return true;

    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
    {
        if (not millerRabinTeste(d, n))
            return false;
    }

    return true;
}

bool primo(long long numero, int k = 5)
{
    // Teste de Miller-Rabin
    return validaMillerRabinPrime(numero, k);
}

long long chavePrivada(long long e, long long phi)
{
    // Algoritmo: Euclides Estendido
    for (long long d = 2; d < phi; ++d)
    {
        if ((e * d) % phi == 1)
            return (d + phi) % phi;
    }
    return 0; // Para "d" inválido
}

long long totienteEuler(long long p, long long q)
{
    return (p - 1) * (q - 1);
}

long long geraNumeroPrimo()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dist(100, 1000);
    long long candidato = dist(gen);

    while (not primo(candidato))
        candidato = dist(gen);

    return candidato;
}

long long escolheExpoentePublico(long long phi)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dist(65538, phi - 1);

    long long e = dist(gen);

    while (mdc(e, phi) != 1)
        e = dist(gen);

    return e;
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
                }
                else
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
            }
            else
                resultado += ' ';
        }
    }

    return resultado;
}

int main(void)
{
    long long p = geraNumeroPrimo();
    long long q = geraNumeroPrimo();

    long long n = p * q;
    long long phi = totienteEuler(p, q);
    long long e = escolheExpoentePublico(phi);
    long long d = chavePrivada(e, phi);

    cout << "CRIPTOGRAFIA RSA: AJUSTADA" << endl;
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string mensagemCifrada = cifraRSA(mensagemOriginal, chvPublica, n);

    cout << "Mensagem com cifragem ............: " << mensagemCifrada << endl;

    cout << endl;
    long long chvPrivada;
    cout << "Decifrar - entre a chave privada .: ";
    cin >> chvPrivada;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string mensagemDecifrada = cifraRSA(mensagemCifrada, chvPrivada, n, false);

    cout << "Mensagem sem cifragem ............: " << mensagemDecifrada << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
