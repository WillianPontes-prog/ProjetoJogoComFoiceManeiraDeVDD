#include "Inimigo.h"

Inimigo::Inimigo(float dimensionX, float dimensionY, float posX, float posY, Lista<Plataforma*>* listPlat, Lista<Jogador*>* listJogador) :
	EntidadeColisao(dimensionX, dimensionY, posX, posY, listPlat)
{
	body.setFillColor(sf::Color::Cyan);
	body.setPosition(sf::Vector2f(posX, posY));

	armas[0] = new Arma(40, 100, 40.f, dir, 20.f, 7.f, 18.f);

	set_listPlat(listPlat);
	set_listaJogador(listJogador);
}

Inimigo::~Inimigo()
{
	delete armas[0];
}

void Inimigo::move()
{
	vspd += GRAVIDADE;
	
	int found = procurarJogador();

	sf::RectangleShape bodyTemp = body;

	if (abs(found) < 300) {

		int zerarHspd = 1;

		for (Lista<Plataforma*>::iterator it = listPlat->begin(); it != listPlat->end(); ++it) {

			bodyTemp = body;

			if (abs(procurarJogadorX()) > 5) {
				if (found < 0) {
					hspd = velocidade;
					dir = 0;
				}
				else {
					hspd = -velocidade;
					dir = PI;
				}
			}

			bodyTemp.move(sf::Vector2f(hspd + (body.getSize().x * (abs(hspd) / hspd)), 1));
			if (ChecarColisao(bodyTemp, (*it)->get_body())) {
				zerarHspd = 0;
			}
		}

		if(zerarHspd) {
			hspd = 0;
		}
	}
	else {

		int invert = 0;
		bodyTemp = body;

		auto bodyTempX = body;

		bodyTemp.move(sf::Vector2f(hspd + (body.getSize().x * (abs(hspd) / hspd)), 2));
		bodyTempX.move(sf::Vector2f(hspd + (body.getSize().x * (abs(hspd) / hspd)), 0));

		for (Lista<Plataforma*>::iterator it = listPlat->begin(); it != listPlat->end(); ++it) {
			
			if (!ChecarColisao(bodyTemp, (*it)->get_body())) {
				invert = 1;
			}
			else if (!ChecarColisao(bodyTempX, (*it)->get_body()) ){
				invert = 0;
				break;
			}
		}

		if (invert) {
			if (hspd <= 0) {
				hspd = velocidade;
				dir = 0;
			}
			else if (hspd > 0) {
				hspd = -velocidade;
				dir = PI;
			}
		}
	}

	for (Lista<Plataforma*>::iterator it = listPlat->begin(); it != listPlat->end(); ++it) {
		
		bodyTemp = body;

		


		bodyTemp = body;
		bodyTemp.move(sf::Vector2f(hspd, 0));

		if (ChecarColisao(bodyTemp, (*it)->get_body())) {
			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(NumeroMinimo(hspd), 0));

			while (!ChecarColisao(bodyTemp, (*it)->get_body())) {
				body.move(sf::Vector2f(NumeroMinimo(hspd), 0));

				bodyTemp = body;
				bodyTemp.move(sf::Vector2f(NumeroMinimo(hspd), 0));
			}

			hspd = 0;
		}

		bodyTemp = body;
		bodyTemp.move(sf::Vector2f(0, vspd));

		if (ChecarColisao(bodyTemp, (*it)->get_body())) {
			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(0, NumeroMinimo(vspd)));

			while (!ChecarColisao(bodyTemp, (*it)->get_body())) {
				body.move(sf::Vector2f(0, NumeroMinimo(vspd)));

				bodyTemp = body;
				bodyTemp.move(sf::Vector2f(0, NumeroMinimo(vspd)));
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
	listInimigoAtaque->adicionarElemento(hit);	

	vspd = 0;

	cooldown = armas[0]->getCD();
}

int Inimigo::procurarJogador()
{
	int minorDistance = 999999;

	for (Lista<Jogador*>::iterator it = listaJogador->begin(); it != listaJogador->end(); ++it) {
		
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

int Inimigo::procurarJogadorX()
{
	int minorDistance = 999999;

	for (Lista<Jogador*>::iterator it = listaJogador->begin(); it != listaJogador->end(); ++it) {

		int distance = body.getPosition().x - (*it)->get_body().getPosition().x;
		if (distance < abs(minorDistance)) {
			minorDistance = distance;
		}
	}

	return minorDistance;
}

int Inimigo::tempoDeDestruicaoY()
{
	int minorDistance = 999999;

	for (Lista<Jogador*>::iterator it = listaJogador->begin(); it != listaJogador->end(); ++it) {

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
	case Normal: {
		int found = procurarJogador();

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
			state = Normal;
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
	
}

void Inimigo::set_listaJogador(Lista<Jogador*>* listJogador)
{
	this->listaJogador = listJogador;
}

void Inimigo::set_listaAtaque(Lista<Ataque*>* listAtaque)
{
	this->listInimigoAtaque = listAtaque;
}


