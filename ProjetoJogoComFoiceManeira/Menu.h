#pragma once
#include "Button.h"
#include "Key.h"
#include "Jogo.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Jogo;
class Button;

class Menu {
private:
	int continua;
	int buttonSelected;
	sf::RenderWindow* window;
	std::vector<Button*> botoes;

	int flagButtonPressed;

	Jogo* jogo;

public:
	Menu(Jogo* jg);
	~Menu();
	void set_Window(sf::RenderWindow* window);
	void move();
	void atualiza();
};