#pragma once
#include "Inimigo.h"

namespace Personagens {
    class ZumbiFriorento : public Inimigo
    {
    private:
        int directionX;

    public:
        ZumbiFriorento(Listas::Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 5);
        ~ZumbiFriorento();

        void atualiza();
        void move();

        void invertDirectionX() { directionX = -directionX; }
        void sacarArma() {};

        json toJson() {
            return json{
                {classe, Tipo::_zumbifriorento},
                {pX, getBody().getPosition().x},
                {pY, getBody().getPosition().y},
                {vd, vida}
            };
        }

        void danificar(Jogador* j) {
            j->operator--();
        }
    };
}
