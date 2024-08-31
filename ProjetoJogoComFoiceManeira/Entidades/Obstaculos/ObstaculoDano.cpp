#include "ObstaculoDano.h"

using namespace Entidades::Personagens;

namespace Entidades {
	namespace Obstaculos {
		void ObstaculoDano::atualiza()
		{
			draw();
			atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
		}

		void ObstaculoDano::Obstacular(Jogador* j)
		{
			j->operator--();
		}
	}
}