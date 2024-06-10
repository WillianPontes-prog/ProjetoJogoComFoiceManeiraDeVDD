#include "Jogador.h"

Jogador::Jogador(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat) :
	EntidadesColision(dimensionX, dimensionY, posX, posY, listPlat)
{
	listPlayerAtaque = new std::list<Ataque*>();
}

Jogador::~Jogador()
{
}

void Jogador::atualiza()
{
	switch (state)
	{
	case Stand: {
		Move();
		BasicAtk();
	}
		break;

	case Atk: {
		Move();
		
		if (cooldown <= 0) {
			state = Stand;
		}
		else {
			cooldown--;
		}
	}
		break;

	default: {

	}
		break;
	}

	for (auto it = listPlayerAtaque->begin(); it != listPlayerAtaque->end();) {
		if ((*it)->OverTime()) {
			delete* it; // Liberar memória
			it = listPlayerAtaque->erase(it); // Remover elemento e atualizar iterador
		}
		else {
			(*it)->atualiza();
			++it;
		}
	}

	draw();
}

void Jogador::Move()
{

	//movimentação Esquerda
	if (KeyLeft()) {
		hspd = -speedP;
		dir = PI;
	}
	//movimentação Direita
	else if (KeyRight()) {
		hspd = speedP;
		dir = 0;
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
		}
		else if (coyteTime > 0) {
			coyteTime--;
		}

		if (coyteTime) {
			//pulo
			flagJump = 1;
			if (KeyJump()) {
				vspd = -jump;
			}
		}
		else if (flagJump) {
			if (KeyJump() && !flagW) {
				vspd = -jump;
				flagJump = 0;
			}
		}

		if (KeyJump()) {
			flagW = 1;
		}
		else {
			flagW = 0;
		}

	}


	body.move(sf::Vector2f(hspd, vspd));
}

void Jogador::BasicAtk(){

	if (KeyBasicAtk()){
		state = Atk;
		Ataque* corte = new Ataque(40,100,get_body().getPosition().x,get_body().getPosition().y - 30, 40.f, dir, 20.f, 7.f);
		corte->set_Window(window);
		listPlayerAtaque->push_back(corte);

		vspd = 0;

		cooldown = 30;
	}
}

std::list<Ataque*>* Jogador::getListAtk()
{
	return listPlayerAtaque;
}
