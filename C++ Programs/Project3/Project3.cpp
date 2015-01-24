#include <iostream>
#include <ctime>
#include "Enemy.h"
#include "Bear.h"
#include "Bomber.h"
#include "BadCop.h"
using namespace std;

int main()
{
	const int max_enemy = 20;	// max enemies limit
    Enemy* enemy_ptr[max_enemy];	// array of different enemies
	Enemy* random_ptr= 0;	// used to dynamically choose random enemy type
	int typesEnemy = 3;			// set the different types of enemies
    int num_enemy;			// set value of total number of enemies

	srand((unsigned int)time(NULL));	// initialize random seed
	int randomNumber;	// will hold random number
	
	// create Enemy objects, place in array	(randomly)
	for (int x=0; x<max_enemy;x++)
	{
		randomNumber = rand() % typesEnemy;	// generate random number between 0-2
		switch(randomNumber)		// create a random object depending on random number
		{
		case 0:
			random_ptr = new Bear;
			break;
		case 1:
			random_ptr = new Bomber;
			break;
		case 2:
			random_ptr = new BadCop;
			break;
		}
		enemy_ptr[x] = random_ptr;
	}

	short input;
	cout << "***** Project 3 *****" << endl;	// choose difficulty
	cout << " Choose difficulty: " << endl;
	cout << " 0-Easy, 1-Medium, 2-Hard, 3-Insane " << endl;
	cout << "> ";
	cin >> input;

	switch(input)	// set difficulty options
	{
	case 0:	// easy gets 3 enemies
		num_enemy = 3;
		break;
	case 1:	// 6 enemies
		num_enemy = 6;
		break;
	case 2:	// 9 enemies
		num_enemy = 9;
		break;
	case 3:	// 12 enemies
		num_enemy = 12;
		break;
	default:
		cout << "Choose difficulty again: " << endl;
		cin >> input;
	}
	cout << endl;

	/////////////////////////////////////////////////////////////////////////////////////////
	// Game Loop
	char ch;	// used to exit
    while ( true ) {

		ch= cin.get();
		if (ch == 'x')	// exit game
			break;
		
        // every Enemy object should move_position
		for (int x=0; x<num_enemy; x++)
			enemy_ptr[x]->movePosition();
		cout << endl;

        // Pick a random Enemy to fire_weapon
		randomNumber = rand() % (num_enemy);//(num_enemy + 1);
			enemy_ptr[randomNumber]->fireWeapon();

        // Pick a random Enemy to update_status
		randomNumber = rand() % (num_enemy);//(num_enemy + 1);
			enemy_ptr[randomNumber]->updateStatus();
			
		

        cout << endl;
    }

	// End Game Loop
	////////////////////////////////////////////////////////////////////////////////////////

	// delete the enemy pointer
	for( int i = 0; i < max_enemy; i++)
		delete enemy_ptr[i];
		
	cin.get();
	return 0;
}