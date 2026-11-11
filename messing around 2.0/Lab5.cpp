/***************************************************************************
Ashton Grady

class:computer science

start/end date:(11/3/2026 - 11/10/2026)

Goal:Write a number-guessing game in which the computer selects a randomnumber in the range of 0 to 100, and users get a maximum of 20 
attempts to guess it. At the end of each game, users should be told whether they won or lost and then be asked whether they want to play 
again. When the user quits, the program should output the total number of wins and losses. To make the game more interesting, the program
should vary the wording of the messages that it outputs for winning, for losing, and for asking for another game. Create 10 different 
messages for each of these cases and use random numbers to choose among them. This application should use at least one Do- While loop and 
at least one Switch statement. Write your C++ code using good style and document comments. Only code that has been discussed in class is 
allowed for use. Code that is used that has not been discussed in class will result in significant point loss. Your source code file should 
be called Lab5.cpp.
****************************************************************************/
#include <stdlib.h>	
#include <time.h>	
#include <iostream>

// global variables
int win_num = 0;
int loss_num = 0;

// function prototypes
void menuS();
int options(int& option_);
void playgame();
int randomnumber_v();
int randomnumber();
void playagain();
void end();
void win();
void lose();
void playagain_m();


//-main-start--------------------------------------------------------------
int main(){

	std::cout << "this is a guessing game where you try to guess a number that is ramdamly picked between 1 and 100\n" << std::endl;
	std::cout << "menu________________\npress 1 to play game\npress 2 for options" << std::endl;
	menuS();
	
	return 0;
}
//-main-end----------------------------------------------------------------


//function definitions 
//------------------------------------------------------------------------- void menuS()
/*
precondition: program start with menuS and waits for input from user.

postcondition: runs options and playgame functions based on user input.
*/
void menuS() {
	int menu = 0;
	int option_att = 1;
	while (menu != 1) {
		menu = 0;
		
		std::cin >> menu;
		switch (menu) {

		case 1:
			playgame();
			break;

		case 2:
			if (option_att != 3) {
				options(option_att);
				option_att++;
			}
			else if (option_att == 3) {
				std::cout << "ok thats it, im hiting play for you" << std::endl; 
				playgame();
			}
			break;

		default:
			std::cout << "please enter a valid input" << std::endl;
			break;
		}
	}
}
//------------------------------------------------------------------------- int options(int &option_)
/*
precondition: runs when options is selected from menuS.

postcondition: exits with a message and count is added for seconed unique message and then returns to menuS.
*/
int options(int &option_) {
	
switch (option_) {

case 1:
	(option_ = 0);
	std::cout << "there are no options just hit play already" << std::endl;
	option_++;
	break;

case 2: (option_ = 1);
	std::cout << "I already told you there are no options just play the game" << std::endl;
	option_++;
	break;
	return 1;
}
}
//------------------------------------------------------------------------- int playgame();
/*
precondition: is selected from menuS and runs playgame. 

postcondition: exits with a won or lost message and runs playagain message and then playagain function.
*/
void playgame() {
std::cout << "playing game. . ." << std::endl;

	int tries = 0;
	int randomN = randomnumber_v();
	int guess = 0;
	bool won = false;
	
	do{
		std::cout << "\n\nplease enter your guess 1-100: ";
		std::cin >> guess;
		std::cout << "you entered: " << guess << std::endl;

		tries++;

		if (!(guess)) {
			std::cout << "If your not going to enter a number I dont want to play with you. \n\nNow go away.";
			tries = 3;
		}
		else {
			if (guess == randomN) {
				win();
				win_num++;
				won = true;
				break;
			}
			else if (guess < randomN) {
				std::cout << "you guessed too low." << std::endl;
			}
			else if (guess > randomN) {
				std::cout << "you guessed too high." << std::endl;
			}
		}
	} while (tries < 3);

	if (!(won)) {
		lose();
		loss_num++;
	}

	std::cout << "my number was:" << randomN << std::endl; 
	playagain_m();
	std::cout << "(1 for play again, 2 for exit): ";
	playagain();
	
}
//------------------------------------------------------------------------- void playagain();
/*
precondition: runs affter playgame and waits for user input.

postcondition: runs playgame or ends based on user input.
*/
void playagain() {
	int playagain;
	std::cin >> playagain;
	if (playagain == 1) { playgame(); }

	else if (playagain == 2) {
		std::cout << "Yeah thats what I thought, now beat it. " << std::endl;
		end();
	}
}
//------------------------------------------------------------------------- int randomnumber();
/*
just generates a random number between 1 and 10 for the win/lose/playagain unique messages.
*/
int randomnumber() {
	srand(time(NULL)); 
	int randomN = rand() % 10 + 1;
	return randomN;
}
//------------------------------------------------------------------------- int randomnumber_v();
/*
generates a random number between 1 and 100 for the guessing game.
*/
int randomnumber_v() {
	srand(time(NULL));
	int randomN = rand() % 100 + 1;
	return randomN;
}
//------------------------------------------------------------------------- void playagain_m();
/*
play again unique messages.
*/
void playagain_m() {
	int message = 0;
	randomnumber();
	message = randomnumber();
	if (message == 1)
		std::cout << "would you like to play again?" << std::endl;
	if (message == 2)
		std::cout << "you should play again." << std::endl;
	if (message == 3)
		std::cout << "you probly shoudnt play again. your not very good at this game. " << std::endl;
	if (message == 4)
		std::cout << "play agian, or dont i dot really care." << std::endl;
	if (message == 5)
		std::cout << "press one. unless your scared" << std::endl;
	if (message == 6)
		std::cout << "yawn. . . im bored. you should quit" << std::endl;
	if (message == 7)
		std::cout << "dont play agian im tired." << std::endl;
	if (message == 8)
		std::cout << "well that was a game all right. press 1 or dont i dont care." << std::endl;
	if (message == 9)
		std::cout << "i want to go to bed press 2." << std::endl;
	if (message == 10)
		std::cout << "double or nothing?" << std::endl;
}
//------------------------------------------------------------------------- void win();
/*
win unique messages.
*/
void win() {
	int win = 0;
	randomnumber();
	win = randomnumber();
	if (win == 1) 
		std::cout << "no fair you cheated!" << std::endl;
	if (win == 2)
		std::cout << "you won. . . yay i guess" << std::endl;
	if (win == 3)
		std::cout << "yeah yeah you won, yay good for you. . ." << std::endl;
	if (win == 4)
		std::cout << "you won, congrats. . ." << std::endl;
	if (win == 5)
		std::cout << "you guessed right, so yeah you win. yay good for you.\n\njerk." << std::endl;
	if (win == 6)
		std::cout << "you guessed right, good for you. . ." << std::endl;
	if (win == 7)
		std::cout << "ohh good for you, you won. yay. . ." << std::endl;
	if (win == 8)
		std::cout << "you won. . ." << std::endl;
	if (win == 9)
		std::cout << "your better than i thought." << std::endl;
	if (win == 10)
		std::cout << "ya ya you won you happy now?" << std::endl;
}
//------------------------------------------------------------------------- void lose();
/*
lose unique messages.
*/
void lose() {
	int lost = 0;
	lost = randomnumber();
	if (lost == 1)
		std::cout << "Ha I win!" << std::endl;
	if (lost == 2)
		std::cout << "I win im the best!" << std::endl;
	if (lost == 3)
		std::cout << "I win, man you suck at this game." << std::endl;
	if (lost == 4)
		std::cout << "I win!" << std::endl;
	if (lost == 5)
		std::cout << "not even close that makes you a losser." << std::endl;
	if (lost == 6)
		std::cout << "WRONG! LOSSER!!" << std::endl;
	if (lost == 7)
		std::cout << "WRONG!" << std::endl;
	if (lost == 8)
		std::cout << "you lose." << std::endl;
	if (lost == 9)
		std::cout << "you lost." << std::endl;
	if (lost == 10)
		std::cout << "you really suck at this game." << std::endl;
}
//------------------------------------------------------------------------- void end();
/*
precondition: runs when user selects to exit from playagain function.

postcondition: desplays the number of wins, losses, and total games played and then exits the program.
*/
void end() {
	std::cout << "number of wins:" << win_num << std::endl;
	std::cout << "number of losses:" << loss_num << std::endl;
	std::cout << "number of games played:" << win_num + loss_num << std::endl;
}