#include "Menu.h"

// Construtor da classe Menu
Menu::Menu(Jogo* jg) :
    window(NULL)
{
    continua = 0;
    buttonSelected = 0;

    // Cria��o dos bot�es e adi��o � lista de bot�es
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

// M�todo para definir a janela do menu
void Menu::set_Window(sf::RenderWindow* window)
{
    this->window = window;

    // Define a janela para cada bot�o da lista de bot�es
    for (int i = 0; i < botoes.size(); i++)
    {
        botoes[i]->set_Window(window);
    }
}

// M�todo para mover a sele��o do bot�o
void Menu::move()
{
    // Verifica se o bot�o n�o est� pressionado
    if (!flagButtonPressed) {

        // Verifica se a tecla para baixo est� pressionada
        if (Key::Down()) {
            // Verifica se o bot�o selecionado � o �ltimo da lista
            if (buttonSelected >= botoes.size() - 1) {
                buttonSelected = 0;
            }
            else {
                buttonSelected++;
            }

            flagButtonPressed = 1;
        }
        // Verifica se a tecla para cima est� pressionada
        if (Key::Up()) {
            // Verifica se o bot�o selecionado � o primeiro da lista
            if (buttonSelected <= 0) {
                buttonSelected = botoes.size() - 1;
            }
            else {
                buttonSelected--;
            }

            flagButtonPressed = 1;
        }

    }

    // Verifica se nenhuma tecla est� pressionada
    if (!Key::Up() && !Key::Down())
    {
        flagButtonPressed = 0;
    }
}

// M�todo para atualizar o menu
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
