#include <iostream>
#include <SFML/graphics.hpp>
#include "Window.h"
#include "TileMap.h"
#include <string>
Window w(800, 800, "GameEngine", 60);
sf::RenderWindow& window = w.getSFMLwindow();




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



/*
polygon

pos
vertexArray
vel
texture
texturePath
tilemap
tilemapcoords
rotation

gravity on/off
collision of/off
update



*/

int main()
{
	/*sf::VertexArray square(sf::Quads, 4);
	square[0].position = sf::Vector2f(0, 0);
	square[1].position = sf::Vector2f(100, 0);
	square[2].position = sf::Vector2f(100, 100);
	square[3].position = sf::Vector2f(0, 100);

	square[0].texCoords = sf::Vector2f(0, 0);
	square[1].texCoords = sf::Vector2f(225, 0);
	square[2].texCoords = sf::Vector2f(225, 225);
	square[3].texCoords = sf::Vector2f(0, 225);
	
	sf::Texture texture;
	texture.loadFromFile("images/tima.png");*/

	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	TileMap map;
	if (!map.load("images/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
		return -1;

	while (window.isOpen())
	{	
		

		








		
		/*window.draw(square, &texture);*/
		window.draw(map);
		w.updatePosition();
		w.updateRotation();
		w.updateZoom();
		w.updateWindow();
	}

	return 0;
}