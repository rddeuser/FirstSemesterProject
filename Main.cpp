/*
Author: Becca Deuser
*Date: 09/27/21
*Email: rddeuser@dmacc.edu
*Overview: This is the early working model of how a turn would work in the Medieval Game of Life
*/

#include <iostream>
#include <iomanip>
using namespace std;

//placeholder variables- remove as needed
int spotOnBoard = 0;
const int NUM_SPACES = 150;
string board[NUM_SPACES];
string typeOfSpaces[NUM_SPACES];
int investment[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // array to store investment purchases. 0 indicates nobody has purchased it. 1 means player 1 and 2 means player 2. 
double player1Money = 0; // placeholder
double player2Money = 0; // placeholder

// Checks if rolled number investment has been purchases by a player, if so. They gain x amount of money. 
void checkInvestment(int roll) {
	// check if rolled number investment has been purchased.
	if (investment[roll - 1] != 0) {
		if (investment[roll - 1] == 1) {
			player1Money += 10000; // 10,000 is the value used in life not sure what the scale of points will be in the final game.
		}//end if
		else {
			player2Money += 10000; // 10,000 is the value used in life not sure what the scale of points will be in the final game.
		}//end else
	}//end if
}

// Menu for the player to purchase investments.
void purchaseInvestment() {
	int investNumber;
	string availableNum = "";

	for (int i = 0; i < 10; i++) {
		if (investment[i] == 0) {
			availableNum = availableNum + ", " + i;
		}//end if
	}//end for

	do
	{
		//Output which numbers are available for purchase.
		cout << "The Following Numbers are Available for Purchase: " << availableNum << endl;
		//User inputs number they would like to purchase
		cout << "Which Number Would You Like to Invest In (c to cancel): " << endl;
		cin >> investNumber;
	} while (investment[investNumber - 1] != 0); //input validation

	//Assignment the investment to the player.
	if (/*player 1's turn*/) {
		investment[investNumber - 1] = 1;
	}//end if
	else {
		investment[investNumber - 1] = 2;
	}//end else
}

//function declaration
void turn();

void turn() {
	//display board
	//TODO: add display function

	//display money, cards in hand, etc.
	// TODO: add card display function


	//offer chance to purchase spin investment for $50,000*
	// TODO: add menu for player to purchase investment


	//declare and initialize spin
	int spin = rand() % 10 + 1;

	//display spin to user
	cout << "Spinning spinner..." << endl;
	cout << "You have spun a " << spin << endl;

	//check for long term investments
	//TODO: add long-term investment
	checkInvestment(spin);

	//move player number of spaces if possible
	spotOnBoard += spin;

	if (spotOnBoard >= NUM_SPACES) {
		spotOnBoard = NUM_SPACES - 1; //if spot would exceed index, move to last index
	}//end if

	//change spot on board to represent player
	board[spotOnBoard] = "O"; //or however we're representing their spot on the board

	//display board
	// TODO: add display function

	//if statement to determine what it is they landed on
		if (typeOfSpaces[spotOnBoard] == "") {//TODO: add types of spaces
		//TODO: add function
	}//end if
	else if (typeOfSpaces[spotOnBoard] == "") {//TODO: add types of spaces
		//TODO: add function
	}//end else if
	else if (typeOfSpaces[spotOnBoard] == "") {//TODO: add types of spaces
		//TODO: add function
	}//end else if
	else if (typeOfSpaces[spotOnBoard] == "") {//TODO: add types of spaces
		//TODO: add function
	}//end else if
	else {
		//TODO: add function
	}//end else
	//TODO: Finish if statements
}


int main() {
	// Continue taking turns while player hasn't reached end of board
	while (spotOnBoard < NUM_SPACES - 1) {
		turn();
	}
	return 0;
}

/*------TESTED--------
*
*
*
*
*/