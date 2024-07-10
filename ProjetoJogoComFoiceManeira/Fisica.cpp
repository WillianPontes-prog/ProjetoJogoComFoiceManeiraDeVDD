#include "Fisica.h"

/*
int CollisionH(sf::RectangleShape body, sf::RectangleShape collider) {
	
	//colisão horizontal
	if ((body.getPosition().y >= collider.getPosition().y) && (body.getPosition().y <= collider.getPosition().y + collider.getSize().y) ||
		(body.getPosition().y + body.getSize().y >= collider.getPosition().y) && (body.getPosition().y + body.getSize().y <= collider.getPosition().y + collider.getSize().y)) {
		if (body.getPosition().x + body.getSize().x >= collider.getPosition().x &&
			body.getPosition().x <= collider.getPosition().x + collider.getSize().x) {

			return 1;
		}
	}

	return 0;
}

int CollisionH(float x_, float y_, sf::RectangleShape collider) {

	//colisão horizontal
	if ((y_ >= collider.getPosition().y) && (y_ <= collider.getPosition().y + collider.getSize().y)){
		if (x_ >= collider.getPosition().x &&
			x_ <= collider.getPosition().x + collider.getSize().x) {

			return 1;
		}
	}

	return 0;
}

int CollisionV(sf::RectangleShape body, sf::RectangleShape collider) {
	
	//colisao vertical
	if ((body.getPosition().x >= collider.getPosition().x) && (body.getPosition().x <= collider.getPosition().x + collider.getSize().x) ||
		(body.getPosition().x + body.getSize().x >= collider.getPosition().x) && (body.getPosition().x + body.getSize().x <= collider.getPosition().x + collider.getSize().x)) {
		if (body.getPosition().y + body.getSize().y >= collider.getPosition().y &&
			body.getPosition().y <= collider.getPosition().y + collider.getSize().y) {

			return 1;
		}
	}

	return 0;
}

int CollisionV(float x_, float y_, sf::RectangleShape collider) {

	//colisão horizontal
	if ((x_ >= collider.getPosition().x) && (x_ <= collider.getPosition().x + collider.getSize().x)) {
		if (y_ >= collider.getPosition().y &&
			y_ <= collider.getPosition().y + collider.getSize().y) {

			return 1;
		}
	}

	return 0;
}

int CollisionVH(sf::RectangleShape body, sf::RectangleShape collider)
{
	if (CollisionH(body, collider) && CollisionH(body, collider)) {
		return 1;
	}

	return 0;
}
*/

int MinimalNumber(float valor)
{
	if (valor == 0) { return 0; } 
	else { return (valor / abs(valor)); }
}


int CheckCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2) {
	sf::FloatRect bounds1 = rect1.getGlobalBounds();
	sf::FloatRect bounds2 = rect2.getGlobalBounds();
	return bounds1.intersects(bounds2);
}
