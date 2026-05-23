Instantiating a class that inherits from another on the heap:

-	Base Pointer to Derived Object (The Polymorphic Way)

	const Animal* i = new Cat();

	-	A pointer of the base class type (Animal*) points to an object of
		the derived class type (Cat). This is exactly what the subject
		requests for the main testing suite.
	
	-	PROS: This enables Subtype Polymorphism. It allows you to treat
		different derived objects uniformly.If you want to put this cat
		into an array alongside dogs, you can, because an Animal* pointer
		can hod both a Cat* and a Dog*.