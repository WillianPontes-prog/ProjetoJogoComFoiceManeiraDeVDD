#pragma once

#include <SFML/Graphics.hpp>

class Entidade {

protected:
	sf::RectangleShape body;
	sf::RenderWindow *window;

public:
	Entidade(float dimensionX = 100.f, float dimensionY = 100.f);
	~Entidade();

	void set_Window(sf::RenderWindow* w) {this->window = w; };
	void draw() { window->draw(body); }
	virtual void atualiza() { draw(); }
	sf::RectangleShape get_body() { return body; }

};