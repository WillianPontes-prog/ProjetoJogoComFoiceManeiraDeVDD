#include "Menu.h"

Menu::Menu(Jogo* jg): 
    Ente(),
    fases(false),
    WS(0)
{
    continua = 0;
    botaoSelecionado = 0;

    setGerenciadorGrafico();

    // Cria��o dos bot�es e adi��o � lista de bot�es
    botoes.push_back(new Botao(100, 50, 400, 50, "Continua", Botao::_CarregarJogo, jg));
    botoes.push_back(new Botao(100, 150, 400, 50, "Novo Jogo", Botao::_NovoJogo, jg));
    botoes.push_back(new Botao(100, 250, 400, 50, "Novo Jogo:2Jogadores", Botao::_NovoJogo2Jogadores, jg));
    botoes.push_back(new Botao(100, 350, 400, 50, "Sair", Botao::_Sair, jg));

    botoesFases.push_back(new Botao(100, 50, 400, 50, "Fase1", Botao::_Fase1, jg));
    botoesFases.push_back(new Botao(100, 150, 400, 50, "Fase2", Botao::_Fase2, jg));

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
    int MaxNumBotoes = botoes.size();

    if (fases) {
       MaxNumBotoes = botoesFases.size();
    }

    if (!WS)
    {
        flagBotaoPressionado = 0;
    }

    if (!flagBotaoPressionado) {

        // Verifica se a tecla para baixo est� pressionada
        if (WS == -1) {
            // Verifica se o bot�o selecionado � o �ltimo da lista
            botaoSelecionado++;
            flagBotaoPressionado = 1;
        }
        // Verifica se a tecla para cima est� pressionada
        if (WS == 1) {
            // Verifica se o bot�o selecionado � o primeiro da lista
            botaoSelecionado--;
            flagBotaoPressionado = 1;
        }

        if (botaoSelecionado < 0) {
            botaoSelecionado = MaxNumBotoes - 1;
        }

        if (botaoSelecionado > MaxNumBotoes - 1) {
            botaoSelecionado = 0;
        }

    }

    // Verifica se nenhuma tecla est� pressionada

}

void Menu::atualiza()
{
    draw();
    move();

    if (!fases) {

        for (int i = 0; i < botoes.size(); i++)
        {

            if (i == botaoSelecionado)
            {
                botoes[i]->set_Pressed(true);

                if (click) {
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
    else {
        for (int i = 0; i < botoesFases.size(); i++)
        {

            if (i == botaoSelecionado)
            {
                botoesFases[i]->set_Pressed(true);

                if (click) {
                    botoesFases[i]->executar();
                }
            }
            else
            {
                botoesFases[i]->set_Pressed(false);
            }

            botoesFases[i]->atualiza();
        }
    }

    WS = 0;
    click = 0;
}
