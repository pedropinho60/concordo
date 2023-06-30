#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include "Mensagem.h"
#include "Canal.h"

class CanalVoz : public Canal {

private:
    Mensagem ultimaMensagem;

public:
    CanalVoz(std::string nome);
    std::string getTipo() override;
    void adicionarMensagem(const Mensagem& mensagem) override;
    std::vector<Mensagem> getMensagens() override;

};

#endif // CANAL_VOZ_H
