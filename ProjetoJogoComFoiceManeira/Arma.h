#pragma once
#include "Ataque.h"
class Arma {
private:
    int Id;
    float dano;
    float tam_X;
    float tam_Y;
    float velocidade;
    float tempo;
    float direc;
    float especial;
    float cd;

public:
    // Constructor
    Arma(float tam_X = 100.f, float tam_Y = 100.f, float velocidade = 0.f, float direc = 1.f, float dano = 0.f,float temp = 0, float id = 0, float espec = 1, float cd = 30.f);
    ~Arma();

    Ataque* atack(float x, float y, float dir) {
        Ataque* corte = new Ataque(tam_X, tam_Y,x,y, velocidade, dir, dano, tempo);
        return corte;
    }
    
    void NEW_DMG(float dmg) {
        dano *= dmg;
    }
    void NEW_VEL(float vel) {
		velocidade *= vel;
	}
    void NEW_DUR(float temp) {
        tempo *= temp;  
    }

    float getCD() {
		return cd;
	}
};
