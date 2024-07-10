#pragma once
#include <SFML/Graphics.hpp>
class Button {
private:
	sf::RectangleShape body;
	sf::Text text;
	sf::Font font;
	sf::RenderWindow* window;
	int pressed;
public:
	Button(sf::RenderWindow* w, float x = 0, float y = 0.0, float width = 0.0, float height = 0.0, std::string text = "");
	~Button();

	void draw();
	void set_Color(sf::Color color);
	void set_Window(sf::RenderWindow* window);
	void set_Pressed( bool test);
	virtual void execute();
	void atualiza();
};