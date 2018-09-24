//Paddle CPP file by Zachary Greenfield

#include "Paddle.hpp"

#define PADDLESIZE 100

//Contstructor for a paddle
Paddle::Paddle(){
	rect.setSize(sf::Vector2f(10, PADDLESIZE));
	rect.setFillColor(sf::Color(0,0,0));
	rect.setPosition(50,250);
}

//Gets the rectangle for paddle
sf::RectangleShape Paddle::getRect(){
	return rect;
}

//Sets paddle color
void Paddle::setColor(sf::Color color){
	rect.setFillColor(color);
}

//Sets paddle position
void Paddle::setPosition(int x, int y){
	rect.setPosition(x,y);
}
		
//Moves the paddle
void Paddle::move(int x){
	if (rect.getPosition().y < 0) {
		rect.setPosition(50,0);
	}
	else if (rect.getPosition().y > (600 - PADDLESIZE)){
		rect.setPosition(50,600 - PADDLESIZE);
	}
		rect.move(0, x);
}

//Detects if a ball object intersects with a paddle object. Only checks Y relative locations, not X
Ball Paddle::hit(Ball ball){
	if (((ball.getBall().getPosition().y) < (this->getRect().getPosition().y + PADDLESIZE)) && ((ball.getBall().getPosition().y) > (this->getRect().getPosition().y))){
		ball.deflect();
	}
	return ball;
};

//Resets the paddle to its starting position
void Paddle::reset(){
	this->rect.setPosition(50,250);
}

//Hides the paddle to blend with background.  If change base game this needs to be changed too.
void Paddle::hide(){
	this->setColor(sf::Color::Cyan);
}
