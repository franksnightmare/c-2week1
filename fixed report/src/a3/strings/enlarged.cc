#include "strings.ih"

// Basic: Nothing is allocated if rawPointers fails.
// Strong: Nothing is changed if the exception occurs.

string **Strings::enlarged()
{
	string **ret = 0;
	// new block, doubling the # pointers
	try
	{
		ret = rawPointers(d_capacity);
	}
	catch (bad_alloc &ba)
	{
		throw;
	}

	// copy the existing pointers
	for (size_t idx = 0; idx != d_size; ++idx)
		ret[idx] = d_str[idx];
	
	return ret;
}
