# JSON SA:MP

**JSON SA:MP** é um plugin leve, seguro e moderno para servidores SA:MP, escrito em Rust. Ele fornece suporte nativo para manipulação de JSON diretamente em Pawn, facilitando a integração com APIs externas e armazenamento de dados estruturados.

Este projeto é de uso livre. A distribuição é feita exclusivamente em formato binário (sem código-fonte).

---

## Recursos
- Compatível com Linux e Windows (32-bit)
- Manipulação segura de objetos JSON
- Integração simples via `.inc`
- Funciona com gamemodes, filterscripts e includes

---

## Instalação

1. Copie para o servidor:
   - `samp_json.dll` (Windows) ou `libsamp_json.so` (Linux)
   - `json.inc` → `pawno/include/`

2. No seu script Pawn:
```pawn
#include <json>
```

3. Adicione ao `server.cfg`:
```
plugins samp_json
```

> **Nota técnica sobre `#pragma library json`:**
> Essa diretiva é opcional. Ela serve para informar o compilador Pawn que seu script depende de uma biblioteca externa. **Você não precisa usá-la** em gamemodes ou filterscripts, desde que esteja utilizando corretamente o `.inc` e o plugin esteja carregado.

---

## Funções Disponíveis

### `json_parse(const json_str[], &id)`
Faz o parse de uma string JSON e armazena internamente com um ID de referência.
```pawn
new id;
if (json_parse(response_body, id)) {
    // JSON válido e armazenado
}
```

### `json_free(id)`
Libera o JSON da memória associada ao ID.

### `json_get_int(id, key[], &output)`
Obtém um valor inteiro da chave fornecida.

### `json_get_float(id, key[], &output)`
Obtém um valor decimal (float) da chave fornecida.

### `json_get_bool(id, key[], &output)`
Obtém um valor booleano (0 ou 1).

### `json_is_valid(const json_str[])`
Valida se uma string está em formato JSON correto.

### `json_has_key(id, key[])`
Verifica se a chave existe no JSON armazenado.

### `json_create(&id)`
Cria um novo objeto JSON vazio e retorna seu ID.

### `json_set_string(id, key[], value[])`
Define uma string no objeto JSON.

### `json_to_string(id, output[], size)`
Converte o JSON armazenado no ID para uma string formatada.

---

## Exemplos

### Parse simples de resposta de API
```pawn
public OnHTTPResponse(index, code, data[])
{
    if (code != 200) return;

    new id;
    if (!json_parse(data, id)) return;

    new price;
    json_get_int(id, "preco", price);

    new nome[32];
    json_get_bool(id, "ativo", nome);

    printf("Preço: %d | Nome: %s", price, nome);

    json_free(id);
}
```

### Construção de JSON
```pawn
new id;
json_create(id);
json_set_string(id, "status", "sucesso");

new output[128];
json_to_string(id, output, sizeof(output));

printf("Saída JSON: %s", output);
json_free(id);
```

---

## Sobre o Projeto
- Autor: **Erick**
- Projeto: [github.com/ErickDev/samp-json](https://github.com/ErickDev/samp-json)
- Site pessoal: [erickdev.me](https://erickdev.me)

---

## Suporte
Abra um [issue](https://github.com/ErickDev/samp-json/issues) para dúvidas ou sugestões.

---

## Licença
Distribuição binária. Uso livre, mas o código-fonte não está incluído.
