function cifraVigenere(texto, chave, cifrar=true)
    mensagem = ""
    j = 1

    for i = 1:length(texto)
        if texto[i] == ' '
            mensagem *= ' '
        elseif isletter(texto[i])
            base = isuppercase(texto[i]) ? Int('A') : Int('a')
            if cifrar
                mensagem *= Char((Int(texto[i]) + Int(chave[j]) - 2 * base) % 26 + base)
            else
                mensagem *= Char((Int(texto[i]) - Int(chave[j]) + 26) % 26 + base)
            end
            j = (j % length(chave)) + 1
        else
            mensagem *= texto[i]
        end
    end
    return mensagem
end

println("CRIPTOGRAFIA: VIGENERE")
println()

print("Informe mensagem a ser cifrada ..: ")
flush(stdout)
mensagemOriginal = uppercase(readline())

print("Informe a palavra chave .........: ")
flush(stdout)
chave = uppercase(readline())

mensagemCifrada = cifraVigenere(mensagemOriginal, chave)
mensagemDecifrada = cifraVigenere(mensagemCifrada, chave, false)

println()
println("Mensagem com cifragem ..: ", mensagemCifrada)
println("Mensagem sem cifragem ..: ", mensagemDecifrada)

println()
print("Tecle <Enter> para encerrar... ")
flush(stdout)
readline()
