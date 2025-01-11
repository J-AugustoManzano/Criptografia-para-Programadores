package main

import (
  "bufio"
  "fmt"
  "os"
  "strings"
  "unicode"
)

func cifraCaesarPolialfabetico(mensagem string, cifrar bool) string {
  deslocamento := 3
  resultado := ""

  for _, c := range mensagem {
      if unicode.IsLetter(c) {
        base := 'A'
        if unicode.IsLower(c) {
          base = 'a'
        }

      if cifrar {
        c = rune((int(c)-int(base)+deslocamento)%26 + int(base))
      } else {
        c = rune((int(c)-int(base)-deslocamento+26)%26 + int(base))
      }

      deslocamento = (deslocamento + 1) % 26
    }

    resultado += string(c)
  }

  return resultado
}

func main() {
  fmt.Println("CRIPTOGRAFIA: CAESAR POLIALFABETICO\n")

  fmt.Print("Informe mensagem a ser cifrada ..: ")
  reader := bufio.NewReader(os.Stdin)
  mensagemOriginal, _ := reader.ReadString('\n')
  mensagemOriginal = strings.ToUpper(strings.TrimSpace(mensagemOriginal))

  mensagemCifrada := cifraCaesarPolialfabetico(mensagemOriginal, true)
  mensagemDecifrada := cifraCaesarPolialfabetico(mensagemCifrada, false)

  fmt.Println()
  fmt.Printf("Mensagem com cifragem ..: %s\n", mensagemCifrada)
  fmt.Printf("Mensagem sem cifragem ..: %s\n", mensagemDecifrada)

  fmt.Println()
  fmt.Print("Tecle <Enter> para encerrar... ")
  fmt.Scanln()
}
