#pragma once
#include <SFML/Graphics.hpp>

int CollisionH(sf::RectangleShape body, sf::RectangleShape collider);

int CollisionV(sf::RectangleShape body, sf::RectangleShape collider);

int CollisionVH(sf::RectangleShape body, sf::RectangleShape collider);