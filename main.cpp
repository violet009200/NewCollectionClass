#include <iostream>
//#include "Collection.cpp"
#include "LList.h"
//#include "Array.h"

using namespace std;

/*
	testing 
*/
//for testing map
int foo(int a){
	 a= a+1;
	 return a;
}

void testingLinkedList(){


	Collection* c = new LList();
	//test for copy construct
	
	//LList l;
	cout<<"	Testing copy constructor"<<endl;
	Collection *c1 = new LList();
	Collection *c2(c1);
	c2->display();

	//test add
	cout<<"	test adding elements"<<endl;
	c->add(1,0);
	c->add(2,1);
	c->add(3,2);
	c->add(4,3);
	c->add(5,4);
	c->add(6,5);

	c->display();

	c->add(7,0);
	c->add(8,3);
	c->add(9,5);

	c->display();
	
	cout<<"	test remove"<<endl;
	c->remove(3);
	
	c->display();

	//test operator[]
	cout<<"	testing operator[]"<<endl;
	int& i = (*c)[5];	
	cout<<"i is = "<< i<< endl;
	cout<<"change elem in LList"<<endl;
	(*c)[0] = 11;
	c->display();
	//deepcopy testing
	cout<<"	testing operator="<<endl;
	Collection* newC = new LList();
	*newC = c;
	cout<<"this is new list"<<endl;
	newC->display();

	cout<<"testing copy()"<<endl;
	Collection* copiedCollection = newC->copy();
	copiedCollection->display();

	cout<<"testing contain()"<<endl;
	cout<<"Contain true(1) or false(0): "<<copiedCollection->contains(4)<<endl;
	
	cout<<"testing map()"<<endl;
	copiedCollection->map(foo);
	copiedCollection->display();

	delete copiedCollection;
	delete c2;
}

void testingArray(){
	Collection* a = new Array(3);

	a->add(1,0);
	a->remove(1);

	//test operator[]
	cout<<"	testing operator[]"<<endl;
	int& i = (*a)[2];	
	cout<<"i is = "<< i<< endl;
	cout<<"change elem in LList"<<endl;
	(*a)[0] = 11;
	(*a)[1] = 8;
	(*a)[2] = 6;

	a->display();

	//deepcopy testing
	cout<<"	testing operator="<<endl;
	Collection* newC = new Array(3);
	*newC = a;
	cout<<"this is new Array"<<endl;
	newC->display();

	cout<<"testing copy()"<<endl;
	Collection* copiedCollection = newC->copy();
	copiedCollection->display();

	cout<<"testing contain()"<<endl;
	cout<<"Contain true(1) or false(0): "<<copiedCollection->contains(11)<<endl;


	cout<<"testing map()"<<endl;
	copiedCollection->map(foo);
	copiedCollection->display();

	delete a;
	//delete newC;
	delete copiedCollection;

}

int main(){
	cout<<"New Collection Project"<<endl;
	cout<<"testing LList"<<endl;
	testingLinkedList();
	
	cout<<"------------------------------------------"<<endl;

	cout<<"testing Array"<<endl;
	testingArray();

	return 0;
}