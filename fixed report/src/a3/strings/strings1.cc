#include "strings.ih"

// If the construction fails none of the
// exception guarantees are applicable.
// The caller of the constructor will
// want to know that it failed.

Strings::Strings()
try :
	d_str(rawPointers(1))
{}
catch (bad_alloc &ba)
{
	cerr << "(Strings) Unable to create strings object:"
		<< " \"memory allocation failed\".\n";
	throw;
}
