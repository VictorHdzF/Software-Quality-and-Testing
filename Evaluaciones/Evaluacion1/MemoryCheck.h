#include <stdlib.h>

using namespace std;

static int i = 0;

class MemoryCheck 
{
public:

	void* operator new(size_t n) 
	{
		i++;
		void* temp = ::operator new(n);
		return temp;
	}

	void* operator new[](size_t n) 
	{
		i++;
		void* temp = ::operator new(n);
		return temp;
	}

	void operator delete(void * p) 
	{
		i--;
		::operator delete(p);
	}

	void operator delete[](void * p) 
	{
		i--;
		::operator delete(p);
	}
};
