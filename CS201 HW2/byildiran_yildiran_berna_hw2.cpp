#include<iostream>
#include<string>

using namespace std;

/* C++ program that helps baristas to know know what kind of coffee customer would like to drink! */

bool isItEqual(string product1, string product2) 
/* function that used for learning equality of the product1 and product2 */

{
	bool equality = true;
	string isIt, product;
	cout << "Do " << product1 << " and " << product2 
		 << " are in equal amounts?" << endl;
	cin >> isIt;
	
	if(isIt == "yes")
	{
		equality = true;
	}
	else
	{
		equality = false;
	}

	return equality;
}

void order(string name, string product) 
// function that prints what customers order according to which product they choose
{
	cout << "Your order is ready " << name << "! What you want is a " 
		 << product << ". Enjoy!" << endl; 
}

bool doesItHave(string ingredient)
// function that ask if the product that customer orders include the given ingredient
{
	string haveIt;
	bool status = true;
	cout << "Does it have " << ingredient << "?" << endl;
	cin >> haveIt;

	if(haveIt == "yes")
	{
		status = true;
	}
	else if(haveIt == "no")
	{
		status = false;
	}

	return status;
}

void espresso(string name) 
// asks ingredients which were in the given flowchart with if else statements
{
	string espresso, product;
	cout << "Dear " << name << ", would you kindly answer our questions, so we can determine the coffee you want." << endl;
	cout << "Does it have espresso?" << endl;
	cin >> espresso;
	if(espresso ==  "no")
	{
		product = "filtered coffee";
		order(name, product);
	}
	else if (espresso == "yes")
	{
		if(doesItHave("milk"))
		{
			if(doesItHave("hot chocolate"))
			{
				product = "mocha";
				order(name, product);
			}
			else 
			{
				if (doesItHave("foam"))
				{
					if(isItEqual("foam", "milk"))
					{
						product = "cappucino";
						order(name, product);
					}
					else
					{
						product = "latte";
						order(name, product);
					}
				}
				else
				{
					product = "cafe au lait";
					order(name, product);
				}
			 }

		 }
		 else
		 {
			 if(doesItHave("water"))
			 {
				 product = "americano";
				 cout << "Your order is ready " << name << "! What you want is an americano. Enjoy!" << endl;
			 }
			 else
			 {
				 product = "espresso";
				 order(name, product);
			 }
		 }
	 }
}

int main()
{
	string name, product; // starting of the program
	cout << "Welcome to Pequod's Coffee! Can you tell me your name?" << endl;
	cin >> name;

	espresso(name); // big function that includes other functions

	return 0;
}
