#include <iostream>


/*
ACTIONS :
0 -> Up
1 -> Down
2 -> Right
3 -> Left
*/

class environment
{

	int states[7][10];
	int reward[7][10];
	int rows;
	int columns;
	int start[2];
	int end[2];
	bool stochastic;
public:
	environment(bool isStochastic);
	void display();
	void printReward();
	int Model(int startState[2],int action,int endState[2]);


};