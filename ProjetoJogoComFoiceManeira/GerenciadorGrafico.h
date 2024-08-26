#pragma once
#include <iostream>
#include "Ente.h"
#include <SFML/Graphics.hpp>

class Ente;

class GerenciadorGrafico {
private:
    sf::RenderWindow* window;
    static GerenciadorGrafico* instance; // Instância única do Singleton
    void carregarTexturas();

    sf::Texture* tJogador1;
    sf::Texture* tInimigo1;
    sf::Texture* tFase1;
    sf::Texture* tFase1Plat;

    sf::Texture* tFasePlataforma;

    GerenciadorGrafico();
    ~GerenciadorGrafico();

public:
    // Função pública para acessar a instância única
    static GerenciadorGrafico* getInstance() {
        if (instance == nullptr) {
            instance = new GerenciadorGrafico();
        }
        return instance;
    }

    // Excluindo os construtores de cópia e operador de atribuição para evitar cópias
    GerenciadorGrafico(const GerenciadorGrafico&) = delete;
    GerenciadorGrafico& operator=(const GerenciadorGrafico&) = delete;

    void draw(Ente* e);
    void draw(sf::Sprite s);
    void draw(sf::RectangleShape b);
    void draw(sf::Text t);
    void Close();

    void atualiza();

    sf::RenderWindow* getWindow() { return window; };

    sf::Texture* devolveImagemEnte(Ente* e = nullptr);
};

// Inicialização da instância única fora da classe
GerenciadorGrafico* GerenciadorGrafico::instance = nullptr;
