#include "Ball.hpp"
#include <SFML/Graphics.hpp>
//#include <random>

//Balls constructor initialize ball properties
Ball::Ball(){
	ball.setRadius(4);
	ball.setFillColor(sf::Color(0,0,0));
	ball.setPosition(400, 300);
	setSpeed(1,1);
}

//Sets the speed of the ball
void Ball::setSpeed(int x, int y){
	this->speedX = x;
	this->speedY = y;
}

//Returns ball speed in X direction
int Ball::getSpeedX(){
	return this->speedX;
}

//Returns ball speed in Y Direction
int Ball::getSpeedY(){
	return this->speedY;
}

//Returns ball object. TODO: not need this for public
sf::CircleShape Ball::getBall(){
	return ball;
}

//Sets ball color
void Ball::setColor(sf::Color color){
			ball.setFillColor(color);
}

//Sets ball position
void Ball::setPosition(int x, int y){
			ball.setPosition(x,y);
}

//Returns ball's topleft position.
sf::Vector2f Ball::getPosition(){
		return ball.getPosition();
};
		
//Moves ball object.  Checks for edges of game.  Keeps speed consistant when bouncing off sides, with -Y velocity
void Ball::move(int x, int y){
	//Too far up
	if (ball.getPosition().y < 0){
		this->speedY =  -this->speedY;
		//this->deflect();
	}
	//Too far down
	else if (ball.getPosition().y > 600){
		this->speedY =  -this->speedY;
		//this->deflect();
	}

	ball.move(getSpeedX(), getSpeedY());
}

//Gets a random number from the object's random number generator.
int Ball::getRandomNumber(int a, int b){
	std::uniform_int_distribution<int> distribution(a,b);
	return distribution(this->generator);
};

//Deflects a ball off a paddle with a random number for deflection.  Both X and Y velocity changes randomly.
void Ball::deflect(){
	//Randomly selects
	std::uniform_int_distribution<int> distribution(1,2);
	int randx = distribution(this->generator);
	int randy = distribution(this->generator);
	
	//Decides if speed is positive or negative in X direction
	if (this->speedX > 0){
		this->speedX = 1;
	}
	else{
		this->speedX = -1; 
	}
	
	//Sets speed to the opposite direction and a random speed
	this->speedX = ((-this->speedX) * randx);
	
	
	//Decides if speed is positive or negative in Y direction
	if (this->speedY > 0){
		this->speedY = 1;
	}
	else{
		this->speedY = -1; 
	}
	
	//Sets speed to the opposite direction and a random speed
	this->speedY = (this->speedY * randy) ;
}

//Resets ball position
void Ball::reset(){
	this->ball.setPosition(400, 300);
	this->setSpeed(0,0);
}

//Sets color to background color. Needs to be changed if background color is changed.
void Ball::hide(){
	this->setColor(sf::Color::Cyan);
}

