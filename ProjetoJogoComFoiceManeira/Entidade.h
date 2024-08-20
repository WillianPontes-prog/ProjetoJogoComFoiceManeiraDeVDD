#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Lista.h"

constexpr double PI = 3.14159265358979323846;

class Entidade {

protected:
	
	sf::RenderWindow *window;

public:
	sf::RectangleShape body;

	Entidade(float dimX = 100.f, float dimY = 100.f, float posX = 0, float posY = 0);
	~Entidade();

	void set_Window(sf::RenderWindow* w) {this->window = w; };
	
	virtual void atualiza() = 0;
	sf::RectangleShape get_body() { return body; }
	sf::Vector2f middleCenter();

	

};