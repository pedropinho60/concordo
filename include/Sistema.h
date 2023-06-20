#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>

#include "Usuario.h"
#include "Canal.h"
#include "Servidor.h"

class Sistema {

private:
    std::vector<Usuario> usuarios;
    std::vector<Servidor> servidores;
    Usuario *usuarioLogado;
    Servidor *servidorAtual;
    Canal *canalAtual;
    int ultimoIdUsuario;

public:
    // Construtores e destrutores
    Sistema();
    ~Sistema() = default;

    // Getters
    Usuario* getUsuario(std::string email);
    Usuario* getUsuario(int id);
    Servidor* getServidor(std::string nome);

    // Comandos
    void iniciar();
    bool lerComando();
    void createUser(std::string args);
    void login(std::string args);
    void disconnect();
    void createServer(std::string args);
    void setServerDesc(std::string args);
    void setServerInviteCode(std::string args);
    void listServers();
    void removeServer(std::string nome);
    void enterServer(std::string args);
    void leaveServer();
    void listParticipants();

};

#endif // SISTEMA_H
