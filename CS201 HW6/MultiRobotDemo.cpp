#include <string>
#include "Robots_Modified.h"
#include "miniFW_Modified.h"
#include "strutils.h"
using namespace std;

/*
 * A sample robot program: Two robots' movements are controlled by some keys. 
 * First a message is displayed to show number of things in the environment and
 * number of things in robot's bag. Then user is asked the press keys to move 
 * the robot. Allowed movements and their respective keys are as follows:
 *
 *		- Right arrow	: Move towards east
 *		- Left arrow	: Move towards west
 *		- Up arrow		: Move towards north
 *		- Down arrow	: Move towards south
 *		- Insert		: Insert thing in bag
 *		- Delete		: Remove thing from bag
 *
 *		For the red robot:
 *		- d				: Move towards east
 *		- a				: Move towards west
 *		- w				: Move towards north
 *		- s				: Move towards south
 *		- e				: Insert thing in bag
 *		- f				: Remove thing from bag
 *
 *		- Home			: Beam up yellow robot to input points
 *
 * At any step you can press home button to beam up the yellow robot.
 * Then, you are asked to enter x, y values of the point to be beamed up and
 * the direction of the robot
 *
 * As long as both robot are alive game will react to input keys; however once
 * any of them is dead, a message is displayed to show number of things in the
 * environment and number of things in robot's bag and program terminates.
 */

void DisplayThingCount(Robot& r1, Robot& r2)
{
	int thing_env = GetThingCount(0,0,9,9);  //environment is 9-by-9 area
	int bag1 = r1.BagContent();
	int bag2 = r2.BagContent();
	ShowMessage(itoa(thing_env)+" thing(s) in environment\n" + itoa(bag1) + " thing(s) in yellow robot's bag\n" + itoa(bag2) + " thing(s) in red robot's bag");
}


int main()
{
	Robot r(0,0);
	Robot r2(8,8);
	r2.SetColor(red);


	string message = "Press arrow keys to control both robots.\n";
	message = message
		+ "For the yellow robot:\n"
		+ "-Right arrow	: Move towards east\n"
		+ "- Left arrow	: Move towards west\n"
		+ "- Up arrow	: Move towards north\n"
		+ "- Down arrow	: Move towards south\n"
		+ "- Insert		: Insert thing in bag\n"
		+ "- Delete		: Remove thing from bag\n"
		+ "For the red robot:\n"
		+ "- d		: Move towards east\n"
		+ "- a		: Move towards west\n"
		+ "- w		: Move towards north\n"
		+ "- s		: Move towards south\n"
		+ "- e		: Insert thing in bag\n"
		+ "- f		: Remove thing from bag\n"
		+ "- Home		: Beam up yellow robot to input points";

	ShowMessage (message);
	
	DisplayThingCount(r,r2);
	
	while (r.IsAlive()== true && r2.IsAlive()== true)
	{	
		if (IsPressed(keyRightArrow))
		{				
			r.Turn(east);
			r.Move();
		}
		else if (IsPressed(keyLeftArrow))
		{
			r.Turn(west);
			r.Move();
		}
		else if (IsPressed(keyUpArrow))
		{
			r.Turn(north);
			r.Move();
		}
		else if (IsPressed(keyDownArrow))
		{
			r.Turn(south);		
			r.Move();
		}
		else if (IsPressed(keyInsert))
		{
			r.PickThing();
		}
		else if (IsPressed(keyDelete))
		{
			r.PutThing();
		}
		else if (IsPressed('d'))
		{				
			r2.Turn(east);
			r2.Move();
		}
		else if (IsPressed('a'))
		{
			r2.Turn(west);
			r2.Move();
		}
		else if (IsPressed('w'))
		{
			r2.Turn(north);
			r2.Move();
		}
		else if (IsPressed('s'))
		{
			r2.Turn(south);		
			r2.Move();
		}
		else if (IsPressed('e'))
		{
			r2.PickThing();
		}
		else if (IsPressed('f'))
		{
			r2.PutThing();
		}
		else if (IsPressed(keyHome))
		{
			int x, y;
			string direction;
			ShowMessage("Now enter x, y values of the point for the yellow robot to beam up");
			GetInput("x value", x);
			GetInput("y value", y);
			GetInput("Now enter the direction in one of the forms below:\neast west north south", direction);

			if(direction=="east")
				r.Teleport(x,y,east);
			else if(direction=="west")
				r.Teleport(x,y,west);
			else if(direction=="north")
				r.Teleport(x,y,north);
			else if(direction=="south")
				r.Teleport(x,y,south);
		}
	}

	DisplayThingCount(r,r2);

	return 0;
}