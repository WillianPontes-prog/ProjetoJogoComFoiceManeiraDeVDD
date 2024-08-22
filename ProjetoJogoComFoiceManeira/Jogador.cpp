#include "Jogador.h"
#include "GerenciadorDeComandos.h"


Jogador::Jogador(float posX, float posY, int vida, Arma* arma): 
	EntidadeColisao(posX, posY, vida, arma),
    state(Normal),
    tempoMachucado(0),
    maxTempoMachucado(45)
{
	setTextura("Imagens/Jogador1.png");
	setVelocidade(5);

    if (!texturaVida.loadFromFile("LifeImg.png")) {
        // Tratar o erro de carregamento da textura
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    spriteVida.setTexture(texturaVida);

}

Jogador::~Jogador()
{
}

void Jogador::move()
{

    //movimentação Esquerda
    if (GerenciadorDeComandos::Esquerda()) {
        hspd = -velocidade;
        direcao.x = -1;
        sprite.setScale(-1, 1);
        
    }
    //movimentação Direita
    else if (GerenciadorDeComandos::Direita()) {
        hspd = velocidade;
        direcao.x = 1;
        sprite.setScale(1, 1);
    }
    else {
        hspd = 0;
    
    }

    vspd += GRAVIDADE;

    if(GerenciadorDeComandos::Cima() && noChao)
	{
		vspd = -10;
	}
}

void Jogador::atualiza()
{
    atualizaProjetil();
    drawVida(16, 16, spriteVida);

    switch (state)
    {
    case Jogador::Normal:
        move();
        sacarArma();

        break;
    case Jogador::Recarregando:
        move();

        if (tempoRecarregando > 0)
            tempoRecarregando--;
		else
			setState(Normal);
		

        break;
    case Jogador::Machucado:

        
        if(tempoMachucado > 0)
		{
			tempoMachucado--;

            if (vspd == 0) {
                if (hspd > 0)
                    hspd--;
                else if (hspd < 0)
                    hspd++;
            }
            
            sprite.setColor(sf::Color::Black);

            vspd += GRAVIDADE;
		}
		else
		{
            sprite.setColor(sf::Color::White);
			setState(Normal);
		}

        break;
    default:
        break;
    }
   
	atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
	draw();
    
}

void Jogador::setState(State state)
{
    if(getState() != Machucado && state == Machucado)
    {
		tempoMachucado = maxTempoMachucado;
	}

    this->state = state;
}

void Jogador::sacarArma()
{
    if (GerenciadorDeComandos::Disparar()) {
        disparar();
        setState(Recarregando);
    }
}






