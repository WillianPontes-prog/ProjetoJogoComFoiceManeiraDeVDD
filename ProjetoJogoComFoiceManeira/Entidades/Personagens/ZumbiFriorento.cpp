#include "ZumbiFriorento.h"

using namespace Listas;

namespace Entidades {
	namespace Personagens {
		ZumbiFriorento::ZumbiFriorento(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida) :
			Inimigo(listaJogadores, posX, posY, vida),
			directionX(1)
		{

			velocidade = 2;

			if (!(rand() % 2))
				directionX = -1;
		}

		ZumbiFriorento::~ZumbiFriorento()
		{
		}

		void ZumbiFriorento::atualiza()
		{
			mudarCorDano();
			move();
			atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
			draw();
		}

		void ZumbiFriorento::move()
		{

			hspd = velocidade * directionX;

			sprite.setScale(directionX, 1);

			vspd += GRAVIDADE;
		}
	}
}
