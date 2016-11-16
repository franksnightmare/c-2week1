#include <iostream>
#include <string>

using namespace std;

//Exclusive class to exit the program
class Quiter {};

int main()
try
// nesting deeper
{
	// nesting deeper
	{
		// nesting deeper
		{
			// statements of deepest nested level
			try
			{
				Quiter x;
				throw x;
				// This terminates the program,
				// the exception is caught by the
				// same-level catch and then
				// rethrown to upper levels
				// until one catch (Quiter) is
				// founded.
			}
			catch(...)
			{
				throw;
			}
		}
	}
}
catch (Quiter &quit)
{
	cout << "Ending of program" << endl;
}
