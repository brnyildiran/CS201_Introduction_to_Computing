#include<iostream>
#include<string>

using namespace std;

bool inputCheckSource(string source_string)
{
	bool statue = true;

	if (source_string.length() == 0 )
	{
		statue = false;
	}
	else
	{
		for (unsigned int i = 0 ; i < source_string.length() ; i++)
		{
			char ch = source_string[i];
			if(ch >= 'a' && ch <= 'z')
			{
				if(ch == '?')
				{
					statue = false;
				}
			}
			else
			{
				statue = false;
			}
		}
	}
	return statue;
}
bool inputCheckSearch(string search_string, string source_string)
{
	bool statue = true;

	if (search_string.length() == 0 )
	{
		statue = false;
	}
	else if (search_string.length() > source_string.length())
	{
		statue = false;
	}
	else
	{
		for (unsigned int i = 0 ; i < search_string.length() ; i++)
		{
			char ch = search_string[i];
			if(ch >= 'a' && ch <= 'z' && (ch = '?'))
			{
				statue = true;
			}
			else 
			{
				if(ch == '?')
				{
					statue = false;
				}
			}
		}
	}
	return statue;
}

void stringfind(string source_input,string search_input)
{

    for( size_t index = source_input.find(search_input);index!=string::npos;
         index=source_input.find(search_input,index+search_input.length()))
    {
		cout << search_input<< " has been found at index " << index << endl;
		
    }

	if(size_t index = source_input.find(search_input))
	{
		cout << "For the source word \"" << source_input << "\" and search word \"" 
		     << search_input << "\", no match has been found." << endl;
	}
}



int main()
{
	string source_string, search_string;
	int choice=5;
	
	//display the aim of the program
	cout << "This program searches a search string in a source string with the option of wild cards." << endl;
    cout << endl;
	cout << "Example inputs with their meaning in parantheses:" << endl;
    cout << "1 thislectureisawesome (to enter a new source string)" << endl;
    cout << "2 lecture (to enter a new source string)" << endl;
    cout << "2 t?r? (to enter a source string with wildcards)" << endl;
    cout << "3 (to exit the program)" << endl;
	cout << endl;

	while(choice != 3 )
	{
		cout << "Enter your choice and string: " << endl;
	    cin >> choice;
	    if (choice == 1)
	    {
		    cin >> source_string;

		    if (inputCheckSource(source_string) == 0)
		    {
			    cout << "Wrong input format! Try again.";
		        cout << endl;
		    }
		    else if (inputCheckSource(source_string) == 1)
		    {
			    cout << "Source word has been changed to " << source_string << endl;
			    cout << endl;  
		    }
	    }
        else if ( choice == 2 )
	    { 
			if(source_string.length() != string::npos)
			{
				cin >> search_string;
		        
		        if(inputCheckSearch(search_string, source_string) == 0 )
		        {
				    cout << "Wrong input format! Try again." << endl;
		        }
		        else if(inputCheckSearch(search_string, source_string) == 1)
		        {
					stringfind(source_string, search_string);
		        }
	        }
			else
			{
				cout << "Wrong input format! Try again." << endl;
		        cout << endl;
			}
	    }
	    else if (choice == 3)
	    {
		    cout << "See you!" << endl;
	    }
	    else
	    {
		    cout << "Choice can be 1, 2 or 3! Try again.";
		    cout << endl;
	    }
    }
	return 0;
}