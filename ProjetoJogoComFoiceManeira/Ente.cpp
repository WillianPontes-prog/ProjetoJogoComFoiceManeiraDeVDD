#include "Ente.h"

Ente::Ente() : gerenciadorGrafico(NULL), textura(NULL)
{
}

Ente::~Ente()
{
}

void Ente::setGerenciadorGrafico()
{
    this->gerenciadorGrafico = GerenciadorGrafico::getInstance();
    textura = gerenciadorGrafico->devolveImagemEnte(this);

    if (textura != NULL) {
        sprite.setOrigin(textura->getSize().x / 2, textura->getSize().y / 2); //centraliza o sprite
        sprite.setTexture(*textura);

        atualizaSprite(0, 0);
    }
}

void Ente::draw() {
	gerenciadorGrafico->draw(this);
}