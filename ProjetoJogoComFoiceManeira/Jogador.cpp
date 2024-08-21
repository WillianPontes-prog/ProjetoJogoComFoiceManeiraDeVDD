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

    vspd += 0.5;

    if(GerenciadorDeComandos::Up() && noChao)
	{
		vspd = -10;
	}
}

void Jogador::atualiza()
{
    move();
   
	atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
	draw();
    
}

