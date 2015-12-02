//#include "Collection.h"
#include "Array.h"
#include "node.h"

class LList: public Collection
{
	public:
		node *head;
		
		//default construct
		LList();
		~LList();

		//member function
		Collection* add(int,int);
		Collection* remove(int);
		int& operator[](int);
		void operator=(Collection*);

		void deleteAll();
		LList* copy();
		void display();
		
		int getSize();

		


};