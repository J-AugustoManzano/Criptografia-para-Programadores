use std::io::{self, Write};

fn cifra_caesar_polialfabetico(mensagem: &str, cifrar: bool) -> String {
    let mut resultado = String::new();
    let mut deslocamento = 3;

    for c in mensagem.chars() {
        if c.is_alphabetic() {
            let base = if c.is_uppercase() { b'A' } else { b'a' } as u8;

            let nova_letra = if cifrar {
                (((c as u8 - base + deslocamento) % 26) + base) as char
            } else {
                (((c as u8 - base + 26 - deslocamento) % 26) + base) as char
            };

            deslocamento = (deslocamento + 1) % 26;
            resultado.push(nova_letra);
        } else {
            resultado.push(c);
        }
    }

    resultado
}

fn main() {
    println!("CRIPTOGRAFIA: CAESAR POLIALFABETICO");
    println!();
    
    print!("Informe mensagem a ser cifrada ..: ");
    io::stdout().flush().unwrap();
    let mut mensagem_original = String::new();
    io::stdin().read_line(&mut mensagem_original).unwrap();
    let mensagem_original = mensagem_original.trim().to_uppercase();

    let mensagem_cifrada = cifra_caesar_polialfabetico(&mensagem_original, true);
    let mensagem_decifrada = cifra_caesar_polialfabetico(&mensagem_cifrada, false);

    println!();
    println!("Mensagem com cifragem ..: {}", mensagem_cifrada);
    println!("Mensagem sem cifragem ..: {}", mensagem_decifrada);

    println!();
    print!("Tecle <Enter> para encerrar... ");
    io::stdout().flush().unwrap();
    let _ = io::stdin().read_line(&mut String::new());
}
