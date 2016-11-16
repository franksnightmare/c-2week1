#include "strings.ih"

// Basic: If the constructor fails then
//         the allocations are not finished
//         so there are no leaks.
// NOT Strong: There is no state to roll back to.
// NOT Nothrow: This constructor throws.

// This function may throw bad_alloc.

Strings::Strings(int argc, char *argv[])
	Strings()
{
	for (size_t begin = 0, end = argc; begin != end;
			++begin)
		add(argv[begin]);
}
