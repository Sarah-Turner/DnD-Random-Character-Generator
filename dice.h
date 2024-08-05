#ifndef DICE
#define DICE

#include <vector>

int rollD20();
int rollD4();
int rollD6();
int rollD8();
int rollD10();
int rollD12();
int customRoll(int maxVal, int numDice);
int findMin(const std::vector<int>& v); 
int rollStat();
int randomBetween(int min, int max);

#endif