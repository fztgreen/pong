#include "Ball.hpp"
#include <SFML/Graphics.hpp>
//#include <random>


Ball::Ball(){
	ball.setRadius(4);
	ball.setFillColor(sf::Color(0,0,0));
	ball.setPosition(400, 300);
	setSpeed(1,1);
}

void Ball::setSpeed(int x, int y){
	this->speedX = x;
	this->speedY = y;
}

int Ball::getSpeedX(){
	return this->speedX;
}
int Ball::getSpeedY(){
	return this->speedY;
}

sf::CircleShape Ball::getBall(){
	return ball;
}

void Ball::setColor(sf::Color color){
			ball.setFillColor(color);
}

void Ball::setPosition(int x, int y){
			ball.setPosition(x,y);
}

sf::Vector2f Ball::getPosition(){
		return ball.getPosition();
};
		
void Ball::move(int x, int y){
	/*
	//Too far right
	if (ball.getPosition().x > 800){
		//this->deflect();
		this->speedX =  -this->speedX;
	}	
	//Too far Left
	else if (ball.getPosition().x < 0){
		//this->deflect();
		this->speedX =  -this->speedX;
	}
	*/
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

int Ball::getRandomNumber(int a, int b){
	std::uniform_int_distribution<int> distribution(a,b);
	return distribution(this->generator);
};

void Ball::deflect(){
	//Randomly selects
	std::uniform_int_distribution<int> distribution(1,2);
	int randx = distribution(this->generator);
	int randy = distribution(this->generator);
	
	
	if (this->speedX > 0){
		this->speedX = 1;
	}
	else{
		this->speedX = -1; 
	}
	
	
	//this->speedX = -(this->speedX);
	
	
	this->speedX = ((-this->speedX) * randx);
	
	
	if (this->speedY > 0){
		this->speedY = 1;
	}
	else{
		this->speedY = -1; 
	}
	
	
	
	this->speedY = (this->speedY * randy) ;
	
	//setSpeed(((-this->speedX) * randx), (this->speedY * randy));
	//this->move(speedX,speedY);
}

void Ball::reset(){
	this->ball.setPosition(400, 300);
	this->setSpeed(0,0);
}

void Ball::hide(){
	this->setColor(sf::Color::Cyan);
}

