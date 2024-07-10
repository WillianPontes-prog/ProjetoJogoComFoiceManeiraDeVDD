#pragma once
class Weapons {
private:
    int Id;
    float dano;
    float tam_X;
    float tam_Y;
    float velocidade;
    float tempo;
    float pos_X;
    float pos_Y;
    float direc;
    float especial;

public:
    // Constructor
    Weapons(float tam_X = 100.f, float tam_Y = 100.f, float pos_X = 0.f, float pos_Y = 0.f, float velocidade = 0.f, float direc = 0.f, float dano = 0.f,float temp=0, float id= 0, float espec = 1);
    void NEW_DMG(float dmg) {
        dano *= dmg;
    }
    void NEW_VEL(float vel) {
		velocidade *= vel;
	}
    void NEW_DUR(float temp) {
        tempo *= temp;  
    }
};
