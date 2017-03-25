#include "agent.h"

Agent::Agent(int actionsNo)
{
	actions=actionsNo;
	discount=1;
	for(int i =0;i<7;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<actions;k++)
				qValue[i][j][k]=0;
	timestep=1;
	
	srand(1447168938);
	//srand(1447170261);
	//srand(time(NULL));
	cout<<"Seed  "<<time(NULL)<<endl;
}


int Agent::epsilonGreedyAction(int state[])
{
	//double randomNo=(double)random()/RAND_MAX;
	double randomNo=(double)random()/RAND_MAX;
	//cout<<randomNo<<" ";
	//	return GreedyAction(state);
	
	if(randomNo<=(EPSILON_GREEDY))
	{
		return random()%actions;
	}
	else
	{
		return GreedyAction(state);
	}
	
	
}

int Agent::GreedyAction(int state[])
{

	int action=random()%actions;

	double temp=qValue[state[0]][state[1]][action];

	for(int i=0;i<actions;i++)
	{
		if(temp<qValue[state[0]][state[1]][i])
		{
			temp=qValue[state[0]][state[1]][i];
			action=i;
		}
	}
	return action;
}

double Agent::updateQValue(int startState[],int startAction,double reward,int endState[],int endAction)
{
	qValue[startState[0]][startState[1]][startAction] = qValue[startState[0]][startState[1]][startAction]+ALPHA*(reward+qValue[endState[0]][endState[1]][endAction]-qValue[startState[0]][startState[1]][startAction]);
	return qValue[startState[0]][startState[1]][startAction];
}

void Agent::updateTerminateStateQValue(int startState[],double reward,int startAction)
{
	qValue[startState[0]][startState[1]][startAction] = qValue[startState[0]][startState[1]][startAction]+ALPHA*(reward-qValue[startState[0]][startState[1]][startAction]);
}
void Agent::printPolicy()
{
	cout<<endl<<"-----------"<<endl;
	string out[]={"U ","D ","R ","L ","UR","UL","DR","DL"};

	int temp[2];
	for(int i=0;i<7;i++)
	{
		temp[0]=i;
		for(int j=0;j<10;j++)
		{
			temp[1]=j;
			cout<<out[GreedyAction(temp)]<<" ";
		}
		cout<<endl;
	}
}