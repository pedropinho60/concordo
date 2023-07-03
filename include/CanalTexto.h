#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <vector>

#include "Canal.h"
#include "Mensagem.h"

class CanalTexto : public Canal {
   private:
    std::vector<Mensagem> mensagens;

   public:
    CanalTexto(std::string nome);
    std::string getTipo() override;

    void adicionarMensagem(const Mensagem& mensagem) override;
    std::vector<Mensagem> getMensagens() override;
};

#endif
