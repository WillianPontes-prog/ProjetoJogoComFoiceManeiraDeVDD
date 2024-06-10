#pragma once
#include"Entidade.h"
#include <cmath>
class Ataque : public Entidade {
private:
	float velocidade, direc, dano;
	

public:
	Ataque(float dimensionX = 100.f, float dimensionY = 100.f, float posX = 0, float posY = 0, float vel = 0, float dir = 0, float dan = 0);
	~Ataque();
	void Move();
	void Atualiza();
	

};