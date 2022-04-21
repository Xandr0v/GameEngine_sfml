#include "Window.h"

Window::Window(int x, int y, std::string title, int FPS)
{
	size = sf::Vector2f(x, y);

	//initialization
	speed         = 10.f;
	angle         = 0.f;
	rotationSpeed = 2.f;
	zoom          = 2.f;
	zoomSpeed     = 1.1f;

	//window creation
	window.create(sf::VideoMode(x, y), title);

	//setting view
	sf::View view = window.getDefaultView();
	
	window.setFramerateLimit(FPS);

	sf::Event event;
	sf::Clock clock;
}




void Window::updateWindow()
{
	isMousePressed = false;
	isMouseReleased = false;

	//displaying and clock
	window.display();
	window.clear();
	clock.restart();

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)              { window.close(); }
		if (event.type == sf::Event::MouseButtonPressed)  { isMousePressed = true; }
		if (event.type == sf::Event::MouseButtonReleased) { isMouseReleased = true; }
		if (event.type == sf::Event::MouseWheelScrolled)
		{
			if      (event.mouseWheel.x > 0) { zoom /= zoomSpeed; }
			else if (event.mouseWheel.x < 0) { zoom *= zoomSpeed; }
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)	{ window.close(); }
		}
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { viewMove(sf::Vector2f( 0     ,  speed )); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { viewMove(sf::Vector2f( 0     , -speed )); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { viewMove(sf::Vector2f(  speed, 0      )); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { viewMove(sf::Vector2f( -speed, 0      )); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { angle += rotationSpeed; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { angle -= rotationSpeed; }
}

sf::Vector2f Window::getMousePos()
{
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	sf::Vector2f wpos = window.mapPixelToCoords(pos);
	return wpos;
}

sf::RenderWindow& Window::getSFMLwindow()
{
	return window;
}


void Window::viewMove(sf::Vector2f vel)
{
	sf::Vector2f direction =
	{
		 angle       * 3.14f / 180.f,
		(angle + 90) * 3.14f / 180.f
	}; // unit vector

	pos += sf::Vector2f
	(
		cosf(direction.x) * vel.x + cosf(direction.y) * vel.y,
		sinf(direction.x) * vel.x + sinf(direction.y) * vel.y
	); // movement relative to rotation
}




void Window::updatePosition()
{
	view.setCenter(pos);
	window.setView(view);
}

void Window::updateRotation()
{
	view.setRotation(angle);
	window.setView(view);
}

void Window::updateZoom()
{
	view.setSize(size.x * zoom, -size.y * zoom);
	window.setView(view);
}
