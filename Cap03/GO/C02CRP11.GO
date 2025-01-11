package main

import (
  "bufio"
  "fmt"
  "os"
  "strings"
)

func isLetter(s string) bool {
  return strings.ToUpper(s) != strings.ToLower(s)
}

func isLower(s string) bool {
  return strings.ToLower(s) == s
}

func cifraVigenere(texto, chave string, cifrar bool) string {
  mensagem := ""
  j := 0

  for _, char := range texto {
    if char == ' ' {
      mensagem += " "
    } else if isLetter(string(char)) {
      base := byte('A')
      if isLower(string(char)) {
        base = byte('a')
      }

      chaveChar := chave[j%len(chave)]
      j++

      if cifrar {
        mensagem += string((byte(char)-base+byte(chaveChar)-base)%26 + base)
      } else {
        mensagem += string((byte(char)-byte(chaveChar)+26)%26 + base)
      }
    } else {
      mensagem += string(char)
    }
  }

  return mensagem
}

func main() {
  fmt.Println("CRIPTOGRAFIA: VIGENERE\n")

  reader := bufio.NewReader(os.Stdin)

  fmt.Print("Informe mensagem a ser cifrada ..: ")
  mensagemOriginal, _ := reader.ReadString('\n')
  mensagemOriginal = strings.ToUpper(strings.TrimSpace(mensagemOriginal))

  fmt.Print("Informe a palavra chave .........: ")
  chave, _ := reader.ReadString('\n')
  chave = strings.ToUpper(strings.TrimSpace(chave))

  mensagemCifrada := cifraVigenere(mensagemOriginal, chave, true)
  mensagemDecifrada := cifraVigenere(mensagemCifrada, chave, false)

  fmt.Println()
  fmt.Printf("Mensagem com cifragem ..: %s\n", mensagemCifrada)
  fmt.Printf("Mensagem sem cifragem ..: %s\n", mensagemDecifrada)

  fmt.Println()
  fmt.Print("Tecle <Enter> para encerrar... ")
  reader.ReadString('\n')
}
