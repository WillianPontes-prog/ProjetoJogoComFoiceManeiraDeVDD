#include "Fisica.h"

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

int CollisionVH(sf::RectangleShape body, sf::RectangleShape collider)
{
	if (CollisionH(body, collider) && CollisionH(body, collider)) {
		return 1;
	}

	return 0;
}
