#include "Jogador.h"

Jogador::Jogador(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat):
	EntidadesColision(dimensionX, dimensionY,posX, posY, listPlat)
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
		
	for (std::list<Plataforma*>::iterator it = listPlat->begin(); it != listPlat->end(); ++it) {

		sf::RectangleShape bodyTemp;

		bodyTemp = body;
		bodyTemp.move(sf::Vector2f(hspd, 0));

		if (CheckCollision(bodyTemp, (*it)->get_body())) {
			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(MinimalNumber(hspd), 0));

			while (!CheckCollision(bodyTemp, (*it)->get_body())) {
				body.move(sf::Vector2f(MinimalNumber(hspd), 0));
				
				bodyTemp = body;
				bodyTemp.move(sf::Vector2f(MinimalNumber(hspd), 0));
			}

			hspd = 0;
		}

		bodyTemp = body;
		bodyTemp.move(sf::Vector2f(0, vspd));

		if (CheckCollision(bodyTemp, (*it)->get_body())) {
			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(0, MinimalNumber(vspd)));

			while (!CheckCollision(bodyTemp, (*it)->get_body())) {
				body.move(sf::Vector2f(0, MinimalNumber(vspd)));

				bodyTemp = body;
				bodyTemp.move(sf::Vector2f(0, MinimalNumber(vspd)));
			}

			vspd = 0;
		}

		bodyTemp = body;
		bodyTemp.move(sf::Vector2f(0, 1));

		if (CheckCollision(bodyTemp, (*it)->get_body())) {
			coyteTime = MAXcoyteTime;
		}else if(coyteTime > 0){
			coyteTime--;
		}

		if (coyteTime) {
			//pulo
			flagJump = 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				vspd = -jump;
			}
		}
		else if (flagJump) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !flagW){
				vspd = -jump;
				flagJump = 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			flagW = 1;
		}
		else {
			flagW = 0;
		}

	}


	body.move(sf::Vector2f(hspd, vspd));
}

void Jogador::atualiza()
{
	Move();
	draw();
}
