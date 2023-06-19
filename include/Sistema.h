#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>

#include "Usuario.h"
#include "Canal.h"
#include "Servidor.h"

class Sistema {

private:
    std::vector<Usuario> usuarios;
    std::vector<Servidor> servidores;
    Usuario *usuarioLogado;
    Servidor *servidorAtual;
    Canal *canalAtual;

};

#endif // SISTEMA_H
