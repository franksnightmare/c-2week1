#include "strings.ih"

// Basic: If the constructor fails then
//         the allocations are not finished
//         so there are no leaks.
// NOT Strong: There is no state to roll back to.
// NOT Nothrow: This constructor throws.

// This function may throw bad_alloc.

Strings::Strings()
	d_str(rawPointers(1))
{}
