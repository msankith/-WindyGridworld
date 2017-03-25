#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <random>
#define ALPHA 0.1
#define lin long long int
#define RUN_COUNT_SIMULATE_MODEL 100
#define EPSILON_GREEDY 0.1
#define REWARD_GOAL_STATE 5
using namespace std;


class Agent
{
private:
	int states;
	int actions;
	double discount;
	double qValue[7][10][8];
	int timestep;
	

public:
	Agent(int actions);
	int epsilonGreedyAction(int state[]);
	int GreedyAction(int state[]);
    double updateQValue(int startState[],int startAction,double reward,int endState[],int endAction);
    void printPolicy();
    void updateTerminateStateQValue(int nextState[],double reward,int action);
};