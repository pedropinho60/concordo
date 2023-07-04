#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

/**
 * @brief Classe que representa uma mensagem enviada por um usuário.
 */
class Mensagem {
   private:
    std::string dataHora;  //!< Data e hora da mensagem
    int enviadaPor;        //!< ID do usuário que enviou a mensagem
    std::string conteudo;  //!< Conteúdo da mensagem

   public:
    Mensagem() = default;
    Mensagem(std::string dataHora, int enviadaPor, std::string conteudo);

    std::string getDataHora();
    int getEnviadaPor();
    std::string getConteudo();
};

#endif  // MENSAGEM_H
