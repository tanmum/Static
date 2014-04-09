//				 		  String.cpp

#include "String.hpp"

String::String(char *str)
{
s = 0;								// Always initialize
length = 0;
initCopy(str);
}
    
String::String(long length)
{
s = 0;
String::length = 0; 

if (length > 0)
	create(length);
}    
    
String::~String()
{
if (s)
	{
	delete[] s;						// Deleting an array
	s = 0, length = 0;
	}
}

void String::initCopy(char *str)
{
if (str)
	{
	create(strLen(str));
	copy(str);
	}
}

void String::clear()
{
if (s)
	for (long i = 0; i < length; i++)
		s[i] = 0;
}

       
long String::ln()
{
long l = 0;
if (s)
	while (s[l]) 
		l++;
return l;
}       
       
void String::stncpy(char *dest, char *src, long n)
{
if (dest && src)
	while ((n-- > 0) && (*dest++ = *src++))
		;
}
  
void String::copy(char *str)
{
if (s && str)
	stncpy(s, str, length - 1);
}

long String::maX(long l, long m)
{
return (l >= m) ? l : m;
}

void String::create(long l)
{
length = maX(l+1, 2*length);	// avoid too frequent re-allocations
s = new char[length];
clear();
}

void String::prt(FILE *f)
{
	if (f)
		if (s)
			fprintf(f, "<%s>\n", s);
		else
			fprintf(f, "<>\n");
} 

long String::strLen(char *t)
{
long ret = 0;

if (t)
	while (*t++)
		ret++;

return ret;
}

void String::setTo(char *t)
{
if (t)
	{
	long l = strLen(t);  			// length needed
	l = (l >= 1 ? l : 1);			// consider it's at least equal to 1
	if (l > length - 1)				// allocate more space if needed
		{
		if (s) delete [] s, s = 0, length = 0;
		create(l);
		}
	copy(t);						// copy contents t is pointing to
	}
else
	clear();
}




          


