#include "Jogador.h"

Jogador::Jogador(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat) :
	EntidadeColisao(dimensionX, dimensionY, posX, posY, listPlat)
	/*
	vida(new Barra(0,0, 0)),
	mana(new Barra(0, 0, 10))
	//*/
	
	
{
	
	//(int dano, int alcance, float velocidade, float dir, float x, float y, float cd)//
	armas[0] = new Arma(40, 100, 40.f, dir, 20.f, 5.f, 60.f);
	armas[1] = new Arma(10, 10, 5.f, dir, 10.f, 200.f, 15.f);
	armas[2] = new Arma(100, 20, 3, dir, 50.f, 6.f, 40.f);
	armatual = 1;

	//stamina.set_Window(window);
}

Jogador::~Jogador()
{
}

void Jogador::TrocarArma()
{
	if (Tecla::ChangeWeapon()) {
		if (flagArma) {
			armatual++;
			if (armatual > 2) {
				armatual = 0;
			}
			flagArma = 0;	
		}
	}
	else
		flagArma = 1;
}

void Jogador::atualiza()
{
	switch (state)
	{
	case Normal: {
		Move();
		AtkBasico();
		TrocarArma();
	}
		break;

	case Atk: {
		Move();
		TrocarArma();

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

	for (auto it = listaJogadorAtaque->begin(); it != listaJogadorAtaque->end();) {
		if ((*it)->OverTime()) {
			delete* it;							// Liberar memória
			it = listaJogadorAtaque->erase(it);	// Remover elemento e atualizar iterador
		}
		else {
			(*it)->atualiza();
			++it;
		}
	}

	//draw();

}

void Jogador::Move()
{

	//movimentação Esquerda
	if (Tecla::Left()) {
		hspd = -velocidadeP;
		dir = PI;
	}
	//movimentação Direita
	else if (Tecla::Right()) {
		hspd = velocidadeP;
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


		if (ChecarColisao(bodyTemp, (*it)->get_body())) {
			coyteTime = MAXcoyteTime;
		}
		else if (coyteTime > 0) {
			coyteTime--;
		}

		if (coyteTime) {
			//pulo
			flagPulo = 1;
			if (Tecla::Jump()) {
				vspd = -pulo;
			}
		}
		else if (flagPulo) {
			if (Tecla::Jump()) {
				vspd = -pulo;
				flagPulo = 0;
			}
		}



		
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
		bodyTemp.move(sf::Vector2f(hspd, vspd));

		if (ChecarColisao(bodyTemp, (*it)->get_body())) {
			bodyTemp = body;
			bodyTemp.move(sf::Vector2f(hspd, NumeroMinimo(vspd)));

			while (!ChecarColisao(bodyTemp, (*it)->get_body())) {
				body.move(sf::Vector2f(0, NumeroMinimo(vspd)));

				bodyTemp = body;
				bodyTemp.move(sf::Vector2f(hspd, NumeroMinimo(vspd)));
			}

			vspd = 0;
		}

	}


	body.move(sf::Vector2f(hspd, vspd));
}

void Jogador::AtkBasico(){

	if (Tecla::BasicAtk()){
		state = Atk;
		Ataque* corte = armas[armatual]->atack(middleCenter().x, middleCenter().y, dir);
		corte->set_Window(window);
		listaJogadorAtaque->push_back(corte);

		cooldown = armas[armatual]->getCD();
	}
}

std::list<Ataque*>* Jogador::getListaAtk()
{
	return listaJogadorAtaque;
}
