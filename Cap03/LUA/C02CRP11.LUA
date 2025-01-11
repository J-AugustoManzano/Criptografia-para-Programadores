function cifraVigenere(texto, chave, cifrar)
    cifrar = cifrar == nil and true or cifrar
    
    local mensagem = ""
    local j = 1

    for i = 1, #texto do
        if texto:sub(i, i) == ' ' then
            mensagem = mensagem .. ' '
        elseif texto:sub(i, i):match('%a') then
            local base = texto:sub(i, i):match('%u') and string.byte('A') or string.byte('a')
            if cifrar then
                mensagem = mensagem .. string.char((texto:byte(i) + chave:byte(j) - 2 * base) % 26 + base)
            else
                mensagem = mensagem .. string.char((texto:byte(i) - chave:byte(j) + 26) % 26 + base)
            end
            j = (j % #chave) + 1
        else
            mensagem = mensagem .. texto:sub(i, i)
        end
    end
    return mensagem
end

print("CRIPTOGRAFIA: VIGENERE")
print()

io.write("Informe mensagem a ser cifrada ..: ")
local mensagemOriginal = io.read()
mensagemOriginal = mensagemOriginal:upper()

io.write("Informe a palavra chave .........: ")
local chave = io.read()
chave = chave:upper()

local mensagemCifrada = cifraVigenere(mensagemOriginal, chave, true)
local mensagemDecifrada = cifraVigenere(mensagemCifrada, chave, false)

print()
print("Mensagem com cifragem ..: " .. mensagemCifrada)
print("Mensagem sem cifragem ..: " .. mensagemDecifrada)

print()
io.write("Tecle <Enter> para encerrar... ")
io.read()
