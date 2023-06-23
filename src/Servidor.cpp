#include <string>

#include "Servidor.h"
#include "Usuario.h"

// ================= CONSTRUTORES E DESTRUTORES ===================

/**
 * @brief Construtor padrão da classe.
 *
 * @param nome Nome do servidor.
 * @param usuarioDono Usuário dono do servidor.
 */
Servidor::Servidor(std::string nome, Usuario *usuarioDono) {
    this->nome = nome;
    this->usuarioDonoId = usuarioDono->getId();
}

// ======================== GETTERS ==============================

/// @brief Retorna o nome do servidor.
std::string Servidor::getNome() {
    return nome;
}

/// @brief Retorna a descrição do servidor.
std::string Servidor::getDescricao() {
    return descricao;
}

/// @brief Retorna o código de convite do servidor.
std::string Servidor::getCodigoConvite() {
    return codigoConvite;
}

const std::vector<int> &Servidor::getParticipantesIds() {
    return participantesIds;
}

// ======================== SETTERS ==============================

/// @brief Altera a descrição do servidor.
void Servidor::setDescricao(std::string descricao) {
    this->descricao = descricao;
}

/// @brief Altera o código de convite do servidor.
void Servidor::setCodigoConvite(std::string codigoConvite) {
    this->codigoConvite = codigoConvite;
}

// ======================== MÉTODOS ==============================

/// @brief Verifica se o usuário passado é dono do servidor.
bool Servidor::isDono(Usuario *usuario) {
    return usuario->getId() == usuarioDonoId;
}

/// @brief Verifica se o usuário passado é participante do servidor.
bool Servidor::isParticipante(Usuario *usuario) {
    for(auto& participanteId : participantesIds) {
        if(participanteId == usuario->getId()) {
            return true;
        }
    }
    return false;
}

/// @brief Adiciona um usuário como participante do servidor.
void Servidor::adicionarParticipante(Usuario *usuario) {
    participantesIds.push_back(usuario->getId());
}

