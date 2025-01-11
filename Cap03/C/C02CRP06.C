#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define QUANT_CARACTERES 1000
#define TRUE 1
#define FALSE 0

char* cifraCaesarPolialfabetico(char *mensagem, int cifrar = TRUE) 
{
    char resultado[QUANT_CARACTERES] = "";
    int deslocamento = 3;

    for (int i = 0; mensagem[i] != '\0'; ++i) 
    {
        char c = mensagem[i];
        if (isalpha(c)) 
        {
            char base = isupper(c) ? 'A' : 'a';

            if (cifrar)
                c = (c - base + deslocamento) % 26 + base;
            else
                c = (c - base - deslocamento + 26) % 26 + base;

            deslocamento++;
        }
        resultado[i] = c;
    }

    resultado[strlen(resultado)] = '\0';
    strcpy(mensagem, resultado);
    return mensagem;
}

int main(void) 
{
    printf("CRIPTOGRAFIA: CAESAR POLIALFABETICO\n");
    printf("\n");
    
    char mensagemOriginal[QUANT_CARACTERES];
    printf("Informe mensagem a ser cifrada ..: ");
    fgets(mensagemOriginal, QUANT_CARACTERES, stdin);

    // Remover o caractere de nova linha, se presente
    size_t len = strlen(mensagemOriginal);
    if (len > 0 && mensagemOriginal[len - 1] == '\n')
        mensagemOriginal[len - 1] = '\0';

    // Converter caracteres minúsculos em maiúsculos
    for (int i = 0; mensagemOriginal[i] != '\0'; ++i)
        mensagemOriginal[i] = toupper(mensagemOriginal[i]);

    char mensagemCifrada[QUANT_CARACTERES];
    char mensagemDecifrada[QUANT_CARACTERES];
    
    strcpy(mensagemCifrada, mensagemOriginal);
    cifraCaesarPolialfabetico(mensagemCifrada);

    strcpy(mensagemDecifrada, mensagemCifrada);
    cifraCaesarPolialfabetico(mensagemDecifrada, FALSE);

    printf("\n");
    printf("Mensagem com cifragem ..: %s\n", mensagemCifrada);
    printf("Mensagem sem cifragem ..: %s\n", mensagemDecifrada);

    printf("\n");
    printf("Tecle <Enter> para encerrar... ");
    getchar();

    return 0;
}
