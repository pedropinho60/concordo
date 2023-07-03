#include "Usuario.h"

#include <string>

// ================= CONSTRUTORES E DESTRUTORES ===================

/**
 * @brief Construtor padrão da classe.
 *
 * @param email Email do usuário.
 * @param senha Senha do usuário.
 * @param nome Nome do usuário.
 * @param id Identificador único do usuário.
 */
Usuario::Usuario(std::string email, std::string senha, std::string nome,
                 int id) {
    this->email = email;
    this->senha = senha;
    this->nome = nome;
    this->id = id;
}

// ======================== GETTERS ==============================

/// @brief Retorna o id do usuário.
int Usuario::getId() { return id; }

/// @brief Retorna o nome do usuário.
std::string Usuario::getNome() { return nome; }

/// @brief Retorna o email do usuário.
std::string Usuario::getEmail() { return email; }

// ======================== MÉTODOS ==============================

/**
 * @brief Verifica se a senha passada é correta.
 *
 * @param senha Senha a ser verificada.
 */
bool Usuario::checarSenha(std::string senha) { return this->senha == senha; }
