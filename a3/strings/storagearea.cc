#include "strings.ih"

// Basic: This function does not cause any leaks
// Strong: This function rolls back the capacity
//          if enlarged fails.

string **Strings::storageArea()
{
    if (d_size + 1 < d_capacity)        // enough room?
        return d_str;                   // return the current memory block
	
	try
	{
		d_capacity <<= 1;               // double the capacity
		return enlarged();              // return ptr to the enlarged space
	}
	catch(bad_alloc)
	{
		d_capacity >>= 1;
		throw;
	}
}

