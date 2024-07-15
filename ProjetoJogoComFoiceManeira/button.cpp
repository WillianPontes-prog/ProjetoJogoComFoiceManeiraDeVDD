#include "Button.h"

Button::Button(sf::RenderWindow* w ,float x, float y, float width, float height, std::string text, buttonType _type, Jogo* jg)
{
	body.setPosition(x, y);
	body.setSize(sf::Vector2f(width, height));
	set_Color(sf::Color::White);

	font.loadFromFile("PIXEAB.TTF");
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(x + width / 2 - this->text.getGlobalBounds().width / 2, y + height / 2 - this->text.getGlobalBounds().height / 2);
	set_Window(w);
	pressed = 0;

	this->type = _type;

	jogo = jg;

}

Button::~Button()
{
}

void Button::draw()
{
	window->draw(body);
	window->draw(text);

}

void Button::set_Color(sf::Color color)
{
	body.setFillColor(color);
}

void Button::set_Window(sf::RenderWindow* w)
{
	window = w;
}

void Button::set_Pressed(bool test)
{	
	if(test)
		pressed = 1;
	else	
		pressed = 0;
}

void Button::execute()
{
	switch (type)
	{
	case Button::NewGame: {
		jogo->setGameState(Jogo::InGame);
	}
		break;
	case Button::LoadGame: {

	}
		break;
	case Button::Save: {

	}
		break;
	case Button::Exit: {

	}
		break;
	default: {

	}
		break;
	}
}

void Button::atualiza()
{
	if (pressed)
	{
		set_Color(sf::Color::Green);
	}
	else
	{
		set_Color(sf::Color::White);
	}
	draw();
}
