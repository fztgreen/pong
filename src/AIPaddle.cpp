#include "AIPaddle.hpp"
#include <SFML/Graphics.hpp>

#define PADDLESIZE 100

AIPaddle::AIPaddle(){
	rect.setSize(sf::Vector2f(10, PADDLESIZE));
	rect.setFillColor(sf::Color(0,0,0));
	rect.setPosition(750,250);
}

		
void AIPaddle::move(int x){
	if (rect.getPosition().y < 0) {
		rect.setPosition(750,0);
	}
	else if (rect.getPosition().y > (600 - PADDLESIZE)){
		rect.setPosition(750,600 - PADDLESIZE);
	}
	
	rect.move(0, x);
}

void AIPaddle::reset(){
	this->rect.setPosition(750,250);
}
