#include "Jogador.h"
#include "GerenciadorDeComandos.h"


Jogador::Jogador(float posX, float posY, int vida, Arma* arma, bool jogador2): 
	EntidadeColisao(posX, posY, vida, arma),
    state(Normal),
    posicaoInicial(posX, posY),
    jogador2(jogador2)
{
    maxTempoMachucado = 45;

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
    if ((!jogador2 && GerenciadorDeComandos::Esquerda()) || (jogador2 && GerenciadorDeComandos::EsquerdaV2())) {
        hspd = -velocidade;
        direcao.x = -1;
        sprite.setScale(-1, 1);
        
    }
    //movimentação Direita
    else if ((!jogador2 && GerenciadorDeComandos::Direita()) || (jogador2 && GerenciadorDeComandos::DireitaV2())) {
        hspd = velocidade;
        direcao.x = 1;
        sprite.setScale(1, 1);
    }
    else {
        hspd = 0;
    
    }


    vspd += GRAVIDADE;

    if (((!jogador2 && GerenciadorDeComandos::Cima()) || (jogador2 && GerenciadorDeComandos::CimaV2())) && noChao)
	{
		vspd = -30;
	}
}

void Jogador::atualiza()
{
    atualizaProjetil();

    if (jogador2) {
        drawVida(8, 40, spriteVida);
    }
    else {
        drawVida(8, 8, spriteVida);
    }

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
    if ((!jogador2 && GerenciadorDeComandos::Disparar())
        ||(jogador2 && GerenciadorDeComandos::DispararV2())) {
        disparar();
        setState(Recarregando);
    }
}






