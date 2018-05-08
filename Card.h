#include <iostream>
#include <string>
//g++ CIS2013_Week15_Homework1.cpp

using namespace std;

class Card {
	private: 
	
	//string *card_deck; // will be array - deck of cards - make it 2D - call in main : BlackJack blackjack [52];
	// in .cpp : card_deck = new string [52];
	//int length =0;
	// int next=0;
	// string card;
	// string suit, value;
	
	char _suit; //(diamonds, clubs, hearts, spades)
	char _value; // (A-K)
	int _weight; // (i.e. is the card an Ace worth 1)
	bool is_used;// (is the card already out of play) 
	
	public:
		
	// default constructor
	Card();
	// default destructor
	~Card();
	
	//BlackJack ();
	
	void assignValues(char suit, char value);
	void print();
	int weight();
	// bool is_used ();
};