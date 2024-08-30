#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Obstaculos{

	class Obstaculo : public Entidade
	{
	protected:

	public:
		Obstaculo(int posX = 0, int posY = 0);
		~Obstaculo();

		virtual void atualiza() = 0;
		virtual void Obstacular(Personagens::Jogador* j) = 0;
		virtual json toJson() = 0;
	};


}
