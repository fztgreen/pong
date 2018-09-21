#include <SFML/Graphics.hpp>
#include <../src/Ball.cpp>
#include <../src/Paddle.cpp>
#include <../src/AIPaddle.cpp>
#include <unistd.h>
#include <string>

//Defines input values and Window size
#define KEYUP -1
#define KEYDOWN 1
#define VIDEOWIDTH 800
#define VIDEOHEIGHT 600


//TODO List:
//Add Sound
//Add less random reflection
//Add scaling window



int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(VIDEOWIDTH,VIDEOHEIGHT,32), "Pong", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

  Paddle pad;
  AIPaddle ai;
  Ball ball;
  ball.setSpeed(0,0);
  int playerScore = 0;
  int AIScore = 0;
  int over = 0;
  
  sf::Font font;
  if (!font.loadFromFile("BEBAS.ttf"))
{
    // error...
}
  
//Scoreboard text
sf::Text scoreboard;
scoreboard.setFont(font);
scoreboard.setString("Player: " + std::to_string(playerScore) + " AI: " + std::to_string(AIScore));
scoreboard.setCharacterSize(24);
scoreboard.setFillColor(sf::Color::Black);
scoreboard.setStyle(sf::Text::Bold);

//Start screen text
sf::Text go;
go.setFont(font);
go.setString("Press 'G' to Begin Ball Movement");
go.setCharacterSize(24);
go.setStyle(sf::Text::Bold);
go.setPosition(250,100);
go.setFillColor(sf::Color::Black);

//End text
sf::Text end;
end.setFont(font);

//Timing based activities
sf::Clock clock; 
//Framerate (30fps)
float targetMs = 2000;
sf::Time deltaMs  = clock.getElapsedTime(); 


  
  // start main loop
  while(App.isOpen())
  { 
	scoreboard.setString("Player: " + std::to_string(playerScore) + "\nAI: " + std::to_string(AIScore));

    // process events
    sf::Event Event;

	
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
		App.close();
    }
	
	//Closes Application with Escape key
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		App.close();
	}
	
	//Determine input to send to playerView
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		//Move Up
		pad.move(KEYUP);
    }
     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      	//Move Left
		pad.move(KEYDOWN);
    }
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
      	//Restarts Game
		pad.reset();
		ai.reset();
		ball.reset();
		playerScore = 0;
		AIScore = 0;
		over = 0;
		end.setString("");
		go.setFillColor(sf::Color::Black);
    }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
      	//"Go" starts game
		if ((ball.getSpeedX() == 0) && (!over)){
			ball.setSpeed(1,1);
			go.setFillColor(sf::Color::Cyan);
		}
    }


	
	//AI move
	if ((ball.getBall().getPosition().y - 50) > ai.getRect().getPosition().y){
		ai.move(KEYDOWN);
	}
	else{
		ai.move(KEYUP);
	}
	
	//Update ball position
	ball.move(ball.getSpeedX(), ball.getSpeedY());
	
	
	//Detect collisions between ball and paddles
	if ((ball.getBall().getPosition().x >= 750) && (ball.getBall().getPosition().x < 752)){
		ball = ai.hit(ball);
	}
	else if ((ball.getBall().getPosition().x <= 50) && (ball.getBall().getPosition().x > 48)){
		ball = pad.hit(ball);
	}
	
	
	//Point player
	if (ball.getBall().getPosition().x > VIDEOWIDTH){
		playerScore += 1;
		//reset();
		ball.reset();
		pad.reset();
		ai.reset();
	}
	//Point AI
	else if (ball.getBall().getPosition().x < 0){
		AIScore += 1;
		ball.reset();
		pad.reset();
		ai.reset();
	}
	
	
	//-->
	
	
	
	
	//Draw Views
	App.clear(sf::Color::Cyan);


	
	//End game, if a paddle score is 11
	if ((playerScore == 11) || (AIScore == 11)){
		
		if (playerScore > AIScore){
			end.setString("Game Over!\nPlayerWins!\nPress 'R' to Play Again!!\nPress 'ESC' to QUIT");
		}
		else{
			end.setString("Game Over!\nAI Wins!\nPress 'R' to Try Again!!\nPress 'ESC' to QUIT");
		}
		
		//Resets the positions of entities
		pad.reset();
		ai.reset();
		ball.reset();
		
		//Loads end text into buffer
		end.setCharacterSize(24);
		end.setFillColor(sf::Color::Black);
		end.setStyle(sf::Text::Bold);
		end.setPosition(350,100);
		
		//Set game state to over
		over = 1;
		
		//Destroy objects
	}
	
	//Draw entities
	App.draw(go);
	App.draw(ball.getBall());
	App.draw(pad.getRect());
	App.draw(ai.getRect());
	App.draw(end);
	App.draw(scoreboard);
	
	
	
    //Display
    App.display();
	
	
	//Lock framerate to a cap
	deltaMs  = clock.getElapsedTime(); 
	if (deltaMs.asMilliseconds() < targetMs){
		usleep(targetMs - deltaMs.asMilliseconds());
	}
	clock.restart();
  }

  // Done.
  return 0;
}





