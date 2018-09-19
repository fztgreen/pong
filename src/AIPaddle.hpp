//Header file for AI Paddle
//By Zachary Greenfield
#ifndef AIPADDLE_HPP
#define AIPADDLE_HPP
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

//Paddle class header for pong game
class AIPaddle : public Paddle{        
        public:
			AIPaddle();
			void move(int x);
			void reset();
};


#endif
