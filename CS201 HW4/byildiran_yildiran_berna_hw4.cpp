#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

bool compare(string startTime, string departureTime)
{
	bool situation = true;
	
	if (startTime.substr(0,2) > departureTime.substr(0,2))
	{
		situation = false;
	}
	else if (startTime.substr(0,2) == departureTime.substr(0,2))
	{
		if(startTime.substr(3,2) > departureTime.substr(3,2))
		{
			situation = false;
		}
	}
	else if(startTime.substr(0,2) < departureTime.substr(0,2))
	{
		situation = true;
	}
	return situation;
}


bool departureTimeCheck(string startTime)
{
	/*
	Time should be in format hh:mm, hh for 2-digit hour and mm for 2-digit minutes.
	Example: 03:05 not 3:5 or not 3:05. Additionally, the time needs to be in the valid range (between 00:00 and 23:59)
	such as 12:15, 21:03. Some examples of invalid time: 26:84, 10:60, 3a:0x, bb:dd. 
	If this input is wrong, then display an error message and ask for another departure time.  

	*/
	unsigned int i;
	bool status = false;
	for (i = 0; i < startTime.length()+1; i++)
	{
		char ch = startTime[i];
		if(startTime.length() == 5)
			//length of the time should be equal to 5.
		{
			if(startTime[2] == ':')
				//second index of time should be ':'.
			{
				if((ch >= '0' && ch <= '9') || ch == ':')
					//character of the time should be all digits or ':'.
				{
					if(startTime[0] == '0' || startTime[0] == '1')
						//if 0th index equals to 0 or 1,
							//and 3rd index equals to 0, 1, 2, 3, 4 or 5,
								//program will return TRUE
					{
						if (startTime[3] == '0' ||startTime[3] == '1'||startTime[3] == '2'||startTime[3] == '3'||
							startTime[3] == '4'||startTime[3] == '5')
						{
							status = true;
						}
					}
					else if (startTime[0] == '2')
						//if 0th index equals to 2,
						//and 1st index equals to 0, 1, 2, or 3
						//and 3rd index equals to 0, 1, 2, 3, 4 or 5,
						//program will return TRUE
					{
						if(startTime[1] == '0'|| startTime[1] == '1'|| startTime[1] == '2' || startTime[1] == '3')
						{
							if (startTime[3] == '0' ||startTime[3] == '1'||startTime[3] == '2'||startTime[3] == '3'||
								startTime[3] == '4'||startTime[3] == '5')
							{
								status = true;
							}
						}
					}
				}
			}
		}
	}

	return status;
}

int main()
{
	// This program that search bus route and time databases to find departure times for you.
	ifstream inputRoutes, inputTimes;
	string filenameR, filenameT, departureLocation, startTime;
	
	do
	// Ask file name for route database until it entered in the right format
	{
		cout << "Please enter a filename for route database: " ;
		cin >> filenameR;
		inputRoutes.open(filenameR.c_str());
		if(inputRoutes.fail())
		{
			cout << "cannot open routes database file" << endl;
		}	
	}
	while (inputRoutes.fail());

	do
	// Ask file name for route database until it entered in the right format
	{
		cout << "Please enter a filename for time database: " ;
		cin >> filenameT;
		inputTimes.open(filenameT.c_str());
		if(inputTimes.fail())
		{
			cout << "cannot open times database file" << endl;
		}	
	}
	while (inputTimes.fail());

	do
	{
		// Enter location.
		cout << "Please enter departure location: " ;
		cin >> departureLocation;

		// If departure location equals to "EXIT", program will stop.
		if(departureLocation == "EXIT")
		{
			inputRoutes.close();
			inputTimes.close();
		}
		// If departure location is something other than "EXIT", 
		// program will request start time of travel.
		else
		{
			do
			{ 
				cout << "Please enter start time of travel: ";
				cin >> startTime;
				if (departureTimeCheck(startTime) == 1)
				{
					//If user will enter time in the correct format, 
					//program will return you bus schedule.

					string line, routeEnd, routeStart, routeID, departureTime;
					
					cout << "The search results are: " <<endl;

					//Check Routes document line by line.
					while(getline(inputRoutes, line))
					{
						istringstream routesStream(line);
						routesStream >> routeID >> routeStart >> routeEnd;
						
						//If routeStart equals to departureLocation,
						//Check Times document line by line.
						if(routeStart == departureLocation)
						{
							string line1, routeID2;
							while(getline(inputTimes, line1))
							{
								istringstream timesStream(line1);
								timesStream >> routeID2 >> departureTime;

								//If route ID's in both files match,
								//Cout the bus schedule.
								if(routeID2 == routeID)
								{
									if(compare(startTime, departureTime) == 1)
									{
										cout << departureLocation << " "<<routeEnd<<" "<<departureTime<<endl;
									}
								}
							}
							//Clear Times document,
							//to make it work for other searches
							//until location entered as EXIT
							inputTimes.clear();
							inputTimes.seekg(0);
						}
					}
					//Clear Routes document,
					//to make it work for other searches
					//until location entered as EXIT
					inputRoutes.clear();
				    inputRoutes.seekg(0);
			    }
				
				else if (departureTimeCheck(startTime)== 0)
				{
					 //If start time will be in wrong format,
					 //program will display an ERROR message.

     			     cout << "Time is not in correct format" << endl;
				}
			}
			while(departureTimeCheck(startTime) == 0);
		}
	}
	//This program will run until, user enters location as "EXIT".
	while(departureLocation != "EXIT");
	return 0;
}