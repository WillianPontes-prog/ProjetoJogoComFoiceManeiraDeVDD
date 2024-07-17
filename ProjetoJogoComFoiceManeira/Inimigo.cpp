#include "Inimigo.h"

Inimigo::Inimigo(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat, std::list<Jogador*>* listJogador) :
	EntidadesColision(dimensionX, dimensionY, posX, posY, listPlat)
{
	body.setFillColor(sf::Color::Cyan);
	body.setPosition(sf::Vector2f(posX, posY));

	listInimigoAtaque = new std::list<Ataque*>();
	armas[0] = new Weapons(40, 100, 40.f, dir, 20.f, 7.f, 18.f);

	set_listPlat(listPlat);
	set_listJogador(listJogador);
}

Inimigo::~Inimigo()
{
}

void Inimigo::move()
{
	vspd += GRAVIDADE;
	


	for (std::list<Plataforma*>::iterator it = listPlat->begin(); it != listPlat->end(); ++it) {
		
		sf::RectangleShape bodyTemp = body;

		int found = search();

		if (abs(found) < 300) {
			if (abs(searchX()) > 5) {
				if (found < 0) {
					hspd = speed;
					dir = 0;
				}
				else {
					hspd = -speed;
					dir = PI;
				}
			}

			bodyTemp.move(sf::Vector2f(hspd + (body.getSize().x * (abs(hspd)/hspd)), 1));
			if (!CheckCollision(bodyTemp, (*it)->get_body())) {
				hspd = 0;
			}
		}
		else {

			bodyTemp.move(sf::Vector2f(hspd + (body.getSize().x * (abs(hspd) / hspd)), 1));

			if (!CheckCollision(bodyTemp, (*it)->get_body())) {

				if (hspd <= 0) {
					hspd = speed;
					dir = 0;
				}
				else if (hspd > 0) {
					hspd = -speed;
					dir = PI;
				}
	
			}
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

	}


	body.move(sf::Vector2f(hspd, vspd));
}

void Inimigo::atk()
{
	state = Atk;

	Ataque* hit = armas[0]->atack(get_body().getPosition().x, get_body().getPosition().y, dir);
	hit->set_Window(window);
	listInimigoAtaque->push_back(hit);	

	vspd = 0;

	cooldown = armas[0]->getCD();
}

int Inimigo::search()
{
	int minorDistance = 999999;

	for (std::list<Jogador*>::iterator it = listJogador->begin(); it != listJogador->end(); ++it) {
		
		int distance = std::hypot(body.getPosition().x - (*it)->get_body().getPosition().x, body.getPosition().y - (*it)->get_body().getPosition().y);
		if (distance < abs(minorDistance)) {
			
			if (body.getPosition().x - (*it)->get_body().getPosition().x > 0) {
				minorDistance = distance;
			}
			else {
				minorDistance = -distance;
			}
		}
	}

	return minorDistance;
}

int Inimigo::searchX()
{
	int minorDistance = 999999;

	for (std::list<Jogador*>::iterator it = listJogador->begin(); it != listJogador->end(); ++it) {

		int distance = body.getPosition().x - (*it)->get_body().getPosition().x;
		if (distance < abs(minorDistance)) {
			minorDistance = distance;
		}
	}

	return minorDistance;
}

int Inimigo::searchY()
{
	int minorDistance = 999999;

	for (std::list<Jogador*>::iterator it = listJogador->begin(); it != listJogador->end(); ++it) {

		int distance = body.getPosition().y - (*it)->get_body().getPosition().y;
		if (distance < abs(minorDistance)) {
			minorDistance = distance;
		}
	}

	return minorDistance;
}

void Inimigo::atualiza()
{
	switch (state)
	{
	case Stand: {
		int found = search();

		if (abs(found) < 80) {
			atk();
		}
		else {
			move();
		}
	}
	break;
	case Atk:{

		move();

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

	for (auto it = listInimigoAtaque->begin(); it != listInimigoAtaque->end();) {
		if ((*it)->OverTime()) {
			delete* it; // Liberar memória
			it = listInimigoAtaque->erase(it); // Remover elemento e atualizar iterador
		}
		else {
			(*it)->atualiza();
			++it;
		}
	}
	

	draw();
}

void Inimigo::set_listJogador(std::list<Jogador*>* listJogador)
{
	this->listJogador = listJogador;
}


