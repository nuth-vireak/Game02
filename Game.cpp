#include "Game.h"

//--------------------------------------------------------------------------------------------------------------------
// Private function
//--------------------------------------------------------------------------------------------------------------------
void Game::initVariables()
{
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 02", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//--------------------------------------------------------------------------------------------------------------------
// Constructors and Destructors
//--------------------------------------------------------------------------------------------------------------------
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//--------------------------------------------------------------------------------------------------------------------
// Public functions
//--------------------------------------------------------------------------------------------------------------------
const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))										// While there are pending events...
	{
		switch (this->sfmlEvent.type)														// Check the type of the event...
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->player.update(this->window);
}

void Game::render()
{
	this->window->clear();																	// Clear window

	//Render stuff
	this->player.render(this->window);														// Render player to window
	this->window->display();																// Render window
}
