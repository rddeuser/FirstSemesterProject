/*
* Author: Becca Deuser, Eric Stalcup, Alicia Rustan
* Date: 09/27/21
* Email: rddeuser@dmacc.edu, esstalcup@dmacc.edu
* Overview: This is the early working model of how a turn would work in the Medieval Game of Life
*/

#include <iostream>
#include <iomanip>
#include <lifespaces.h>
#include <player.h>
using namespace std;


// placeholder variables- remove as needed
int spotOnBoard = 0;
const int NUM_SPACES = 50;
string board[NUM_SPACES] = {
    "S", "-", "-", "-", "-", "-", "-", "-", "-", "|",
    "-", "-", "-", "-", "-", "-", "-", "-", "-", "|",
    "-", "-", "-", "-", "-", "-", "-", "-", "-", "|",
    "-", "-", "-", "-", "-", "-", "-", "-", "-", "|",
    "-", "-", "-", "-", "-", "-", "-", "-", "-", "W",
};
string typeOfSpaces[NUM_SPACES];

void displayBoard() {
    for (int i = 0; i < NUM_SPACES; i++) {
        if(board[i] == "|") {
            cout << board[i] << endl;
        }
        else {
            cout << board[i];
        }
    }
}

// function declaration
void turn();

void turn() {
    string input;

    // TODO: Add functionality to switch between player turns

    //display board
    displayBoard();
    cout << endl;

    // reset board display for player's last position
    if (board[spotOnBoard] == board[0]){
        board[spotOnBoard] = "S";
    } else {
    board[spotOnBoard] = "-";
    }

    cout << "Type \"move\" to move!" << endl;
    cin >> input;

    //display money, cards in hand, etc.
    // TODO: add card display function
    //declare and initialize spin
    int spin = rand() % 10 + 1;


    //display spin to user
    cout << "Spinning spinner..." << endl;
    cout << "You have spun a " << spin << endl;

    //check for long term investments
    //TODO: add long-term investment

    //move player number of spaces if possible
    spotOnBoard += spin;
    board[spotOnBoard] = "P";

    if (spotOnBoard >= NUM_SPACES) {
        spotOnBoard = NUM_SPACES - 1; //if spot would exceed index, move to last index
    }//end if


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

void winCheck(){
    // TODO: Add calculations for win function
}

int main() {
    int numOfPlayers = 0;
    string playerName;

    cout << endl << "Welcome to Medieval Game of Life!" << endl;
    cout << "You will start at the \"S\" piece, and your goal is to make it to the \"W\" piece at the end of the game board." << endl;
    cout << endl;

    // Create players and ask how many would like to play the game
    Player player1();
    Player player2();
    Player player3();
    Player player4();
    cout << "How many players would like to play?" << endl;
    cin >> numOfPlayers;
    cout << "Starting game!" << endl;
    // TODO: Add players starting info

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
