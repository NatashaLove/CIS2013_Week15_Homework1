#include <iostream>
#include <fstream>
#include <string>
//g++ CIS2013_Week15_Quiz1.cpp

using namespace std;

class BlackJack {
	private: 
	//string file_name = "todo.dat";
	string *card_deck; // will be array - deck of cards - make it 2D - call in main : BlackJack blackjack [52];
	// in .cpp : card_deck = new string [52];
	//int length =0;
	int next=0;
	string card;
	string suit, value;
	
	//void file_read();
	//void file_save();
	
	
	public:
		
	// default constructor
	BlackJack ();
	
};