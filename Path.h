#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Path {
private:
	string currentLoc = "Navoo";
	string nextLoc = "Mount Pisgah";
	int famNum = 6; // make this a random number between 3 and 6, family number will deplete food faster
	int numFood = 3;
	int helpedMan = 0; //0 = didn't get event, 1 = didn't help, 2 = Did help
	int wheelHelp = 0; //0 = didn't get event, 1 = didn't help, 2 = Did help
	int gotWolf = false; //0 = didn't get event, 1 = didn't help, 2 = Did help
	bool hasWolf = false;
	bool wardedFox = false;
public:
	int getRand() {
		srand(time(NULL));
		int randNum = rand();
		return randNum;
	}

	void start() {
		cout << "\n    ----------------------------------------------START OF GAME : NAUVOO------------------------------------    " << endl;
		currentLoc = "Navoo";
		cout << "The Missouri Executive Order 44 has just been issued by Governer Boggs and you have just moved to Nauvoo with your family. You have been ";
		cout << "told by Brigham to lead a handcart company West to Salt Lake valley to be one of the first groups to go see the new promised land. ";
		cout << "Although reluctant to leave after just relocating, you have faith to do as commanded." << endl;

		cout << "\nYou start your journey in " << currentLoc << " with " << famNum << " family members." << endl;		
		//the first trek can be an outline of how the game will work
		//coding an outline for how events will work
		cout << "As you play the game, your last location will be marked so you will have a checkpoint in case you lose. You lose when your hunger ";
		cout <<  "hits 0. As you go from location to location, there is a random chance for events for happen, and some locations have garunteed events to happen. ";
		cout << "Your choices will influence you gameplay. While some this is left to chance, your choices can result in losing family members or substantial ";
		cout << "amounts of food. After reaching a new location, you will be given a small menu to go hunting, play a pioneer game, sing, or sleep. Keep in mind ";
		cout << "that you can only choose one thing to do when given the menu." << endl;
		cout << "Have you read the basics of the game? Answer \"yes\" if so (without the quotation marks)" << endl;
		string userInput;
		do {
			cout << "ENTER ANSWER: ";
			cin >> userInput;
		} while (userInput != "yes");
		cout << "Great! Your handcart company starts it's journey towards Mount Pisgah" << endl;
		system("pause");
		mountPisgah();

	}
	void mountPisgah() {
		currentLoc = "Mount Pisgah";
		//nextLoc = "Winter Quarters";
		cout << "\n    ----------------------------------------------MOUNT PISGAH------------------------------------    " << endl;
		cout << "\nYou have made it to " << currentLoc << "." << endl;
		cout << "Now the menu that pops up at every location stop will happen." << endl;
		system("pause");
		campStop();
		system("pause");

		cout << "You come to a fork in the road. The sign that points to the left says \"Winter Quarters\" ";
		cout << "And the sign the points to the right says \"Confluence Point\"." << endl;		
		string userInput;
		bool goodOutput;
		do {
			cout << "Would you like to go:\n    -Left\n    -Right" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "left") {
				goodOutput = true;
				winterQuarters();
			}
			else if (userInput == "right") {
				goodOutput = true;
				confluencePoint();
			}
			else {
				cout << "Not a direction, try again." << endl;
				cout << "Remember to type in lowercase only." << endl;
				system("pause");
				goodOutput = false;
			}
		} while (goodOutput == false);
	}
	void winterQuarters() {
		currentLoc = "Winter Quarters";
		//nextLoc = "Confluence Point";
		cout << "\n    ----------------------------------------------WINTER QUARTERS------------------------------------    " << endl;
		cout << "\nYou have made it to " << currentLoc << "." << endl;


		//Garunteed event
		kidWander();
		system("pause");
		fortLaurence();
	}

	void confluencePoint() {
		currentLoc = "Confluence Point";
		cout << "\n    ----------------------------------------------CONFLUENCE POINT------------------------------------    " << endl;
		cout << "\nYou have made it to " << currentLoc << "." << endl;
		system("pause");
		campStop();
		system("pause");

		//Garunteed event
		childBirth();

		system("pause");
		fortLaurence();
	}
	void fortLaurence() {
		currentLoc = "Fort Laurence";
		cout << "\n    ----------------------------------------------FORT LAURENCE------------------------------------    " << endl;
		cout << "\nYou have made it to " << currentLoc << "." << endl;
		system("pause");
		campStop();
		system("pause");

		// Garunteed random event:
		chooseEvent();

		int chosenPath = splitPath();
		system("pause");
		if (chosenPath == 1) { //left - Indians
			indepRock();
		}
		if (chosenPath == 2) { // right - Wolf
			southPass();
		}		
	}
	void indepRock() {
		currentLoc = "Independance Rock";
		cout << "\n    ----------------------------------------------INDEPENDANCE ROCK--------------------------------    " << endl;
		cout << "\nYou have made it to " << currentLoc << "." << endl;
		system("pause");
		campStop();
		system("pause");

		//Chance to get indian villiage or Indian attack


		system("pause");
		echoCanyon();
	}
	void southPass() {
		currentLoc = "South Pass";
		nextLoc = "Echo Canyon";
		cout << "\n    ----------------------------------------------SOUTH PASS------------------------------------    " << endl;
		cout << "\nYou have made it to " << currentLoc << "." << endl;
		system("pause");
		campStop();
		system("pause");

		//If they don't have the pet wolf, then there will be an attack		

		system("pause");
		echoCanyon();
	}
	void echoCanyon() {
		currentLoc = "Echo Canyon";
		nextLoc = "Salt Lake Valley";
		cout << "\n    ----------------------------------------------ECHO CANYON------------------------------------    " << endl;
		cout << "\nYou have made it to " << currentLoc << "." << "You know that the next stop will be " << nextLoc << "!" << endl;
		system("pause");
		campStop();
		system("pause");

		// random event:
		chooseEvent();

		system("pause");
		end();
	}

	void end() {
		cout << "\n    ----------------------------------------------SALT LAKE VALLEY-------------------------------    " << endl;
		cout << "\nYou have made it to salt Lake Valley! Great job" << endl;
		printStats();
		cout << "\n    ------------------------------------------------END OF GAME---------------------------------------------    " << endl;
		system("pause");
	}

	void printStats() {
		cout << "You ended with " << famNum << " family members and " << numFood << " food left." << endl;
		//WHEEL wheelHelp
		if (wheelHelp == 1) {
			cout << "You decided to have the company go ahead of you instead of getting help. One man army. You also had a fox invade your camp, " << endl;
			if (wardedFox == true) {
				cout << "but your pet wolf warded him off." << endl;
			}
			else {
				cout << "and lost food." << endl;
			}			
		}
		if (wheelHelp == 2) {
			cout << "When in need of help and your wheel broke, you had your company stop and help you. Hooray for teamwork." << endl;
		}
		//0 = didn't get event, 1 = didn't get help, 2 = Did get help
		//MAN 
		if (helpedMan == 1) {
			cout << "When a man was in need, you instead walked past him. Good job you saint." << endl;
		}
		if (helpedMan == 2) {
			cout << "When a man was in need, you stopped and save his life. Good job you saint." << endl;
		}
		//0 = didn't get event, 1 = didn't help, 2 = Did help
		//WOLF
		if (gotWolf == true) {
			cout << "When going back to get your son, you added a baby wolf to your family." << endl;
			if (hasWolf == true) {
				cout << "You kept him all the way to Salt Lake." << endl;
			}
			else {
				cout << "The baby was returned to it's family and you avoided being attacked by wolves." << endl;
			}
		}
		//gotWolf
	}

	// Finish song
	void sing() {
		int randNum = (getRand() % 2);
		if (randNum == 0) {
			cout << "Country Roads. Take me home." << endl;
			cout << "Almost heaven, West Virginia" << endl;
			cout << "Blue Ridge Mountains, Shenandoah River" << endl;
			cout << "Life is old there, older than the trees" << endl;
			cout << "Younger than the mountains, growing like a breeze" << endl;
			cout << "Country roads, take me home" << endl;
			cout << "To the place I belong" << endl;
			cout << "West Virginia, mountain mama" << endl;
			cout << "Take me home, country roads" << endl;
		}
		else {
			cout << "Pioneer children sang as they walked and walked and walked and walked. " << endl;
			cout << "	Pioneer children sang as they walked and walked and walked and walked. " << endl;
			cout << "They washed at streams and worked and played.  " << endl;
			cout << "	Sundays they camped and read and prayed. " << endl;
			cout << "Week after week, they sang as they walked and walked and walked and walked and walked. " << endl;
		}
	}

	//Add randomizer when done
	void hunt() {
		if (hasWolf == true) {
			int randNum = (getRand() % 2);
			//can get a food between 2 & 3
			if (randNum == 0) {
				cout << "Your pet wolf leads you to group of rabbits. +2 Food" << endl;
				numFood += 2;
			}
			else {
				cout << "Your pet wolf leads you to deer drinking water by a river. +3 Food" << endl;
				numFood += 2;
			}
		}
		else {
			int randNum = (getRand() % 3);
			
			// can get between 1-3
			if (randNum == 0) {
				cout << "You check your traps to a rabbit. +1 Food" << endl;
				numFood += 1;
			}
			else if (randNum == 1) {
				cout << "You check your traps to a fox. +2 Food" << endl;
				numFood += 2;
			}
			else {
				cout << "Along the way to check your traps, you see a deer. You aim your musket and take it down. +3 Food" << endl;
				numFood += 3;
			}
		}
	}

	//Need to do randomizer to randNum
	void cornHole() {
		int userPower;
		int numAces = 0;
		int randNum = ((getRand() % 3) + 5);
		bool goodInput = false;
		cout << "\n    ----------------------------------------------MINIGAME: CORNHOLE---------------------------    " << endl;
		cout << "You get 3 shots. If the power level you choose matches the random number generated you make it." << endl;
		do {
			cout << "Choose a power level from 5-7" << endl;
			cin >> userPower;
			if (userPower >= 5 && userPower <= 7) {
				goodInput = true;
			}
			else {
				goodInput = false;
				cout << "Not an input. Try again." << endl;
			}
		} while (goodInput == false);
		
		if(userPower == randNum) {
			cout << "Perfect shot!" << endl;
			numAces += 1;
		}
		else {
			cout << "Miss!" << endl;
		}

		do {
			cout << "Choose a power level from 5-7" << endl;
			cin >> userPower;
			if (userPower >= 5 && userPower <= 7) {
				goodInput = true;
			}
			else {
				goodInput = false;
				cout << "Not an input. Try again." << endl;
			}
		} while (goodInput == false);
		if (userPower == randNum) {
			cout << "Perfect shot!" << endl;
			numAces += 1;
		}
		else {
			cout << "Miss!" << endl;
		}
		
		do {
			cout << "Choose a power level from 5-7" << endl;
			cin >> userPower;
			if (userPower >= 5 && userPower <= 7) {
				goodInput = true;
			}
			else {
				goodInput = false;
				cout << "Not an input. Try again." << endl;
			}
		} while (goodInput == false);

		if (userPower == randNum) {
			cout << "Perfect shot!" << endl;
			numAces += 1;
		}
		else {
			cout << "Miss!" << endl;
		}

		cout << "\nYou made " << numAces << "/3 shots." << endl;

		cout << "\n    ----------------------------------------------END OF MINIGAME------------------------------    " << endl;
		system("pause");
	}

	void hungerCheck() {
		if (numFood == 0) {
			cout << "\n    -----------------------------------------OUT OF FOOD: GAME OVER------------------------    " << endl;
			cout << "You ran out of food, you have lost the game. The page will now exit. Please hit play again if you'd like to do another game" << endl;
			system("pause");
			exit(0);
		}
	}
	//Done
	void campStop() {
		hungerCheck();
		cout << "Your company all gets in a large circle to form camp and rest." << endl;
		
		cout << "You are at " << numFood << " food left." << endl;
		string userInput;
		bool goodOutput;
		do {
			cout << "Would you like to:\n    -Hunt\n    -Play a game(answer: play)\n    -sing\n    -sleep" << endl;
			cout << "Please remember that you only get to do one option" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "hunt") {
				goodOutput = true;
				
				hunt();
			}
			else if (userInput == "play") {
				goodOutput = true;
				cornHole();
			}
			else if (userInput == "sing") {
				goodOutput = true;
				sing();
			}
			else if (userInput == "sleep") {
				goodOutput = true;
			}
			else {
				cout << "\nNot an option, try again.\n" << endl;
				//cout << "Remember to type in lowercase only." << endl;
				goodOutput = false; 
				//system("pause");
			}
		} while (goodOutput == false);
		cout << "You get your family together for a nice meal. -1 Food" << endl;
		numFood -= 1;
		cout << "You now have " << numFood << " food left." << endl;
	}

	/*GARUNTEED EVENTS*/
	//Done
	void childBirth() {
		famNum += 1;
		cout << "While along the trail, your pregnant wife goes into labor. You now have " << famNum << " family memebers" << endl;
	};

	//Done
	void kidWander() {
		cout << "While walking along the path, your spouse tells you that one of your boys have gone missing. You assume they ";
		cout << "have wandered off the path while walking, and are now no longer with the group." << endl;
		
		bool inputCheck;
		string userInput;
		do {
			cout << "Would you like to : \n    -Hope he makes his way back(answer: hope)\n    -Go looking for him(answer: look)" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "hope") {
				cout << "\nHmmm. Not sure why you chose that one." << endl;
				cout << "While you hoped that the boy would have gotten picked up by another family in the handcart company, ";
				cout << "you don't see him at the campfire that night. What a good parent you are." << endl;
				famNum -= 1;
				cout << "You now have " << famNum << " family memebers" << endl;
				inputCheck = true;
			}
			else if (userInput == "look") {
				cout << "\nYou head back while your family continues to trek along. You take some food in case the journey is long. ";
				cout << "You find your son petting a small wolf that has also wandered from it's pack. You feed the wolf food you brought. ";
				cout << "You now have added a pet to the family and will make hunting easier. ";
				cout << "The wolf might also need to be returned to it's family. This might be useful later on." << endl;
				hasWolf = true;
				gotWolf = true;
				inputCheck = true;
			}
			else {
				cout << "Remember to type in lowercase only." << endl;
				cout << "Not an option, try again." << endl;
				system("pause");
				inputCheck = false;
			}
		} while (inputCheck == false);
	}

	//Need to add randomizer in left path
	int splitPath() {
		cout << "While along the trail, theres a fork in the road. It's not marked on you map of where your supposed to go.";
		cout << "On the left you see a tree with a small carving, likely the territory marking of Native Americans. The carving is unknown ";
		cout << "to be of a hostile or friendly tribe." << endl;
		cout << "On your right up ahead further on the path you see a deer carcass on the trail, torn apart likely by wolves." << endl;
		
		bool inputCheck;
		string userInput;
		do {
			cout << "Which path would you like to go?\n    -Left\n    -Right" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "left") {
				int randNum = (getRand() % 2);
				cout << "\nYour company takes the left. Many people seemed worried after noticing the carving themselves.\n" << endl;
				if (randNum == 0) {
					indianAttack();
				}
				else {
					indianTrade();
				}
				inputCheck = true;
				return 1;
			}
			else if (userInput == "right") {
				cout << "\nYour company walks around the dead deer. In the distance, you see a single wolf on the top of a cliff" << endl;
				wolfAttack();
				inputCheck = true;
				return 2;
			}
			else {
				cout << "Not a direction, try again." << endl;
				inputCheck = false;
				//system("pause");
			}
		} while (inputCheck == false);
		//cout << "Well that wasn't suppose to happen" << endl;
		return 0;
	}

	void wolfAttack() {
		cout << "\nWhile your handcart company has gathered to rest, you hear howls off in the distance getting closer and closer ";
		cout << "Eyes glow around your camp." << endl;
		if (hasWolf == true) {
			cout << "The baby wolf begins to howl and the sourrounding wolves quiet down. The baby wolf licks your face before walking";
			cout << " out into the dark to join its family. The other wolves ignore you." << endl;
			hasWolf = false;
		}
		else {
			bool inputCheck;
			string userInput;
			do {
				cout << "What would you like to do?\n    -Fight\n    -Warn the wolves off with fire(answer: warn)\n" << endl;
				cout << "Remember to type answers in all lowercase" << endl;
				cout << "ENTER ANSWER: ";
				cin >> userInput;
				if (userInput == "fight") {
					cout << "The company fires their muskets where they see eyes. You hear a cry after firing your musket at eyes.";
					cout << "The wolves howl one last time and leave." << endl;
					numFood += 2;
					cout << "You now have " << numFood << " food from the killed wolf." << endl;
					inputCheck = true;
				}
				else if (userInput == "warn") {
					cout << "You craft a makeshift torch along with the others and wave them at the wolves as they get closer." << endl;
					cout << "They are warded off for now, but come back during the night and kill one of your oxen while the company is asleep." << endl;
					numFood -= 1;
					cout << "You now have " << numFood << " food." << endl;
					inputCheck = true;
				}
				else {
					cout << "Not an option, try again." << endl;
					inputCheck = false;
					system("pause");
				}
			} while (inputCheck == false);
		}
	}
	
	// Add randomizer in prayer
	void indianAttack() {
		cout << "\nWhile your handcart company has gathered to rest, you hear multiple screeches accompanying the ";
		cout << "stomping of hooves on the ground around you. You realize that indians are circling around you." << endl;
		
		bool inputCheck;
		string userInput;
		do {
			cout << "What would you like to do?\n    -Fight\n    -Hope they go away(answer: hope)\n    -Pray" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "fight") {
				string userInput2;
				do {
					cout << "Would you like to: \n    -Fire a warning shot(answer: warn)\n    -Prepare the men for close quarter combat(answer: prepare)" << endl;
					cin >> userInput2;
					if (userInput2 == "warn") {
						cout << "The natives are scared of the loud pop and the flash of light. They leave." << endl;
						inputCheck = true;
					}
					else if (userInput2 == "prepare") {
						cout << "The natives get closer and closer and a fight ensues. They leave soon after but you discover ";
						cout << "that your eldest son has been fatally wounded." << endl;
						famNum -= 1;
						cout << "You now have " << famNum << "family members. You bury your eldest son at your next camp stop." << endl;
						inputCheck = true;
					}
					else {
						cout << "Not an option, try again." << endl;
						inputCheck = false;
						system("pause");
					}
				} while (inputCheck == false);
				inputCheck = true;
			}
			else if (userInput == "hope") {
				//steal all of your food
				cout << "The indians sorround you and steal all of your food." << endl;
				numFood = 1;
				cout << "You now have " << numFood << "food left." << endl;
				inputCheck = true;
			}
			else if (userInput == "pray") {
				int randNum = (getRand() % 2);
				if (randNum == 1) {
					cout << "The noise dies down and the Indians leave without continuing their attack. Only you know why they stopped." << endl;
				}
				else {
					cout << "The indians sorround you and steal all of your food." << endl;
					numFood = 1;
					cout << "You now have " << numFood << "food left." << endl;
				}
				inputCheck = true;
			}
			else {
				cout << "Not an option, try again." << endl;
				inputCheck = false;
				system("pause");
			}
		} while (inputCheck == false);
	}

	//Done
	void indianTrade() {
		cout << "You see an Indian village up ahead. A native approaches you and speaks to a language you cannot understand. ";
		cout << "You can't tell wether the man is friendly or hostile due to a blank expression on his face" << endl;
		bool inputCheck;
		string userInput;
		do {
			cout << "What would you like to do?\n    -Wave to him(answer: wave)\n    -Ignore the man(answer: ignore)\n" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "ignore") {
				cout << "You smile while passing the strange man. He gets your message and walks back to his village" << endl;
				inputCheck = true;
			}
			else if (userInput == "wave") {
				cout << "The man offers you some meat and points to the animal pelts you have drying on top of your cart. +2 Food" << endl;
				numFood += 2;
				cout << "You now have " << numFood << " food." << endl;
				inputCheck = true;
			}
			else {
				cout << "Not an option, try again." << endl;
				inputCheck = false;
				system("pause");
			}
		} while (inputCheck == false);
	}

	/*EVENTS*/
	//Need to finish these, along with add a trade function for wandering man and indian village -
	// All of these should only be able to happen once
	
	//randomizer in choosing
	void chooseEvent() {
		bool relief = false;
		bool wheel = false;
		bool tradesman = false;
		bool hurtMan = false;
		int randNum = (getRand() % 4);
		if (randNum == 0 && relief == false) {
			reliefCart();
			relief = true;
		}
		else if (randNum == 1 && wheel == false) {
			wheelBreak();
			wheel = true;
		}
		else if (randNum == 2 && tradesman == false) {
			wanderingTradesman();
			tradesman = true;
		}
		else if (randNum == 3 && hurtMan == false) {
			manToHelp();
			hurtMan = true;
		}
	}

	//Done
	void reliefCart() {
		numFood += 5;
		cout << "In the distance you see a small group of handcarts, the cart leading the group has a red cross on the side of the cart. ";
		cout << "They are here with food."<< endl;
		cout << "You have been given +5 food. Your food is now at " << numFood << "." << endl;
		//Somehow max out hunger, but still can lose it to an indian/wolf attack
	}
	
	//Done
	void wheelBreak() {
		cout << "Your cart goes over a bump and you hear a crack. You ignore it at first, but while going over a pothole your ";
		cout << "wheel breaks and your cart now stuck. You get other members to help carry the cart to the side of the road." << endl;
		
		
		bool inputCheck;
		string userInput;
		do {
			cout << "How would you like to approach him?\n    -Tell the company to contine without you(answer: continue)";
			cout << "\n    -Have the company stop to help you(answer: stop)" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "stop") {
				wheelHelp = 2;
				cout << "The company stops with you and the men gather to help fix the wheel. It is done in less than an hour" << endl;
				inputCheck = true;
			}
			else if (userInput == "continue") {
				wheelHelp = 1;
				cout << "The company leaves and you fix the wheel, but have to camp for the night without them. ";
				cout << "A fox comes in to steal some food."<< endl;
				if (hasWolf == true) {
					wardedFox = true;
					cout << "Your pet wolf wakes up and wards off the fox. You don't lose any food." << endl;
				}
				else {
					if (numFood <= 2) {
						numFood -= 1;
						cout << "-1 Food. You now have " << numFood << "food." << endl;
					}
					else {
						numFood -= 2;
						cout << "-2 Food. You now have " << numFood << "food." << endl;
					}
				}
				inputCheck = true;
			}
			else {
				cout << "Not an option, try again." << endl;
				inputCheck = false;
				system("pause");
			}
		} while (inputCheck == false);
	}
	
	//Done
	void manToHelp() {
		helpedMan = 1; //0 = didn't get event, 1 = didn't help, 2 = Did help
		cout << "Along the path you see a man lying face down on the path. At first he seems dead, but he is stil breathing" << endl;
		
		bool inputCheck;
		string userInput;
		do {
			cout << "Would you like to:\n    Help the man(answer: help - cost: -1 food)\n    -Not my problem, someone else will help(answer: ignore)" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "help") {
				helpedMan = 2;
				cout << "Help the man up, bandage him " << endl;
				numFood -= 1;
				cout << "You now have " << numFood << " food." << endl;
				inputCheck = true;
			}
			else if (userInput == "ignore") {
				cout << "The company wonders why you didn't stop to help the man but follow your example and leave him there. ";
				cout << "The man lies there longer until he passes away. Hope you feel good about yourself now"<< endl;
				inputCheck = true;
			}
			else {
				cout << "Not an option, try again." << endl;
				inputCheck = false;
				system("pause");
			}
		} while (inputCheck == false);
	}

	//Done
	void wanderingTradesman() {
		cout << "While traveling a long the trail, a man that looks like a game hunter approaches your company" << endl;
		
		bool inputCheck;
		string userInput;
		do {
			cout << "How would you like to approach him?\n    -Greet\n    -Ignore\n    -Ward off(answer: ward)" << endl;
			cout << "Remember to type answers in all lowercase" << endl;
			cout << "ENTER ANSWER: ";
			cin >> userInput;
			if (userInput == "greet") {
				cout << "The man stops to talk to you asking to trade. You give him some supplies in exchange for meat" << endl;
				numFood += 2;
				cout << "You now have " << numFood << " food." << endl;
				inputCheck = true;
			}
			else if (userInput == "ignore") {
				cout << "The man waves to you as you pass him" << endl;
				inputCheck = true;
			}
			else if (userInput == "ward") {
				cout << "You tell the man to keep his distance. He sighs and walks away, ";
				cout << "it sure would have been nice to trade with him" << endl;
				inputCheck = true;
			}
			else {
				cout << "Not an option, try again." << endl;
				inputCheck = false;
				system("pause");
			}
		} while (inputCheck == false);
	}	

};

#endif
