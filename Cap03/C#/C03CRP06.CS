using System;

class Program
{
    static string cifraCaesarPolialfabetico(string mensagem, bool cifrar = true)
    {
        char[] caracteres = mensagem.ToCharArray();
        string resultado = "";
        int deslocamento = 3;

        for (int i = 0; i < caracteres.Length; i++)
        {
            char c = caracteres[i];

            if (Char.IsLetter(c))
            {
                char baseChar = Char.IsUpper(c) ? 'A' : 'a';

                if (cifrar)
                    c = (char)(((c - baseChar + deslocamento) % 26 + 26) % 26 + baseChar);
                else
                    c = (char)(((c - baseChar - deslocamento + 26) % 26 + 26) % 26 + baseChar);

                deslocamento++;
            }

            resultado += c;
        }

        return resultado;
    }

    static void Main()
    {
        Console.WriteLine("CRIPTOGRAFIA: CAESAR POLIALFABETICO\n");

        Console.Write("Informe mensagem a ser cifrada ..: ");
        string mensagemOriginal = Console.ReadLine().ToUpper();

        string mensagemCifrada = cifraCaesarPolialfabetico(mensagemOriginal);
        string mensagemDecifrada = cifraCaesarPolialfabetico(mensagemCifrada, cifrar: false);

        Console.WriteLine();
        Console.WriteLine("Mensagem com cifragem ..: " + mensagemCifrada);
        Console.WriteLine("Mensagem sem cifragem ..: " + mensagemDecifrada);

        Console.WriteLine();
        Console.Write("Tecle <Enter> para encerrar... ");
        Console.ReadLine();
    }
}
