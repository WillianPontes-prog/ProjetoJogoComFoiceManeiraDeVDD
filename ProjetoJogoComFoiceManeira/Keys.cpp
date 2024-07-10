#include "Keys.h"

int KeyLeft()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
int KeyRight()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
int KeyJump()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int keyDown()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
int KeyUp()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }

int KeyBasicAtk()	{ return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
int KeySpecialAtk() { return sf::Keyboard::isKeyPressed(sf::Keyboard::X); }