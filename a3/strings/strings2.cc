#include "strings.ih"

// If the construction fails none of the
// exception guarantees are applicable.
// The caller of the constructor will
// want to know that it failed.

Strings::Strings(int argc, char *argv[])
try :
	Strings()
{
	for (size_t begin = 0, end = argc; begin != end; ++begin)
		add(argv[begin]);
}
catch (bad_alloc &ba)
{
	throw;
}
