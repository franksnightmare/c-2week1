#include "strings.ih"

// Basic: tmp is deleted after an allocation exception
//         from "new string(next)".
// Strong: Capacity is rolled back if
//          "new string(next)" fails but not
//          "storageArea()".
// Nothrow: This function does not throw any
//           exceptions.

void Strings::add(string const &next)
{
	string **tmp = 0;
	size_t oldCapacity = d_capacity;
	try
	{
		tmp = storageArea();
		
		tmp[d_size] = new string(next);
	}
	catch (bad_alloc &ba)
	{
		delete[] tmp;
		d_capacity = oldCapacity;
		cerr << "(Strings) Unable to add string:"
			<< " \"memory allocation failed\".\n";
		return;
	}

	// destroy old memory if new storageArea
	if (tmp != d_str) // was allocated
	{
		// destroy the old string * array
		destroy();
		d_str = tmp;
	}

	++d_size;
}
