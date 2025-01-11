use std::io::{self, Write};

fn cifra_vigenere(texto: &str, chave: &str, cifrar: bool) -> String {
    let mut mensagem = String::new();
    let mut j = 0;

    for c in texto.chars() {
        if c == ' ' {
            mensagem.push(' ');
        } else if c.is_alphabetic() {
            let base = if c.is_uppercase() { b'A' } else { b'a' } as u8;
            let chave_byte = chave.as_bytes()[j % chave.len()] as u8;

            let nova_letra = if cifrar {
                (((c as u8 + chave_byte - 2 * base) % 26) + base) as char
            } else {
                (((c as u8 + 26 - chave_byte) % 26) + base) as char
            };

            j += 1;
            mensagem.push(nova_letra);
        } else {
            mensagem.push(c);
        }
    }

    mensagem
}

fn main() {
    println!("CRIPTOGRAFIA: VIGENERE");
    println!();
    
    print!("Informe mensagem a ser cifrada ..: ");
    io::stdout().flush().unwrap();
    let mut mensagem_original = String::new();
    io::stdin().read_line(&mut mensagem_original).unwrap();
    let mensagem_original = mensagem_original.trim().to_uppercase();

    print!("Informe a palavra chave .........: ");
    io::stdout().flush().unwrap();
    let mut chave = String::new();
    io::stdin().read_line(&mut chave).unwrap();
    let chave = chave.trim().to_uppercase();

    let mensagem_cifrada = cifra_vigenere(&mensagem_original, &chave, true);
    let mensagem_decifrada = cifra_vigenere(&mensagem_cifrada, &chave, false);

    println!();
    println!("Mensagem com cifragem ..: {}", mensagem_cifrada);
    println!("Mensagem sem cifragem ..: {}", mensagem_decifrada);

    println!();
    print!("Tecle <Enter> para encerrar... ");
    io::stdout().flush().unwrap();
    let _ = io::stdin().read_line(&mut String::new());
}
