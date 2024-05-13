#include "Jogador.h"

Jogador::Jogador(float dimensionX, float dimensionY):
	EntidadesColision(dimensionX, dimensionY)
{
}

Jogador::~Jogador()
{
}


void Jogador::Move()
{


	//movimentação Esquerda
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		hspd = -speedP;
	}
	//movimentação Direita
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		hspd = speedP;
	}
	else {
		hspd = 0;
	}

	vspd += GRAVIDADE;

	if(listPlat != nullptr){
		
		for (std::list<Plataforma>::iterator it = listPlat->begin(); it != listPlat->end(); ++it) {

			sf::RectangleShape bodyTemp;

			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(hspd, 0));

			if (CheckCollision(bodyTemp, it->get_body())) {
				hspd = 0;
			}

			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(0, vspd));

			if (CheckCollision(bodyTemp, it->get_body())) {
				vspd = 0;
			}

			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(0, 1));

			if (CheckCollision(bodyTemp, it->get_body())) {
				//pulo
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					vspd = -5;
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
