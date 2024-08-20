#pragma once
#include"Entidade.h"
#include <cmath>
class Projetil : public Entidade {
private:
	float velocidade, direc, dano;

	int tempoDeDestruicao;
	

public:
	Projetil(float dimX = 100.f, float dimY = 100.f, float posX = 0, float posY = 0, float vel = 0, float dir = 0, float dan = 0, float tempATK = INT_MAX);
	~Projetil();
	void Move();
	void atualiza();
	
	int OverTime();

};