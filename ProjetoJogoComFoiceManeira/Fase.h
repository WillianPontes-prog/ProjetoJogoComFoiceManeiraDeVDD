#pragma once

#include "Ente.h"
#include "Lista.h"
#include "Jogador.h"

class Fase : public Ente
{
protected:
	Lista<Jogador*>* listaJogadores;


public:
	Fase(GerenciadorGrafico* GG);
	~Fase();

	void atualiza();
	virtual void criaEntidades() = 0;

	//------------metodos de criação de entidades-----------------\\
	================================================================
	void criaJogador(float posX = 0, float posY = 0, int vida = 5);

};

