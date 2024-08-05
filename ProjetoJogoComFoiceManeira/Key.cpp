#include "Key.h"

int Key::Left()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
int Key::Right()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
int Key::Down()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
int Key::Up()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int Key::Click()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }

int Key::Jump()			{ return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int Key::BasicAtk()		{ return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
int Key::SpecialAtk()	{ return sf::Keyboard::isKeyPressed(sf::Keyboard::X); }
int Key::ChangeWeapon() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Tab); }
