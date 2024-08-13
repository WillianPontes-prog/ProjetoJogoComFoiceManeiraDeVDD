#include "Tecla.h"

int Tecla::isPJump = 0;

int Tecla::Left()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
int Tecla::Right()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
int Tecla::Down()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
int Tecla::Up()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int Tecla::Click()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }

int Tecla::Jump()			{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isPJump)
	{
		isPJump = 1;
		return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		isPJump = 0;
	}

	return 0;
}



int Tecla::BasicAtk()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
int Tecla::SpecialAtk()	{ return sf::Keyboard::isKeyPressed(sf::Keyboard::X); }
int Tecla::ChangeWeapon() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Tab); }
