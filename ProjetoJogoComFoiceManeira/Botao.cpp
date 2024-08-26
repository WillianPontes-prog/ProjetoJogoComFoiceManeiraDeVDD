#include "Botao.h"

Botao::Botao(GerenciadorGrafico* gg, float x, float y, float width, float height, std::string text, tipoDoBotao _type, Jogo* jg):
	Entidade( x, y, width, height)
{
	setGerenciadorGrafico(gg);
	set_Color(sf::Color::White);

	//*
	font.loadFromFile("PIXEAB.TTF");
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(x + width / 2 - this->text.getGlobalBounds().width / 2, y + height / 2 - this->text.getGlobalBounds().height / 2);
	//*/
	pressionado = 0;

	this->tipo = _type;

	jogo = jg;

}

Botao::~Botao()
{
}

void Botao::draw()
{
	drawBody();
	
	//window->draw(text); ver depois

}

void Botao::set_Color(sf::Color color)
{
	body.setFillColor(color);
}



void Botao::set_Pressed(bool test)
{
	if (test)
		pressionado = 1;
	else
		pressionado = 0;
}

void Botao::executar()
{
	switch (tipo)
	{
	case Botao::NovoJogo: {
		jogo->setarModoDeJogo(Jogo::_fase1);
	}
		break;
	case Botao::CarregarJogo: {

	}
		break;
	case Botao::Salvar: {

	}
		break;
	case Botao::Sair: {
		gerenciadorGrafico->Close();
	}
		break;
	default: {

	}
		break;
	}
}

void Botao::atualiza()
{
	if (pressionado)
	{
		set_Color(sf::Color::Green);
	}
	else
	{
		set_Color(sf::Color::White);
	}
	draw();
	drawText();
}

void Botao::drawText()
{
	gerenciadorGrafico->draw(text);
}
