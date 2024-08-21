#include "Jogador.h"



Jogador::Jogador(float posX, float posY, int vida): 
	EntidadeColisao(posX, posY, vida)
{
	setTextura("LifeImg.png");
	
}

Jogador::~Jogador()
{
}

void Jogador::move()
{
}

void Jogador::atualiza()
{
	atualizaSprite(body.getPosition().x, body.getPosition().y);
	draw();
}
