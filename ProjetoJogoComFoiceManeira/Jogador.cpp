#include "Jogador.h"
#include "GerenciadorDeComandos.h"


Jogador::Jogador(float posX, float posY, int vida): 
	EntidadeColisao(posX, posY, vida),
    listaProjetil(new Lista<Projetil*>),
    arma(new Arma(listaProjetil))
	EntidadeColisao(posX, posY, vida),
    state(Normal),
    tempoMachucado(0),
    maxTempoMachucado(45)
{
	setTextura("LifeImg.png");
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

    vspd += GRAVIDADE;

    if(GerenciadorDeComandos::Up() && noChao)
	{
		vspd = -10;
	}
}

void Jogador::atualiza()
{

    drawVida(16, 16, spriteVida);

    switch (state)
    {
    case Jogador::Normal:
        move();

        break;
    case Jogador::Ataque:


        break;
    case Jogador::Machucado:

        if(tempoMachucado > 0)
		{
			tempoMachucado--;

            if (vspd == 0) {
                if (hspd > 0) {
                    hspd--;
                }
                else if (hspd < 0) {
                    hspd++;
                }
            }

            vspd += GRAVIDADE;
		}
		else
		{
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

