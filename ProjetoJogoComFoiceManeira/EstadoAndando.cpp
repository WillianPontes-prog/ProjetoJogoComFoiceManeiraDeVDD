#include "EstadoAndando.h"
#include "Inimigo2.h"
#include "EstadoAtacando.h"

void EstadoAndando::atualiza(Inimigo2* inimigo) {
    sf::Vector2f posicao = inimigo->BuscarJogador();
    inimigo->move();
    if (std::abs(posicao.x) < 100 && std::abs(posicao.y) < 90) {
        
        inimigo->setHspd(0);

        SwitchState(inimigo);
        
    }
    inimigo->atualizaSprite(inimigo->getBody().getPosition().x, inimigo->getBody().getPosition().y);
    inimigo->draw();
    inimigo->atualizaProjetil();
}

void EstadoAndando::move(Inimigo2* inimigo) {

    inimigo->Movimentacao();
    
}

void EstadoAndando::sacarArma(Inimigo2* inimigo) {

}

void EstadoAndando::SwitchState(Inimigo2* inimigo) {
    inimigo->setEstado(new EstadoAtacando());
}