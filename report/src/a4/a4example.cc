class Quiter
{
	string d_message = "Program quit!\n";
};

int main()
{
	try
	// nesting deeper
	{
		// nesting deeper
		{
			// nesting deeper
			{
				// statements of deepest nested level
				throw Quiter;
				// This terminates the program,
				// the exception is caught by main
				// and all destructors are called.
			}
		}
	}
	catch (Quiter &quit)
	{
		cerr << quit.d_message;
	}
}
