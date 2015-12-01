/*
	Collection class 
	This is abstract class fo Array and LList class
*/
#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <stdlib.h>  
//#include "LList.h"

using namespace std;


class Collection{

	public:
		//abstact function
		virtual Collection* add(int,int)=0; //add element into int position
		virtual Collection* remove(int)=0; //remove element which has int
		virtual int& operator[](int)=0; //take index return the element at the index
		virtual void operator=(Collection*)=0; //take input collection instance do deep copy
		

		//virtual destructor
		virtual ~Collection();
		virtual Collection* copy();

		//default constructor
		Collection();
		//copy constroctor
		Collection(const Collection&);

		//accessor functions
		int getsize();
		void setsize(int);

		//concrete fuctions
		virtual void display()=0;
		bool contains(int); //if the collection has int, return true
		Collection* map(int (*fn)(int));


	protected:
		int size_;
};

