#pragma once
#include "EntidadesColision.h"
#include "FIsica.h"
#include "Ataque.h"
#include "Keys.h"
#include "Weapons.h"

class Jogador : public EntidadesColision {
private:

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

	int flagW = 0;

	int coyteTime = 0;
	int MAXcoyteTime = 5;

	int cooldown = 0;

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



};