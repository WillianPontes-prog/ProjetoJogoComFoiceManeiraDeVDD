#include "Inimigo2.h"
#include "EstadoAndando.h"
#include <cstdlib> // para rand()

Inimigo2::Inimigo2(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida, Arma* arma)
    : Inimigo(listaJogadores, posX, posY, vida, arma), estadoAtual(new EstadoAndando()),  directionX(1)
{
    tempoRecarregando = 0;
    if (!(rand() % 2)) {
        directionX = -1;

    }

    velocidade = 0.5f;
}

Inimigo2::~Inimigo2() {
    delete estadoAtual;
}

void Inimigo2::atualiza() {
    estadoAtual->atualiza(this);
}

void Inimigo2::move() {
    estadoAtual->move(this);
}

void Inimigo2::sacarArma() {
    estadoAtual->sacarArma(this);
}

void Inimigo2::SwitchState(Estado* novoEstado) {
    setEstado(novoEstado);
}

void Inimigo2::setEstado(Estado* novoEstado) {
    if (estadoAtual) {
        delete estadoAtual;
    }
    estadoAtual = novoEstado;
}

void Inimigo2::AtacaJogador() {
    direcao = BuscarJogador();
    disparar();
}

