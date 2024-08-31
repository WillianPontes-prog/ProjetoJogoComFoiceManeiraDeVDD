#include "Projetil.h"


namespace Entidades {
	Projetil::Projetil(float posX, float posY, float tamX, float tamY, int tempo, int velocidade, int dano, sf::Color c, sf::Vector2f direc) :
		Entidade(posX, posY, tamX, tamY),
		tempoDeDestruicao(tempo),
		velocidad(velocidade),
		dano(dano),
		direcao((direc) / sqrt(direc.x * direc.x + direc.y * direc.y))
	{
		body.setFillColor(c);

		float angleRad = std::atan2(direcao.y, direcao.x);

		// Converte o ângulo para graus
		float angleDeg = angleRad * 180.0f / 3.14159f;

		// Aplica a rotação ao retângulo
		body.setRotation(angleDeg);

	}

	Projetil::~Projetil()
	{
	}

	void Projetil::Move()
	{
		body.move(direcao * velocidad);
	}

	void Projetil::atualiza()
	{
		Move();
		drawBody();

	}

	int Projetil::OverTime()
	{
		tempoDeDestruicao--;
		if (tempoDeDestruicao <= 0)
		{
			return 1;
		}
		return 0;
	}

	void Projetil::destruir()
	{
		tempoDeDestruicao = 0;
	}

	json Projetil::toJson()
	{
		return json{
			{classe, Tipo::_projetil},
			{pX, body.getPosition().x},
			{pY, body.getPosition().y},
			{TEMPO, tempoDeDestruicao},
			{TAM_X, body.getSize().x},
			{TAM_Y, body.getSize().y},
			{VELOCIDADE, velocidad},
			{DANO, dano},
			{COR_R, body.getFillColor().r},
			{COR_G, body.getFillColor().g},
			{COR_B, body.getFillColor().b},
			{DIRECAO_X, direcao.x},
			{DIRECAO_Y, direcao.y}
		};




	}
}