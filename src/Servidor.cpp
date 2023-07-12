#include "Servidor.h"

#include <string>

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
    this->adicionarParticipante(usuarioDono);
}

/**
 * @brief Construtor padrão da classe.
 *
 * @param nome Nome do servidor.
 * @param idDono Id do usuário dono do servidor.
 */
Servidor::Servidor(std::string nome, int idDono) {
    this->nome = nome;
    this->usuarioDonoId = idDono;
    this->adicionarParticipante(idDono);
}

/**
 * @brief Destrutor padrão da classe.
 *
 * @note Os canais do servidor são deletados pelo destrutor da classe Sistema.
 */
Servidor::~Servidor() = default;

// ======================== GETTERS ==============================

/// @brief Retorna o id do dono do servidor
int Servidor::getDonoId() { return usuarioDonoId; }

/// @brief Retorna o nome do servidor.
std::string Servidor::getNome() { return nome; }

/// @brief Retorna a descrição do servidor.
std::string Servidor::getDescricao() { return descricao; }

/// @brief Retorna o código de convite do servidor.
std::string Servidor::getCodigoConvite() { return codigoConvite; }

/// @brief Reorna o vetor de ids dos participantes do servidor.
const std::vector<int> &Servidor::getParticipantesIds() {
    return participantesIds;
}

/// @brief Retorna o vetor de canais do servidor.
const std::vector<Canal *> &Servidor::getCanais() { return canais; }

// ======================== SETTERS ==============================

/**
 * @brief Altera a descrição do servidor.
 *
 * @param descricao Nova descrição do servidor.
 */
void Servidor::setDescricao(std::string descricao) {
    this->descricao = descricao;
}

/**
 * @brief Altera o código de convite do servidor.
 *
 * @param codigoConvite Novo código de convite do servidor.
 */
void Servidor::setCodigoConvite(std::string codigoConvite) {
    this->codigoConvite = codigoConvite;
}

// ======================== MÉTODOS ==============================

/**
 * @brief Verifica se o usuário passado é dono do servidor.
 *
 * @param usuario Usuário a ser verificado.
 */
bool Servidor::isDono(Usuario *usuario) {
    return usuario->getId() == usuarioDonoId;
}

/**
 * @brief Verifica se o usuário passado é participante do servidor.
 *
 * @param usuario Usuário a ser verificado.
 */
bool Servidor::isParticipante(Usuario *usuario) {
    for (auto &participanteId : participantesIds) {
        if (participanteId == usuario->getId()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Adiciona um usuário como participante do servidor.
 *
 * @param usuario Usuário a ser adicionado.
 */
void Servidor::adicionarParticipante(Usuario *usuario) {
    participantesIds.push_back(usuario->getId());
}

/**
 * @brief Adiciona um usuário como participante do servidor.
 *
 * @param id Id do usuário a ser adicionado.
 */
void Servidor::adicionarParticipante(int id) {
    participantesIds.push_back(id);
}

/**
 * @brief Adiciona um canal ao servidor.
 *
 * @param canal Canal a ser adicionado.
 */
void Servidor::adicionarCanal(Canal *canal) { canais.push_back(canal); }

/**
 * @brief Busca um canal no servidor pelo nome.
 *
 * @param nome Nome do canal a ser buscado.
 * @return Ponteiro para o canal buscado.
 */
Canal *Servidor::buscarCanal(std::string nome) {
    for (auto canal : canais) {
        if (canal->getNome() == nome) {
            return canal;
        }
    }

    return nullptr;
}

/**
 * @brief Busca um canal no servidor pelo nome e tipo.
 *
 * @param nome Nome do canal a ser buscado.
 * @param tipo Tipo do canal a ser buscado.
 * @return Ponteiro para o canal buscado.
 */
Canal *Servidor::buscarCanal(std::string nome, std::string tipo) {
    for (auto canal : canais) {
        if (canal->getNome() == nome && canal->getTipo() == tipo) {
            return canal;
        }
    }

    return nullptr;
}
