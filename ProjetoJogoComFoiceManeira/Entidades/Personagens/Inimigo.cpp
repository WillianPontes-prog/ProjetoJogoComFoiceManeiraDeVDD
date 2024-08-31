#include "Inimigo.h"

using namespace Listas;

namespace Entidades {
	namespace Personagens {
		Inimigo::Inimigo(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida, Arma* arma) :
			EntidadeColidivel(posX, posY, vida, arma),
			listaJogadores(listaJogadores)
		{
		}

		Inimigo::~Inimigo()
		{
		}

		sf::Vector2f Inimigo::BuscarJogador()
		{
			//--itera sobre todos os jogadores e retorna um vetor com a menor distancia--\\
			===============================================================================

			sf::Vector2f menorDistancia = sf::Vector2f(999999, 999999);
			sf::Vector2f compareVecto;

			for (Lista<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); it++)
			{
				compareVecto = sf::Vector2f((*it)->getBody().getPosition().x - getBody().getPosition().x, (*it)->getBody().getPosition().y - getBody().getPosition().y);

				if (sqrt((compareVecto.x * compareVecto.x) + (compareVecto.y * compareVecto.y)) < sqrt((menorDistancia.x * menorDistancia.x) + (menorDistancia.y * menorDistancia.y)))
					menorDistancia = compareVecto;
			}

			return menorDistancia;
		}
	}
}
