#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <vector>

#include "Canal.h"
#include "Mensagem.h"

/**
 * @brief Classe que representa um canal de texto, que guarda todas as mensagens
 * enviadas.
 */
class CanalTexto : public Canal {
   private:
    std::vector<Mensagem> mensagens; //!< Mensagens do canal de texto

   public:
    CanalTexto(std::string nome);
    virtual ~CanalTexto() = default;
    std::string getTipo() override;

    void adicionarMensagem(const Mensagem& mensagem) override;
    std::vector<Mensagem> getMensagens() override;
};

#endif
