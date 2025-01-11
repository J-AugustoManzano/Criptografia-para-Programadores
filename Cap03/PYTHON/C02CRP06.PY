def cifraCaesarPolialfabetico(mensagem, cifrar = True):
    resultado = ""
    deslocamento = 3

    for c in mensagem:
        if c.isalpha():
            base = ord('A') if c.isupper() else ord('a')

            if cifrar:
                c = chr((ord(c) - base + deslocamento) % 26 + base)
            else:
                c = chr((ord(c) - base - deslocamento + 26) % 26 + base)

            deslocamento += 1

        resultado += c

    return resultado


print("CRIPTOGRAFIA: CAESAR POLIALFABETICO\n")

mensagemOriginal = input("Informe mensagem a ser cifrada ..: ").upper()

mensagemCifrada = cifraCaesarPolialfabetico(mensagemOriginal)
mensagemDecifrada = cifraCaesarPolialfabetico(mensagemCifrada, cifrar=False)

print()
print("Mensagem com cifragem ..: " + mensagemCifrada)
print("Mensagem sem cifragem ..: " + mensagemDecifrada)

print()
input("Tecle <Enter> para encerrar... ")
