#include "Jogo.h"
#include "Fases/Fase1.h"
#include "Fases/Fase2.h"

#define FPS 60

using namespace Fases;
using namespace Gerenciadores;

Jogo::Jogo():
	gerenciadorGrafico(Gerenciadores::GerenciadorGrafico::getInstance()),
    f1(nullptr),
    f2(nullptr),
    menu(new Menu(this)),
    pontuacao(0),
    atualizarPontuacao(true)
{
    if (!texturaFim.loadFromFile("imagens/fimDeJogo.png")) {
        throw std::runtime_error("Erro ao carregar a textura!");
    }

    if (!texturaVenceu.loadFromFile("imagens/parabens.png")) {
        throw std::runtime_error("Erro ao carregar a textura!");
    }

    
    if (!font.loadFromFile("PIXEAB.ttf")) { // Certifique-se de ter o arquivo de fonte no diretório
        std::cerr << "Erro ao carregar a fonte." << std::endl;
    }

    // Cria um objeto sf::Text para exibir o texto na janela
    
    text.setFont(font);
    text.setCharacterSize(24); // Tamanho da fonte
    text.setFillColor(sf::Color::Black); // Cor do texto
    text.setPosition(gerenciadorGrafico->getWindow()->getSize().x/2, 540); // Posição inicial do texto
    
    

    srand(time(NULL));
	rodando = Jogo::_menu;
	executar();


}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
#ifdef SHOW_FPS
    //mostrar FPS
    int frameCount = 0;
    sf::Clock clock;
#endif // SHOW_FPS

    gerenciadorDeComandos.adicionarObserver(menu);
    sf::RenderWindow* window = gerenciadorGrafico->getWindow();

    window->setFramerateLimit(FPS);

    while (window->isOpen())
    {
        //limitador FPS
        window->setFramerateLimit(FPS);

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
            if (rodando != Jogo::_menu && rodando != Jogo::_menuFases)
            {

                if (rodando == Jogo::_fase1 || rodando == Jogo::_fase2)
                {

                    json jMap;

                    if (rodando == Jogo::_fase1) {
                        jMap = { {"Fase", _F1}, };

                        f1->salvarFase();
                    }
                    else {
                        jMap = { {"Fase", _F2} };

                        f2->salvarFase();
                    }

                    std::ofstream outputFile("map.json");
                    if (!outputFile.is_open()) {
                        std::cerr << "Erro ao abrir o arquivo JSON para escrita!" << std::endl;
                    }
                    else {

                        outputFile << jMap.dump(4); // Salvando com identação de 4 espaços
                        outputFile.flush();
                        outputFile.close();
                    }
                }

                if (rodando == Jogo::_fimDeJogo) {

                    // Tente ler o arquivo JSON existente
                    json jsonData;
                    std::ifstream inputFile("Rank.json");

                    if (inputFile.is_open()) {
                        try {
                            inputFile >> jsonData;
                            inputFile.close();
                        }
                        catch (const json::exception& e) {
                            std::cerr << "Erro ao ler o arquivo JSON: " << e.what() << std::endl;

                        }
                    }


                    jsonData.push_back(json{ {"Nome", inputText}, {"Pontos", pontuacao} });

                    // Salvar o JSON atualizado de volta no arquivo
                    std::ofstream outputFile("Rank.json");
                    if (outputFile.is_open()) {
                        outputFile << jsonData.dump(4); // Salvando com identação de 4 espaços
                        outputFile.close();
                    }
                    else {
                        std::cerr << "Erro ao abrir o arquivo JSON para escrita!" << std::endl;

                    }
                }

                Sleep(100); // Espera 100ms para evitar múltiplas entradas
                rodando = Jogo::_menu;
            }
		}

        gerenciadorDeComandos.processarEvento();

        switch (rodando)
        {
        case Jogo::_menu:

            if (atualizarPontuacao) {

                atualizaPontuacao();
                atualizarPontuacao = false;
            }

           


            menu->fases = false;
            menu->atualiza();

            drawPontuacao();

            break;
        case Jogo::_menuFases:


            pontuacao = 0;

            menu->fases = true;
            menu->atualiza();

            break;
        case Jogo::_fase1:

            spriteFinal.setTexture(texturaFim);
            f1->atualiza();

            break;
        case Jogo::_fase2:

            spriteFinal.setTexture(texturaFim);
            f2->atualiza();
            
            if (f2->checarMudarFase()) {
                setarModoDeJogo(Jogo::_fimDeJogo);
                spriteFinal.setTexture(texturaVenceu);
            }

            break;
        case _fimDeJogo:

            gerenciadorGrafico->draw(spriteFinal);

            window->setKeyRepeatEnabled(false);

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) { // Verifica se o caractere é ASCII
                    if (event.text.unicode == '\b' && !inputText.empty()) {
                        // Apaga o último caractere se 'Backspace' for pressionado
                        inputText.pop_back();
                    }
                    else if (event.text.unicode >= 32) {
                        // Adiciona o caractere à string se não for 'Backspace'
                        inputText += static_cast<char>(event.text.unicode);
                    }

                    text.setString(inputText); // Atualiza o texto exibido

                    sf::FloatRect textBounds = text.getLocalBounds();

                    // Calcular a posição central (assumindo que queremos centralizar na janela)
                    float posX = (gerenciadorGrafico->getWindow()->getSize().x/2 - textBounds.width) / 2.0f;
                    

                    // Ajustar a posição do texto
                    text.setPosition(posX - textBounds.left, text.getPosition().y);

                    

                    Sleep(100); // Espera 100ms para evitar múltiplas entradas
                }
            }

            

            break;
        default:

            break;
        }
        

#ifdef SHOW_FPS
        /* Mostrar FPS*/
        frameCount++;
        if (clock.getElapsedTime().asSeconds() >= 1.f)
        {
            std::cout << "FPS: " << frameCount << std::endl;
            frameCount = 0;
            clock.restart();
        }
#endif

        if (rodando != Jogo::_menu) {
            atualizarPontuacao = true;
        }

        if(rodando == Jogo::_fimDeJogo)
		{
			window->draw(text);
		}
        window->display();

    }
}

void Jogo::CriaFase1(bool n, bool carregar = false)
{
    if (!f1) { delete f1; } 

    f1 = new Fase1(n, this, carregar);

}

void Jogo::CriaFase2(bool n, bool carregar)
{
    if (!f2) { delete f2; }

    f2 = new Fase2(n, this, carregar);

    
}

void Jogo::atualizaPontuacao()
{
    
    // Abre o arquivo JSON
    std::ifstream arquivo("Rank.json");

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo " << "Rank" << std::endl;
        return;
    }

    // Carrega o JSON a partir do arquivo
    json j;
    arquivo >> j;

    std::vector<std::string> nomes;
    std::vector<int> pontos;


    // Itera sobre cada objeto no JSON e exibe nome e pontos
    for (const auto& item : j) {
        std::string n = item.at("Nome").get<std::string>();
        int p = item.at("Pontos").get<int>();
        
        nomes.push_back(n);
        pontos.push_back(p);

    }

    int n = pontos.size();
    bool trocado;

    int nRank = 10;

    for(size_t i = 0; i < nomes.size() && i < nRank; ++i)
	{
        int n = pontos.size();
        bool trocado;

        // Loop para realizar as passagens pelo vetor
        for (int i = 0; i < n - 1 ; i++) {
            trocado = false;

            // Loop para comparar e trocar elementos adjacentes
            for (int j = 0; j < n - i - 1; j++) {
                if (pontos[j] < pontos[j + 1]) {
                    // Troca os elementos se estiverem na ordem errada
                    std::swap(pontos[j], pontos[j + 1]);
                    std::swap(nomes[j], nomes[j + 1]);
                    trocado = true;
                }
            }

            // Se nenhum elemento foi trocado, o vetor já está ordenado
            if (!trocado)
                break;
        }
	}


    while (!rank.empty()) {
        rank.pop();
    }

    for (size_t i = 0; i < nomes.size() && i < nRank; ++i) {
        sf::Text text;



        // Define a string do texto com o nome e a pontuação
        text.setString(std::to_string(i+1) + " - " + nomes[i] + " : " + std::to_string(pontos[i]) + "pts");

        // Define a fonte do texto
        text.setFont(font);

        // Define o tamanho do texto
        text.setCharacterSize(16);

        // Define a cor do texto
        text.setFillColor(sf::Color::Black);

        // Define a posição do texto (ajustando para cada linha)
        text.setPosition(600, 100 + i * 30);

        // Adiciona o texto ao vetor
        rank.push(text);
    }
}

void Jogo::adicionarObserver(Observer* observer)
{
    gerenciadorDeComandos.adicionarObserver(observer);
}

void Jogo::drawPontuacao()
{
    stack<sf::Text> rankCopy = rank;
    while (!rankCopy.empty()) {
        gerenciadorGrafico->draw(rankCopy.top());
        rankCopy.pop();
    }
}
