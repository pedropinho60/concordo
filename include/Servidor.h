#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>

#include "Canal.h"
#include "Usuario.h"

class Servidor {

private:
    int usuarioDonoId;
    std::string nome;
    std::string descricao;
    std::string codigoConvite;
    std::vector<Canal *> canais;
    std::vector<int> participantesIds;

public:
    Servidor(std::string nome, Usuario *usuarioDono);

    // Getters
    std::string getNome();
    std::string getDescricao();
    std::string getCodigoConvite();

    // Setters
    void setDescricao(std::string descricao);
    void setCodigoConvite(std::string codigoConvite);

    // Métodos
    bool isDono(Usuario *usuario);
    bool isParticipante(Usuario *usuario);
    void adicionarParticipante(Usuario *usuario);
};

#endif
