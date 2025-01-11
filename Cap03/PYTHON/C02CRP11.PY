def cifraVigenere(texto, chave, cifrar = True):
    mensagem = ""
    j = 0

    for i in range(len(texto)):
        if texto[i] == ' ':
            mensagem += ' '
        elif texto[i].isalpha():
            base = ord('A') if texto[i].isupper() else ord('a')
            if cifrar:
                mensagem += chr((ord(texto[i]) + ord(chave[j]) - 2 * base) % 26 + base)
            else:
                mensagem += chr((ord(texto[i]) - ord(chave[j]) + 26) % 26 + base)
            j = (j + 1) % len(chave)
        else:
            mensagem += texto[i]

    return mensagem

print("CRIPTOGRAFIA: VIGENERE")
print()

mensagemOriginal = input("Informe mensagem a ser cifrada ..: ").upper()

chave = input("Informe a palavra chave .........: ").upper()

mensagemCifrada = cifraVigenere(mensagemOriginal, chave)
mensagemDecifrada = cifraVigenere(mensagemCifrada, chave, False)

print()
print("Mensagem com cifragem ..:", mensagemCifrada)
print("Mensagem sem cifragem ..:", mensagemDecifrada)

print()
input("Tecle <Enter> para encerrar... ")
