#include "Menu.h"

// Construtor da classe Menu
Menu::Menu(Jogo* jg) :
    window(NULL)
{
    continua = 0;
    buttonSelected = 0;

    // Criação dos botões e adição à lista de botões
    botoes.push_back(new Button(window, 100, 50, 200, 50, "Continua", Button::LoadGame, jg));
    botoes.push_back(new Button(window, 100, 150, 200, 50, "Novo Jogo", Button::NewGame, jg));
    botoes.push_back(new Button(window, 100, 250, 200, 50, "Sair", Button::Exit, jg));

    flagButtonPressed = 0;

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
    if (!flagButtonPressed) {

        // Verifica se a tecla para baixo está pressionada
        if (Key::Down()) {
            // Verifica se o botão selecionado é o último da lista
            if (buttonSelected >= botoes.size() - 1) {
                buttonSelected = 0;
            }
            else {
                buttonSelected++;
            }

            flagButtonPressed = 1;
        }
        // Verifica se a tecla para cima está pressionada
        if (Key::Up()) {
            // Verifica se o botão selecionado é o primeiro da lista
            if (buttonSelected <= 0) {
                buttonSelected = botoes.size() - 1;
            }
            else {
                buttonSelected--;
            }

            flagButtonPressed = 1;
        }

    }

    // Verifica se nenhuma tecla está pressionada
    if (!Key::Up() && !Key::Down())
    {
        flagButtonPressed = 0;
    }
}

// Método para atualizar o menu
void Menu::atualiza()
{
    move();
    for (int i = 0; i < botoes.size(); i++)
    {
        if (i == buttonSelected)
        {
            botoes[i]->set_Pressed(true);

            if (Key::Click()) {
                botoes[i]->execute();
            }
        }
        else
        {
            botoes[i]->set_Pressed(false);
        }

        botoes[i]->atualiza();
    }
}
