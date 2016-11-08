#include "strings.ih"

Strings::Strings()
try
:
    d_str(rawPointers(1))
{}
catch (bad_alloc)
	cerr << "(Strings) Unable to create strings object: \"memory allocation failed\".\n";
