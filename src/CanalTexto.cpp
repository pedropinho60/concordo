#include "CanalTexto.h"

#include <vector>

#include "Mensagem.h"

/// @brief Construtor da classe CanalTexto
CanalTexto::CanalTexto(std::string nome) : Canal(nome) {}

/// @brief Retorna o tipo do canal
std::string CanalTexto::getTipo() { return "texto"; }

/// @brief Adiciona uma mensagem ao canal
void CanalTexto::adicionarMensagem(const Mensagem& mensagem) {
    mensagens.push_back(mensagem);
}

/// @brief Retorna o vetor das mensagens do canal
std::vector<Mensagem> CanalTexto::getMensagens() { return mensagens; }
