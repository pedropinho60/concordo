#include "Mensagem.h"

/// @brief Construtor da classe Mensagem.
Mensagem::Mensagem(std::string dataHora, int enviadaPor, std::string conteudo)
    : dataHora(dataHora), enviadaPor(enviadaPor), conteudo(conteudo) {}

/// @brief Retorna a data e hora da mensagem.
std::string Mensagem::getDataHora() { return dataHora; }

/// @brief Retorna o ID do usuário que enviou a mensagem.
int Mensagem::getEnviadaPor() { return enviadaPor; }

/// @brief Retorna o conteúdo da mensagem.
std::string Mensagem::getConteudo() { return conteudo; }
