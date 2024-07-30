#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalVars.h"

/*
int CollisionH(sf::RectangleShape body, sf::RectangleShape collider);

int CollisionV(sf::RectangleShape body, sf::RectangleShape collider);

int CollisionH(float x_, float y_, sf::RectangleShape collider);

int CollisionV(float x_, float y_, sf::RectangleShape collider);

int CollisionVH(sf::RectangleShape body, sf::RectangleShape collider);
*/

int MinimalNumber(float valor);

int CheckCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2);
