#include "Menu.h"

// Construtor da classe Menu
Menu::Menu(Jogo* jg) :
    window(NULL)
{
    continua = 0;
    botaoSelecionado = 0;

    // Cria��o dos bot�es e adi��o � lista de bot�es
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
    if (!flagBotaoPressionado) {

        // Verifica se a tecla para baixo est� pressionada
        if (Tecla::Down()) {
            // Verifica se o bot�o selecionado � o �ltimo da lista
            if (botaoSelecionado >= botoes.size() - 1) {
                botaoSelecionado = 0;
            }
            else {
                botaoSelecionado++;
            }

            flagBotaoPressionado = 1;
        }
        // Verifica se a tecla para cima est� pressionada
        if (Tecla::Up()) {
            // Verifica se o bot�o selecionado � o primeiro da lista
            if (botaoSelecionado <= 0) {
                botaoSelecionado = botoes.size() - 1;
            }
            else {
                botaoSelecionado--;
            }

            flagBotaoPressionado = 1;
        }

    }

    // Verifica se nenhuma tecla est� pressionada
    if (!Tecla::Up() && !Tecla::Down())
    {
        flagBotaoPressionado = 0;
    }
}

// M�todo para atualizar o menu
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
