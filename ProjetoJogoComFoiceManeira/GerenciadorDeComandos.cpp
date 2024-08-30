#include "GerenciadorDeComandos.h"

void GerenciadorDeComandos::adicionarObserver(Observer* observer) {
    observers.push_back(observer);
}

void GerenciadorDeComandos::removerObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GerenciadorDeComandos::processarEvento() {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        notificar(sf::Keyboard::W);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        notificar(sf::Keyboard::A);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        notificar(sf::Keyboard::S);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        notificar(sf::Keyboard::D);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        notificar(sf::Keyboard::F);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		notificar(sf::Keyboard::Z);
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        notificar(sf::Keyboard::Up);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		notificar(sf::Keyboard::Down);
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    	notificar(sf::Keyboard::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        notificar(sf::Keyboard::Right);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        notificar(sf::Keyboard::M);
    }
    
}

void GerenciadorDeComandos::notificar(int tecla) {
    for (Observer* observer : observers) {
        observer->onNotify(tecla);
    }
}
