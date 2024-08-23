#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorDeComandos {

private:
    static int isPJump;
    static int isPJumpV2;

public:

    GerenciadorDeComandos() {}
    ~GerenciadorDeComandos() {};

    static int Esquerda();
    static int Direita();
    static int Baixo();
    static int Cima();

    static int Pular();
    static int Disparar();

    static int Click();

    static int EsquerdaV2();
    static int DireitaV2();
    static int BaixoV2();
    static int CimaV2();

    static int PularV2();
    static int DispararV2();


};