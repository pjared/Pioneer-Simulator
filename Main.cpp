#include "Path.h"

void startGame() {	
	Path begin;
	begin.start();
}

void fAQ() {
	cout << "\n    ----------------------------------------------START OF FAQ---------------------------------------------    " << endl;
	cout << "\nThis type-to-play game is based off of real events that happened to pioneers along their journey.The \"stops\" along ";
	cout << "the route of the game are real places that the pioneers went through while going along the trail to Salt Lake Valley. While ";
	cout << "the events that are  garunteed to happen were based on real events, the events that are generated by chance did ";
	cout << "happen to the pioneers, but are inputted for games purposes only." << endl;
	cout << "END OF FAQ" << endl;
	cout << "\n    ------------------------------------------------END OF FAQ---------------------------------------------    " << endl;
	system("pause");
}

void how() {
	cout << "\n    ----------------------------------------------START OF HOW TO PLAY---------------------------------------------    " << endl;
	cout << "\nThis is a type-to-play game, ran off the console. All possible answers will be ";
	cout << "presented before hand, and you type your choice in lowercase" << endl;
	
	cout << "Remember to type answers in all lowercase" << endl;
	string userInput;
	bool goodOutput;
	do {
		cout << "Let's try a practice run, would you like to go left or right?\n    -Left\n    -Right" << endl;
		cout << "ENTER ANSWER: ";
		cin >> userInput;
		if (userInput == "left") {
			goodOutput = true;
		}
		else if (userInput == "right") {
			goodOutput = true;
		}
		else {
			cout << "Not a direction, try again." << endl;
			cout << "Remember to type in lowercase only." << endl;
			goodOutput = false;
		}
	} while (goodOutput == false);
	cout << "You chose: " << userInput << endl;
	cout << "\n    ------------------------------------------------END OF HOW TO PLAY---------------------------------------------    " << endl;
	system("pause");
}

int main() {
	string userInput;
	cout << "Welcome to Pioneer simulator" << endl;
	cout << "This is a command line based game where you will type in your answers to choose your path and continue playing" << endl;
	/*might want to implement a Menu where user will be able to choose from start, FAQ, how to play, and quit*/
	do {
		cout << "\nThese are your options to choose from:\n    -FAQ\n    -Start\n    -Quit" << endl; // \n    -HowToPlay(Type \"how\")
		cout << "Remember to type answers in all lowercase" << endl;
		cout << "ENTER ANSWER: ";
		cin >> userInput;
		if (userInput == "faq") {
			fAQ();
		}
		else if (userInput == "start") {
			how();
			startGame();
		}
		else if (userInput == "quit") {}
		//else if (userInput == "rand") { getRand(); }
		else {
			cout << "Not an option, try again." << endl;
		}
	} while (userInput != "quit");
	cout << "Thanks for playing!" << endl;
	system("pause");
	return 0;
}

// CTRL + FN + F5