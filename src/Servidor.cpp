#include <string>

#include "Servidor.h"
#include "Usuario.h"

Servidor::Servidor(std::string nome, Usuario *usuarioDono) {
    this->nome = nome;
    this->usuarioDonoId = usuarioDono->getId();
}

std::string Servidor::getNome() {
    return nome;
}

std::string Servidor::getDescricao() {
    return descricao;
}

std::string Servidor::getCodigoConvite() {
    return codigoConvite;
}

void Servidor::setDescricao(std::string descricao) {
    this->descricao = descricao;
}

void Servidor::setCodigoConvite(std::string codigoConvite) {
    this->codigoConvite = codigoConvite;
}

bool Servidor::isDono(Usuario *usuario) {
    return usuario->getId() == usuarioDonoId;
}

bool Servidor::isParticipante(Usuario *usuario) {
    for(auto& participanteId : participantesIds) {
        if(participanteId == usuario->getId()) {
            return true;
        }
    }
    return false;
}

void Servidor::adicionarParticipante(Usuario *usuario) {
    participantesIds.push_back(usuario->getId());
}

const std::vector<int> &Servidor::getParticipantesIds() {
    return participantesIds;
}
