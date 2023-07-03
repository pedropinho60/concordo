#ifndef CANAL_H
#define CANAL_H

#include <string>
#include <vector>

#include "Mensagem.h"

class Canal {
   private:
    std::string nome;

   public:
    Canal(std::string nome);
    std::string getNome();
    virtual std::string getTipo() = 0;
    virtual void adicionarMensagem(const Mensagem& mensagem) = 0;
    virtual std::vector<Mensagem> getMensagens() = 0;
};

#endif  // CANAL_H
