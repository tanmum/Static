// Person.hpp

#include "String.hpp"
#include "List.hpp"

class Person
{
private:

	int rank;
	String name;
	String position;
    
    static List instances;

public:

	static void showInstances();						// Show all instances

	Person(int r, char *nm = 0, char *po = 0);
	~Person();
	void show();
};


