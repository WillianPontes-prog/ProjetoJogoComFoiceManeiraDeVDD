#pragma once

#include "Fase.h"

class Fase;

class EntityGenerator
{
private:
	Jogador* createPlayer		(float posX = 0.f, float posY = 0.f);
	Inimigo* createEnemy		(float posX = 0.f, float posY = 0.f);
	Plataforma* createPlatform	(float posX = 0.f, float posY = 0.f);

	Fase* fase;

public:
	EntityGenerator(Fase* _fase = nullptr);
	~EntityGenerator();

	void setFase(Fase* fase) { this->fase = fase; };
	void execute(float posX = 0, float posY = 0, int n = 0);

};

