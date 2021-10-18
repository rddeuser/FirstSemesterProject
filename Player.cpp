/*
Author: Jil Dietz
*Date: 10/12/2021
*Email: jdietz@dmacc.edu
*Overview: This is a class that holds all the necessary player information so that that game can record,
* and return values that can be accumulated at the end of the game.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Player{
private:
	//declaring variables to generate
	int kids = 0;
	double money = 0.00;
	string job, house, career;
	bool marriage = false;
	bool ownHouse = false;
	double salary = 0.00;
	int lifeCards = 0;

public:

	void setJob(string job){this->job = job;}
	void setHouse(string house) {this->house = house;}
	void setSalary(double salary){this->salary = salary;}
	void setCareer(string career){this->career = career;}
	int getKids(){return kids;}
	double getMoney(){return money;}
	string getJob(){return job;}
	string getHouse(){return house;}
	bool getMarriage(){return marriage;}
	bool getOwnedHouse(){return ownHouse;}
	double getSalary(){return salary;}
	int getLifeCards(){return lifeCards;}
	string getCareer(){return career;}

	void addKids(int numOfKids){ //adds children if needed
		kids+=numOfKids;
	}
	void addLifeCards(){ //adds life cards to the total
		lifeCards++;
	}
	void addIncome(){ //adds salary to the overall income
		money += salary;
	}
	void obtainHouse(){ //determines if the player has a house
		ownHouse = true;
	}
	void getMarried(){ //changes the status of married to true
		marriage = true;
	}
	double makePayment(double cost){ //removes cost from total amounth of money
		money -= cost;
		return money;
	}
};

