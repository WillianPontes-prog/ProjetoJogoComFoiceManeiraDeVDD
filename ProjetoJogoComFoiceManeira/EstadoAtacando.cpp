#include "EstadoAtacando.h"
#include "Inimigo2.h"
#include "EstadoAndando.h"

void EstadoAtacando::atualiza(Inimigo2* inimigo) {
    inimigo->atualizaProjetil();
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

void EstadoAtacando::move(Inimigo2* inimigo) {
    // Nenhuma ação aqui, pois o movimento não é relevante no estado Atacando
}

void EstadoAtacando::sacarArma(Inimigo2* inimigo) {
    inimigo->AtacaJogador();
}

void EstadoAtacando::SwitchState(Inimigo2* inimigo) {
    inimigo->setEstado(new EstadoAndando());
}