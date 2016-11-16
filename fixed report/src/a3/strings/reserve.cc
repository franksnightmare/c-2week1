#include "strings.ih"

// Basic: If "enlarged()" fails then there
//         are no allocations or leaks.
// Strong: The capcity is rolled back if
//          enlarging fails.

// This function may throw bad_alloc.

void Strings::reserve(size_t nextCapacity)
{
	if (d_capacity < nextCapacity)
	{
		size_t oldCapacity = d_capacity;
		while (d_capacity < nextCapacity)
			d_capacity <<= 1;
		
		try
		{
			d_str = enlarged();
		}
		catch (bad_alloc &ba)
		{
			d_capacity = oldCapacity;
			string message = "(Strings) Unable to increase";
			message += " size: \"memory allocation";
			message += " failed\".\n";
			throw bad_alloc(message);
		}
	}
}
