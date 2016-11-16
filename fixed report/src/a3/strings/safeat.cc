#include "strings.ih"

std::string &Strings::safeAt(size_t idx) const
{
    static string empty;

    empty.clear();
	
	if (idx >= d_size)
	{
		string message = "(Strings) Unable to get string at ";
		message += idx;
		message += ": \"out of bounds\".\n";
		throw out_of_range(message);
	}
	
    return idx < d_size ? *d_str[idx] : empty;
}
