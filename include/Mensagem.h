#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

class Mensagem {

private:
    std::string dataHora;
    int enviadaPor;
    std::string conteudo;

public:
    Mensagem() = default;
    Mensagem(std::string dataHora, int enviadaPor, std::string conteudo);

    std::string getDataHora();
    int getEnviadaPor();
    std::string getConteudo();
};

#endif // MENSAGEM_H
