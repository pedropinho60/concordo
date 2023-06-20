#include "Sistema.h"

#include <iostream>
#include <sstream>

Sistema::Sistema() {
    usuarioLogado = nullptr;
    servidorAtual = nullptr;
    canalAtual = nullptr;
    ultimoIdUsuario = 0;
}

Usuario* Sistema::getUsuario(std::string email) {
    for(auto& usuario : usuarios) {
        if(usuario.getEmail() == email) {
            return &usuario;
        }
    }
    return nullptr;
}

Usuario* Sistema::getUsuario(int id) {
    for(auto& usuario : usuarios) {
        if(usuario.getId() == id) {
            return &usuario;
        }
    }
    return nullptr;
}

Servidor* Sistema::getServidor(std::string nome) {
    for(auto& servidor : servidores) {
        if(servidor.getNome() == nome) {
            return &servidor;
        }
    }
    return nullptr;
} 

void Sistema::iniciar() {
    while(lerComando()) {};
}

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

void Sistema::createServer(std::string args) {
    if(usuarioLogado == nullptr) {
        std::cout << "Não está conectado" << std::endl;
        return;
    }

    std::string nome;

    std::istringstream iss(args);
    std::getline(iss, nome);

    if(getServidor(nome) != nullptr) {
        std::cout << "Servidor com esse nome já existe!" << std::endl;
        return;
    }

    Servidor servidor(nome, usuarioLogado);
    servidores.push_back(servidor);
    std::cout << "Servidor criado" << std::endl;    
}

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

    if(!servidor->isDono(usuarioLogado)) {
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
