#pragma once
#include "EntidadesColision.h"
#include "FIsica.h"

class Jogador : public EntidadesColision {
private:
	float speedP = 10;

	float jump = 16;

	float hspd = 0;
	float vspd = 0;

	int flagJump = 0;

	int flagW = 0;

	int coyteTime = 0;
	int MAXcoyteTime = 10;

public:
	Jogador(float dimensionX = 100.f, float dimensionY = 100.f, std::list<Plataforma*>* listPlat = nullptr);
	~Jogador();

	sf::Vector2f MidleButton() {
		sf::Vector2f rtn;
		rtn.x = body.getPosition().x + (body.getSize().x / 2);
		rtn.y = body.getPosition().y + body.getSize().y;
		return rtn;
	}

	void Move();

	void atualiza() override;

};