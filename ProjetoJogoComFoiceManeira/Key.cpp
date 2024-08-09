#include "Key.h"

int Key::isPJump = 0;

int Key::Left()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
int Key::Right()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
int Key::Down()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
int Key::Up()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int Key::Click()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }

int Key::Jump()			{
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



int Key::BasicAtk()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
int Key::SpecialAtk()	{ return sf::Keyboard::isKeyPressed(sf::Keyboard::X); }
int Key::ChangeWeapon() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Tab); }
