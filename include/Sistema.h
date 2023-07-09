#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>

#include "Canal.h"
#include "Servidor.h"
#include "Usuario.h"

/// @brief Classe do sistema do Concordo. Guarda todos os usuários e servidores.
class Sistema {
   private:
    std::vector<Usuario> usuarios;     //!< Vetor com os usuários cadastrados.
    std::vector<Servidor> servidores;  //!< Vetor com os servidores criados.
    Usuario* usuarioLogado;            //!< Usuário logado atualmente.
    Servidor* servidorAtual;           //!< Servidor atual.
    Canal* canalAtual;                 //!< Canal atual.
    int ultimoIdUsuario;               //!< Id do último usuário criado.

   public:
    // Construtores e destrutores
    Sistema();
    ~Sistema();

    // Getters
    Usuario* getUsuario(std::string email);
    Usuario* getUsuario(int id);
    Servidor* getServidor(std::string nome);

    // Métodos
    void iniciar();
    bool lerComando();
    void salvar();

    // Comandos
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
    void listChannels();
    void createChannel(std::string args);
    void enterChannel(std::string args);
    void leaveChannel();
    void sendMessage(std::string args);
    void listMessages();

   private:
    void salvarUsuarios();
    void salvarServidores();
};

#endif  // SISTEMA_H
