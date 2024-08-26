#include "Menu.h"

Menu::Menu(GerenciadorGrafico* gg, Jogo* jg): Ente()
{
    continua = 0;
    botaoSelecionado = 0;

    setGerenciadorGrafico(gg);

    // Criação dos botões e adição à lista de botões
    botoes.push_back(new Botao(gg, 100, 50, 200, 50, "Continua", Botao::CarregarJogo, jg));
    botoes.push_back(new Botao(gg, 100, 150, 200, 50, "Novo Jogo", Botao::NovoJogo, jg));
    botoes.push_back(new Botao(gg, 100, 250, 200, 50, "Sair", Botao::Sair, jg));

    

    flagBotaoPressionado = 0;

    jogo = jg;
}

Menu::~Menu()
{
    for (int i = 0; i < botoes.size(); i++)
    {
        delete botoes[i];
    }
}

void Menu::move()
{
    if (!GerenciadorDeComandos::Cima() && !GerenciadorDeComandos::Baixo())
    {
        flagBotaoPressionado = 0;
    }

    if (!flagBotaoPressionado) {

        // Verifica se a tecla para baixo está pressionada
        if (GerenciadorDeComandos::Baixo()) {
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
        if (GerenciadorDeComandos::Cima()) {
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

}

void Menu::atualiza()
{
    move();
    for (int i = 0; i < botoes.size(); i++)
    {

        if (i == botaoSelecionado)
        {
            botoes[i]->set_Pressed(true);

            if ( GerenciadorDeComandos::Click()) {
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
