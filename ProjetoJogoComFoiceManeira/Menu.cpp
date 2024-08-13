#include "Menu.h"

// Construtor da classe Menu
Menu::Menu(Jogo* jg) :
    window(NULL)
{
    continua = 0;
    botaoSelecionado = 0;

    // Criação dos botões e adição à lista de botões
    botoes.push_back(new Botao(window, 100, 50, 200, 50, "Continua", Botao::CarregarJogo, jg));
    botoes.push_back(new Botao(window, 100, 150, 200, 50, "Novo Jogo", Botao::NovoJogo, jg));
    botoes.push_back(new Botao(window, 100, 250, 200, 50, "Sair", Botao::Sair, jg));

    flagBotaoPressionado = 0;

    jogo = jg;
}

// Destrutor da classe Menu
Menu::~Menu()
{
    for (int i = 0; i < botoes.size(); i++)
    {
        delete botoes[i];
    }
}

// Método para definir a janela do menu
void Menu::set_Window(sf::RenderWindow* window)
{
    this->window = window;

    // Define a janela para cada botão da lista de botões
    for (int i = 0; i < botoes.size(); i++)
    {
        botoes[i]->set_Window(window);
    }
}

// Método para mover a seleção do botão
void Menu::move()
{
    // Verifica se o botão não está pressionado
    if (!flagBotaoPressionado) {

        // Verifica se a tecla para baixo está pressionada
        if (Tecla::Down()) {
            // Verifica se o botão selecionado é o último da lista
            if (botaoSelecionado >= botoes.size() - 1) {
                botaoSelecionado = 0;
            }
            else {
                botaoSelecionado++;
            }

            flagBotaoPressionado = 1;
        }
        // Verifica se a tecla para cima está pressionada
        if (Tecla::Up()) {
            // Verifica se o botão selecionado é o primeiro da lista
            if (botaoSelecionado <= 0) {
                botaoSelecionado = botoes.size() - 1;
            }
            else {
                botaoSelecionado--;
            }

            flagBotaoPressionado = 1;
        }

    }

    // Verifica se nenhuma tecla está pressionada
    if (!Tecla::Up() && !Tecla::Down())
    {
        flagBotaoPressionado = 0;
    }
}

// Método para atualizar o menu
void Menu::atualiza()
{
    move();
    for (int i = 0; i < botoes.size(); i++)
    {
        if (i == botaoSelecionado)
        {
            botoes[i]->set_Pressed(true);

            if (Tecla::Click()) {
                botoes[i]->executar();
            }
        }
        else
        {
            botoes[i]->set_Pressed(false);
        }

        botoes[i]->atualiza();
    }
}
