=== Instantiating a class that inherits from another on the heap: ===

-	Base Pointer to Derived Object (The Polymorphic Way)

	const Animal* i = new Cat();

	-	A pointer of the base class type (Animal*) points to an object of
		the derived class type (Cat). This is exactly what the subject
		requests for the main testing suite.
	
	-	PROS: This enables Subtype Polymorphism. It allows you to treat
		different derived objects uniformly.If you want to put this cat
		into an array alongside dogs, you can, because an Animal* pointer
		can hod both a Cat* and a Dog*.

=== STATIC BINDING ===

-	Static binding (also known as early binding or compile-time binding)
	refers to the mechanism where the compiler connects a function call
	to the actual function definition at compile time, long before the 
	program ever runs.

	Because this decision is locked in during compilation, the compiler
	relies strictly on the type of the pointer or reference you are 
	using, completely ignoring what type of object is actually sitting 
	in memory.

	When we created a WrongCat object on the heap but saved it inside 
	a WrongAnimal* pointer, we were witnessing static binding in action:

	const WrongAnimal* meta = new WrongCat();
	meta->makeSound();

	Here is how the compiler processes that makeSound() call under 
	static binding:

	(1)	Look at the pointer: The compiler checks the variable type on 
		the left. It sees meta is a pointer of type WrongAnimal*.
	
	(2)	Check for virtual: It checks if makeSound() was declared with
		the virtual keyword in the WrongAnimal class definition.

	(3)	Make the final decision: Since it is not virtual, the compiler
		says: "Alright, this is a standard function call. I don't care
		what meta points to at runtime. Because the pointer type is
		WrongAnimal*, I am hardcoding a jump straight to
		WrongAnimal::makeSound() right now."

=== KEY CHARACTERISTICS OF STATIC BINDING ===

*	RESOLVED AT COMPILE TIME: The executable binary already contains
	the exact memory address of the function to jump to.

*	BASED ON POINTER/REFERENCE TYPE: The compiler looks exclusively
	at the declared type of the reference or pointer.

*	FASTER EXECUTION: Because the decision is made upfront, there is
	zero performance overhead at runtime. The CPU doesn't have to 
	look anything up; it just runs the instructions.

*	DEFAULT IN C++: By default, all member functions in C++ use 
	static binding unless you explicitly opt into dynamic binding by
	adding the virtual keyword.

			  === STATIC BINDING VS. DYNAMIC BINDING ===

FEATURE				|	STATIC BINDING			|	DYNAMIC BINDING
					|	(early binding)			|	(late binding)
----------------------------------------------------------------------
when it happens		|	compile time			|	runtime
----------------------------------------------------------------------
trigger mechanism	|	normal functions		|	virtual functions
					|	(non-virtual)			|
----------------------------------------------------------------------
decision basis		|	type of the pointer/	|	type of the actual	
					|	reference				|	object in memory
----------------------------------------------------------------------
OOP concept			|	overloading / standard	|	subtype
					|	inheritance				|	polymorphism
----------------------------------------------------------------------

*	By leaving out the "virtual" keyword in your "Wrong" classes, you
	forced C++ to fall back to its default static binding, which
	perfectly demonstrated why polymorphism is completely broken
	without it.