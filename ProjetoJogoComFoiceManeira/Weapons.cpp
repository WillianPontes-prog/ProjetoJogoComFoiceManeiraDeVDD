#include "Weapons.h"

Weapons::Weapons(float tam_x, float tam_y,  float veloc, float dir, float dan, float temp,float id, float espec, float cd)
{
	tam_X = tam_x;
	tam_Y = tam_y;
	velocidade = veloc;
	direc = dir;
	dano = dan;
	especial = espec;
	Id = id;
	tempo = temp;
	this->cd = cd;
}

Weapons::~Weapons()
{
}
