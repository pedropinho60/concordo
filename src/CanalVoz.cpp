#include "CanalVoz.h"

#include <vector>

#include "Canal.h"
#include "Mensagem.h"

CanalVoz::CanalVoz(std::string nome) : Canal(nome) {}

std::string CanalVoz::getTipo() { return "voz"; }

void CanalVoz::adicionarMensagem(const Mensagem& mensagem) {
    ultimaMensagem = mensagem;
}

std::vector<Mensagem> CanalVoz::getMensagens() {
    std::vector<Mensagem> vec;

    if (ultimaMensagem.getConteudo() != "") {
        vec.push_back(ultimaMensagem);
    }

    return vec;
}
