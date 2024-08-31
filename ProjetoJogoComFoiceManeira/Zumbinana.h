#pragma once
#include "Inimigo.h"
#include "Estado.h"

namespace Entidades {
    namespace Personagens {
        class Zumbinana : public Inimigo
        {
        private:
            int directionX;
            Estado* estadoAtual;


        public:
            Zumbinana(Listas::Lista<Jogador*>* listaJogadores = nullptr, float posX = 0, float posY = 0, float vida = 5, Arma* arma = nullptr);
            ~Zumbinana();

            void atualiza();
            void move();
            void sacarArma();
            void SwitchState(Estado* novoEstado);

            const int getDirectionX() const { return directionX; }
            const float getVelocidade() const { return velocidade; }
            void invertDirectionX() { directionX = -directionX; }
            void setEstado(Estado* novoEstado);
            const int getTempoCarregando() const { return tempoRecarregando; }
            void setTempoCarregando(int tempo) { tempoRecarregando = tempo; }
            const int getTempoMax() const { return arma->getTempoDeRecarga(); }
            void operator-() { tempoRecarregando--; }
            void AtacaJogador();

            json toJson() {
                return json{
                    {classe, Tipo::_zumbinana},
                    {pX, getBody().getPosition().x},
                    {pY, getBody().getPosition().y},
                    {vd, vida}
                };
            }

            void danificar(Jogador* j) {
                j->operator--();
            };

            void Movimentacao() {
                hspd = velocidade * directionX;

                sprite.setScale(directionX, 1);

                vspd += GRAVIDADE;
            }
        };
    }
}
