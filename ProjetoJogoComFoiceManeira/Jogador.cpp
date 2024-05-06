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

	Entidade* temp;

	for (int i = 0; i < LEs->LEs.get_len(); i++) {

		temp = LEs->LEs.get_item(i);
		

		if (temp->get_body().getPosition() != body.getPosition()) {

			//colisão horizontal
			if ((body.getPosition().y + vspd >= temp->get_body().getPosition().y) && (body.getPosition().y + vspd <= temp->get_body().getPosition().y + temp->get_body().getSize().y) ||
				(body.getPosition().y + vspd + body.getSize().y >= temp->get_body().getPosition().y) && (body.getPosition().y + vspd + body.getSize().y <= temp->get_body().getPosition().y + temp->get_body().getSize().y)){
				if (hspd + body.getPosition().x + body.getSize().x >= temp->get_body().getPosition().x &&
					hspd + body.getPosition().x <= temp->get_body().getPosition().x + temp->get_body().getSize().x) {

					hspd = 0;
				}
			}

			//colisao vertical
			if ((body.getPosition().x + hspd >= temp->get_body().getPosition().x) && (body.getPosition().x + hspd <= temp->get_body().getPosition().x + temp->get_body().getSize().x) ||
				(body.getPosition().x + hspd + body.getSize().x >= temp->get_body().getPosition().x) && (body.getPosition().x + hspd + body.getSize().x <= temp->get_body().getPosition().x + temp->get_body().getSize().x)) {
				if (vspd + body.getPosition().y + body.getSize().y >= temp->get_body().getPosition().y &&
					vspd + body.getPosition().y <= temp->get_body().getPosition().y + temp->get_body().getSize().y) {

					vspd = 0;
				}
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
