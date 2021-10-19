/* Author: Noah Clark
 * Originally Created: 09/28/2021
 * Date Last Updated: 10/19/2021
 * Email: npclark@dmacc.edu
 * Overview: Defines various game spaces and manipulates the Player's variables
 */

/* Update by: Alicia Rustan
 * Date: 10/12/2021
 * color variables on spaces wasn't working. Changed to a virtual function that will be inherited by all tiles.
 */

#include <iostream>
#include <string>
#include "Player.cpp"
using namespace std;

// Base Class
class Space {
	string display; // This is the flavor text for the space; "Won a beauty contest, earned $5,000," "Twins! Draw a LIFE card," "Midlife Crisis, draw a new career," etc
	string color; //placeholder for a space's color
	int spaceID; // unique identifier for each space

	public:
		string getDisplay() {
			return display;
		}
		string getColor() {
			return color;
		}
		int getSpaceID() {
			return spaceID;
		}
		void setDisplay(string d) {
			display = d;
		}
		void setColor(string c) {
			color = c;
		}
		void setSpaceID(int s) {
			spaceID = s;
		}

		// Method to be overloaded by other spaces
		void spaceEffect(Player p);
		virtual void Color() = 0;
};

// For salary spaces
class SalarySpace : public Space {
	string color = "green";
	void Color() = green;

	public:
		// Add player's salary to player balance
		void spaceEffect(Player p) {
			p.addIncome();
		}
};

//-------------------------------------------------------------------------------------------------------------------------------------

// Generic subclass for orange spaces
class OrangeSpace : Space {
	string color = "orange";
	void Color() = orange;
};
// For spaces that change the player's balance
class BalanceChange : OrangeSpace {
	double changeAmount; // The amount the player's balance changes. Negative values are used for penalties to the player's balance; positive for bonuses
	public:
		double getChangeAmount() {
			return changeAmount;
		}
		void setChangeAmount(double c) {
			changeAmount = c;
		}

		void spaceEffect(Player p) {
			p.makePayment(-changeAmount);
		}
};
// Space that changes effect depending on if player or other players have a matching career
class CareerSpace : BalanceChange {
	string spaceCareer; // What career is associated with the space

	public:
		string getSpaceCareer() {
			return spaceCareer;
		}
		void setSpaceCareer(string s) {
			spaceCareer = s;
		}

		void spaceEffect(Player p) {
			// NOTE: changeAmount for CareerSpace will always be positive, makes things easier for altering multiple balances
			// NOTE: if player's career is the space's career, they do not pay or earn anything. It is essentially a "blank" space for them
			if(p.getCareer() != spaceCareer){
				p.makePayment(getChangeAmount());
			}
		}
};
// Space that adds a LIFE card to player's stock
class LifeSpace : OrangeSpace {
	public:
		void spaceEffect(Player p) {
			p.addLifeCards();
		}
};
// A variation of LifeSpace that adds to the player's family
class KidsSpace : LifeSpace {
	int addKids; // Number of kids that are being added to player family

	public:
		int getAddKids() {
			return addKids;
		}
		void setAddKids(int a) {
			addKids = a;
		}

		void spaceEffect(Player p) {
			p.addLifeCards();
			p.addKids(addKids);
		}
};
// Space that skips the player's next turn
class SkipSpace : OrangeSpace {
	void spaceEffect() {
		// TODO: add skip turn function
		// nextTurn = 0;
	}
};
// Space that gives a player another turn if they are not in first
class SpinSpace : OrangeSpace {
	void spaceEffect() {
		// Checks to see if player is in first place
		// If not in first, player gets another turn
	}
};
// Forces player to change career
class ChangeCareer : OrangeSpace {
	// Draws a new career and salary card for the player, replaces their current cards and returns them to the deck
};

//-------------------------------------------------------------------------------------------------------------------------------------

// NOTE: all red spaces will stop the player early
// Generic subclass for red spaces
class RedSpace : Space {
	string color = "red";
	void Color() = red;
};
// Space at the end of college for players to choose career
class CareerChoice : RedSpace {
	void spaceEffect(Player p) {
		// TODO: add logic to draw three career and salary cards, player chooses one of each
	}
};
// Space that adds a partner to the player's family and gives a LIFE card
class MarriageSpace : RedSpace {
	void spaceEffect(Player p) {
		p.getMarried();
		p.addKids(1);
		p.addLifeCards();
	}
};
// Space that gets player to buy house
class HouseSpace : RedSpace {
	void spaceEffect(Player p) {
		p.getHouse();
	}
};
