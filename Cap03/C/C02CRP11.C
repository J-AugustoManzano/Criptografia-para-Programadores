#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define QUANT_CARACTERES 1000
#define TRUE 1
#define FALSE 0

char* cifraVigenere(const char texto[], const char chave[], int cifrar = TRUE)
{
    static char mensagem[QUANT_CARACTERES];
    size_t len = strlen(texto);
    int j = 0;

    for (size_t i = 0; i < len; ++i)
    {
        if (texto[i] == ' ')
        {
            mensagem[i] = ' ';
            ++i;
        }
        if (isalpha(texto[i]))
        {
            char base = isupper(texto[i]) ? 'A' : 'a';
            if (cifrar)
                mensagem[i] = (texto[i] + chave[j] - 2 * base + 26) % 26 + base;
            else
                mensagem[i] = (texto[i] - chave[j] + 26) % 26 + base;
            j = (j + 1) % strlen(chave);
        }
        else
        {
            mensagem[i] = texto[i];
        }
    }

    mensagem[len] = '\0';

    return mensagem;
}

int main(void)
{
    printf("CRIPTOGRAFIA: VIGENERE\n");
    printf("\n");

    printf("Informe mensagem a ser cifrada ..: ");
    char mensagemOriginal[QUANT_CARACTERES];
    fgets(mensagemOriginal, sizeof(mensagemOriginal), stdin);
    
    // Remover o caractere de nova linha, se presente
    size_t len = strlen(mensagemOriginal);
    if (len > 0 && mensagemOriginal[len - 1] == '\n')
        mensagemOriginal[len - 1] = '\0';

    // Converter caracteres minúsculos em maiúsculos
    for (int i = 0; mensagemOriginal[i] != '\0'; ++i)
        mensagemOriginal[i] = toupper(mensagemOriginal[i]);
        
    char chave[QUANT_CARACTERES];
    printf("Informe a palavra chave .........: ");
    scanf("%s", chave);
    while (getchar() != '\n');
    for (size_t i = 0; i < strlen(chave); ++i)
        chave[i] = toupper(chave[i]);

    char mensagemCifrada[QUANT_CARACTERES];
    strcpy(mensagemCifrada, cifraVigenere(mensagemOriginal, chave));

    char mensagemDecifrada[QUANT_CARACTERES];
    strcpy(mensagemDecifrada, cifraVigenere(mensagemCifrada, chave, FALSE));

    printf("\n");
    printf("Mensagem com cifragem ..: %s\n", mensagemCifrada);
    printf("Mensagem sem cifragem ..: %s\n", mensagemDecifrada);

    printf("\n");
    printf("Tecle <Enter> para encerrar... ");
    getchar();

    return 0;
}
