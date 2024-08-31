#include "EstadoAndando.h"
#include "Entidades/Personagens/Zumbinana.h"
#include "EstadoAtacando.h"

using namespace Entidades::Personagens;

void EstadoAndando::atualiza(Zumbinana* inimigo) {
    sf::Vector2f posicao = inimigo->BuscarJogador();
    inimigo->move();
    inimigo->mudarCorDano();
    if (std::abs(posicao.x) < 100 && std::abs(posicao.y) < 90) {
        
        inimigo->setHspd(0);
        SwitchState(inimigo);
        
    }
    inimigo->atualizaSprite(inimigo->getBody().getPosition().x, inimigo->getBody().getPosition().y);
    inimigo->draw();
    inimigo->atualizaProjetil();
}

void EstadoAndando::move(Zumbinana* inimigo) {

    inimigo->Movimentacao();
    
}

void EstadoAndando::sacarArma(Zumbinana* inimigo) {

}

void EstadoAndando::SwitchState(Zumbinana* inimigo) {
    inimigo->setEstado(new EstadoAtacando());
}