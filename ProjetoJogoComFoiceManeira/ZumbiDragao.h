#pragma once
#include "Entidade.h"
#pragma once
#include "Inimigo.h"

namespace Personagens {
	class ZumbiDragao : public Inimigo
	{
	private:
		int directionX;
		int chanceTeleporte;
		sf::Vector2f posicao1;
		sf::Vector2f posicao2;


	public:
		ZumbiDragao(Listas::Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 100, int chanceTeleporte = 600, Arma* arma = nullptr);
		~ZumbiDragao();

		void atualiza();
		void move();

		void invertDirectionX() { directionX = -directionX; }
		void sacarArma();
		void setPosicao2(sf::Vector2f pos) { posicao2 = pos; }
		void Teleporte();
		json toJson() {
			return json{
				{classe, Tipo::_zumbidragao},
				{pX, getBody().getPosition().x},
				{pY, getBody().getPosition().y},
				{vd, vida}
			};
		}

		void danificar(Jogador* j) {
			j->operator--();
		};
	};
}
