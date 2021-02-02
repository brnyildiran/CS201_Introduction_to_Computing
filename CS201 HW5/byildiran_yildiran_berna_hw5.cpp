#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

struct studentsinfo
{
	string studentID2;
	string studentname;
	double grade;
};


void Insert(std::vector<studentsinfo> & a ,int left,int right)
// precondition: left <= right
// postcondition: a[left] <= ... <= a[right]
//     
// standard insertion sort between left/right
// for use in small quick/merge cases as well
{
    int k,loc;
    
    for(k=left+1;k<=right;k++) 
    {
        // shift elements to make room for a[k]
        
        studentsinfo hold = a[k];   // insert this element
        loc = k;            // location for insertion
        while (left < loc  && hold.grade > a[loc-1].grade)
        {
            a[loc] = a[loc-1];
            loc--;
        }
        a[loc] = hold;
    }
}

void InsertSort(std::vector<studentsinfo> & a, int size)
// precondition: size = # of elements of a
// postcondition: a is sorted
//
// uses insertion sort     
{
    Insert(a,0,size-1);
}


void print(vector<studentsinfo> & s, int rank)
{
	int i = rank-1;
		cout << rank << ", " << s[i].studentID2 <<", " << s[i].studentname
			<< ", " << s[i].grade << endl;
	
}

bool inputCheckRank(int rank)
{
	bool status = true;
	if (rank < 0 && rank > 15) 
	{
		status = false;
	}
	return status;
}
vector<studentsinfo> create(ifstream & inputGrades, ifstream & inputStudents) 
{
	string studentID1, studentID2;
	double grade, grade1 = 0, grade2 = 0, grade3 = 0;
	string line1, line2;
	vector<studentsinfo> studentRecords;
	while(getline(inputStudents, line2))
	{   
		string studentname = "";

		int index = line2.find(" ");
		studentID2 = line2.substr(0,index);
		studentname = line2.substr(index + 1, line2.length() - index);
		int decision =0;

		studentsinfo information;
		information.studentID2 = studentID2;
		information.studentname = studentname;
		information.grade = -1;
		studentRecords.push_back(information);
	}	

	int decision = 0;
	while(getline(inputGrades,line1))
	{
		if(line1 == "")
		{
			decision = 0;
		}

		else if(line1 == "***MIDTERM***" )
		{
			decision = 1;
		}
		else if(line1 == "***HOMEWORK***")
		{
			decision = 2;
		}
		else if(line1 == "***FINAL***")
		{
			decision = 3;
		}
		else
		{
			istringstream iss(line1);
			iss >> studentID1 >> grade;
			if(decision == 1)
			{
				for(unsigned int i=0; i < studentRecords.size(); i++) 
				{	
					if(studentRecords[i].studentID2 == studentID1)
					{
						if(studentRecords[i].grade == -1)
						{
							studentRecords[i].grade = 0;
						}

						studentRecords[i].grade +=grade * 0.2;
					}
				}
			}
			if(decision == 2)
			{
				for(unsigned int i=0; i < studentRecords.size(); i++) 
				{	
					if(studentRecords[i].studentID2 == studentID1)
					{
						if(studentRecords[i].grade == -1)
						{
							studentRecords[i].grade = 0;
						}
						studentRecords[i].grade +=grade*0.1;
					}
				}
			}
			if(decision == 3)
			{
				for(unsigned int i=0; i < studentRecords.size(); i++) 
				{	
					if(studentRecords[i].studentID2 == studentID1)
					{
						if(studentRecords[i].grade == -1)
						{
							studentRecords[i].grade = 0;
						}
						studentRecords[i].grade += grade*0.3;
					}
				}
			}
		}
	}
	return studentRecords;
}
int main()
{
	ifstream inputGrades, inputStudents;
	string filenameGrades, filenameStudents, line1, line2;
	int rank;

	cout << "Please enter a filename for Students Grades Results: ";
	cin >> filenameGrades;
	inputGrades.open(filenameGrades.c_str());

	if(inputGrades.fail())
	{
		cout << "Can not find the requested file. Terminating application ..." << endl;
	}
	else
	{
		cout << "Please enter a filename for Students Names : ";
		cin >> filenameStudents;
		inputStudents.open(filenameStudents.c_str());

		if(inputStudents.fail())
		{
			cout << "Can not find the requested file. Terminating application ..." << endl;
		}
		else
		{
			vector<studentsinfo>studentRecords = create(inputGrades, inputStudents);
			InsertSort(studentRecords,studentRecords.size());
			for(int i = studentRecords.size()-1; i > 0; i--)
			{
				if(studentRecords[i].grade <=0)
				{
					studentRecords.pop_back();
				}

			}

			do
			{
				do
				{

					cout << "Enter the rank you want to query (enter 0 to exit): ";
					cin >> rank;
					if((rank < 0) || (rank > studentRecords.size()) )
					{
						cout << "Rank needs to be greater than 0 and smaller than " << studentRecords.size()+1 << "!" << endl;

					}
				}
				while(rank < 0 || rank > studentRecords.size());

				if(rank == 0)
				{
					cout << "Exiting..." << endl;
					inputGrades.close();
					inputStudents.close();
					return 0;
				}
				else
				{
				print(studentRecords, rank);
				}
			}
			while(rank != 0);
		}
	}
	return 0;
}