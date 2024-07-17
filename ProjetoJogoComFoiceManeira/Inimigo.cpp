#include "Inimigo.h"

Inimigo::Inimigo(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat, std::list<Jogador*>* listJogador) :
	EntidadesColision(dimensionX, dimensionY, posX, posY, listPlat)
{
	body.setFillColor(sf::Color::Cyan);
	body.setPosition(sf::Vector2f(posX, posY));

	listInimigoAtaque = new std::list<Ataque*>();
	armas[0] = new Weapons(40, 100, 40.f, dir, 20.f, 7.f);

	set_listPlat(listPlat);
	set_listJogador(listJogador);
}

Inimigo::~Inimigo()
{
}

void Inimigo::move()
{
	vspd += GRAVIDADE;
	
	if(dir == 0)
		hspd = speed;
	else if(dir == PI)
		hspd = -speed;


	for (std::list<Plataforma*>::iterator it = listPlat->begin(); it != listPlat->end(); ++it) {
		
		sf::RectangleShape bodyTemp = body;

		
		bodyTemp.move(sf::Vector2f(hspd, 1));

		if (!CheckCollision(bodyTemp, (*it)->get_body())) {
			if (hspd <= 0) {
				dir = 0;
			}
			else if (hspd > 0) {
				dir = PI;
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

	cooldown = 30;
}

int Inimigo::search()
{
	int minorDistance = 999999.f;
	double minorDistance = std::numeric_limits<double>::max(); 

	for (std::list<Jogador*>::iterator it = listJogador->begin(); it != listJogador->end(); ++it) {
		double distance = std::hypot(body.getPosition().x - (*it)->get_body().getPosition().x, body.getPosition().y - (*it)->get_body().getPosition().y);

		if (distance < minorDistance) {
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

		if (abs(found) < 300) {
			if (found < 0) {
				
				dir = 0;
			}
			else {
				dir = PI;
			}
		}
			


		if (abs(found) < 80) {
			atk();
		}
		else {
			move();
		}
	}
	break;
	case Atk:{
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


