#include "EstadoAndando.h"
#include "Inimigo2.h"
#include "EstadoAtacando.h"

void EstadoAndando::atualiza(Inimigo2* inimigo) {
    sf::Vector2f posicao = inimigo->BuscarJogador();
    inimigo->move();
    if (std::abs(posicao.x) > 80 || std::abs(posicao.y) > 60) {
        SwitchState(inimigo);
    }
    inimigo->atualizaSprite(inimigo->getBody().getPosition().x, inimigo->getBody().getPosition().y);
    inimigo->drawBody();
}

void EstadoAndando::move(Inimigo2* inimigo) {
    inimigo->setHspd(inimigo->getVelocidade() * inimigo->getDirectionX());
    //inimigo->sprite.setScale(inimigo->directionX, 1);
    inimigo->setVspd( GRAVIDADE);
}

void EstadoAndando::sacarArma(Inimigo2* inimigo) {
   
}

void EstadoAndando::SwitchState(Inimigo2* inimigo) {
    inimigo->setEstado(new EstadoAtacando());
}
