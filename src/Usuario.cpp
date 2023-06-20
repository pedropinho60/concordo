#include "Usuario.h"
#include <string>

Usuario::Usuario(std::string email, std::string senha, std::string nome, int id){
   this->email = email;
   this->senha = senha;
   this->nome = nome;
   this->id = id;
}

int Usuario::getId(){
    return id;
}

std::string Usuario::getNome(){
    return nome;
}

std::string Usuario::getEmail(){
    return email;
}

bool Usuario::checarSenha(std::string senha){
    return this->senha == senha;
}
