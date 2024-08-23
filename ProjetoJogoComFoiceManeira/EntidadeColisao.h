#pragma once
#include "Entidade.h"
#include "Arma.h"

class EntidadeColisao : public Entidade {
protected:

    Lista<Projetil*>* listaProjetil;
    Arma* arma;

    float velocidade;

    float hspd;
    float vspd;

    int vida;

    bool noChao;

    int tempoRecarregando;

    sf::Vector2f direcao;

    int maxTempoMachucado;
    int tempoMachucado;

public:
    EntidadeColisao(int posX = 0, int posY = 0, int vida = 5, Arma* arma = NULL);
    ~EntidadeColisao();

    void setVelocidade(float velocidade) { this->velocidade = velocidade; };

    virtual void move() = 0;
    virtual void atualiza() = 0;

    float getHspd() { return hspd; };
    float getVspd() { return vspd; };

    void setHspd(float hspd) { this->hspd = hspd; };
    void setVspd(float vspd) { this->vspd = vspd; };

    void setNoChao(bool noChao) { this->noChao = noChao; };

    void drawVida(float posX, float poY, sf::Sprite sprVida);

    virtual void operator--() { vida--; };

    void disparar();

    void atualizaProjetil();

    virtual void sacarArma() = 0;

    Lista<Projetil*>* getListaProjetil() { return listaProjetil; };

    void setArma(Arma* arma) { this->arma = arma; };

    int getVida() { return vida; }

};