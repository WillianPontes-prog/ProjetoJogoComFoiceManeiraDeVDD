#pragma once
#include<iostream>
#include "Entidade.h"

class Barra : public Entidade {
private:
	float maxima;
	float atual;
	bool automatico; // define se cura automaticamente a barra;
	bool parado; // define se a barra automatica deve curar ou nao

public:
	Barra(bool autom = false,float posX = 0, float posY = 0, float max = 100.f, float at = 100.f);
	~Barra();

	void set_maxima(float max) { this->maxima = max; }
	bool dano(float at);
	void cura(float at) { atual += at; if (atual > maxima) atual = maxima; }
	void set_pos(float x, float y) { body.setPosition(sf::Vector2f(x, y)); }
	void set_dimension(float x, float y) { body.setSize(sf::Vector2f(x, y)); }

	void atualiza() override;
	
	


};