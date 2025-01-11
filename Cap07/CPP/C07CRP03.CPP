#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int tamanhoBloco = 8; // Tamanho do bloco em caracteres

string substituicao(const string &bloco, bool cifrar)
{
    string resultado = bloco;

    // Tabela de substituição
    string tabelaSubstituicao = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (char &caractere : resultado)
    {
        if (isalpha(caractere))
        {
            char maiuscula = toupper(caractere);
            size_t pos = tabelaSubstituicao.find(maiuscula);

            if (pos != string::npos)
            {
                // Realiza a substituição baseada na tabela
                if (cifrar)
                    caractere = tabelaSubstituicao[(pos + 1) % tabelaSubstituicao.size()];
                else
                    caractere = tabelaSubstituicao[(pos - 1 + tabelaSubstituicao.size()) % tabelaSubstituicao.size()];
                if (islower(caractere) && isupper(maiuscula))
                    caractere = tolower(caractere);
                else if (isupper(caractere) && islower(maiuscula))
                    caractere = toupper(caractere);
            }
        }
    }

    return resultado;
}

string permutacao(const string &bloco)
{
    string resultado = bloco;
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

string retroalimentacao(const string &bloco, const string &saidaRodadaAnterior)
{
    string resultado = bloco;
    resultado = saidaRodadaAnterior;
    return resultado;
}

string finalizacao(const string &bloco)
{
    string resultado = bloco;
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

string processarBloco(const string &bloco, int chave, bool cifrar)
{
    string resultado = bloco;
    string saidaRodadaAnterior = ""; // Inicia saída rodada anterior

    // Realizar múltiplas rodadas de substituição e permutação
    for (int i = 0; i < 3; ++i)
    {
        resultado = substituicao(resultado, cifrar);
        resultado = permutacao(resultado);

        // Salva saída da rodada atual para retroalimentação
        saidaRodadaAnterior = resultado;
    }

    // Aplicar retroalimentação usando a saída da última rodada
    resultado = retroalimentacao(resultado, saidaRodadaAnterior);

    // Efetuar a finalização
    resultado = finalizacao(resultado);

    // Eficiência e paralelismo (simplificada
    #pragma omp parallel for
    for (char &caractere : resultado)
    {
        if (cifrar)
            caractere = (caractere + chave) % 128;
        else
            caractere = (caractere - chave + 128) % 128;
    }

    return resultado;
}

int main(void)
{
    int chave = 3;

    cout << "CRIPTOGRAFIA DE BLOCO: AJUSTADA" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string mensagemOriginal;
    getline(cin, mensagemOriginal);
    transform(mensagemOriginal.begin(), mensagemOriginal.end(), mensagemOriginal.begin(), ::toupper);

    cout << endl;
    // Dividir a mensagem em blocos
    for (int i = 0; i < mensagemOriginal.size(); i += tamanhoBloco)
    {
        string blocoOriginal = mensagemOriginal.substr(i, tamanhoBloco);

        // Cifrar ou decifrar cada bloco
        string blocoProcessado = processarBloco(blocoOriginal, chave, true);
        cout << "Bloco Cifrado ....: " << setw(8) << blocoProcessado;

        string blocoDecifrado = processarBloco(blocoProcessado, chave, false);
        cout << "   Bloco Decifrado ..: " << setw(8) << blocoDecifrado << endl;
    }

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
