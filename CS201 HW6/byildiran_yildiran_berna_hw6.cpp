#include "Robots_Modified.h"
#include "MiniFW_Modified.h"
#include "randgen.h"
#include <iostream>
#include <fstream>
#include <string>
#include "strutils.h"

using namespace std;
void WhoWon (Robot & r, Robot & m1, Robot & m2, Robot & m3, int lifeCount)
{
	int A = r.GetBagCount();
	int B = m1.GetBagCount();
	int C = m2.GetBagCount();
	int D = m3.GetBagCount();

	if (lifeCount == 0)
	{
		ShowMessage("You have run out of life. You lost the game!");
	}
	else if (A > B && A > C && A > D)
	{
		ShowMessage("Congratulations." + r.GetName() + " has won the game.");
	}
	else if (B > A && B > C && B > D)
	{
		ShowMessage("You lost." + m1.GetName() + " has won the game.");
	}
	else if(C > A && C > B && C > D)
	{
		ShowMessage("You lost." + m2.GetName() + " has won the game.");
	}
	else if (D > A && D > B && D > C)
	{
		ShowMessage("You lost." + m3.GetName() + " has won the game.");
	}
}

void moveMonster(Robot & monster)
{
	RandGen r;
	int dir = r.RandInt(1,4);
	if(dir == 1) //east
	{
		monster.TurnFace(east);
		monster.Move();
		monster.Resurrect();
		monster.PickAllThings();
		
	}
	else if(dir == 2) //west
	{
		monster.TurnFace(west);
		monster.Move();
		monster.Resurrect();
		monster.PickAllThings();
		
	}
	else if(dir == 3) // north
	{
		monster.TurnFace(north);
		monster.Move();
		monster.Resurrect();
		monster.PickAllThings();
		
	}
	else if(dir == 4) //south
	{
		monster.TurnFace(south);
		monster.Move();
		monster.Resurrect();
		monster.PickAllThings();
		
	}
}

void createEnvironment()
{
	RandGen randCell, randx, randy, randthing;
	int cellCount = randCell.RandInt(20,35);
	int count = 0;
	while(cellCount != count)
	{
		int x = randx.RandInt(0,7);
	    int y = randy.RandInt(0,7);

		if(GetCellCount(x,y) == 0)
		{
			int thing = randthing.RandInt(1,10);
			PutThings(x,y,thing);
			count++;
		}
	}
}

int main()
{
	createEnvironment();
	string name, monster1_name, monster2_name, monster3_name;
	Robot player_robot(5,2);
	Robot monster1(0,0);
	Robot monster2(0,7);
	Robot monster3(7,7);
	player_robot.SetColor(blue);
	monster1.SetColor(red);
	monster2.SetColor(red);
	monster3.SetColor(red);

	GetInput("Please enter the name of the player robot: ", name);
	player_robot.SetName(name);

	GetInput("Please enter the name of the monster1: ", monster1_name);
	monster1.SetName(monster1_name);

	GetInput("Please enter the name of the monster2: ", monster2_name);
	monster1.SetName(monster2_name);

	GetInput("Please enter the name of the monster3: ", monster3_name);
	monster1.SetName(monster3_name);


	int lifeCount = 3;
	while (GetThingCount(0,0,8,8) != 0 && lifeCount > 0)
	{	
		if (IsPressed(keyRightArrow))
		{				
			player_robot.TurnFace(east);
			player_robot.Move();
			player_robot.PickAllThings();
		}
		else if (IsPressed(keyLeftArrow))
		{
			player_robot.TurnFace(west);
			player_robot.Move();
			player_robot.PickAllThings();
		}
		else if (IsPressed(keyUpArrow))
		{
			player_robot.TurnFace(north);
			player_robot.Move();
			player_robot.PickAllThings();
		}
		else if (IsPressed(keyDownArrow))
		{
			player_robot.TurnFace(south);		
			player_robot.Move();
			player_robot.PickAllThings();
		}
		if(!player_robot.IsAlive())
		{
			player_robot.Resurrect();
			lifeCount--;
			ShowMessage("You have "+ itoa(lifeCount)+ " lives left.");
		}

		RandGen r;
		int turn = r.RandInt(1,3);
		if(turn == 1)
		{
			//move monster robot 1
			moveMonster(monster1);
		}
		else if(turn == 2)
		{
			//move monster robot 2
			moveMonster(monster2);
		}
		else if(turn == 3)
		{
			//move monster robot 3
			moveMonster(monster3);
		}

	}
	WhoWon(player_robot, monster1, monster2, monster3, lifeCount);

	return 0;
}