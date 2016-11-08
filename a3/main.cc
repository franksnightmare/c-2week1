#include "strings/strings.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	Strings strings1(argc, argv);
	string test("Blah!");
	strings1.add(test);
	
	for (size_t index = 0; index != strings1.size(); ++index)
		cout << strings1.at(index) << '\n';
}
