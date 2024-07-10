#pragma once
#include <SFML/Graphics.hpp>

class Menu {
private:
	int continua;
	sf::RenderWindow* window;

public:
	Menu();
	~Menu();
	void set_Window(sf::RenderWindow* window);
	void atualiza();
};