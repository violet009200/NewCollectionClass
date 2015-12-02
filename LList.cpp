#include "LList.h"

	LList::LList(){
		head = (node*)NULL;
	}
	LList::~LList(){
		cout<<"		~LList()"<<endl;
	
		this->deleteAll();
	}

	//member function
	Collection* LList::add(int elem, int position){
		cout<<"		LList add() is called"<<endl;	

		node* newNode = new node();
		newNode->value = elem;
		size_++;
		
		if(position == 0){
			//index = 0;
			if(this->head == NULL){
				head = newNode;
			}
			else{

				newNode->next = head;
				head = newNode;
			}
			return this;
		}
		else{
			node* curNode = new node();
			int count = 1;
			curNode = head;
			while(count!=position){
				curNode = curNode->next;
				count++;
			}
			newNode->next = curNode->next;
			curNode->next = newNode;
		}
		return this;
	}

	Collection* LList::remove(int elem){
		cout<<"		LList remove() is called"<<endl;
		
		node* prev = NULL;
		node* cur = this->head;

		if(cur == NULL) return 0;
		else{
			//find node
			while(cur->value != elem){
				if(cur->next != NULL){
					prev = cur;
					cur = cur->next;
				}
				else //cannot find node
				{
					cout<<"Cannot find node"<<endl;
					return this;
				}
			}
			if(cur->next == NULL){
				prev->next = NULL;
				delete cur;
				size_--;
				return this;
			}
			else if(cur->next != NULL){
				if(prev!=NULL)	prev->next = cur->next;
				delete cur;
				size_--;
				return this;
			}

		}//else
	}

	//take index return the element at the index
	int& LList::operator[](int index){
		cout<< "	LList operator[] is called"<<endl;
		cout<<"	finding "<<index<<"th elem"<<endl;
		//exception throw
		if(index < 0 || index > size_ ){
			throw invalid_argument( "Index is out of bound!" );
		}

		if(this->head == NULL){
			cerr<<"list is empty"<<endl;
			exit(0);
		}
		int i=0;

		node* cur = this->head;
		while(i<index){
			if(cur == NULL) {
				cerr<<"cur node is empty"<<endl;
				exit(0);
			}
			cur = cur->next;
			i++;
		}
		return cur->value;

	}



	//deepcopy
	void LList::operator=(Collection* llist){
		cout<< "	LList operator=(Collection*) is called"<<endl;
		
		if(llist == NULL){
			cerr<<"LList is Empty"<<endl;
			return;
		}

		//delete current LList
		this->deleteAll();

		//LList* newList = new LList();

		node* inputNode = ((LList*)llist)->head;
		node* newNode = new node();
		//set head
		newNode->value = inputNode->value;
		this->head = newNode;
		inputNode = inputNode->next;
		
		//set size_
		this->setsize(llist->getsize());

		newNode = this->head;
		
		while(inputNode != NULL){
			newNode = newNode->next = new node();
			//copy all node until inputNode is NULL
			newNode->value = inputNode->value;
			//newNode = newNode->next;
			inputNode = inputNode->next;
		}
		//set last node of new 
		newNode->next = NULL;
	}


	LList* LList::copy(){
		/*cout<<"		LList copy() is called"<<endl;
		LList* newList = (*this).copy();
		return newList;*/
		return this;
	}

	void LList::deleteAll(){
		//cout<<"		LList: delete All node"<<endl;
		if(this->head != NULL){
			node* curNode = this->head;
			node* nextNode = NULL;

			while(curNode->next != NULL){
				nextNode = curNode -> next;
				delete curNode;
				curNode = nextNode;
			}
			delete curNode;
		}
		this->size_ = 0;
	}

	void LList::display(){
		node* cur = this->head;
		while(cur != NULL){
			cout<<cur->value<<" ";
			cur = cur->next;
		}
		cout<<"[size of LList: "<<size_<<" ]"<<endl;
		cout<<endl;

	}

	int LList::getSize(){
		return size_;
	}
