#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <../src/Ball.cpp>
#include <../src/Paddle.cpp>
#include <../src/AIPaddle.cpp>
#include <unistd.h>
#include <string>
#include <cmath>

//Defines input values and Window size
#define KEYUP -1
#define KEYDOWN 1
#define VIDEOWIDTH 800
#define VIDEOHEIGHT 600


//TODO List:
//Add less random reflection
//Add scaling window



int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(VIDEOWIDTH,VIDEOHEIGHT,32), "Pong", sf::Style::Titlebar | sf::Style::Close);

  //Game Objects
  Paddle pad;
  AIPaddle ai;
  Ball ball;
  
  //Scores
  int playerScore = 0;
  int AIScore = 0;
  
  //Indicates if game is over
  int over = 0;
  
  //Indicates if its the titlescreen
  int titlescreen = 1;
  
  //Loads in font
  sf::Font font;
  if (!font.loadFromFile("../resources/BEBAS.ttf"))
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
go.setFillColor(sf::Color::Cyan);

//Start screen text
sf::Text difficulty;
difficulty.setFont(font);
difficulty.setString("Press\n(1) for Hard\n(2) for Medium\n(3) for Easy");
difficulty.setCharacterSize(24);
difficulty.setStyle(sf::Text::Bold);
difficulty.setPosition(150,150);
difficulty.setFillColor(sf::Color::Black);

//End text
sf::Text end;
end.setFont(font);

//Timing based activities
sf::Clock clock; 
//Framerate (30fps)
float targetMs = 10000;
sf::Time deltaMs  = clock.getElapsedTime(); 

//Sound paddle hit
sf::SoundBuffer buffer;
if (!buffer.loadFromFile("../resources/cling_2.wav")){
	return -1;
}
sf::Sound ballSound;
ballSound.setBuffer(buffer);

//Player Score sound
sf::SoundBuffer buffer2;
if (!buffer2.loadFromFile("../resources/yes.wav")){
	return -1;
}
sf::Sound scoreSound;
scoreSound.setBuffer(buffer2);

//Ai score
sf::SoundBuffer buffer3;
if (!buffer3.loadFromFile("../resources/nextTime.wav")){
	return -1;
}
sf::Sound aiSound;
aiSound.setBuffer(buffer3);

//Player Wins
sf::SoundBuffer buffer4;
if (!buffer4.loadFromFile("../resources/congratz.wav")){
	return -1;
}
sf::Sound win;
win.setBuffer(buffer4);

//AI Wins
sf::SoundBuffer buffer5;
if (!buffer5.loadFromFile("../resources/lose.wav")){
	return -1;
}
sf::Sound aiWin;
aiWin.setBuffer(buffer5);

//Pause Barrier
int barrier = 0;

  // start main loop
  while(App.isOpen())
  { 
	//Update scoreboard visuals
	scoreboard.setString("Player: " + std::to_string(playerScore) + "\nAI: " + std::to_string(AIScore));

    // process events
    sf::Event Event;

    while(App.pollEvent(Event)){
		// Exit
		if(Event.type == sf::Event::Closed)
			App.close();
    
		//Scale window (sort of works)
		if (Event.type == sf::Event::Resized){
			//Event.size.width = Event.size.height;
			App.setSize(sf::Vector2u(Event.size.width,  ceil((Event.size.width * .75))));
		}
		
		//Pause game on loss of focus
		if (Event.type == sf::Event::LostFocus){
			barrier = 1;
		}

		//Resume game on focus
		if (Event.type == sf::Event::GainedFocus){
			barrier = 0;
		}	
	}
	
	if (!barrier){
		
		//Closes Application with Escape key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			App.close();
		}
		
		//If titlescreen is on, only allow numbers to be pressed, can quit
		if (titlescreen){
			//Hard
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
				targetMs = 1500;
				titlescreen = 0;
				go.setFillColor(sf::Color::Black);
				difficulty.setFillColor(sf::Color::Cyan);
			}
			//Medium
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
				targetMs = 2000;
				titlescreen = 0;
				go.setFillColor(sf::Color::Black);
				difficulty.setFillColor(sf::Color::Cyan);
			}
			//Easy
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
				targetMs = 4000;
				titlescreen = 0;
				go.setFillColor(sf::Color::Black);
				difficulty.setFillColor(sf::Color::Cyan);
			}
		}
		else{
			//Determine input to send to playerView
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				//Move Up
				pad.move(KEYUP);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				//Move Left
				pad.move(KEYDOWN);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
				//"Go" starts game
				if ((ball.getSpeedX() == 0) && (!over)){
					ball.setSpeed(1,1);
					go.setFillColor(sf::Color::Cyan);
				}
			}
		}
		
		//Restarts Game, variables, text, sounds, etc.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
				pad.reset();
				ai.reset();
				ball.reset();
				playerScore = 0;
				AIScore = 0;
				over = 0;
				end.setString("");
				difficulty.setFillColor(sf::Color::Black);
				go.setFillColor(sf::Color::Cyan);
				aiWin.stop();
				win.stop();
				titlescreen = 1;
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
		
		
//-------------HERE BEGINS GAME LOGIC---------------

		
		//Detect collisions between ball and paddles
		if ((ball.getBall().getPosition().x >= 750) && (ball.getBall().getPosition().x < 752)){
			ball = ai.hit(ball);
			ballSound.play();
		}
		else if ((ball.getBall().getPosition().x <= 50) && (ball.getBall().getPosition().x > 48)){
			ball = pad.hit(ball);
			ballSound.play();
		}	
		
		//Point player
		if (ball.getBall().getPosition().x > VIDEOWIDTH){
			playerScore += 1;
			ball.reset();
			pad.reset();
			ai.reset();
			scoreSound.play();
		}
		//Point AI
		else if (ball.getBall().getPosition().x < 0){
			AIScore += 1;
			ball.reset();
			pad.reset();
			ai.reset();
			aiSound.play();
		}
		
		//End game, if a paddle score is 11
		if (((playerScore == 11) || (AIScore == 11)) && (!over)){
			
			if (playerScore > AIScore){
				end.setString("Game Over!\nPlayerWins!\nPress 'R' to Play Again!!\nPress 'ESC' to QUIT");
				ballSound.stop();
				scoreSound.stop();
				win.play();
			}
			else if (playerScore < AIScore){
				end.setString("Game Over!\nAI Wins!\nPress 'R' to Try Again!!\nPress 'ESC' to QUIT");
				ballSound.stop();
				aiSound.stop();
				aiWin.play();
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
		
//---------HERE ENDS GAME LOGIC---------------
		
		
		//Draw entities
		App.clear(sf::Color::Cyan);
		App.draw(difficulty);
		App.draw(go);
		App.draw(pad.getRect());
		App.draw(ai.getRect());
		App.draw(end);
		App.draw(scoreboard);
		App.draw(ball.getBall());
		
		//Display
		App.display();
	}
	
	//Lock framerate to a cap
	deltaMs  = clock.getElapsedTime(); 
	//deltaMs *= difficulty;
	if (deltaMs.asMilliseconds() < targetMs){
		usleep(targetMs - deltaMs.asMilliseconds());
	}
	clock.restart();
  }

  // Done.
  return 0;
}





