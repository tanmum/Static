#include "List.hpp"

List::List(List &lr) : start(0), current(0)
{
	copy(lr);
}

List::List(List *lp) : start(0), current(0)
{
	if (lp)
		copy(*lp);
}

void List::copy(List& lr)
{
	for (void *item = lr.restart(); item; item = lr.getNextItem())
		append(item);
}

void List::append(void *item)					// Append an item
{
	if (!start)
		start = new Link(item);					// Create the first link to this item
	else
		start->append(item);					// Delegate this append to first link
}

void List::remove(void *item)					// Append an item
{
	if (item)
		if (start)
			if (start->getItem() == item)		// If item is found as the first item
				{
				Link *tmp = start;				// ...keep reference to fist Link
				start = start->getNextLink();	// ...set start to its successor
				tmp->setNextLink(0);			// ...disconnect that first item
				delete tmp, tmp = 0;			// ...get rid of it
				}
			else
				start->remove(item);			// Delegate the removal
}

void *List::restart()							// Restart from first item
{
	void *ret = 0;

	if (current = start)						// Make current point to start link
		ret = current->getItem();				// Return start item, if any

	return ret;									// Return either 0 or firts item
}

void *List::getNextItem()						// Return item next to current, if any
{
	void *ret = 0;
	
	if (current)								// If there is a current item
		if (current = current->getNextLink())	// if there is a next-to-current item
			ret = current->getItem();			// return it

	return ret;									// Return either 0 or the next item
}

List::Link::Link(void *i)				// Constructor
{
	item = i;							// Point to the item
	next = 0;							// No neighbor to start with
}

void List::Link::append(void *it)		// Append an item
{
	if (next)							// If there is a neighbor, 
		next->append(it);				// ... delegate append to him
	else								// else
		next = new Link(it);			// ... create that neighbor and have him hold the item
}

void List::Link::remove(void *it)		// Remove an item
{
	if (next)							// If there is a neighbor
		if (next->getItem() == it)		// ...and it's holding the item
			{
			Link *tmp = next;
			next = next->getNextLink();	// ...skip it
			tmp->setNextLink(0);		// ...disconnect it
			delete tmp, tmp = 0;		// ...and drop it
			}
		else
			next->remove(it);
		
}


List::Link::~Link()						// Destructor
{
	if (next)							// If there is a neighbor,
		delete next, next = 0;			// ... delete him
}

List::Link *List::Link::getNextLink()	// Return this Link's neighbor
{
	return next;
}		


