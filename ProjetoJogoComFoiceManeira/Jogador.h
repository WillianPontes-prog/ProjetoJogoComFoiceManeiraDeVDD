#pragma once
#include "EntidadesColision.h"
#include "FIsica.h"

class Jogador : public EntidadesColision {
private:
	float speedP = 6;

	float hspd = 0;
	float vspd = 0;

public:
	Jogador(float dimensionX = 100.f, float dimensionY = 100.f);
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