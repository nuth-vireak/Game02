#include "Player.h"

//--------------------------------------------------------------------------------------------------------------------
// Private function
//--------------------------------------------------------------------------------------------------------------------
void Player::initVariables()
{
	this->movementSpeed = 10.f;										// Initialize movement speed of player
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

//--------------------------------------------------------------------------------------------------------------------
// Constructors and Destructors
//--------------------------------------------------------------------------------------------------------------------
Player::Player()
{
	this->shape.setPosition(0.f, 0.f);

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
	
}

//--------------------------------------------------------------------------------------------------------------------
// Public functions
//--------------------------------------------------------------------------------------------------------------------
void Player::updateInput()
{
	// Keyboard input
	// Mleft
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	// Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(+this->movementSpeed, 0.f);
	}
	// Top
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	// Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, +this->movementSpeed);
	}
}

void Player::updateWindowBoundCollision(const sf::RenderTarget* target)
{
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	//Left
	if (playerBounds.left <= 0.f)
		this->shape.setPosition(0.f, playerBounds.top);
	//Right
	else if (playerBounds.left + playerBounds.width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
	//Top
	if (playerBounds.top <= 0.f)
		this->shape.setPosition(playerBounds.left, 0.f);
	//Bottom
	else if (playerBounds.top + playerBounds.height >= target->getSize().y)
		this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
}

void Player::update(const sf::RenderTarget* target)
{
	// Window bonds collision
	this->updateWindowBoundCollision(target);

	this->updateInput();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
