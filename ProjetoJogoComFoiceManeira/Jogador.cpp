#include "Jogador.h"

Jogador::Jogador(float dimensionX, float dimensionY, float posX, float posY) :
	EntidadeColisao(dimensionX, dimensionY, posX, posY),
	listaJogadorAtaque(nullptr)
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


	if (noChao) {
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

}

void Jogador::AtkBasico(){

	if (Tecla::BasicAtk()){
		state = Atk;
		Ataque* corte = armas[armatual]->atack(middleCenter().x, middleCenter().y, dir);
		
		listaJogadorAtaque->adicionarElemento(corte);

		cooldown = armas[armatual]->getCD();
	}
}