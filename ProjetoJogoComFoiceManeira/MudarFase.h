#pragma once
#include "Fase.h"
#include "Jogo.h"
#include "Entidade.h"

class Jogo;

class MudarFase :  public Entidades::Entidade
{
private:
	Jogo* jg;

public:

	MudarFase(float posX = 0, float posY = 0, float tamX = 32, float tamY = 32, Jogo* jg = NULL);
	~MudarFase();
	void atualiza() override;

	void executa();
	json toJson() {
		return json{
		{classe, Tipo::_alternadorDeFase},
		{pX, getBody().getPosition().x},
		{pY, getBody().getPosition().y}
		};
	}

};

