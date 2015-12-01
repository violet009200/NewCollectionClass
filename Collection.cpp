//#include "Collection.h"
#include "LList.h"
//#include "Array.h"

	//virtual destructor
	Collection::~Collection(){
		//cout<<"		~Collection"<<endl;
		//delete this;
	}

	//default constructor
	Collection::Collection(){
		//cout<<"		default constructor"<<endl;
		size_ = 0;
	}

	//copy constructor
	Collection::Collection(const Collection& c){
		cout<<"		Collection: Copy Constructor is called"<<endl;
		size_ = c.size_;
	}

	Collection* Collection::copy(){
		cout<<"		Collection: Copy() is called"<<endl;
		Collection* newCollection = (*this).copy();
		cout<<"Collection copy"<<endl;
		return newCollection;
	}


	//accessor functions
	int Collection::getsize(){
		return size_;
	}

	void Collection::setsize(int s){
		this->size_ = s;
	}

	//concrete fuctions
	//if the collection has int, return true
	bool Collection::contains(int elem){
		cout<<"		Collection: contains() is called"<<endl;
		bool result = false;

		if(typeid(*this) == typeid(LList))
			result = (((LList&)*this).hasIt(elem));
		else{
			result = (((Array&)*this).hasIt(elem));
			
		}
		return result;
	} 
	
	Collection* Collection::map(int (*fn)(int)){
		cout<<"		Collection: map() is called"<<endl;
		Collection* result;

		if(typeid(*this) == typeid(LList))
			result = (((LList&)*this).helpMap(fn));
		else{
			result = (((Array&)*this).helpMap(fn));
			
		}
		return result;
	}


