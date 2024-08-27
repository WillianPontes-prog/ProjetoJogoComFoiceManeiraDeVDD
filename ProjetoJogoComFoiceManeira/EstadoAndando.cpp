#include "EstadoAndando.h"
#include "Inimigo2.h"
#include "EstadoAtacando.h"

void EstadoAndando::atualiza(Inimigo2* inimigo) {
    sf::Vector2f posicao = inimigo->BuscarJogador();
    inimigo->move();
    if (std::abs(posicao.x) < 100 && std::abs(posicao.y) < 90) {
        SwitchState(inimigo);
    }
    inimigo->atualizaSprite(inimigo->getBody().getPosition().x, inimigo->getBody().getPosition().y);
    inimigo->drawBody();
    inimigo->atualizaProjetil();
}

void EstadoAndando::move(Inimigo2* inimigo) {
    //inimigo->setHspd(inimigo->getVelocidade() * inimigo->getDirectionX());
    //inimigo->setScale(inimigo->getDirectionX());
    inimigo->setVspd(inimigo->getHspd()+GRAVIDADE);
}

void EstadoAndando::sacarArma(Inimigo2* inimigo) {

}

void EstadoAndando::SwitchState(Inimigo2* inimigo) {
    inimigo->setEstado(new EstadoAtacando());
}