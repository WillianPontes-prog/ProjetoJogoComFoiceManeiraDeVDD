#include "Jogador.h"

Jogador::Jogador(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat) :
	EntidadesColision(dimensionX, dimensionY, posX, posY, listPlat)
{
	listPlayerAtaque = new std::list<Ataque*>();
	//(int dano, int alcance, float velocidade, float dir, float x, float y, float cd)//
	armas[0] = new Weapons(40, 100, 40.f, dir, 20.f, 5.f, 60.f);
	armas[1] = new Weapons(10, 10, 5.f, dir, 10.f, 200.f, 15.f);
	armas[2] = new Weapons(100, 20, 3, dir, 50.f, 6.f, 40.f);
	armatual = 2;	
}

Jogador::~Jogador()
{
}

void Jogador::ChangeWeapon()
{
	if (Key::ChangeWeapon()) {
		if (flagWeapon) {
			armatual++;
			if (armatual > 2) {
				armatual = 0;
			}
			flagWeapon = 0;	
		}
	}
	else
		flagWeapon = 1;
}

void Jogador::atualiza()
{
	switch (state)
	{
	case Stand: {
		Move();
		BasicAtk();
		ChangeWeapon();
	}
		break;

	case Atk: {
		Move();
		ChangeWeapon();

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
			delete* it;							// Liberar memória
			it = listPlayerAtaque->erase(it);	// Remover elemento e atualizar iterador
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
	if (Key::Left()) {
		hspd = -speedP;
		dir = PI;
	}
	//movimentação Direita
	else if (Key::Right()) {
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
			if (Key::Jump()) {
				vspd = -jump;
			}
		}
		else if (flagJump) {
			if (Key::Jump() && !flagW) {
				vspd = -jump;
				flagJump = 0;
			}
		}

		if (Key::Jump()) {
			flagW = 1;
		}
		else {
			flagW = 0;
		}

		
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
		bodyTemp.move(sf::Vector2f(hspd, vspd));

		if (CheckCollision(bodyTemp, (*it)->get_body())) {
			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(hspd, MinimalNumber(vspd)));

			while (!CheckCollision(bodyTemp, (*it)->get_body())) {
				body.move(sf::Vector2f(0, MinimalNumber(vspd)));

				bodyTemp = body;
				bodyTemp.move(sf::Vector2f(hspd, MinimalNumber(vspd)));
			}

			vspd = 0;
		}

	}


	body.move(sf::Vector2f(hspd, vspd));
}

void Jogador::BasicAtk(){

	if (Key::BasicAtk()){
		state = Atk;
		Ataque* corte = armas[armatual]->atack(middleCenter().x, middleCenter().y, dir);
		corte->set_Window(window);
		listPlayerAtaque->push_back(corte);

		cooldown = armas[armatual]->getCD();
	}
}

std::list<Ataque*>* Jogador::getListAtk()
{
	return listPlayerAtaque;
}
