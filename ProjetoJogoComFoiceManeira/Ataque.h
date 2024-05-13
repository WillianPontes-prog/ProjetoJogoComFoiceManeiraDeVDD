#pragma once
#include"Entidade.h"
class Ataque : protected Entidade{
private:
	float tamanho, velocidade, direção, dano;
public :
	Ataque();
	~Ataque();


}