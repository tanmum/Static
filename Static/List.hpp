class List
{
private:
	class Link									// This is an inner class
	{
		void *item;								// The item this Link holds
		Link* next;								// This Link's next neighbor
	public:
		Link(void *i);							// Constructor taking this Link's item
		Link *getNextLink();					// Return this Link's neighbor
		void setNextLink(Link *l){next = l;}
		~Link();								// Destructor
		void *getItem() {return item;}			// Get this Link's item
		void append(void *it);					// Append this item to the list of Links
		void remove(void *it);					// remove this item from the list of Links
	};

	Link *start;
	Link *current;
	void copy(List&);

public:
	List() : start(0), current(0) {}
	List(List&);
	List(List*);

	~List() {if (start) delete start, start = 0;}

	void append(void *);
	void remove(void *);						// Remove an item from the list
	void *getNextItem();
	void *restart();
};


