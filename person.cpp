#include<iostream>
#include<memory>
using namespace std; 

//Factory method design pattern 

class person {
	
	public:
	virtual void getName() {
		cout<<" " <<endl;
	}
};

class Employee : public person{
	public:
	virtual void getName() {
		cout<<" Employee " <<endl;
	}
};



class Factory {
	
	public: 
	static unique_ptr<person> createPerson(int i) {

		switch(i) {

			case 1: 
			       return make_unique<Employee> () ; 
					    
		    default :
		             return make_unique<person>();
		}
	}

};

int main() {
	
		shared_ptr<person>  ptr = Factory::createPerson(1);
		ptr->getName();
}