#include "Paddle.hpp"
#include <SFML/Graphics.hpp>

#define PADDLESIZE 100

Paddle::Paddle(){
	rect.setSize(sf::Vector2f(10, PADDLESIZE));
	rect.setFillColor(sf::Color(0,0,0));
	rect.setPosition(50,250);
}

sf::RectangleShape Paddle::getRect(){
	return rect;
}

void Paddle::setColor(sf::Color color){
			rect.setFillColor(color);
}

void Paddle::setPosition(int x, int y){
			rect.setPosition(x,y);
}
		
void Paddle::move(int x){
	if (rect.getPosition().y < 0) {
		rect.setPosition(50,0);
	}
	else if (rect.getPosition().y > (600 - PADDLESIZE)){
		rect.setPosition(50,600 - PADDLESIZE);
	}
		rect.move(0, x);
}

Ball Paddle::hit(Ball ball){
	if (((ball.getBall().getPosition().y) < (this->getRect().getPosition().y + PADDLESIZE)) && ((ball.getBall().getPosition().y) > (this->getRect().getPosition().y))){
		ball.deflect();
	}
	return ball;
};

void Paddle::reset(){
	this->rect.setPosition(50,250);
}

void Paddle::hide(){
	this->setColor(sf::Color::Cyan);
}
