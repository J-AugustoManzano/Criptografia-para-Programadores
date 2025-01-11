#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string cifraColTransp(const string &texto, const string &chv, bool cifra = true)
{
    string mensagem;

    // Calcular o número de colunas
    int numColunas = chv.length();

    // Calcular o número de linhas
    int numLinhas = texto.length() / numColunas;
    if (texto.length() % numColunas != 0)
        numLinhas++;

    // Inicializar a tabela com um caractere padrão (neste caso '*')
    vector<vector<char>> tabela(numLinhas, vector<char>(numColunas, '*'));

    if (cifra)
    {
        // Preencher a tabela com a texto
        int pos = 0;
        for (int lin = 0; lin < numLinhas; ++lin)
        {
            for (int col = 0; col < numColunas; ++col)
                if (pos < texto.length())
                    tabela[lin][col] = texto[pos++];
        }

        // Ordenar as colunas com base na palavra-chave
        vector<pair<char, int>> chaveOrdenada;
        for (int i = 0; i < numColunas; ++i)
            chaveOrdenada.push_back(make_pair(chv[i], i));

        sort(chaveOrdenada.begin(), chaveOrdenada.end());

        // Construir a texto cifrada
        for (int i = 0; i < numColunas; ++i)
        {
            int col = chaveOrdenada[i].second;
            for (int lin = 0; lin < numLinhas; ++lin)
                mensagem += tabela[lin][col];
        }
    }
    else
    {
        // Calcular a ordem das colunas com base na palavra-chave
        vector<int> ordemColunas(numColunas);
        for (int i = 0; i < numColunas; ++i)
            ordemColunas[i] = i;

        sort
        (
             ordemColunas.begin(), ordemColunas.end(), [&chv](int a, int b)
             {
                 return chv[a] < chv[b];
             }
        );

        // Preencher a tabela com a texto cifrada
        int pos = 0;
        for (int col = 0; col < numColunas; ++col)
        {
            for (int lin = 0; lin < numLinhas; ++lin)
                tabela[lin][ordemColunas[col]] = texto[pos++];
          }

        // Construir a texto decifrada
        for (int lin = 0; lin < numLinhas; ++lin)
        {
            for (int col = 0; col < numColunas; ++col)
                mensagem += tabela[lin][col];
        }

    }

    return mensagem;
}

string limparCifra(const string &texto)
{
    string mensagem = texto;
    size_t pos = mensagem.find('*');

    while (pos != string::npos)
    {
        mensagem.replace(pos, 1, "");
        pos = mensagem.find('*', pos);
    }

    return mensagem;
}

int main(void)
{
    cout << "CRIPTOGRAFIA: COLUMNAR TRANSPOSITION" << endl;
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

    string mensagemCifrada = cifraColTransp(mensagemOriginal, chave, true);
    string mensagemDecifrada = cifraColTransp(mensagemCifrada, chave, false);

    cout << endl;
    cout << "Mensagem com cifragem ..: " << mensagemCifrada << endl;
    cout << "Mensagem sem cifragem ..: " << mensagemDecifrada << endl;

    cout << endl;
    cout << "Mensagem com cifragem ..: " << limparCifra(mensagemCifrada) << endl;
    cout << "Mensagem sem cifragem ..: " << limparCifra(mensagemDecifrada) << endl;

    cout << endl << "Tecle <Enter> para encerrar... ";
    cin.get();

    return 0;
}
