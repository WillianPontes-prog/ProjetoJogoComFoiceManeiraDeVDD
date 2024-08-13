#pragma once
#include"Entidade.h"
#include <cmath>
class Ataque : public Entidade {
private:
	float velocidade, direc, dano;

	int tempoDeDestruicao;
	

public:
	Ataque(float dimX = 100.f, float dimY = 100.f, float posX = 0, float posY = 0, float vel = 0, float dir = 0, float dan = 0, float tempATK = INT_MAX);
	~Ataque();
	void Move();
	void atualiza();
	
	int OverTime();

};