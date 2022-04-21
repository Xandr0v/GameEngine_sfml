#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

struct Window
{
	sf::RenderWindow window;
	sf::View view;
	sf::Vector2f size;
	sf::Vector2f pos;
	float speed;
	float angle;
	float rotationSpeed;
	float zoom;
	float zoomSpeed;
	sf::Event event;
	sf::Clock clock;
	bool isMousePressed;
	bool isMouseReleased;

	

	Window(int x, int y, std::string title, int FPS);
	void updateWindow();
	sf::Vector2f getMousePos();
	sf::RenderWindow& getSFMLwindow();

	void viewMove(sf::Vector2f vel);
	void updatePosition();
	void updateRotation();
	void updateZoom();
};
	


