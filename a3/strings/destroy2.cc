#include "strings.ih"

void Strings::destroy(size_t start, size_t end)
{
	for (size_t index = start; index != end; ++index)
	{
		delete d_str[index];
	}
    delete[] d_str;
}
