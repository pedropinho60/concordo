#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include "Canal.h"
#include "Mensagem.h"

/**
 * @brief Classe que representa um canal de voz, que guarda a última mensagem
 * enviada.
 */
class CanalVoz : public Canal {
   private:
    Mensagem ultimaMensagem;  //!< Última mensagem enviada no canal de voz

   public:
    CanalVoz(std::string nome);
    virtual ~CanalVoz() = default;
    std::string getTipo() override;
    void adicionarMensagem(const Mensagem& mensagem) override;
    std::vector<Mensagem> getMensagens() override;
};

#endif  // CANAL_VOZ_H
