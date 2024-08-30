#ifndef GERENCIADORDECOMANDOS_H
#define GERENCIADORDECOMANDOS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Observer.h"

namespace Gerenciadores {
    class GerenciadorDeComandos {
    public:
        // Método para adicionar observadores
        void adicionarObserver(Observer* observer);

        // Método para remover observadores
        void removerObserver(Observer* observer);

        // Método para processar eventos de teclado
        void processarEvento();

    private:
        // Notifica todos os observadores
        void notificar(int tecla);

        std::vector<Observer*> observers;
    };
}

#endif // GERENCIADORDECOMANDOS_H
