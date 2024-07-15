#include "Menu.h"

Menu::Menu():
	window(NULL)
{
	continua = 0;
	buttonSelected = 0;
	
	botoes.push_back(new Button(window, 100, 100, 200, 50, "Continua"));
	botoes.push_back(new Button(window, 100, 300, 200, 50, "Novo Jogo"));
	botoes.push_back(new Button(window, 100, 500, 200, 50, "Sair"));

	flagButtonPressed = 0;

}

Menu::~Menu()
{
}

void Menu::set_Window(sf::RenderWindow* window)
{
	this->window = window;

	for(int i = 0; i < botoes.size(); i++)
	{
		botoes[i]->set_Window(window);
	}
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

void Menu::move()
{
	if (!flagButtonPressed) {

		if (keyDown()) {
			if (buttonSelected > botoes.size() - 1) {
				buttonSelected = 0;
			}
			else {
				buttonSelected++;
			}

			flagButtonPressed = 1;
		}
		if (KeyUp()) {
			if (buttonSelected < 0) {
				buttonSelected = botoes.size() - 1;
			}
			else {
				buttonSelected--;
			}

			flagButtonPressed = 1;
		}
		
	}

	if(!KeyUp() && !keyDown())
	{
		flagButtonPressed = 0;
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
