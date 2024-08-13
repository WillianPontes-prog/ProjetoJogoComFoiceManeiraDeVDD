#include "Botao.h"

Botao::Botao(sf::RenderWindow* w, float x, float y, float width, float height, std::string text, tipoDoBotao _type, Jogo* jg)
{
	body.setPosition(x, y);
	body.setSize(sf::Vector2f(width, height));
	set_Color(sf::Color::White);

	font.loadFromFile("PIXEAB.TTF");
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(x + width / 2 - this->text.getGlobalBounds().width / 2, y + height / 2 - this->text.getGlobalBounds().height / 2);
	set_Window(w);
	pressionado = 0;

	this->tipo = _type;

	jogo = jg;

}

Botao::~Botao()
{
}

void Botao::draw()
{
	window->draw(body);
	window->draw(text);

}

void Botao::set_Color(sf::Color color)
{
	body.setFillColor(color);
}

void Botao::set_Window(sf::RenderWindow* w)
{
	window = w;
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
		jogo->setGameState(Jogo::EmJogo);
	}
	break;
	case Botao::CarregarJogo: {

	}
	break;
	case Botao::Salvar: {

	}
	break;
	case Botao::Sair: {
		window->close();
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
}
