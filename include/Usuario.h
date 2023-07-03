#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/// @brief Classe que representa um usuário do sistema.
class Usuario {
   private:
    int id;             //!< Identificador único do usuário.
    std::string nome;   //!< Nome do usuário.
    std::string email;  //!< Email do usuário.
    std::string senha;  //!< Senha do usuário.

   public:
    // Construtores e destrutores
    Usuario(std::string email, std::string senha, std::string nome, int id);
    ~Usuario() = default;

    // Getters
    int getId();
    std::string getNome();
    std::string getEmail();

    // Métodos
    bool checarSenha(std::string senha);
};

#endif  // USUARIO_H
