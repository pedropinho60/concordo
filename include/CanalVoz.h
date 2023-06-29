#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include "Mensagem.h"
#include "Canal.h"

class CanalVoz : public Canal {

private:
    Mensagem ultimaMensagem;

public:
    CanalVoz(std::string nome) : Canal(nome) {}
    std::string getTipo() override;

};

#endif // CANAL_VOZ_H
