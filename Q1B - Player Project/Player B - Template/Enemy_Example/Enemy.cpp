// Enemy class

#include "Enemy.h"   // include Enemy header file
#include "Game.h"


// Definition of member functions of the Enemy class


Enemy::Enemy() // default constructor
{
	loadImage(); // load the image file for the sprite

	setPosition(100, 400);  // set the position of the Enemy sprite

	strength = (rand() % 10) + 1;
	direction = (rand() % 2) + 1;        // Generates a random number between 1 and 2
	speed = 1; 
	alive = true;
}

void Enemy::loadImage()
// Loads the image for the Enemy object
{
	if (!texture.loadFromFile("ASSETS/IMAGES/EnemyGuy.bmp"))
	{
		std::cout << "error with Enemy image file";
	}

	sprite.setTexture(texture);
}



sf::Sprite Enemy::getBody() // get the Enemy's body
{
	return sprite;
}



void Enemy::setPosition()  // set the position of the Enemy on the screen
{
	sprite.setPosition(100, 400);
}


void Enemy::setPosition(int xPos, int yPos)  // set the position of the Enemy on the screen
{
	sprite.setPosition(xPos, yPos);
}

void Enemy::moveRight()
{
	
	speed = 5;

	sf::Vector2f pos(sprite.getPosition());
	setPosition(pos.x + speed, pos.y);

	if (pos.x > SCREEN_WIDTH)
	{
		setPosition(0 - sprite.getGlobalBounds().width, pos.y);
	}
	
}



