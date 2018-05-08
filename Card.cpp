#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

	// BlackJack::BlackJack () {
		// card_deck = new string [52];
	// }
	
Card::Card(){
			
}


Card::~Card(){
		
}

void Card::assignValues(char suit, char value){
	
	_suit = suit;
	_value = value;
	
	switch (_value)	{
	case 11:
		_weight = 1; // Ace = 1;
		break;
	case 12:		
	case 13:
	case 14:	
		_weight = 10; // Jack, Queen, King = 10;
		break;
	default:
		_weight = value; // КАК ЭТО?
		break;
	}
}

void Card::print(){
	
	switch (_value)	{
	case 11:
		cout << "Ace";
		break;
	case 12:
		cout << "Jack";
		break;
	case 13:
		cout << "Queen";
		break;
	case 14:
		cout << "King";
		break;
	default:
		cout << ((int)_value);
		break;
	}
	
	switch (_suit)	{
	case 0:
		cout << " of Spades";
		break;
	case 1:
		cout << " of Clubs";
		break;
	case 2:
		cout << " of Diamonds";
		break;
	case 3:
		cout << " of Hearts";
		break;
	}
}


int Card::weight(){
	
	return _weight;
}


/*	
int print_card_value(int card){
	using namespace std;
	switch(card){
	 case 1:
		cout << "You got an Ace" << endl; 
		return 1;
		break;
	 case 11:
		cout << "You got a Jack" << endl;
		return 10;
		break;
	 case 12:
		cout << "You got a Queen" << endl;
		return 10;
		break;
	 case 13:
		cout << "You got a King" << endl;
		return 10;
		break;
	 default:
		cout << "You got a " << card << endl;
		return card;
		break;
		
	}
}
*/
