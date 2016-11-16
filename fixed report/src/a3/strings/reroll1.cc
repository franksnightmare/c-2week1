#include "strings.ih"

void Strings::reroll(string **oldStr, size_t oldCapacity,
	size_t oldSize)
{
	d_str = oldStr;
	d_capacity = oldCapacity;
	d_size = oldSize;
}
