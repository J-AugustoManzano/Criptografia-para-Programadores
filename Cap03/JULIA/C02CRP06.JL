function cifraCaesarPolialfabetico(mensagem, cifrar=true)
  resultado = ""
  deslocamento = 3

  for i = 1:length(mensagem)
      c = mensagem[i]
      if isletter(c)
          base = isuppercase(c) ? Int('A') : Int('a')

          if cifrar
              c = Char((Int(c) - base + deslocamento) % 26 + base)
          else
              c = Char((Int(c) - base - deslocamento + 26) % 26 + base)
          end

          deslocamento += 1
      end
      resultado *= c
  end

  return resultado
end

println("CRIPTOGRAFIA: CAESAR POLIALFABETICO\n")

print("Informe mensagem a ser cifrada ..: ")
flush(stdout)
mensagemOriginal = uppercase(readline())

mensagemCifrada = cifraCaesarPolialfabetico(mensagemOriginal)
mensagemDecifrada = cifraCaesarPolialfabetico(mensagemCifrada, false)

println()
println("Mensagem com cifragem ..: ", mensagemCifrada)
println("Mensagem sem cifragem ..: ", mensagemDecifrada)

println()
print("Tecle <Enter> para encerrar... ")
flush(stdout)
readline()
