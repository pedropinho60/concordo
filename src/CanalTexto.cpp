#include "CanalTexto.h"

#include <vector>

#include "Mensagem.h"

CanalTexto::CanalTexto(std::string nome) : Canal(nome) {}

std::string CanalTexto::getTipo() { return "texto"; }

void CanalTexto::adicionarMensagem(const Mensagem& mensagem) {
    mensagens.push_back(mensagem);
}

std::vector<Mensagem> CanalTexto::getMensagens() { return mensagens; }
