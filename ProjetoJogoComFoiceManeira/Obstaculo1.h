#pragma once
#include"Obstaculo.h"

class Obstaculo1 :public Obstaculo {
private:
	int dano;
	
public:
	Obstaculo1(float posX, float posY, int dano) : Obstaculo(posX, posY), dano(dano) {};
	~Obstaculo1() {};

	void atualiza();


};