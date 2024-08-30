#include "EntidadeColidivel.h"

using namespace Listas;

EntidadeColidivel::EntidadeColidivel(int posX, int posY, int vida, Arma* arma) : 
	Entidade(posX, posY, 32, 32), 
	listaProjetil(new Lista<Projetil*>),
	arma(arma),
	hspd(0), 
	vspd(0), 
	vida(vida),
	velocidade(0),
	noChao(false),
    tempoRecarregando(0),
    direcao(1, 0),
    maxTempoMachucado(10),
    tempoMachucado(0),
    sobAtrito(false)
{
    if (arma != NULL) {
        arma->setListaProjetil(listaProjetil);
    }
}

EntidadeColidivel::~EntidadeColidivel()
{
    delete arma;

    delete listaProjetil;
}

void EntidadeColidivel::drawVida(float posX, float poY, sf::Sprite sprVida)
{
	for(int i = 0; i < vida; i++){
		sprVida.setPosition(posX + (i * 32), poY);
		gerenciadorGrafico->draw(sprVida);
	}
}

void EntidadeColidivel::disparar()
{
    if (arma != NULL) {

        sf::Vector2f posicao = getBody().getPosition();
        posicao.x += getBody().getSize().x / 2;
        posicao.y += getBody().getSize().y / 2;

        arma->disparar(posicao, direcao);

        tempoRecarregando = arma->getTempoDeRecarga();
    }
}

void EntidadeColidivel::atualizaProjetil() {

    for (Lista<Projetil*>::iterator it = listaProjetil->begin(); it != listaProjetil->end(); )
    {
        (*it)->atualiza();

        if ((*it)->OverTime()) {
            Projetil* projetil = (*it);
            it = listaProjetil->removerElemento(it);
            delete projetil;
        }
        else {
            ++it;
        }
        
    }

}

Listas::Lista<Projetil*>* EntidadeColidivel::getListaProjetil()
{
    return listaProjetil;
}

