#include "Ente.h"

Ente::Ente() : gerenciadorGrafico(NULL)
{
}

Ente::~Ente()
{
}

void Ente::setGerenciadorGrafico(GerenciadorGrafico* gerenciadorGrafico)
{
    this->gerenciadorGrafico = gerenciadorGrafico;
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