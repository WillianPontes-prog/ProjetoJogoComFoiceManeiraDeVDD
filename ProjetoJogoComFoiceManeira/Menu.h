#pragma once
#include "Button.h"
#include "Keys.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Menu {
private:
	int continua;
	int buttonSelected;
	sf::RenderWindow* window;
	std::vector<Button*> botoes;

	int flagButtonPressed;
public:
	Menu();
	~Menu();
	void set_Window(sf::RenderWindow* window);
	void move();
	void atualiza();
};