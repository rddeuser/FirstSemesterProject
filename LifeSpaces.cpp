/* Author: Noah Clark, Alicia Rustan
 * Space methods and classes
 */

/* Update by: Alicia Rustan
 * Date: 10/12/2021
 * color variables on spaces wasn't working. Changed to a virtual function that will be inherited by all tiles.
 */

#include <iostream>
#include <string>

using namespace std;

// Base Class
class Space {
private:
    string display; // This is the flavor text for the space; "Won a beauty contest, earned $5,000," "Twins! Draw a LIFE card," "Midlife Crisis, draw a new career," etc
    string color; //placeholder for a space's color
    int spaceID; // unique identifier for each space

    public:
    Space (string display, string color, int spaceID): display(display), color(color), spaceID(spaceID){}
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
        void spaceEffect();
        virtual void Color() = 0;
};

// For salary spaces
class SalarySpace : public Space {

    public:
        void spaceEffect() {
            // TODO: Logic to check if playermovement passes SalarySpace
            // Add player's salary to player balance
        }
        void Color() {};
};

//-------------------------------------------------------------------------------------------------------------------------------------

// Generic subclass for orange spaces
class OrangeSpace : Space {
};
// For spaces that change the player's balance
class BalanceChange : OrangeSpace {
    int changeAmount; // The amount the player's balance changes. Negative values are used for penalties to the player's balance;
    public:
        int getChangeAmount() {
            return changeAmount;
        }
        void setChangeAmount(int c) {
            changeAmount = c;
        }

        void spaceEffect() {
            // TODO: access player balance and change amount
            // will look something like the following:
            // playerBalance =+ changeAmount;
        }
        void Color() {};
};
// Taxes spaces; value changes based on career salary
class TaxSpace : BalanceChange {
    //TODO: access player tax rate, use that value as changeAmount
};
// Accidents that can be prevented if player buys insurance
class InsuranceSpace : BalanceChange {
    // TODO: spaceEffect will have an if statement determining if player has insurance or not
    // If player has insurance, there is no effect, otherwise function goes as normal
    // Note: possibly add distinction between home/car (horse?) insurance
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

        void spaceEffect() {
            // TODO: implement logic for checking careers of player; pseudocode included below
            /* if otherPlayerCareer = spaceCareer then
             *		otherPlayerBalance =+ changeAmout
             *		playerBalance =- changeAmount
             * else if playerCareer =! spaceCareer then
             *		playerBalance =- changeAmount
             */
            // NOTE: changeAmount for CareerSpace will always be positive, makes things easier for altering multiple balances
            // NOTE: if player's career is the space's career, they do not pay or earn anything. It is essentially a "blank" space for them
        }
};
// Space that adds a LIFE card to player's stock
class LifeSpace : OrangeSpace {
    public:
        void spaceEffect() {
            // TODO: add logic to add LIFE card to player stock
            // NOTE: in the board game, there is a limit of 25 cards; add logic to steal from other players when limit is reached
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

        void spaceEffect() {
            // NOTE: will use a copy of LifeSpace's spaceEffect, with the addition of the following line
            // playerFamily =+ addKids
        }
        void Color() {};
};
// Space that skips the player's next turn
class SkipSpace : OrangeSpace {
    void spaceEffect() {
        // TODO: add skip turn function
        // nextTurn = 0;
    }
    void Color() {};
};
// Space that gives a player another turn if they are not in first
class SpinSpace : OrangeSpace {
    void spaceEffect() {
        // Checks to see if player is in first place
        // If not in first, player gets another turn
    }
    void Color() {};
};
// Forces player to change career
class ChangeCareer : OrangeSpace {
    // Draws a new career and salary card for the player, replaces their current cards and returns them to the deck
};

//-------------------------------------------------------------------------------------------------------------------------------------

// Generic subclass for blue spaces
class BlueSpace : Space {
};
// Lets player swap salary with another
class SwapSalary : BlueSpace {
    void spaceEffect() {
        // Prompts player if they want to swap salaries with another player, if yes player can choose which player to swap salaries with
    }
};
// Allows player to change career and salary
class NightSchool : BlueSpace {
    void spaceEffect() {
        // Prompts player if they want to go to (k)night school to change careers
        // If yes, draw two career cards and two salary cards. Player can choose one of each
    }
};

//-------------------------------------------------------------------------------------------------------------------------------------
// NOTE: all red spaces will stop the player early
// Generic subclass for red spaces
class RedSpace : Space {
    void Color() {};
};
// Space at the end of college for players to choose career
class CareerChoice : RedSpace {
    void spaceEffect() {
        // TODO: add logic to draw three career and salary cards, player chooses one of each
    }
};
// Space that adds a partner to the player's family and gives a LIFE card
class MarriageSpace : RedSpace {
    void spaceEffect() {
        // TODO: add logic to add one LIFE card and add one to the player's family
    }
};
// Space that gets player to buy house
class HouseSpace : RedSpace {
    void spaceEffect() {
        // TODO: logic for drawing a house card and taking the payment from the player's balance
    }
};
