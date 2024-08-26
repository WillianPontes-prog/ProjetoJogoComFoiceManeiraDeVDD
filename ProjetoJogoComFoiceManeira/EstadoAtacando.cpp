#include "EstadoAtacando.h"
#include "Inimigo2.h"
#include "EstadoAndando.h"

void EstadoAtacando::atualiza(Inimigo2* inimigo) {
    sf::Vector2f posicao = inimigo->BuscarJogador();
    inimigo->sacarArma();
    if (std::abs(posicao.x) < 160 || std::abs(posicao.y) < 120) {
        SwitchState(inimigo);
    }
    inimigo->atualizaSprite(inimigo->getBody().getPosition().x, inimigo->getBody().getPosition().y);
    inimigo->drawBody();
}

void EstadoAtacando::move(Inimigo2* inimigo) {
    // Nenhuma ação aqui, pois o movimento não é relevante no estado Atacando
}

void EstadoAtacando::sacarArma(Inimigo2* inimigo) {
    //inimigo->disparar(inimigo->body.getPosition(), inimigo->BuscarJogador(), inimigo->gerenciadorGrafico);
}

void EstadoAtacando::SwitchState(Inimigo2* inimigo) {
    inimigo->setEstado(new EstadoAndando());
}
