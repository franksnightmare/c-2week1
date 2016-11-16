#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <iosfwd>

// All public member functions have the basic
//  guarantee.

// All public member functions ahve the strong
//  	guarantee.

// Out of all the public member functions only
//  the constructors, reserve and resize function
//  do not ahve the nothrow guarantee.

class Strings
{
	size_t d_size = 0;
	size_t d_capacity = 1;
	// now a double *
	std::string **d_str;

	public:
		Strings();

		Strings(int argc, char *argv[]);
		Strings(char **environLike);

		~Strings();

		size_t size() const;
		size_t capacity() const;
		// for const-objects
		std::string const &at(size_t idx) const;
		// for non-const objects
		std::string &at(size_t idx);

		// add another element
		void add(std::string const &next);

		void resize(size_t newSize);
		void reserve(size_t newCapacity);
		
	private:
		// private backdoor
		std::string &safeAt(size_t idx) const;
		// to store the next str.
		std::string **storageArea();
		void destroy();
		// also deletes allocated strings
		void destroy(size_t start, size_t end);
		// to d_capacity
		std::string **enlarged();
		std::string **rawPointers(size_t nPointers);
		
		// to roll back
		void reroll(string **oldStr, size_t oldCapacity,
			size_t oldSize)
};

// potentially dangerous practice:
// inline accessors
inline size_t Strings::size() const		 
{
	return d_size;
}

inline size_t Strings::capacity() const
{
	return d_capacity;
}

inline std::string const &Strings::at(
	size_t idx) const
{
	return safeAt(idx);
}

inline std::string &Strings::at(size_t idx)
{
	return safeAt(idx);
}

		
#endif

