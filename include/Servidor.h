#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>

#include "Canal.h"
#include "Usuario.h"

/// @brief Classe que representa um servidor do sistema.
class Servidor {

private:
    int usuarioDonoId; //!< Id do usuário dono do servidor.
    std::string nome; //!< Nome do servidor.
    std::string descricao; //!< Descrição do servidor.
    std::string codigoConvite; //!< Código de convite do servidor.
    std::vector<Canal *> canais; //!< Vetor com os canais do servidor.
    std::vector<int> participantesIds; //!< Vetor com os ids dos participantes do servidor.

public:
    Servidor(std::string nome, Usuario *usuarioDono);

    // Getters
    std::string getNome();
    std::string getDescricao();
    std::string getCodigoConvite();
    const std::vector<int>& getParticipantesIds();
    const std::vector<Canal *>& getCanais();

    // Setters
    void setDescricao(std::string descricao);
    void setCodigoConvite(std::string codigoConvite);

    // Métodos
    bool isDono(Usuario *usuario);
    bool isParticipante(Usuario *usuario);
    void adicionarParticipante(Usuario *usuario);
    void adicionarCanal(Canal *canal);
    Canal* buscarCanal(std::string nome);
    Canal* buscarCanal(std::string nome, std::string tipo);
};

#endif
