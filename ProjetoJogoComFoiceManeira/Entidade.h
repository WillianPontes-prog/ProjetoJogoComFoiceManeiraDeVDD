#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

constexpr double PI = 3.14159265358979323846;

class Entidade {

protected:
	sf::RectangleShape body;
	sf::RenderWindow *window;

public:
	Entidade(float dimX = 100.f, float dimY = 100.f, float posX = 0, float posY = 0);
	~Entidade();

	void set_Window(sf::RenderWindow* w) {this->window = w; };
	
	virtual void atualiza() = 0;
	sf::RectangleShape get_body() { return body; }
	sf::Vector2f middleCenter();

};