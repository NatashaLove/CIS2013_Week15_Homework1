#include <iostream>
#include <string>
#include <time.h>
#include "Card.h"
#include "Player.h"

using namespace std;

Card* get_card(Card** deck, int& last){
	
	int n = rand() % 52;
	Card* c = deck[n];
	deck[n] = deck[last];
	deck[last--] = c; //сохраняем адрес карты, чтобы  потом было что чистить
	return c;
}
// question to continue the game
void question (char& answer) {
	
	cout << "Do you want to hit more? y/n" << endl;
	cin >> answer;
}

int main(){
	char over = 0;
	char answ='y';
	char answer;
	string name;
	
	cout << endl;
	cout << "Hello!!! " << endl;
	cout << "Welcome to Black Jack!"<< endl;
	cout << endl;
	cout << "What is your name? "<< endl;
	cin >> name;
	cout << "						Let's play, " << name << endl;
	cout << "			********************************************************" << endl;
	
	while (answ== 'y')	{
		
		int last = 51;
		Player dealer("Dealer");
		Player player(name);
		
		Card* deck[52];
		for (int i = 2; i <= 14; i++){
			
			for (int j = 0; j < 4; j++){
				
				Card* c = new Card();
				c->assignValues(j, i);
				deck[(i - 2) * 4 + j] = c;
			}
		}
	
		srand(time(0));
		
		Card* c = get_card(&deck[0], last);
		player.addCard(c);
		c = get_card(&deck[0], last);
		player.addCard(c);
		player.print();
		cout << endl;

		c = get_card(&deck[0], last);
		dealer.addCard(c);
		c = get_card(&deck[0], last);
		dealer.addCard(c);
		dealer.print();
		cout << endl;
		
		// ВОЗМОЖНО НЕ нужно сплит..
		if (player.points() == 21){
			
			if (dealer.points() == 21){
				
				cout << endl << "Equal points! Split!" << endl;
			} else {
				
				cout << endl << player.name() << " wins!";
			}
			
		} else if (player.points() > 21){
			
			cout << endl << dealer.name() << " wins!";
			
		} else {
			
			bool b = true;
			char x;
			
			question (answer);
			//cin >> x;
			
			while (answer == 'y') {
				
					
				c = get_card(&deck[0], last);
				player.addCard(c);
				player.print();
				
				if (player.points() == 21){
					
					cout << endl << player.name() << " wins!";
					b = false;
					break;
				}
				else if (player.points() > 21){
					
					cout << endl << dealer.name() << " wins!";
					b = false;
					break;
				}
				//cin >> x;
				question (answer);
			}	
			
// ЗАЧЕМ ЭТА while loop? 
// ПОЧЕМУ ==18? И ПРИ ЭТОМ ИГРОК ВЫИГРЫВАЕТ?
			while (b){
				
				c = get_card(&deck[0], last);
				dealer.addCard(c);
				dealer.print();
				if (dealer.points() > 21){
					
					cout << endl << player.name() << " wins!";
					b = false;
				} else if ((dealer.points() == 21) || (dealer.points() >= player.points())){
					
					cout << endl << dealer.name() << " wins!";
					b = false;
				} else if (dealer.points() >= 18){
					
					cout << endl << dealer.name() << " stays!" << endl;
					cout << player.name() << " wins!";
					b = false;
				}
			}
		}

		for (int i = 0; i < 52; i++)
		{
			delete deck[i];
		}
		
		cout << endl;
		cout << "Do you wanna play another game? (y/n): " << endl;
		cin >> answ;
	}	
			
	
	/*
	BlackJack blackjack [52];// 2D array for the deck
	// вместо создания 2D array - создать класс Card.  
	// в классе создать конструкторы - присваивают value и suit.. 
	
	// потом вызвать в main - Card card [52] - и каждая карта в array будет иметь конструкторы и функции..
	// через  for loop заполнить array картами (конкретно)..
// создать для этого array из 4 char suit [] {'S', 'H', 'C', 'D'}
// и аrray из 13 char value [] {'2', '3', '4'...'Q', 'K'...}
// for loop тройная - все arrays перебирает и наполняет
	
	*/
	
	
	return 0;
}