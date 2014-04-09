// Person.cpp

#include "stdio.h"
#include "Person.hpp"

List Person::instances;

void Person::showInstances()		// Shows all Person instances
{
    for (auto go = (Person*)Person::instances.restart(); go; go = (Person*)Person::instances.getNextItem()) {
        go->show();
    }
}


Person::Person(int r, char *nm, char *po) : name(nm), position(po), rank(r)
{
    Person::instances.append(this);
}

Person::~Person()
{
    Person::instances.remove(this);
}

void Person::show()
{
	name.prt();
	position.prt();
	printf("Rank: %d\n\n", rank);
}

