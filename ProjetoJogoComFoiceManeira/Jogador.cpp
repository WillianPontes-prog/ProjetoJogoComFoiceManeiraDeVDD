#include "Jogador.h"

namespace Personagens {
    Jogador::Jogador(float posX, float posY, int vida, Arma* arma, bool jogador2, bool voar) :
        EntidadeColidivel(posX, posY, vida, arma),
        state(Normal),
        posicaoInicial(posX, posY),
        jogador2(jogador2),
        voador(voar),
        vivo(true)
    {
        maxTempoMachucado = 45;

        //setTextura("Imagens/Jogador1.png");
        setVelocidade(5);

        if (!texturaVida.loadFromFile("LifeImg.png")) {
            // Tratar o erro de carregamento da textura
            throw std::runtime_error("Erro ao carregar a textura!");
        }
        spriteVida.setTexture(texturaVida);

    }

    Jogador::~Jogador()
    {
    }

    void Jogador::move()
    {

        //movimentação Esquerda
        if (WASD[1]) {
            hspd = -velocidade;
            direcao.x = -1;
            sprite.setScale(-1, 1);

        }
        //movimentação Direita
        else if (WASD[3]) {
            hspd = velocidade;
            direcao.x = 1;
            sprite.setScale(1, 1);
        }
        else {
            hspd = 0;

        }


        vspd += GRAVIDADE;

        if (WASD[0] && noChao)
        {
            if (voador)
                vspd = -4;
            else
                vspd = -12;

        }
    }

    void Jogador::atualiza()
    {
        atualizaProjetil();

        if (vivo) {
            if (jogador2) {
                drawVida(8, 40, spriteVida);
            }
            else {
                drawVida(8, 8, spriteVida);
            }

            switch (state)
            {
            case Jogador::Normal:
                move();
                sacarArma();

                break;
            case Jogador::Recarregando:
                move();

                if (tempoRecarregando > 0)
                    tempoRecarregando--;
                else
                    setState(Normal);


                break;
            case Jogador::Machucado:


                if (tempoMachucado > 0)
                {
                    tempoMachucado--;

                    if (vspd == 0) {
                        if (hspd > 0)
                            hspd--;
                        else if (hspd < 0)
                            hspd++;
                    }

                    sprite.setColor(sf::Color::Black);

                    vspd += GRAVIDADE;
                }
                else
                {
                    sprite.setColor(sf::Color::White);
                    setState(Normal);
                }

                break;
            default:
                break;
            }

            if (vida <= 0) {
                vivo = false;
            }

            atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
            draw();
        }

        WASD[0] = 0;
        WASD[1] = 0;
        WASD[2] = 0;
        WASD[3] = 0;

        gun = 0;

    }

    void Jogador::setState(State state)
    {
        if (getState() != Machucado && state == Machucado)
        {
            tempoMachucado = maxTempoMachucado;
        }

        this->state = state;
    }

    void Jogador::sacarArma()
    {
        if ((!jogador2 && gun)
            || (jogador2 && gun)) {
            disparar();
            setState(Recarregando);
        }
    }



}


