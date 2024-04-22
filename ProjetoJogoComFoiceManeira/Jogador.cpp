#include "Jogador.h"

Jogador::Jogador():
	Entidade()
{
}

Jogador::~Jogador()
{
}

void Jogador::Move()
{
	//movimentação Cima
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		body.move(sf::Vector2f(0.f, -speedP));
	}
	//movimentação direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		body.move(sf::Vector2f(-speedP, 0.f));
	}
	//movimentação direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		body.move(sf::Vector2f(0.f,speedP));
	}
	//movimentação direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		body.move(sf::Vector2f(speedP,0.f));
	}
}
