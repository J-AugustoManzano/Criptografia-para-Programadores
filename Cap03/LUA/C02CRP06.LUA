function cifraCaesarPolialfabetico(mensagem, cifrar)
    cifrar = cifrar == nil and true or cifrar

    local resultado = ""
    local deslocamento = 3

    for i = 1, #mensagem do
        local c = mensagem:sub(i, i)
        if c:match('%a') then
            local base = c:match('%u') and string.byte('A') or string.byte('a')

            if cifrar then
                c = string.char((c:byte() - base + deslocamento) % 26 + base)
            else
                c = string.char((c:byte() - base - deslocamento + 26) % 26 + base)
            end

            deslocamento = deslocamento + 1
        end
        resultado = resultado .. c
    end

    return resultado
end


print("CRIPTOGRAFIA: CAESAR POLIALFABETICO\n")

io.write("Informe mensagem a ser cifrada ..: ")
local mensagemOriginal = io.read()
mensagemOriginal = mensagemOriginal:upper()

local mensagemCifrada = cifraCaesarPolialfabetico(mensagemOriginal)
local mensagemDecifrada = cifraCaesarPolialfabetico(mensagemCifrada, false)

print()
print("Mensagem com cifragem ..: " .. mensagemCifrada)
print("Mensagem sem cifragem ..: " .. mensagemDecifrada)

print()
io.write("Tecle <Enter> para encerrar... ")
io.flush()
io.read()
