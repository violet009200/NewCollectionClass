#include "Collection.h"
//#include "LList.h"


class Array: public Collection
{
	public:
		//default construct
		Array(int);
		~Array();
		int arraySize;
		int* arrayPtr;

		//member function
		Collection* add(int,int);
		Collection* remove(int);
		int& operator[](int);
		void operator=(Collection*);

		Array* copy();
		void display();
		//int getIndex();
		int getSize();

		//helpfunction for contains()
		bool hasIt(int);
		Array* helpMap(int (*fn)(int));


};