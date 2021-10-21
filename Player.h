#pragma once

#include "SFML/Graphics.hpp"

class Player
{
private:
	// Variables Declaration
	//--------------------------------------------------------------------------------------------------------------------
	sf::RectangleShape shape;

	float movementSpeed;

	// Private function
	//--------------------------------------------------------------------------------------------------------------------
	void initVariables();													// Initialize variables
	void initShape();														// Initialize player shape

public:
	// Constructor and Destructors
	//--------------------------------------------------------------------------------------------------------------------
	Player();																// Constructors
	virtual ~Player();                                                      // Virtual Destructors

	// Public functions
	//--------------------------------------------------------------------------------------------------------------------
	void updateInput();														// Update player movement
	void updateWindowBoundCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);									// Update player
	void render(sf::RenderTarget* target);									// Render player
};

