#include "Menu.h"

Menu::Menu():
	window(NULL)
{
	continua = 0;
	buttonSelected = 0;
	
}

Menu::~Menu()
{
}

void Menu::set_Window(sf::RenderWindow* window)
{
	this->window = window;
}

void Menu::move()
{
	if (KeyUp()) {
		if (buttonSelected > botoes.size() - 1) {
			buttonSelected = 0;
		}
		else {
			buttonSelected++;
		}
	}
	if (keyDown()) {
		if (buttonSelected < 0) {
			buttonSelected = botoes.size() - 1;
		}
		else {
			buttonSelected--;
		}
	}
}

void Menu::atualiza()
{
	move();
	for (int i = 0; i < botoes.size(); i++)
	{
		if (i == buttonSelected)
		{
			botoes[i]->set_Pressed(true);
		}
		else
		{
			botoes[i]->set_Pressed(false);
		}
			botoes[i]->atualiza();
	}
	
	
}
