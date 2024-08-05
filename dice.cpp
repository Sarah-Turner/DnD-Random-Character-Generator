#include "dice.h"
#include <random>

std::default_random_engine randGen(time(0));

int rollD20()
{
	std::uniform_int_distribution<int> random_roll(1, 20);
	return random_roll(randGen);
}

int rollD4()
{
	std::uniform_int_distribution<int> random_roll(1, 4);
	return random_roll(randGen);
}

int rollD6()
{
	std::uniform_int_distribution<int> random_roll(1, 6);
	return random_roll(randGen);
}

int rollD8()
{
	std::uniform_int_distribution<int> random_roll(1, 8);
	return random_roll(randGen);
}

int rollD10()
{
	std::uniform_int_distribution<int> random_roll(1, 10);
	return random_roll(randGen);
}

int rollD12()
{
	std::uniform_int_distribution<int> random_roll(1, 12);
	return random_roll(randGen);
}

//custom roll using a numDice_D_maxValue 
int customRoll(int maxVal, int numDice)
{
	std::uniform_int_distribution<int> random_roll(1, maxVal);
	int total = 0;
	for (int i = 0; i < numDice; i++)
	{
		total += random_roll(randGen);
	}
	return total;
}

// to use with rollStat
int findMin(const std::vector<int>& v)
{
	int min = v[0];
	for (int num : v)
	{
		if (num < min)
		{
			min = num;
		}
	}
	return min;
}

//To roll for a random stat and return it
int rollStat()
{
	int sum = 0;
	bool discardMin = false;
	std::vector<int> rolls;
	for (int i = 0; i < 4; i++)
	{
		int num = rollD6();
		rolls.push_back(num);
	}

	int min = findMin(rolls);

	for (int roll : rolls)
	{
		if (roll != min || discardMin == true)
		{
			sum += roll;
		}
		else if (roll == min && discardMin == false)
		{
			discardMin = true;
		}
	}
	return sum;
}

//returns a random value between min and max
int randomBetween(int min, int max)
{
	std::uniform_int_distribution<int> random_roll(min, max);
	return random_roll(randGen);
}