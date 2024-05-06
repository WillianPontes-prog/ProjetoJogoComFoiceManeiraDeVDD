#pragma once

#include <SFML/Graphics.hpp>

class Entidade {

protected:
	sf::RectangleShape body;
	sf::RenderWindow *window;

public:
	Entidade();
	~Entidade();

	void set_Window(sf::RenderWindow* w) {this->window = w; };
	void draw() { window->draw(body); }
	virtual void atualiza() { draw(); }

};