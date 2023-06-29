#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <vector>

#include "Mensagem.h"
#include "Canal.h"

class CanalTexto : public Canal {

private:
    std::vector<Mensagem> mensagens;

public:
    CanalTexto(std::string nome) : Canal(nome) {};
    std::string getTipo() override;

};

#endif
