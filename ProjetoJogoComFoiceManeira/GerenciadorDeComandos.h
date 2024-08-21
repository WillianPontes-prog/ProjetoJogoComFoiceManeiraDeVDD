#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorDeComandos {

private:
    static int isPJump;

public:

    GerenciadorDeComandos() {}
    ~GerenciadorDeComandos() {};

    static int Esquerda();
    static int Direita();
    static int Baixo();
    static int Cima();
    static int Click();

    static int Pular();

    static int Disparar();
    

    
};