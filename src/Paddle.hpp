//Header file for Paddle
//By Zachary Greenfield
#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SFML/Graphics.hpp>
#include "Ball.cpp"

//Paddle class header for pong game
class Paddle{
        protected:
                sf::RectangleShape rect;
                
        public:
               Paddle();
			   sf::RectangleShape getRect();
			   void setColor(sf::Color color);
			   void setPosition(int x, int y);
			   void move(int x);
			   Ball hit(Ball);
			   void reset();
			   void hide();
};


#endif

