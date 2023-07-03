#include "Mensagem.h"

Mensagem::Mensagem(std::string dataHora, int enviadaPor, std::string conteudo)
    : dataHora(dataHora), enviadaPor(enviadaPor), conteudo(conteudo) {}

std::string Mensagem::getDataHora() { return dataHora; }

int Mensagem::getEnviadaPor() { return enviadaPor; }

std::string Mensagem::getConteudo() { return conteudo; }
