#include "CanalVoz.h"

#include <vector>

#include "Canal.h"
#include "Mensagem.h"

/// @brief Construtor da classe CanalVoz.
CanalVoz::CanalVoz(std::string nome) : Canal(nome) {}

/// @brief Retorna o tipo do canal.
std::string CanalVoz::getTipo() { return "voz"; }

/// @brief Substitui a última mensagem enviada no canal.
void CanalVoz::adicionarMensagem(const Mensagem& mensagem) {
    ultimaMensagem = mensagem;
}

/// @brief Retorna um vetor com a última mensagem enviada no canal.
std::vector<Mensagem> CanalVoz::getMensagens() {
    std::vector<Mensagem> vec;

    if (ultimaMensagem.getConteudo() != "") {
        vec.push_back(ultimaMensagem);
    }

    return vec;
}
