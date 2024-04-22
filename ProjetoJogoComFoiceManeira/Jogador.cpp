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
	//movimenta��o Cima
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		body.move(sf::Vector2f(0.f, -speedP));
	}
	//movimenta��o direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		body.move(sf::Vector2f(-speedP, 0.f));
	}
	//movimenta��o direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		body.move(sf::Vector2f(0.f,speedP));
	}
	//movimenta��o direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		body.move(sf::Vector2f(speedP,0.f));
	}
}
