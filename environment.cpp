#include "environment.h"
#define REWARD_GOAL_STATE 10
using namespace std;

environment::environment(bool isStochastic)
	{
		rows=7;
		stochastic=isStochastic;
		columns=10;
		start[0]=3;
		start[1]=0;
		end[0]=3;
		end[1]=7;

		for(int i=0;i<columns;i++)
		{
			int temp=0;
			if(i<3)
				temp=0;
			else if(i<6)
				temp=1;
			else if(i<8)
				temp=2;
			else if(i<9)
				temp=1;
			for(int j=0;j<rows;j++)
			{
				states[j][i]=temp;
				reward[j][i]=-1;
			}
		}	
		reward[end[0]][end[1]]=REWARD_GOAL_STATE;
	}	

void environment::display()
{

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<states[i][j]<<" ";
		}
		cout<<endl;
	}
}


void environment::printReward()
{

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<reward[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*
ACTIONS :
0 -> Up
1 -> Down1
2 -> Right
3 -> Left
4 -> UpRight
5 -> UpLeft
6 -> DownRight 
7 -> DownLeft

*/

bool validAction(int startState[2],int action)
{
	if(startState[0]==0 && (action==0 || action==4 || action==5))
	{
		return false;
	}

	if(startState[0]==6 && (action==1 || action== 6 || action==7 ))
		return false;

	if(startState[1]==0 && (action==3 || action==5 || action==7 ))
		return false;

	if(startState[1]==6 &&(action==2 || action==4 || action==5 ))
		return false;
	return true;
}

int environment::Model(int startState[2],int action,int endState[2])
{
	endState[0]=startState[0];
	endState[1]=startState[1];
	
	if(!validAction(endState,action))
	{
	//	return -1;
	}
	endState[0]-=states[startState[0]][startState[1]];
	
	if(action==0)
	{
		endState[0]-=1;
	//	endState[0]-=states[startState[0]][startState[1]];
		if(endState[0]<0)
			endState[0]=0;
	}
	else if(action==1)
	{
		endState[0]+=1;
	//	endState[0]-=states[startState[0]][startState[1]];
		if(endState[0]<0)
			endState[0]=0;
		if(endState[0]>(rows-1))
			endState[0]=rows-1;
	}
	else if(action==2)
	{
	//	endState[0]-=states[startState[0]][startState[1]];
		endState[1]+=1;
		if(endState[0]<0)
			endState[0]=0;
		if(endState[1]>(columns-1))
			endState[1]=columns-1;
	}
	else if(action==3)
	{
	//	endState[0]-=states[startState[0]][startState[1]];
		endState[1]-=1;
		if(endState[0]<0)
			endState[0]=0;
		
		if(endState[1]<0)
			endState[1]=0;
	}
	else if(action==4)
	{
	//	endState[0]-=states[startState[0]][startState[1]];
		endState[0]-=1;
		endState[1]+=1;
		if(endState[0]<0)
			endState[0]=0;
		
		if(endState[1]<0)
			endState[1]=0;
	}
	else if(action==5)
	{
	//	endState[0]-=states[startState[0]][startState[1]];
		endState[0]-=1;
		endState[1]-=1;
		if(endState[0]<0)
			endState[0]=0;
		
		if(endState[1]<0)
			endState[1]=0;
	}
	else if(action==6)
	{
	//	endState[0]-=states[startState[0]][startState[1]];
		endState[0]+=1;
		endState[1]+=1;
		if(endState[0]<0)
			endState[0]=0;
		
		if(endState[1]<0)
			endState[1]=0;
	}
	else if(action==7)
	{
	//	endState[0]-=states[startState[0]][startState[1]];
		endState[0]+=1;
		endState[1]-=1;
		if(endState[0]<0)
			endState[0]=0;
		
		if(endState[1]<0)
			endState[1]=0;
	}


	if(stochastic)
	{
		double randonNo=(double)random()/RAND_MAX;

		if(randonNo<0.33)
		{
			
		}
		else if(randonNo<0.66)
		{
			endState[0]+=1;
		}else
		{
			endState[0]-=1;
		}
	}
	if(endState[0]<0)
		endState[0]=0;
		
	if(endState[1]<0)
		endState[1]=0;
	
	if(endState[0]>(rows-1))
	{
		endState[0]=rows-1;
	}
	if(endState[1]>(columns-1))
	{
		endState[1]=columns-1;
	}
	if(endState[0]==end[0] && endState[1]== end[1])
		return 0;
	else
		return -1;
//
}////