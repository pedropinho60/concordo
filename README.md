# Concordo - Versão 3

Projeto de "Linguagem de Programação I"

## Descrição

Esse projeto é uma "imitação" do [**Discord**](https://www.discord.com), feita
em C++. Esse repositório contém as versões 1, 2 e 3 do projeto.

Na versão 1, é possível fazer login, criar, configurar e entrar em servidores.
A versão 2 adiciona as funcionalidades de canais, permitindo criar canais de 
texto e voz dentro de um servidor, e enviar mensagens neles.
A versão 3 adiciona funcionalidades de salvar e carregar, permitindo que o
programa guarde informações mesmo após ser encerrado. Também é possível rodar
o programa em dois terminais simultaneamente.

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

### Canais

Esses comandos são relacionados a funcionalidades dos canais.

- `create-channel <nome> <tipo>` cria um canal de tipo voz ou texto. É
necessário ser dono do servidor para criar um canal.
- `list-channels` lista todos os canais do servidor.
- `enter-channel <nome>` entra em um canal.
- `send-message <conteúdo>` envia uma mensagem. É necessário estar em um canal
para enviar mensagens.
- `list-messages` lista as mensagens do canal atual`. É necessário estar em um
canal para listar mensagens.

## Arquivo de salvamento padrão

A pasta [**data**](data) contém arquivos com informações de salvamento.
Ao executar o programa, as informações são lidas do arquivo. Se quiser remover
o conteúdo salvo, apague o conteúdo de ambos arquivos e substitua por uma única
linha contendo `0`.

## Compilação e execução

Para compilar o programa, é utilizado o [**CMake**](https://cmake.org).

Na pasta principal do projeto, execute os comandos a seguir:

- `cmake -B build` para gerar os arquivos de compilação
- `cmake --build build` para compilar o programa

Após a compilação, o programa pode ser executado com `./build/program`.

## Limitações

O programa não verifica se o número de argumentos está correto para cada comando.
Por exemplo, se um usuário digitar `create-user <email> <senha>`, e não especificar
o nome do usuário, o programa criará um usuário com email e senha, mas com o
nome vazio, ao invés de causar um erro.

## Documentação

A documentação feita com [**Doxygen**](https://doxygen.nl) está disponível
na pasta [**docs**](docs). Para acessá-la, abra o arquivo 
[**index.html**](docs/html/index.html) utilizando um navegador.
