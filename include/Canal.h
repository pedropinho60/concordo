#ifndef CANAL_H
#define CANAL_H

#include <string>
#include <vector>

#include "Mensagem.h"

/// @brief Classe que representa um canal de voz ou de texto.
class Canal {
   private:
    std::string nome; //!< Nome do canal

   public:
    Canal(std::string nome);
    virtual ~Canal() = default;
    std::string getNome();

    /// @brief Retorna o tipo do canal.
    virtual std::string getTipo() = 0;
    /// @brief Adiciona uma mensagem ao canal.
    virtual void adicionarMensagem(const Mensagem& mensagem) = 0;
    /// @brief Retorna um vetor com as mensagens do canal.
    virtual std::vector<Mensagem> getMensagens() = 0;
};

#endif  // CANAL_H
