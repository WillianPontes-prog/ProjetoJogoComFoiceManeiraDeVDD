#include "Menu.h"

Menu::Menu(GerenciadorGrafico* gg, Jogo* jg): Ente()
{
    continua = 0;
    botaoSelecionado = 0;

    // Cria��o dos bot�es e adi��o � lista de bot�es
    botoes.push_back(new Botao(gerenciadorGrafico, 100, 50, 200, 50, "Continua", Botao::CarregarJogo, jg));
    botoes.push_back(new Botao(gerenciadorGrafico, 100, 150, 200, 50, "Novo Jogo", Botao::NovoJogo, jg));
    botoes.push_back(new Botao(gerenciadorGrafico, 100, 250, 200, 50, "Sair", Botao::Sair, jg));
    setGerenciadorGrafico(gg);

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
    if (!flagBotaoPressionado) {

        // Verifica se a tecla para baixo est� pressionada
        if (GerenciadorDeComandos::Baixo() || GerenciadorDeComandos::BaixoV2()) {
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
        if (GerenciadorDeComandos::Cima() || GerenciadorDeComandos::CimaV2()) {
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
    if (!GerenciadorDeComandos::Cima() && !GerenciadorDeComandos::Baixo() && GerenciadorDeComandos::CimaV2() && !GerenciadorDeComandos::BaixoV2())
    {
        flagBotaoPressionado = 0;
    }
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
