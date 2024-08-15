#pragma once
#include"Iterativo.h"
using namespace std;

class AlteradorFase : public Iterativo {
private:
	//salva o nome de qual o jason da próxima fase;
	float atual;

	bool cima;
	bool direita;
	bool esquerda;
	bool baixo;

public:
	AlteradorFase(float dimX = 200.f, float dimY = 200.f, float posX = 0, float posY = 0) : Iterativo(dimX, dimY, posX, posY), cima(0),direita(0),esquerda(0),baixo(0) {}
	~AlteradorFase() {}

	//set de qual direção é a proxima fase
	void setDireita() { direita = !direita; }
	void setEsquerda() { esquerda = !esquerda; }
	void setCima() { cima = !cima; }
	void setBaixo() { baixo = !baixo; }
	
	float interacao() override {
		if (cima) { return atual + 1; };
		if (direita) { return atual + 0.1; };
		if (esquerda) { return atual - 0.1; };
		if (baixo) { return atual - 1; };
		std::cout<< "Erro ao alterar a fase" << std::endl;
		return;
	}

};