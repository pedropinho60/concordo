#ifndef CANAL_H
#define CANAL_H

#include <string>

class Canal {
    
private:
    std::string nome;

public:
    Canal(std::string nome);
    std::string getNome();
    virtual std::string getTipo() = 0;
};

#endif // CANAL_H
