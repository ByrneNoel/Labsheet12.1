// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	loadImage(); // load the image file for the sprite

	image_width = 124; // the width of the image in pixels
	scaled = false; // the image is not scaled

	int xPos = SCREEN_WIDTH/2;        // place the player object in the centre of the screen
	int yPos = SCREEN_HEIGHT/2;
	setPosition(xPos, yPos);  // set the position of the players sprite

	speed = 5; // the average speed
	direction = (rand() % 2) + 1;        // Generates a random number between 1 and 2
	lives = 3;
}

void Player::loadImage()
// Loads the image for the player object
{
	if (!texture.loadFromFile("ASSETS/IMAGES/SquareGuy.bmp"))
	{
		std::cout << "error with player image file";
	}

	sprite.setTexture(texture);
	
}


sf::Sprite Player::getBody() // get the player's body
{
	return sprite;
}

void Player::increaseSize()
{
	if (scaled == false)
	{
		sprite.setScale(2.0f, 2.0f);
	}

	scaled = true;

}


void Player::setPosition(int xPos, int yPos)  // set the position of the player on the screen
{
	sprite.setPosition(xPos, yPos);
}

void Player::increaseSpeed()
{
	if (direction == 2)
	{
		speed += 1;
	}

	else if (direction == 1)
	{
		speed = speed - 1;
	}
	
}


void Player::decreaseSpeed()
{
	if (direction == EAST)
	{
		speed = speed - 1;
	}

	else if (direction == WEST)
	{
		speed += 1;
	}
}

void Player::movement()
{
	
 sf::Vector2f pos(sprite.getPosition());


	if (pos.x > SCREEN_WIDTH - image_width && scaled == false)
	{
		speed = -speed;
		direction = WEST;

	}

	else if (pos.x > SCREEN_WIDTH - image_width * 2 && scaled == true)
	{
		speed = -speed;
		direction = WEST;
	}

	else if (pos.x < -sprite.getLocalBounds().width + image_width)
	{
		speed = -speed;
		direction = EAST;
	}

	if (reverse == false)
	{
		setPosition(pos.x + speed, pos.y);
	}

	if (reverse == true)
	{
		setPosition(pos.x - speed, pos.y);
	}
	
}

void Player::reverseMovement()
{
	movement();
	reverse = !reverse;
	
}

void Player::changeColour()
{
	int colour = (rand() % 3) + 1;

	if (colour == 1)
	{
		sprite.setColor(sf::Color::Red);

	}

	else if (colour == 2)
	{
		sprite.setColor(sf::Color::Green);

	}
	else if (colour == 3)
	{
		sprite.setColor(sf::Color::Blue);

	}
	else if (colour == 4)
	{
		sprite.setColor(sf::Color::Yellow);

	}
}



