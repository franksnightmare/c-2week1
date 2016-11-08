#include "strings.ih"

std::string &Strings::safeAt(size_t idx) const
{
    static string empty;

    empty.clear();
	
	if (idx >= d_size)
		throw out_of_range("(Strings) Unable to get string at " << idx << ": \"out of bounds\".\n");
	
    return idx < d_size ? *d_str[idx] : empty;
}
