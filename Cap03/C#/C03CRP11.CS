using System;

class Program
{
    static string cifraVigenere(string texto, string chave, bool cifrar = true)
    {
        string mensagem = "";
        int j = 0;

        for (int i = 0; i < texto.Length; i++)
        {
            char c = texto[i];

            if (c == ' ')
                mensagem += ' ';
            else if (char.IsLetter(c))
            {
                char baseChar = char.IsUpper(c) ? 'A' : 'a';
                if (cifrar)
                    mensagem += (char)(((c - baseChar + chave[j] - 'A') % 26 + 26) % 26 + baseChar);
                else
                    mensagem += (char)(((c - baseChar - (chave[j] - 'A') + 26) % 26 + 26) % 26 + baseChar);
                j = (j + 1) % chave.Length;
            }
            else
                mensagem += c;
        }

        return mensagem;
    }

    static void Main()
    {
        Console.WriteLine("CRIPTOGRAFIA: VIGENERE");
        Console.WriteLine();

        Console.Write("Informe mensagem a ser cifrada ..: ");
        string mensagemOriginal = Console.ReadLine().ToUpper();

        Console.Write("Informe a palavra chave .........: ");
        string chave = Console.ReadLine().ToUpper();

        string mensagemCifrada = cifraVigenere(mensagemOriginal, chave);
        string mensagemDecifrada = cifraVigenere(mensagemCifrada, chave, cifrar: false);

        Console.WriteLine();
        Console.WriteLine("Mensagem com cifragem ..: " + mensagemCifrada);
        Console.WriteLine("Mensagem sem cifragem ..: " + mensagemDecifrada);

        Console.WriteLine();
        Console.WriteLine("Tecle <Enter> para encerrar... ");
        Console.ReadLine();
    }
}
