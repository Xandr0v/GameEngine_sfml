#include <iostream>
#include <SFML/graphics.hpp>
#include "Window.h"

/*
Polygon

pos
vertexArray
vel
texture
texturePath
center
rotation

gravity on/off
collision of/off
update



*/


namespace m
{
	void print(sf::Vector2f v)
	{
		std::cout << v.x << " " << v.y << "\n";
	}
	template <typename T>
	void print(T a, T b)
	{
		std::cout << a << " " << b << "\n";
	}
};





int main()
{

	Window w(800, 800, "GameEngine", 60);
	sf::RenderWindow& window = w.getSFMLwindow();

	sf::RectangleShape rect(sf::Vector2f(100, 100));
	
	while (window.isOpen())
	{	
		

		








		window.draw(rect);

		
		w.updatePosition();
		w.updateRotation();
		w.updateZoom();
		w.updateWindow();
	}

	return 0;
}