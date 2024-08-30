#include "Zumbinana.h"
#include "EstadoAndando.h"
#include <cstdlib> // para rand()

using namespace Listas;

namespace Entidades {
    namespace Personagens {
        Zumbinana::Zumbinana(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida, Arma* arma)
            : Inimigo(listaJogadores, posX, posY, vida, arma), estadoAtual(new EstadoAndando()), directionX(1)
        {
            tempoRecarregando = 0;
            if (!(rand() % 2)) {
                directionX = -1;

            }

            velocidade = 0.5f;
        }

        Zumbinana::~Zumbinana() {
            delete estadoAtual;
        }

        void Zumbinana::atualiza() {
            estadoAtual->atualiza(this);
        }

        void Zumbinana::move() {
            estadoAtual->move(this);
        }

        void Zumbinana::sacarArma() {
            estadoAtual->sacarArma(this);
        }

        void Zumbinana::SwitchState(Estado* novoEstado) {
            setEstado(novoEstado);
        }

        void Zumbinana::setEstado(Estado* novoEstado) {
            if (estadoAtual) {
                delete estadoAtual;
            }
            estadoAtual = novoEstado;
        }

        void Zumbinana::AtacaJogador() {
            direcao = BuscarJogador();
            disparar();
        }

    }
}