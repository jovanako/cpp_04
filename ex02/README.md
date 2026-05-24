Brain::Brain() {
	std::cout << "Brain Default Constructor called" << std::endl;
}

-	This code snippet will initialize an array of 100 empty strings.

*	Why this happens automatically in C++?

	This behavior is driven by how C++ manages compound types and 
	object lifecycles:

	(1)	Object Arrays Invoke Default Constructors: When an object of
		a class (like Brain) is instantiated, C++ automatically
		initializes all its member attributes BEFORE executing the
		code inside the constructor's curly braces {}.
		For an array of objects, C++ steps through the array
		sequentially from index 0 to 99 and calls the default 
		constructor for every single element.
	
	(2)	std::string Has a Built-In Default State: The default
		constructor of std::string is explicitly designed to
		initialize itself as an empty string (a string with a length
		of 0 containing only the null terminator \0).
	
	So by the time your code hits std::cout, C++ has already silently
	run the std::string default constructor 100 times in the background.

!!! Objects vs. Primitive Types !!!

	This automatic initialization only happens because std::string is a
	class type (an object). If your array had been a primitive data type
	- such as integers or raw pointers - C++ would not initialie them for
	you:

	class Brain {
		private:
			int ideas[100];				// primitive type array!
			std::string* ptrs[100];		// pointer array (also primitive)!
	};

	If you leave your constructor empty with primitive arrays, the memory
	slots will contain random, unpredictable garbage data left over from
	your RAM. If you ever switch to primitive types or pointers, you must
	explicitly clear them out yourself using a loop or a member initializer
	list:

	Brain::Brain() {
		for (int i = 0; i < 100; i++) {
			ideas[i] = 0;		// clears garbage data for primitives
		}
	}

	Explicit initialization is ONLY mandatory for primitives/pointers!

=== new keyword ===

When you use "new", you are telling the computer to do two distinct 
things in a single seamless step:

(1)	Allocate memory: It allocates a block of raw memory on the heap
	large enough to hold your object.

(2)	Initialize memory: It immediately runs a constructor to initialize
	that freshly allocated memory slot.

Which constructor it runs depends entirely on what parameters you pass
inside the parentheses ().