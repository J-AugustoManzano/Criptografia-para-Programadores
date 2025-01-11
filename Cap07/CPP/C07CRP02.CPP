#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string substituicao(const string &bloco, bool cifrar)
{
    string resultado = bloco;
    string tabelaSubstituicao = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (char &caractere : resultado)
    {
        if (isalpha(caractere))
        {
            char maiuscula = toupper(caractere);
            size_t pos = tabelaSubstituicao.find(maiuscula);

            if (pos != string::npos)
            {
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
        saidaRodadaAnterior = resultado;
    }

    // Aplicar retroalimentação usando a saída da última rodada
    resultado = retroalimentacao(resultado, saidaRodadaAnterior);

    // Efetuar a finalização
    resultado = finalizacao(resultado);

    // Eficiência e paralelismo (simplificado)
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

    cout << "CRIPTOGRAFIA DE BLOCO: AMPLIADA" << endl;
    cout << endl;

    cout << "Informe mensagem a ser cifrada ..: ";
    string blocoOriginal;
    getline(cin, blocoOriginal);
    transform(blocoOriginal.begin(), blocoOriginal.end(), blocoOriginal.begin(), ::toupper);

    string blocoCifrado = processarBloco(blocoOriginal, chave, true);
    string blocoDecifrado = processarBloco(blocoCifrado, chave, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << blocoCifrado << endl;
    cout << "Mensagem sem cifragem ..: " << blocoDecifrado << endl;

    cout << endl;
    cout << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
