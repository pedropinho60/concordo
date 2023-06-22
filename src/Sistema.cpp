#include "Sistema.h"

#include <iostream>
#include <sstream>

/// @brief Construtor padrão do sistema.
Sistema::Sistema() {
    usuarioLogado = nullptr;
    servidorAtual = nullptr;
    canalAtual = nullptr;
    ultimoIdUsuario = 0;
}

// ==================GETTERS==================

/**
 * @brief Busca pelo usuário com o email especificado.
 *
 * @param email Email do usuário.
 * @return Ponteiro para o usuário, ou nullptr caso não exista.
 */
Usuario* Sistema::getUsuario(std::string email) {
    for(auto& usuario : usuarios) {
        if(usuario.getEmail() == email) {
            return &usuario;
        }
    }
    return nullptr;
}

/**
 * @brief Busca pelo usuário com o id especificado.
 *
 * @param id Id do usuário.
 * @return Ponteiro para o usuário, ou nullptr caso não exista.
 */
Usuario* Sistema::getUsuario(int id) {
    for(auto& usuario : usuarios) {
        if(usuario.getId() == id) {
            return &usuario;
        }
    }
    return nullptr;
}

/**
 * @brief Busca pelo servidor com o nome especificado.
 *
 * @param nome Nome do servidor.
 * @return Ponteiro para o servidor, ou nullptr caso não exista.
 */
Servidor* Sistema::getServidor(std::string nome) {
    for(auto& servidor : servidores) {
        if(servidor.getNome() == nome) {
            return &servidor;
        }
    }
    return nullptr;
} 

// ==================MÉTODOS==================

/// @brief Inicia o sistema, que é encerrado apenas com o comando `quit`.
void Sistema::iniciar() {
    while(lerComando()) {};
}

/**
 * @brief Processa o comando inserido e seus argumentos, chamando a função
 * correspondente.
 *
 * @return False caso `quit` seja executado, e true caso contrário.
 */
bool Sistema::lerComando() {
    std::string line;
    std::getline(std::cin, line);

    std::string command;
    std::string args;

    std::istringstream iss(line);
    std::getline(iss, command, ' ');
    std::getline(iss, args);

    if(command == "quit") {
        std::cout << "Saindo do Concordo" << std::endl;
        return false;
    }
    else if(command == "create-user") {
        createUser(args);
    }
    else if(command == "login") {
        login(args);
    }
    else if(command == "disconnect") {
        disconnect();
    }
    else if(command == "create-server") {
       createServer(args); 
    }
    else if(command == "set-server-desc") {
        setServerDesc(args);
    }
    else if(command == "set-server-invite-code") {
        setServerInviteCode(args);
    }
    else if(command == "list-servers") {
        listServers();
    }
    else if(command == "remove-server") {
        removeServer(args);
    }
    else if(command == "enter-server") {
        enterServer(args);
    }
    else if(command == "leave-server") {
        leaveServer();
    }
    else if(command == "list-participants") {
        listParticipants();
    }
    else{
        std::cout << "Comando inválido!" << std::endl;
    }

    return true;
}

// ==================COMANDOS==================

/**
 * @brief Cria usuário com o email, senha e nome especificados. Executado com
 * `create-user <email> <senha> <nome>`
 *
 * @param args Argumentos do comando, que são email, senha e nome. O email e
 * senha não podem ter espaço.
 */
void Sistema::createUser(std::string args) {
    std::string email;
    std::string senha;
    std::string nome;

    std::istringstream iss(args);
    std::getline(iss, email, ' ');
    std::getline(iss, senha, ' ');
    std::getline(iss, nome);

    if(getUsuario(email) != nullptr) {
        std::cout << "Usuário já existe!" << std::endl;
        return;
    }

    Usuario usuario(email, senha, nome, ultimoIdUsuario++);
    usuarios.push_back(usuario);
    std::cout << "Usuário criado" << std::endl;
}

/**
 * @brief Faz login como um usuário. Executado com `login <email> <senha>`.
 *
 * @note Não pode ser executado caso já esteja logado.
 * @param args Argumentos do comando, que são email e senha. Os argumentos não
 * pode ter espaço.
 */
void Sistema::login(std::string args) {
    if(usuarioLogado != nullptr) {
        std::cout << "Usuário já está logado!" << std::endl;
        return;
    }

    std::string email;
    std::string senha;

    std::istringstream iss(args);
    std::getline(iss, email, ' ');
    std::getline(iss, senha);

    usuarioLogado = getUsuario(email);

    if(usuarioLogado == nullptr) {
        std::cout << "Usuário ou senha inválidos!" << std::endl;
        return;
    }

    if(!usuarioLogado->checarSenha(senha)) {
        std::cout << "Usuário ou senha inválidos!" << std::endl;
        usuarioLogado = nullptr;
        return;
    }

    std::cout << "Logado como " << usuarioLogado->getEmail() << std::endl;
}

/**
 * @brief Desconecta do usuário atual. Executado com `disconnect`.
 *
 * @note Pode ser executado apenas se um usuário estiver logado.
 */
void Sistema::disconnect() {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }
    std::cout << "Desconectando usuário " << usuarioLogado->getEmail() << std::endl;
    usuarioLogado = nullptr;
    servidorAtual = nullptr;
    canalAtual = nullptr;
}

/**
 * @brief Cria um servidor com o nome especificado. Executado com `create-server
 * <nome>`.
 *
 * @note Pode ser executado apenas se um usuário estiver logado.
 * @param args Argumentos do comando, que é o nome do servidor. O nome não
 * pode ter espaços.
 */
void Sistema::createServer(std::string args) {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    std::string nome;

    std::istringstream iss(args);
    std::getline(iss, nome, ' ');

    if(getServidor(nome) != nullptr) {
        std::cout << "Servidor com esse nome já existe!" << std::endl;
        return;
    }

    Servidor servidor(nome, usuarioLogado);
    servidores.push_back(servidor);
    std::cout << "Servidor criado" << std::endl;    
}

/**
 * @brief Altera a descrição do servidor. Executado com `set-server-desc <nome>
 * "<descrição>"`.
 *
 * @note Só pode ser executado caso seja o dono do servidor.
 * @param args Argumentos do comando, que são nome do servidor e descrição.
 * A descrição deve estar entre aspas duplas.
 */
void Sistema::setServerDesc(std::string args) {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    std::string nome;
    std::string descricao;

    std::istringstream iss(args);
    std::getline(iss, nome, ' ');
    iss.ignore();
    std::getline(iss, descricao, '"');

    Servidor* servidor = getServidor(nome);

    if(servidor == nullptr) {
        std::cout << "Servidor '" << nome << "'não existe!" << std::endl;
        return;
    }

    if(!servidor->isDono(usuarioLogado)) {
        std::cout << "Você não pode alterar a descrição de um servidor que não" 
                  << "foi criado por você" << std::endl;
        return;
    }

    servidor->setDescricao(descricao);
    std::cout << "Descrição do servidor '" << servidor->getNome() << "' modificada!" << std::endl;
}

/**
 * @brief Altera o código de convite de um servidor. Executado com 
 * `set-server-invite-code <nome> [codigo]`.
 *
 * @note Só pode ser executado caso seja o dono do servidor.
 * @param args Argumentos do comando, que são o nome do servidor e o código
 * de convite. Caso executado sem especificar o código, ele será removido.
 */
void Sistema::setServerInviteCode(std::string args) {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    std::string nome;
    std::string codigo;

    std::istringstream iss(args);
    std::getline(iss, nome, ' ');
    std::getline(iss, codigo);

    Servidor* servidor = getServidor(nome);

    if(servidor == nullptr) {
        std::cout << "Servidor '" << nome << "'não existe!" << std::endl;
        return;
    }

    if(!servidor->isDono(usuarioLogado)) {
        std::cout << "Você não pode alterar o código de convite de um servidor" 
                  << "que não foi criado por você" << std::endl;
        return;
    }

    servidor->setCodigoConvite(codigo);
    if(codigo == "") {
        std::cout << "Código de convite do servidor '" << servidor->getNome() 
                  << "' removido!" << std::endl;
    } else {
        std::cout << "Código de convite do servidor '" << servidor->getNome() 
                  << "' modificado!" << std::endl;
    }

}

/// @brief Lista os servidores criados.
void Sistema::listServers() {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    if(servidores.size() == 0) {
        std::cout << "Não há servidores cadastrados" << std::endl;
        return;
    }

    for(auto servidor : servidores) {
        std::cout << servidor.getNome() << std::endl;
    }
}

/**
 * @brief Remove o servidor especificado. Executado com `remove-server <nome>`
 *
 * @note Só pode ser executado caso seja o dono do servidor.
 * @param nome Nome do servidor.
 */
void Sistema::removeServer(std::string nome) {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    Servidor* servidor = getServidor(nome);

    if(servidor == nullptr) {
        std::cout << "Servidor '" << nome << "'não existe!" << std::endl;
        return;
    }

    if(!servidor->isDono(usuarioLogado)) {
        std::cout << "Você não é o dono do servidor '" << nome << "'" << std::endl;
        return;
    }

    if(servidorAtual == servidor) {
        servidorAtual = nullptr;
        canalAtual = nullptr;
    }

    size_t index = servidor - &servidores[0];
    servidores.erase(servidores.begin() + index);
    std::cout << "Servidor '" << nome << "' removido!" << std::endl;   
}

/**
 * @brief Entra no servidor especificado. Executado com `enter-server <nome>
 * [codigo].
 *
 * @note Caso seja o dono do servidor, não é necessário código de convite.
 * @param args Argumentos do comando, que são o nome do servidor e o código de
 * convite, se houver um.
 */
void Sistema::enterServer(std::string args) {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    std::string nome;
    std::string codigo;

    std::istringstream iss(args);
    std::getline(iss, nome, ' ');
    std::getline(iss, codigo);

    Servidor* servidor = getServidor(nome);

    if(servidor == nullptr) {
        std::cout << "Servidor '" << nome << "'não existe!" << std::endl;
        return;
    }

    if(!(servidor->isDono(usuarioLogado) || servidor->getCodigoConvite() == "")) {
        if(codigo == "") {
            std::cout << "Servidor requer código de convite" << std::endl;
            return;
        }
        if(codigo != servidor->getCodigoConvite()) {
            std::cout << "Código de convite inválido!" << std::endl;
            return;
        }
    }


    servidorAtual = servidor;
    canalAtual = nullptr;

    if(!servidor->isParticipante(usuarioLogado)) {
        servidor->adicionarParticipante(usuarioLogado);
    }

    std::cout << "Entrou no servidor com sucesso" << std::endl;
}

/**
 * @brief Sai do servidor atual. Executado com `leave-server`.
 *
 * @note Só pode ser executado caso esteja em um servidor.
 */
void Sistema::leaveServer() {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    if(servidorAtual == nullptr) {
        std::cout << "Você não está visualizando nenhum servidor" << std::endl;
        return;
    }

    std::cout << "Saindo do servidor '" << servidorAtual->getNome()
              << "'" << std::endl;
    servidorAtual = nullptr;
}

/**
 * @brief Lista os participantes do servidor atual.
 *
 * @note Só pode ser executado caso esteja em um servidor.
 */
void Sistema::listParticipants() {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    if(servidorAtual == nullptr) {
        std::cout << "Você não está visualizando nenhum servidor" << std::endl;
        return;
    }

    for(auto usuarioId : servidorAtual->getParticipantesIds()) {
        Usuario *usuario = getUsuario(usuarioId);
        std::cout << usuario->getNome() << std::endl;
    }
}
