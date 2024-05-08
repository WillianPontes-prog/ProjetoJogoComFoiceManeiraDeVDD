#include "Jogador.h"

Jogador::Jogador():
	EntidadesColision()
{
}

Jogador::~Jogador()
{
}

void Jogador::Move()
{
	float hspd = 0;
	float vspd = 0;

	//movimentação Cima
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		vspd -= speedP;
	}
	//movimentação direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		hspd -= speedP;
	}
	//movimentação direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		vspd += speedP;
	}
	//movimentação direita
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		hspd += speedP;
	}

	Entidade* entidadeTemp;

	for (int i = 0; i < LEs->LEs.get_len(); i++) {

		entidadeTemp = LEs->LEs.get_item(i);
		

		if (entidadeTemp->get_body().getPosition() != body.getPosition()) {

			sf::RectangleShape bodyTemp = body;
			bodyTemp.move(sf::Vector2f(hspd, vspd));

			if (CollisionH(bodyTemp, entidadeTemp->get_body())) {
				hspd = 0;
			}

			if (CollisionV(bodyTemp, entidadeTemp->get_body())) {
				vspd = 0;
			}


		}

	}

	body.move(sf::Vector2f(hspd, vspd));
}

void Jogador::atualiza()
{
	Move();
	draw();
}
