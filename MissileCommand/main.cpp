#include <iostream>
#include <ctime>
#include <string.h>

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << std::endl;
	}

}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;

struct Missile {
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;

	}
};

int main()
{
	Missile missile;
	float timer = 0;
	int chosen = 0;

	//Intro
	std::cout << "Welcome to missile command" << std::endl;
	std::cout << "You must successfully hit your target with your chosen missile" << std::endl;
	std::cout << "Don't forget! The code for the nuclear weapon is 135." << std::endl;
	std::cout << "The code for the explosive weapon is 579" << std::endl;

	
	system("pause");
	// This clears the screen
	system("cls");

	//Warhead Select
	std::cout << "Enter what kind of missile you would like to us" << std::endl;
	std::cout << "Enter 1 for explosive. Enter 2 for nuclear." << std::endl;
	std::cin >> chosen;

	if (chosen == 0)
	{
		missile.payload = EXPLOSIVE;
		std::cout << "Explosive missile selected " << std::endl;
	}
	else if (chosen == 2)
	{
		missile.payload = NUCLEAR;
		std::cout << "Nuclear missile selected" << std::endl;
	}
	

	system("cls");
	
	// Target!
	srand((unsigned)time(0));
	int targetNorth = 0;
	// How many KM North is the target?
	targetNorth = (rand() % 15) + 1;
	std::cout << "The Target is " << targetNorth << " km North" << std::endl;

	// East
	int targetWest = 0;
	targetWest = (rand() % 15) + 1;
	std::cout << "The Target is " << targetWest << " km East" << std::endl;

	system("pause");
	system("cls");


	//Launch Codes
	int explosive = 135;
	int nuclearArm = 579;
	int userCode = 0;

	std::cout << "Enter the launch code: " << std::endl;
	std::cin >> userCode;



	if(userCode == explosive && chosen == 1 || userCode == nuclearArm && chosen == 2)
	{
		std::cout << "You have entered the right code!! " << std::endl;
	}
	else 
	{
		std::cout << "ACCESS DENIED. GAME OVER" << std::endl;
	}

	system("PAUSE");

	


	//Collision
	int missileNorth = 0;
	missileNorth = (rand() % 15) + 1;
	int missileWest = 0;
	missileWest = (rand() % 15) + 1;

	while (missileNorth != targetNorth && missileWest != targetWest)
	{
		int fireAgain = 3;
		missileNorth = (rand() % 15) + 1;
		missileWest = (rand() % 15) + 1;
		std::cout << "Your missile missed the target!!!!" << std::endl;
		std::cout << "Press 1 to try again. Press 0 to quit: " << std::endl;
		std::cin >> fireAgain;
		if (fireAgain == 0)
		{
			std::cout << "Game over!!!" << std::endl;
			break;
		}

	}

	if (missileNorth == targetNorth && missileWest == targetWest)
	{
		std::cout << "You did it! Target obliterated" << std::endl;
	}

	system("pause");

	return 0;
}
