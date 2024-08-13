#pragma once
#include "EntidadesColision.h"
#include "FIsica.h"
#include "Ataque.h"
#include "Key.h"
#include "Weapons.h"
#include "Barra.h"

class Jogador : public EntidadesColision {
private:

	
	int maxVida = 5;
	int vida = maxVida;

	std::list<Ataque*>* listPlayerAtaque;
	Weapons* armas[3];

	enum palyerState {
		Stand,
		Atk
	};

	int armatual;
	int state = Stand;

	float speedP = 7;

	float jump = 10;

	int flagJump = 0;
	int flagWeapon = 0;	

	int coyteTime = 0;
	int MAXcoyteTime = 5;

	int cooldown = 0;

	/*
	Barra* vida;
	Barra* mana;
	//Barra stamina;
	//*/

public:
	Jogador(float dimensionX = 100.f, float dimensionY = 100.f, float posX = 0, float posY = 0, std::list<Plataforma*>* listPlat = nullptr);
	~Jogador();

	sf::Vector2f MidleButton() {
		sf::Vector2f rtn;
		rtn.x = body.getPosition().x + (body.getSize().x / 2);
		rtn.y = body.getPosition().y + body.getSize().y;
		return rtn;
	}

	void Move();

	void BasicAtk();

	void ChangeWeapon();

	std::list<Ataque*>* getListAtk();

	void atualiza() override;

	int get_vida() { return vida; }
	int get_maxVida() { return maxVida; }

};