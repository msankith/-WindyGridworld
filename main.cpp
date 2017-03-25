#include "environment.h"
#include "agent.h"
#include <fstream>

#define MAX_EPSISODE_COUNT 500
#define MAX_ITERATIONS_COUNT 100000

using namespace std;

bool isEpisodeEnd(int state[])
{
	if(state[0]==3 && state[1]==7)
		return true;
	else 
		return false;
}

void simulateLastRound(Agent agent, environment en)
{
	ofstream finalRun;
	finalRun.open("policyRun.txt");
	int startState[2]={3,0},endState[2],nextState[2];
	int action1;
	finalRun<<startState[0]<<" "<<startState[1]<<endl;
	int steps=0;
	do{
		action1=agent.GreedyAction(startState);
		en.Model(startState,action1,nextState);
		startState[0]=nextState[0];
    	startState[1]=nextState[1];
    	steps++;
		finalRun<<startState[0]<<" "<<startState[1]<<endl;
	
	}while(!isEpisodeEnd(nextState));
	cout<<"Froms start state to end state on following Optimal policy it took " << steps <<" steps"<<endl;
	finalRun.close();
}


int main(int argv,char *args[])
{
	bool stochastic=false;
	int NoOfActions=4;
	ofstream tempFile ;
	tempFile.open("temp.txt");
	//en.display();
	//en.printReward();
	
	if(argv>=2)
	{
		NoOfActions=atoi(args[1]);
		if(argv>=3)
		{
			if(strcmp(args[2],"true")==0){
				stochastic=true;
				//cout<<stochastic<<"-----"<<endl;
			}
		}
		//cout<<"  --- "<<NoOfActions<<endl;
	}
		environment en(stochastic);

	Agent agent(NoOfActions);
	bool loop=true;

	int episodeCount=0;
	int t=0;
	while(episodeCount<MAX_EPSISODE_COUNT && t<MAX_ITERATIONS_COUNT)
	{
	int startState[2]={3,0},endState[2],nextState[2];
	int reward;
	//int stateState2[2],endState2[2];
	int action1=2;
	int action2;
	
	
	//cout<<t<<" "<<startState[0]<<" "<<startState[1]<<endl;
    action1=agent.epsilonGreedyAction(startState);
	
	do{
	//cout<<t<<" "<<startState[0]<<" "<<startState[1]<<"  "<<action1<<endl;
   
	reward=en.Model(startState,action1,nextState);
	action2=agent.epsilonGreedyAction(nextState);
	agent.updateQValue(startState,action1,reward,nextState,action2);
    if(isEpisodeEnd(nextState))
	{
		agent.updateTerminateStateQValue(nextState,REWARD_GOAL_STATE,action2);
		//agent.updateTerminateStateQValue(nextState,0,action2);	
	}	
	
    startState[0]=nextState[0];
    startState[1]=nextState[1];
    action1=action2;
    t++;
   // cout<<t<<" "<<startState[0]<<" "<<startState[1]<<endl;
    }while(!isEpisodeEnd(nextState) && t<MAX_ITERATIONS_COUNT);
	episodeCount++;
	//cout<<episodeCount<<"\t"<<t<<endl;
	tempFile<<episodeCount<<"\t"<<t<<endl;
	//agent.printPolicy();
	}

	tempFile.close();
	simulateLastRound(agent,en);
	agent.printPolicy();
	return 0;
}

