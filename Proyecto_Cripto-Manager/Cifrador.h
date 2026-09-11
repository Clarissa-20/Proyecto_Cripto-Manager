#ifndef CIFRADOR_H
#define CIFRADOR_H

#include <string>

class Cifrador{
public:
    virtual ~Cifrador(){}
    virtual std::string cifrar(const std::string& texto, int clave)=0;
    virtual std::string descifrar(const std::string& texto, int clave)=0;
};

#endif // CIFRADOR_H