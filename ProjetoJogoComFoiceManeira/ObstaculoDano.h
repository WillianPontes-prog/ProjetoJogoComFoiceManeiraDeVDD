#pragma once
#include"Obstaculo.h"
#include"Jogador.h"

namespace Obstaculos {
	class ObstaculoDano :public Obstaculo {
	private:
		int dano;

	public:
		ObstaculoDano(float posX, float posY, int dano) : Obstaculo(posX, posY), dano(dano) {};
		~ObstaculoDano() {};

		void atualiza();
		void Obstacular(Personagens::Jogador* j);
		json toJson() {
			return json{
			{classe, Tipo::_obstaculoDano},
			{pX, getBody().getPosition().x},
			{pY, getBody().getPosition().y}
			};
		}

	};
}