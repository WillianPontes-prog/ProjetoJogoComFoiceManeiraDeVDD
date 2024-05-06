#pragma once
#include "Entidade.h"

class Jogador : public Entidade {
private:
	float speedP = 3;

public:
	Jogador();
	~Jogador();

	void Move();

	void atualiza() override;

};