#pragma once
#include"Obstaculo.h"

class Obstaculo1 :public Obstaculo {
private:
	int dano;
	int desacelera;
public:
	Obstaculo1(float posX, float posY, int dano, int desacelera);
	void atualiza();
	int get_dano();
	int get_desacelera();

};