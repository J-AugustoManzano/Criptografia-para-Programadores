#include <iostream>
#include <string>
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

int main(void)
{
    cout << "CRIPTOGRAFIA: DELLA PORTA" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ...: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    string chave;
    cout << "Informe a palavra chave numerica .: ";
    cin >> chave;

    string mensagemCifrada = cifraPorta(mensagemOriginal, chave);
    string mensagemDecifrada = cifraPorta(mensagemCifrada, chave);

    cout << endl;
    cout << "Mensagem com cifragem ...: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ...: " << mensagemDecifrada << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.ignore();
    cin.get();

    return 0;
}
