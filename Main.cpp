/*
* Author: Becca Deuser, Eric Stalcup
* Date: 09/27/21
* Email: rddeuser@dmacc.edu, esstalcup@dmacc.edu
* Overview: This is the early working model of how a turn would work in the Medieval Game of Life
*/

#include <iostream>
#include <iomanip>
#include "Player.cpp"
#include "LifeSpaces.cpp"
using namespace std;

// placeholder variables- remove as needed
int spotOnBoard = 0;
const int NUM_SPACES = 50;
string board[NUM_SPACES] = { 
	"S", "-", "-", "-", "X", "-", "-", "X", "-", "|",
	"-", "-", "X", "-", "-", "-", "-", "-", "-", "|",
	"-", "-", "-", "-", "-", "-", "X", "-", "-", "|",
	"-", "-", "-", "X", "-", "-", "-", "-", "-", "|",
	"-", "-", "-", "-", "X", "-", "-", "-", "-", "W",
};
string typeOfSpaces[NUM_SPACES];

void displayBoard() {
	const int row = 10;
	for (int i = 0; i < NUM_SPACES; i++) {
		if(board[i] == "|") {
			cout << board[i] << endl;
		}
		else {
			cout << board[i];
		}
	}
	cout << endl;
}

bool investment[] = { false, false, false, false, false, false, false, false, false, false }; 
//Checks if spinned number has been invested by the player, if so. They gain some money. 
void checkInvestment(int spin) {
	//if the spinned number has been purchased they gain $100.
	if (investment[spin - 1] == true) {
		//TODO: add increment players money value
	}//end if
}
//Allows the player to purchase 1 number per turn to invest in.
void purchaseInvestment() {
	int investNumber;
	string availableNum = "";
	//creat list of avalible numbers to purchase
	for (int i : investment) {
		if (investment[i] == false) {
			availableNum += ", " + i;
		}//end if
	}//end for
	do //
	{
		//Output which numbers are available for purchase.
		cout << "The Following Numbers are Available for Purchase: " << availableNum << endl;
		//User inputs number they would like to purchase
		cout << "Which Number Would You Like to Invest In (-1 to cancel): " << endl;
		cin >> investNumber;
		if(investNumber == -1) {
			return;
		}
	} while (investment[investNumber - 1] == true); //input validation
	investment[investNumber - 1] == true; //update investment array after the player has choosen a number to invest in.
}

// function declaration
void turn();

void turn() {
	//display board
	//TODO: add display function

	//display money, cards in hand, etc.
	// TODO: add card display function
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
	displayBoard();
	
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