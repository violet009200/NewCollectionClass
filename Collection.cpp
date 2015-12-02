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
		
		if(typeid(*this) == typeid(LList)){
			node* curNode = ((LList&)*this).head;

			if(curNode == NULL){
				cerr<<"LList is empty"<<endl;
				return false;
			}

			while(curNode->next != NULL){
				if(curNode->value == elem){
					cout<<"LList has the elem"<<endl;
					return true;
				}
				else curNode = curNode->next;
			}
			cout<<"LList does not have the elem"<<endl;
			return false;
			
		}
		else{

			if(((Array&)*this).arrayPtr == NULL){
			cerr<<" Array is Empty"<<endl;
			exit(0);
		}
		int i = 0;
		while(i<size_){
			if(((Array&)*this).arrayPtr[i] == elem){
				cout<<"Array has the elem"<<endl;
				return true;
			}
			else i++;
		}
		cout<<"Array does not have the elem"<<endl;
		return false;
			
			
		}
		
	} 
	
	Collection* Collection::map(int (*fn)(int)){
		cout<<"		Collection: map() is called"<<endl;
		Collection* result;

		if(typeid(*this) == typeid(LList)){
			node* curNode = ((LList&)*this).head;
		while(curNode != NULL){
			curNode->value = fn(curNode->value);
			curNode = curNode->next;
		}
		return this;
		
		}
		else{

			int i = 0;
		while(i< size_){
			((Array&)*this).arrayPtr[i] = fn(((Array&)*this).arrayPtr[i]);
        	i++;
		}
		return this;
			
			
		}
	
	}


