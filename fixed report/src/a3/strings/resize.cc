#include "strings.ih"

// Basic: If reserve fails then nothing is changed
//         so there are no leaks.
//        If the initializing of an empty string fails
//         then all the new empty strings will be
//         deleted along with the resized allocation.

// Strong: If reserve fails then the requested
//          enlarging can not be performed
//          and so resize stops.
//         If the initializing of the empty strings
//          fails then the whole class is rolled back.

// Nothrow: This function throws no exceptions.

void Strings::resize(size_t newSize)
{
	string **oldStr = d_str;
	size_t oldSize = d_size;
	size_t oldCapacity = d_capacity;
	
	// make sure there's enough memory
	reserve(newSize);
	if (d_capacity < newSize)
	{
		cerr << "(Strings) Could not resize:"
			<< " \"reserve failed\".";
		return;
	}
	
	// enlarging? initialize new strings
	if (d_size > newSize)
	{
		try
		{
			for (; d_size != newSize; ++d_size)
				d_str[d_size] = new string;
		}
		catch (bad_alloc &ba)
		{
			destroy(oldSize, d_size);
			d_str = oldStr;
			d_capacity = oldCapacity;
			d_size = oldSize;
			cerr << "(Strings) Unable to increase size:"
				<< " \"Memory allocation failed.\"\n";
		}
	}
	// shrinking? remove excess strings
	else if (newSize < d_size)
	{
		for (; d_size-- != newSize; )
			delete d_str[d_size];
	}
}
