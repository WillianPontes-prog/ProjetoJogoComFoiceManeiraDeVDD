#pragma once
#include "Fase.h"
#include "ZumbiDragao.h"


namespace Fases {
	class Fase2 : public Fase
	{
	protected:


		int numFogo[4];
		int numZumbiDragao[4];

		void carregarFase();

	public:
		Fase2(bool Jogadores, Jogo* jg, bool carregar = false);
		~Fase2();

		void criaEntidades(float posX, float posY, int n);

		void criarChefao(float posX, float posY, int vida);

		void criarFogo(float posX = 0, float posY = 0);

		bool checarMudarFase();
	};
}
