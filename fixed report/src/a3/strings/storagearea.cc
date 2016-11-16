#include "strings.ih"

// Basic: This function does not cause any leaks
// Strong: This function rolls back the capacity
//          if enlarged fails.

string **Strings::storageArea()
{
	// enough room?
	if (d_size + 1 < d_capacity)
		// return the current memory block
		return d_str;
	
	try
	{
		// double the capacity
		d_capacity <<= 1;
		// return ptr to the enlarged space
		return enlarged();
	}
	catch(bad_alloc &ba)
	{
		d_capacity >>= 1;
		throw;
	}
}

