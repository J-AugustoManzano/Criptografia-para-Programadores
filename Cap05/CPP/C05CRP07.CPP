#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

// Gerador aleatório entre min e max
int geradorAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Gerador de assinatura digital única
string geraAssinatura(const string& nomeEmpreg, int numeroEmpreg)
{
    const unsigned long long primo = 18446744073709551557ULL;
    const unsigned long long sal = 987654321ULL; // Valor de sal fixo
    unsigned long long hashCalculado = sal;

    for (char c : nomeEmpreg)
        hashCalculado = (hashCalculado * primo) + static_cast<unsigned long long>(c);
    // Adicionar número do funcionário para garantir unicidade
    hashCalculado = (hashCalculado * primo) + static_cast<unsigned long long>(numeroEmpreg);

    // Obter o ano atual
    time_t tempoAgora = time(0);
    tm* dataAtual = localtime(&tempoAgora);
    int anoAtual = dataAtual->tm_year + 1900;

    // Gerar um número aleatório de 1000 a 9999
    int sufixoRandomico = geradorAleatorio(1000, 9999);

    // Construir a assinatura digital usando
    // ano, número aleatório e parte do hash
    stringstream assinat;
    assinat << "ID" << anoAtual << "-" << setw(4) << setfill('0')
       << sufixoRandomico   << "-" << setw(6) << setfill('0')
       << (hashCalculado & 0xFFFF);

    return assinat.str();
}

int main(void)
{
    cout << "ASSINATURAS DIGITAIS" << endl;
    cout << endl;

    int numeroEmpregs;
    cout << "Informe o numero de funcionarios: ";
    cin >> numeroEmpregs;
    cin.ignore();
    cout << endl;

    for (int i = 1; i <= numeroEmpregs; ++i)
    {
        string nomeEmpreg;
        cout << "Nome do Funcionario " << i << " ..: ";
        getline(cin, nomeEmpreg);

        // Geração da assinatura digital
        string assinatDigital = geraAssinatura(nomeEmpreg, i);

        // Imprimir a assinatura digital
        cout << "Assinatura Digital .....: " << assinatDigital << endl;
        cout << endl;
    }

    cout << "Tecle <Enter> para encerrar... ";
    cin.get();
    return 0;
}
