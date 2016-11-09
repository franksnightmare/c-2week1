#include "strings.ih"

// If the construction fails none of the
// exception guarantees are applicable.
// The caller of the constructor will
// want to know that it failed.

Strings::Strings(char **environLike)
try :
	Strings()
{
	while (*environLike)
		add(*environLike++);
}
catch (bad_alloc &ba)
{
	throw;
}
