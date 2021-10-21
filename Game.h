#pragma once

#include "SFML/Graphics.hpp"
#include <ctime>

#include "Player.h"

class Game
{
private:
	// Variables Declaration
	//--------------------------------------------------------------------------------------------------------------------
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	// Initialize objects
	//--------------------------------------------------------------------------------------------------------------------
	Player player;														  // Initialize player object

	// Private function
	//--------------------------------------------------------------------------------------------------------------------
	void initVariables();                                                 // Initialize variables
	void initWindow();                                                    // Initialize Windows

public:
	// Constructor and Destructors
	//--------------------------------------------------------------------------------------------------------------------
	Game();                                                               // Constructors
	~Game();                                                              // Destructors

	// Accessors
	//--------------------------------------------------------------------------------------------------------------------
	
	// Modifiers
	//--------------------------------------------------------------------------------------------------------------------
	
	// Public functions
	//--------------------------------------------------------------------------------------------------------------------
	const bool running() const;                                           // Return true as long as window isOpen();
	void pollEvents();

	void update();														  // Update game (one frame)
	void render();														  // Render game (one frame)
};