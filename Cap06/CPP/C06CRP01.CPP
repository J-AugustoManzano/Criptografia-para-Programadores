#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

long strpos(const string &mensagem, char c)
{
    for (long i = 0; mensagem[i]; ++i)
    {
        if (mensagem[i] == c)
            return i;
    }
    return -1;
}

string cifraAtbash(const string &texto)
{
    string mensagem;
    for (char c : texto)
    {
        if (c == ' ')
            mensagem += ' ';
        if (isupper(c))
            mensagem += char(155 - c);
    }
    return mensagem;
}

string cifraAtbah(const string &texto, bool cifrar = true)
{
    string mensagem;
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cifrador = "IHGFNDCBARQPOEMLKJZYXWVUTS";

    for (char c : texto)
    {
        if (c == ' ')
            mensagem += ' ';

        if (isupper(c))
        {
            if (cifrar)
                mensagem += cifrador[strpos(alfabeto, c)];
            else
                mensagem += alfabeto[strpos(cifrador, c)];
        }
    }
    return mensagem;
}

string cifraAlbam(const string &texto, bool cifrar = true)
{
    string mensagem;
    for (char c : texto)
    {
        if (c == ' ')
            mensagem += ' ';

        if (isupper(c))
        {
            if (cifrar)
            {
                if (c >= 'N' && c <= 'Z')
                    mensagem += c - 13;
                else
                    mensagem += c + 13;
            }
            else
            {
                if (c <= 'M')
                    mensagem += c + 13;
                else
                    mensagem += c - 13;
            }
        }
    }
    return mensagem;
}

string cifraHebraica(const string &texto, bool cifrar = true)
{
    string mensagemCifrada;
    for (int i = 0; i < texto.length(); ++i)
    {
        char c = texto[i];
        if (c == ' ')
            mensagemCifrada += ' ';
        if (isupper(c))
        {
            if (i % 3 == 0)
                mensagemCifrada += cifraAtbash(string(1, c));
            else if (i % 3 == 1)
                mensagemCifrada += cifraAtbah(string(1, c), cifrar);
            else
                mensagemCifrada += cifraAlbam(string(1, c), cifrar);
        }
    }
    return mensagemCifrada;
}

string cifraKeyLess(const string &texto, bool cifrar = true)
{
    string resultado;
    size_t len = texto.length();

    if (cifrar)
    {
        for (size_t i = 0; i < len; i += 2)
            resultado.push_back(texto[i]);
        for (size_t i = 1; i < len; i += 2)
            resultado.push_back(texto[i]);
    }
    else
    {
        for (size_t i = 0; i < len / 2 + len % 2; ++i)
        {
            resultado.push_back(texto[i]);
            if (i + len / 2 + len % 2 < len)
                resultado.push_back(texto[i + len / 2 + len % 2]);
        }
    }
    return resultado;
}

string cifraHebKeyPass(const string &texto, bool cifrar = true)
{
    if (cifrar)
        return cifraHebraica(cifraKeyLess(texto, cifrar), cifrar);
    else
        return cifraKeyLess(cifraHebraica(texto, cifrar), cifrar);
}

int main(void)
{
    cout << "CRIPTOGRAFIA: HEBRAICA COM KEYPASS" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string mensagemCifrada = cifraHebKeyPass(mensagemOriginal);
    string mensagemDecifrada = cifraHebKeyPass(mensagemCifrada, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl
         << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
