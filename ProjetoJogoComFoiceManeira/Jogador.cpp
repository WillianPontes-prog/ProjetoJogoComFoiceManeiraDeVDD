#include "Jogador.h"
#include "GerenciadorDeComandos.h"


Jogador::Jogador(float posX, float posY, int vida): 
	EntidadeColisao(posX, posY, vida),
    listaProjetil(new Lista<Projetil*>),
    arma(new Arma(listaProjetil)),
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
    if (GerenciadorDeComandos::Esquerda()) {
        hspd = -velocidade;
    }
    //movimentação Direita
    else if (GerenciadorDeComandos::Direita()) {
        hspd = velocidade;
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
        disparar();

        break;
    case Jogador::Recarregando:


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

void Jogador::disparar()
{
    if (GerenciadorDeComandos::Disparar()) {
        		arma->disparar(getBody().getPosition(), sf::Vector2f(1, 0), gerenciadorGrafico);
    }
}

void Jogador::atualizaProjetil(){
    for (Lista<Projetil*>::iterator it = listaProjetil->begin(); it != listaProjetil->end(); it++)
    {
        (*it)->atualiza();

        if ((*it)->OverTime()) {
            Projetil* projetil = *it;
            listaProjetil->removerElemento(projetil);
            projetil = nullptr;
        }
    }
}

