# Concordo - Versão 1

Projeto de "Linguagem de Programação I"

## Descrição

Esse projeto é uma "imitação" do [**Discord**](https://www.discord.com), feita
em C++.

Essa é a versão 1 do projeto. Nela, é possível cadastrar usuários, fazer login,
criar, configurar e entrar em servidores.

## Autoria

O projeto foi feito por Pedro Vinícius Oliveira Maciel Pinho.

## Comandos

### Deslogados

Esses comandos podem ser executados caso o usuário não esteja logado.

- `quit` sai do sistema.
- `create-user <email> <senha> <nome>` cria um usuário. Apenas o nome pode ter
espaços. Dois usuários não podem ter o mesmo email.
- `login <email> <senha>` faz login em um usuário já criado.

### Logados

Esses comandos só podem ser executados caso o usuário esteja logado.

- `disconnect` desconecta o usuário logado.
- `create-server <nome>` cria um servidor.
- `list-servers` lista todos os servidores criados.
- `enter-server <nome> [codigo]` entra no servidor especificado. O código só
é necessário caso o servidor tenha um. O dono do servidor pode entrar sem
utilizar o código.

### Dono do servidor

Esses comandos só podem ser executados caso você seja o dono do servidor.

- `set-server-desc <nome> "<descrição>"` altera a descrição do servidor.
- `set-server-invite-code <nome> [codigo]` altera o código de convite do 
servidor.
- `remove-server <nome>` remove o servidor.

### Dentro de um servidor

Esses comandos só podem ser executados dentro de um servidor.

- `leave-server` sai do servidor.
- `list-participants` lista os participantes do servidor.

## Compilação e execução

Para compilar o programa, é utilizado o [**CMake**](https://cmake.org).

Na pasta principal do projeto, execute os comandos a seguir:

- `cmake -B build` para gerar os arquivos de compilação
- `cmake --build build` para compilar o programa

Após a compilação, o programa pode ser executado com `./build/program`.

Para utilizar o script de exemplo, explicado abaixo, utilize o comando
`./build/program < script.txt`

## Script de exemplo

O repositório contém um [**script**](script.txt) de exemplo, que contém comandos
para demonstrar as funcionalidades do programa.

A seguir, está a explicação de cada linha do script:

```bash
create-user email1 password1 name1            # cria o usuário 1
create-user email2 password2 name2            # cria o usuário 2
create-user email3 password3 name3            # cria o usuário 3
login email1 password1                        # faz login no usuário 1
create-server server1                         # cria o servidor 1
set-server-desc server1 "server1 description" # altera a descrição do servidor
set-server-invite-code server1 invitecode     # adiciona o código de convite
enter-server server1                          # entra no servidor 1
disconnect                                    # desconecta do sistema
login email2 password2                        # faz login no usuário 2
list-servers                                  # lista os servidores (servidor 1)
create-server server2                         # cria o servidor 2
enter-server server1 invitecode               # entra no servidor 1 com o código
list-participants                             # lista os participantes (usuários 1 e 2)
disconnect                                    # desconecta do sistema
login email3 password3                        # faz login no usuário 3
list-servers                                  # lista os servidores (servidores 1 e 2)
enter-server server1                          # tenta entrar no servidor 1 sem o código (falha)
enter-server server2                          # entra no servidor 2
list-participants                             # lista os participantes (usuário 3)
disconnect                                    # desconecta do sistema
login email1 password1                        # faz login no usuário 1
remove-server server1                         # apaga o servidor 1
list-servers                                  # lista os servidores (servidor 2)
disconnect                                    # desconecta do sistema
quit                                          # encerra o programa
```

## Limitações

O programa não verifica se o número de argumentos está correto para cada comando.
Por exemplo, se um usuário digitar `create-user <email> <senha>`, e não especificar
o nome do usuário, o programa criará um usuário com email e senha, mas com o
nome vazio, ao invés de causar um erro.

## Documentação

A documentação feita com [**Doxygen**](https://doxygen.nl) está disponível
na pasta [**docs**](docs). Para acessá-la, abra o arquivo 
[**index.html**](docs/html/index.html) utilizando um navegador.
