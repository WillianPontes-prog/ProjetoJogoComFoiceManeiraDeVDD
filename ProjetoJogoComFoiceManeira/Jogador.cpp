#include "Jogador.h"
#include "GerenciadorDeComandos.h"


Jogador::Jogador(float posX, float posY, int vida): 
	EntidadeColisao(posX, posY, vida)
{
	setTextura("LifeImg.png");
	setVelocidade(5);

}

Jogador::~Jogador()
{
}

void Jogador::move()
{

    //movimentação Esquerda
    if (GerenciadorDeComandos::Left()) {
        hspd = -velocidade;
    }
    //movimentação Direita
    else if (GerenciadorDeComandos::Right()) {
        hspd = velocidade;
    }
    else {
        hspd = 0;
    }


    body.move(sf::Vector2f(getHspd(), getVspd()));
}

void Jogador::atualiza()
{
    move();

	atualizaSprite(body.getPosition().x, body.getPosition().y);
	draw();
}
