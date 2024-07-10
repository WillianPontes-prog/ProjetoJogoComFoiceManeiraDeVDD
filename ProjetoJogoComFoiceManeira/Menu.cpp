#include "Menu.h"

Menu::Menu():
	window(NULL)
{
	continua = 0;
}

Menu::~Menu()
{
}

void Menu::set_Window(sf::RenderWindow* window)
{
	this->window = window;
}

void Menu::atualiza()
{
	
}
