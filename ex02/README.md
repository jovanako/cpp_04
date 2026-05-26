ABSTRACT CLASS

-	Defines an abstract type which cannot be instantiated, but
	can be used as a base class.

"declarator virt-specifier(optional) = 0"

-	Here the sequence "=0" is known as "pure-specifier", and
	appears	either immediately after the declarator or after
	the optional virt-specifier(override or final).

-	pure-specifier cannot appear in a member function
	definition or "friend" declaration

(1) THE CORE CONCEPT: PURE VIRTUAL FUNCTIONS & ABSTRACT CLASSES

	To prevent a class from being instantiated directly, you
	must turn it into an ABSTRACT CLASS. In C++, a class
	automatically becomes abstract the moment it contains at
	least one PURE VIRTUAL FUNCTION.

	A pure virtual function is a function that has no definition
	in the base class; it acts purely as a contract. It forces 
	any derived class (Dog, Cat) to implement its own version of 
	that function, or else those derived will also become
	abstract and uninstantiable.

	virtual void makeSound() const = 0;

	In C++, a pure virtual function CAN have a body in the .cpp
	file, but it is standard practice to delete its definition 
	from Animal.cpp because it can no longer be called directly
	anyway.

	WHAT CAN BE MADE PURE VIRTUAL?

	-	Standard Virtual Member Functions
	
	-	The Base Class Destructor

	Crucial trap for C++: If you make a destructor pure virtual,
	you must still provide a body for it in your .cpp file 
	(e.g., Animal::~Animal() {}). This is because when a derived
	object like Dog is destroyed, it always winds down and calls
	its parent's destructor. If the parent destructor has no 
	physical body code, the linker will crash with an undefined
	reference error!

	WHAT CANNOT BE MADE PURE?

	-	Non-Virtual Member Functions

	-	Static Functions

	-	Friend Functions

	Static member functions belong to the class itself, not to an
	object instance, so they cannot be virtual or pure virtual.

	Friend functions are not actual members of the class, so they
	cannot be virtual or pure virtual.

	WHAT MUST NEVER BE MADE PURE?

	-	Constructors

	A constructor's job is to allocate and set up an object in	
	memory. A pure virtual function implies that the setup mechanics
	don't exist yet and must be defined by a child class. Because a
	child class cannot inherit its parent's constructor, making a
	constructor pure virtual makes zero logical sense to the compiler.

SUMMARY BLUEPRINT FOR ABSTRACT CLASSES

class AbstractClass {
		public:
			// 1. Constructors: NEVER virtual, NEVER pure
			AbstractClass();

			// 2. Standard Functions: CAN be pure virtual (makes the class abstract)
			virtual void pureFunction() = 0;

			// 3. Destructor: MUST be virtual. CAN be pure virtual (but requires a body anyway)
			virtual ~AbstractClass() = 0;
}