#pragma once
#include "Botao.h" 
#include "Jogo.h"
#include"Gerenciadores/GerenciadorDeComandos.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Observer.h"

class Jogo;
class Botao;

class Menu:public Ente, public Observer {
private:
	int continua;
	int botaoSelecionado;
	std::vector<Botao*> botoes;
	std::vector<Botao*> botoesFases;

	int flagBotaoPressionado;

	Jogo* jogo;

    int WS;
    int click;

public:
	Menu(Jogo* jg);
	~Menu();
	void move();
	void atualiza();

	bool fases;

    void onNotify(int tecla) override {
        
        
        switch (tecla) {
        case sf::Keyboard::W:
            WS = 1;
            click = 0;

            break;
        case sf::Keyboard::S:
            WS = -1;
            click = 0;

            break;
        case sf::Keyboard::Z:
            click = 1;
            WS = 0;

            break;
        default:
            WS = 0;
            click = 0;

            break;

        }
        
        
        
    }
};