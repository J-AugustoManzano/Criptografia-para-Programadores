#include <iostream>
#include <string>
using namespace std;

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

int main(void)
{
    cout << "CRIPTOGRAFIA: RAIL FENCE" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    int trilhos;
    cout << "Informe o numero de trilhos .....: ";
    cin >> trilhos;
	cin.ignore(80, '\n');

    string mensagemCifrada = cifraRailFence(mensagemOriginal, trilhos);
    string mensagemDecifrada = cifraRailFence(mensagemCifrada, trilhos, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.ignore();
    cin.get();

    return 0;
}
