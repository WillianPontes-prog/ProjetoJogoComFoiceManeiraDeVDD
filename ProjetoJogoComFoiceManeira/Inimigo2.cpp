#include "Inimigo2.h"

Inimigo2::Inimigo2(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida):Inimigo(listaJogadores, posX, posY, vida)
{
	velocidade = 1;

	if (!(rand() % 2))
		directionX = -1;
}

Inimigo2::~Inimigo2()
{
}

void Inimigo2::atualiza()
{
    switch (state)
    {
    case Inimigo2::Andando:
        move();
        sf::Vector2f posicao = BuscarJogador();
        if (std::abs(posicao.x) > 80 || std::abs(posicao.y) > 60) {
            SwitchState();

        }
        break;
    case Inimigo2::Atacando:
        sacarArma();
        if (std::abs(posicao.x) < 160 || std::abs(posicao.y) < 120) {
            SwitchState();

        }


        break;
    
    default:
        break;
    }
   atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
   drawBody();
	
}

void Inimigo2::move()
{
	hspd = velocidade * directionX;

	sprite.setScale(directionX, 1);

	vspd += GRAVIDADE;
}

void Inimigo2::sacarArma()
{
    arma->disparar(body.getPosition(),BuscarJogador(), gerenciadorGrafico);
}

