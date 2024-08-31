#pragma once
#include "Obstaculo.h"
#include "Entidades/Personagens/Jogador.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo
		{
		private:
			float atrito;
			bool aleatoria;

		public:
			Plataforma(int posX = 0, int posY = 0, bool aleatoria = false);
			~Plataforma();

			void atualiza();
			float getAtrito() { return atrito; }
			void Obstacular(Personagens::Jogador* j);
			json toJson() {
				return json{
				{classe, Tipo::_plataforma},
				{pX, getBody().getPosition().x},
				{pY, getBody().getPosition().y},
				{"aleatoria", aleatoria}
				};
			}
		};
	}
}

