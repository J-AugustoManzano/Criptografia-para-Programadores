#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cifraAutokey(string texto, string chv, bool cifra)
{
    string resultado = "";
    string chvAtual = chv;

    for (int i = 0; i < texto.length(); ++i)
    {
        if (isalpha(texto[i]))
        {
            char base = isupper(texto[i]) ? 'A' : 'a';
            int textoInd = texto[i] - base;
            int chvAjustada = chvAtual[i] - base;

            char caractere;
            if (cifra)
                caractere = (textoInd + chvAjustada) % 26 + base;
            else
                caractere = (textoInd - chvAjustada + 26) % 26 + base;

            resultado += caractere;
            chvAtual += (cifra ? texto[i] : caractere);
        }
        else
            resultado += texto[i];
    }

    return resultado;
}

string cifraRailFence(string texto, int trilhos, bool cifrar = true)
{
    char trilho[trilhos][texto.length()];

    for (int i = 0; i < trilhos; ++i)
        for (int j = 0; j < texto.length(); ++j)
            trilho[i][j] = '\n';

    bool direcaoDescer = false;
    int lin = 0, col = 0;

    for (int i = 0; i < texto.length(); ++i)
    {
        if (lin == 0 or lin == trilhos - 1)
            direcaoDescer = not direcaoDescer;

        trilho[lin][col++] = texto[i];
        direcaoDescer ? lin++ : lin--;
    }

    string resultado;
    if (cifrar)
    {
        for (int i = 0; i < trilhos; ++i)
            for (int j = 0; j < texto.length(); ++j)
                if (trilho[i][j] != '\n')
                    resultado.push_back(trilho[i][j]);
    }
    else
    {
        char trilhoDec[trilhos][texto.length()];

        for (int i = 0; i < trilhos; ++i)
            for (int j = 0; j < texto.length(); ++j)
                trilhoDec[i][j] = '\n';

        direcaoDescer = false;
        lin = 0, col = 0;

        for (int i = 0; i < texto.length(); ++i)
        {
            if (lin == 0)
                direcaoDescer = true;
            if (lin == trilhos - 1)
                direcaoDescer = false;

            trilhoDec[lin][col++] = '*';
            direcaoDescer ? lin++ : lin--;
        }

        int indice = 0;
        for (int i = 0; i < trilhos; ++i)
            for (int j = 0; j < texto.length(); ++j)
                if (trilhoDec[i][j] == '*' and indice < texto.length())
                    trilhoDec[i][j] = texto[indice++];

        lin = 0, col = 0;
        for (int i = 0; i < texto.length(); ++i)
        {
            if (lin == 0)
                direcaoDescer = true;
            if (lin == trilhos - 1)
                direcaoDescer = false;

            if (trilhoDec[lin][col] != '*')
                resultado.push_back(trilhoDec[lin][col++]);

            direcaoDescer ? lin++ : lin--;
        }
    }

    return resultado;
}

string cifraVernam(string texto, string chv, bool cifra = true)
{
    string resultado = "";

    for (int i = 0; i < texto.length(); ++i)
    {
        if (isalpha(texto[i]))
        {
            char base = isupper(texto[i]) ? 'A' : 'a';
            int indiceCar = texto[i] - base;
            int indiceChv = chv[i % chv.length()] - base;

            char caractere;
            if (cifra)
                caractere = (indiceCar + indiceChv) % 26 + base;
            else
                caractere = (indiceCar - indiceChv + 26) % 26 + base;

            resultado += caractere;
        }
        else
            resultado += texto[i];
    }

    return resultado;
}

string cifraKeyRailVer(string texto, string chave, int trilhos, bool cifrar = true)
{
    string resultado;
    if (cifrar)
    {
        string autokeyResult = cifraAutokey(texto, chave, cifrar);
        string railFenceResult = cifraRailFence(autokeyResult, trilhos, cifrar);
        string vernamResult = cifraVernam(railFenceResult, chave, cifrar);
        resultado = vernamResult;
    }
    else
    {
        string vernamResult = cifraVernam(texto, chave, cifrar);
        string railFenceResult = cifraRailFence(vernamResult, trilhos, cifrar);
        string autokeyResult = cifraAutokey(railFenceResult, chave, cifrar);
        resultado = autokeyResult;
    }

    return resultado;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: AUTOKEY, RAIL FENCE COM VERNAM" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string chave;
    cout << "Informe a chave .................: ";
    cin >> chave;
    cin.ignore(80, '\n');
    transform(chave.begin(), chave.end(), chave.begin(), ::toupper);

    int trilhos = chave.length();

    string mensagemCifrada = cifraKeyRailVer(mensagemOriginal, chave, trilhos, true);
    string mensagemDecifrada = cifraKeyRailVer(mensagemCifrada, chave, trilhos, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
