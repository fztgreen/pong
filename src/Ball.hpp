//Header file for Ball
//By Zachary Greenfield
#ifndef BALL_HPP
#define BALL_HPP
#include <SFML/Graphics.hpp>
#include <random>

//Ball Class Header for Pong Game
class Ball{
        private:
                sf::CircleShape ball;
				std::default_random_engine generator;
				int speedX;
				int speedY;
				int getRandomNumber(int a, int b);
				
				
        public:
               Ball();
			   int getSpeedX();
			   int getSpeedY();
			   sf::CircleShape getBall();
			   void setColor(sf::Color color);
			   void setPosition(int x, int y);
			   sf::Vector2f getPosition();
			   void move(int x, int y);
			   void deflect();
			   void setSpeed(int x, int y);
			   void reset();
			   void hide();
			   
};


#endif

