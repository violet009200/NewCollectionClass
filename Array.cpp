#include "Array.h"

	Array::Array(int s){
		//fixed size;
		arraySize = s;
		arrayPtr = new int[s];
		this->size_ = arraySize;
	}

	Array::~Array(){
		cout<<"		~Array()"<<endl;
	
		delete[] arrayPtr;
	}

	//member function
	Collection* Array::add(int elem, int position){
		//cout<<"		Array add() is called"<<endl;	
		cerr<<"		ERROR:Array add() is called"<<endl;	
		return this;
	}

	Collection* Array::remove(int elem){
		cout<<"		ERROR:Array remove() is called"<<endl;
	
		return this;
	}

	//take index return the element at the index
	int& Array::operator[](int index){
		cout<<"		Array operator[] is called"<<endl;
		cout<<"	finding "<<index<<"th element"<<endl;

		//exception throw
		if(index<0 || index > size_){
			throw invalid_argument( "Index is out of bound!" );
		}

		if(this->arrayPtr == NULL){
			cerr<<" Array is Empty"<<endl;
			exit(0);
		}
		else{
			return this->arrayPtr[index];
		}
	}



	//deepcopy
	void Array::operator=(Collection* array){
		cout<< "	Array operator=(Collection*) is called"<<endl;
		
		delete[] this->arrayPtr;
		
		int size = ((Array*)array)->getsize();
		this->setsize(size);
		//create new array
		int* newArray = new int(size);

		this->arrayPtr = newArray;
		int i = 0;
		while(i<size_){
			this->arrayPtr[i] = (*array)[i];
			i++;
		}

	}

	bool Array::hasIt(int elem){

		if(this->arrayPtr == NULL){
			cerr<<" Array is Empty"<<endl;
			exit(0);
		}
		int i = 0;
		while(i<size_){
			if(this->arrayPtr[i] == elem){
				cout<<"Array has the elem"<<endl;
				return true;
			}
			else i++;
		}
		cout<<"Array does not have the elem"<<endl;
		return false;
	}
	
	Array* Array::helpMap(int (*fn)(int)){
		int i = 0;
		while(i< size_){
			this->arrayPtr[i] = fn(this->arrayPtr[i]);
        	i++;
		}
		return this;
	}

	Array* Array::copy(){
	/*	cout<<"		Array copy() is called"<<endl;
		Array* newArray = (*this).copy();
		return newArray;*/
		return this;
	}


	void Array::display(){
		int i = 0;
		while(i<this->arraySize){
			cout<<this->arrayPtr[i]<<" ";
			i++;
		}
		cout<<"[size of Array: "<<size_<<" ]"<<endl;
		cout<<endl;
		

	}

	int Array::getSize(){
		return (this->size_);
	}
