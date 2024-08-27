#pragma once
#include "Inimigo.h"
#include "Estado.h"

class Inimigo2 : public Inimigo
{
private:
    int directionX;
    Estado* estadoAtual;
    float velocidade;
    int TempoCarregando;

public:
    Inimigo2(Lista<Jogador*>* listaJogadores = nullptr, float posX = 0, float posY = 0, float vida = 5, Arma* arma = nullptr);
    ~Inimigo2();

    void atualiza();
    void move();
    void sacarArma();
    void SwitchState(Estado* novoEstado);

    int getDirectionX() { return directionX; }
    float getVelocidade() { return velocidade; }
    void invertDirectionX() { directionX = -directionX; }
    void setEstado(Estado* novoEstado);
    void AtacaJogador();
};