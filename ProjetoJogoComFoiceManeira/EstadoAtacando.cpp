#include "EstadoAtacando.h"
#include "Zumbinana.h"
#include "EstadoAndando.h"

using namespace Personagens;

void EstadoAtacando::atualiza(Zumbinana* inimigo) {
    inimigo->atualizaProjetil();
    inimigo->mudarCorDano();
    sf::Vector2f posicao = inimigo->BuscarJogador();
    if (inimigo->getTempoCarregando() == 0) {
        inimigo->sacarArma();
        inimigo->setTempoCarregando(inimigo->getTempoMax());
    }
    inimigo->operator-();
    if (std::abs(posicao.x) > 160 || std::abs(posicao.y) > 140) {
        inimigo->setTempoCarregando(0);
        SwitchState(inimigo);
    }
    inimigo->atualizaSprite(inimigo->getBody().getPosition().x, inimigo->getBody().getPosition().y);
    inimigo->draw();
}

void EstadoAtacando::move(Zumbinana* inimigo) {
    // Nenhuma ação aqui, pois o movimento não é relevante no estado Atacando
}

void EstadoAtacando::sacarArma(Zumbinana* inimigo) {
    inimigo->AtacaJogador();
}

void EstadoAtacando::SwitchState(Zumbinana* inimigo) {
    inimigo->setEstado(new EstadoAndando());
}