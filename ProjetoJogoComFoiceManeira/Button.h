#pragma once
#include <SFML/Graphics.hpp>
#include "Jogo.h"

class Jogo;

class Button {

public:
	enum buttonType {
		NewGame,
		LoadGame,
		Save,
		Exit,
	};

private:
	sf::RectangleShape body;
	sf::Text text;
	sf::Font font;
	sf::RenderWindow* window;
	int pressed;
	Jogo* jogo;

	buttonType type;

public:

	Button(sf::RenderWindow* w, float x = 0, float y = 0.0, float width = 0.0, float height = 0.0, std::string text = "", buttonType _type = Exit, Jogo* jg = nullptr);
	~Button();

	void draw();
	void set_Color(sf::Color color);
	void set_Window(sf::RenderWindow* window);
	void set_Pressed( bool test);
	virtual void execute();
	void atualiza();


	
};