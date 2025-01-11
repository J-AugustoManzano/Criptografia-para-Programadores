#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string cifraPorta(string texto, string chv)
{
    string mensagem;
    string alfab01 /* AB */ = "NOPQRSTUVWXYZABCDEFGHIJKLM";
    string alfab02 /* CD */ = "ZNOPQRSTUVWXYBCDEFGHIJKLMA";
    string alfab03 /* EF */ = "YZNOPQRSTUVWXCDEFGHIJKLMAB";
    string alfab04 /* GH */ = "XYZNOPQRSTUVWDEFGHIJKLMABC";
    string alfab05 /* IJ */ = "WXYZNOPQRSTUVEFGHIJKLMABCD";
    string alfab06 /* KL */ = "VWXYZNOPQRSTUFGHIJKLMABCDE";
    string alfab07 /* MN */ = "UVWXYZNOPQRSTGHIJKLMABCDEF";
    string alfab08 /* OP */ = "TUVWXYZNOPQRSHIJKLMABCDEFG";
    string alfab09 /* QR */ = "STUVWXYZNOPQRIJKLMABCDEFGH";
    string alfab10 /* ST */ = "RSTUVWXYZNOPQJKLMABCDEFGHI";
    string alfab11 /* UV */ = "QRSTUVWXYZNOPKLMABCDEFGHIJ";
    string alfab12 /* WX */ = "PQRSTUVWXYZNOLMABCDEFGHIJK";
    string alfab13 /* YZ */ = "OPQRSTUVWXYZNMABCDEFGHIJKL";
    int j;
    for (int i = 0; i <= texto.length() - 1; ++i)
    {
        if (texto[i] == ' ')
            texto[i] = ' ';

        if (texto[i] >= 'A' and texto[i] <= 'Z')
        {
            j = i % chv.length();
            if (chv[j] == 'A' or chv[j] == 'B')
                texto[i] = alfab01[texto[i] - 65];
            else if (chv[j] == 'C' or chv[j] == 'D')
                texto[i] = alfab02[texto[i] - 65];
            else if (chv[j] == 'E' or chv[j] == 'F')
                texto[i] = alfab03[texto[i] - 65];
            else if (chv[j] == 'G' or chv[j] == 'H')
                texto[i] = alfab04[texto[i] - 65];
            else if (chv[j] == 'I' or chv[j] == 'J')
                texto[i] = alfab05[texto[i] - 65];
            else if (chv[j] == 'K' or chv[j] == 'L')
                texto[i] = alfab06[texto[i] - 65];
            else if (chv[j] == 'M' or chv[j] == 'N')
                texto[i] = alfab07[texto[i] - 65];
            else if (chv[j] == 'O' or chv[j] == 'P')
                texto[i] = alfab08[texto[i] - 65];
            else if (chv[j] == 'Q' or chv[j] == 'R')
                texto[i] = alfab09[texto[i] - 65];
            else if (chv[j] == 'S' or chv[j] == 'T')
                texto[i] = alfab10[texto[i] - 65];
            else if (chv[j] == 'U' or chv[j] == 'V')
                texto[i] = alfab11[texto[i] - 65];
            else if (chv[j] == 'W' or chv[j] == 'X')
                texto[i] = alfab12[texto[i] - 65];
            else if (chv[j] == 'Y' or chv[j] == 'Z')
                texto[i] = alfab13[texto[i] - 65];
        }
        mensagem += texto[i];
    }
    return mensagem;
}
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

string cifraPortaKey(const string &texto, string chv, bool cifrar = true)
{
    if (cifrar)
        return cifraPorta(cifraAutokey(texto, chv, cifrar), chv);
    else
        return cifraAutokey(cifraPorta(texto, chv), chv, cifrar);
}

int main(void)
{
    cout << "CRIPTOGRAFIA: DELLA PORTA COM AUTOKEY" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string chave;
    cout << "Informe a palavra chave .........: ";
    cin >> chave;
    cin.ignore(80, '\n');
    transform(chave.begin(), chave.end(), chave.begin(), ::toupper);

    string mensagemCifrada = cifraPortaKey(mensagemOriginal, chave);
    string mensagemDecifrada = cifraPortaKey(mensagemCifrada, chave, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl
         << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
