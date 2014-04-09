//
//  main.cpp
//  Static
//
//  Created by Tan Bui on 4/9/14.
//  Copyright (c) 2014 tanbui. All rights reserved.
//

#include <stdlib.h>
#include "Person.hpp"
#include <iostream>
using namespace std;

int main()
{
	Person john(4, "John Fargo", "VP Engineering");
	Person jerry(3, "Jerry White", "Sales Manager");
	Person linda(5, "Linda Smith", "COO");
	Person mark(2, "Mark Roll", "Production Manager");
    
	std::cout << "****" << "After adding John, Jerry, Linda and Mark" << '\n';
	
	Person::showInstances();
    
	{
		Person max(3, "Max Rainford", "Site Manager");
		
		std::cout << "****" << "After Adding Max" << '\n';
		Person::showInstances();
	}
    
	std::cout << "****" << "After Max goes out of scope" << '\n';
	Person::showInstances();
	
	return 0;
}

