#include<Iostream>
using namespace std;

class Iterrator{

public:
	virtual void begin() = 0;

	virtual void end() = 0; 
};

class RandomIterator : public Iterrator {

	void begin() {

		cout<<" Random Iterator : Begin()" << endl;

	}
    
    void end() {
    	cout<<" Random Iterator : End() " <<endl;
    }
};

class SequencetialItertator : public Iterrator {
public:
	void begin() {

		cout<<" Sequencetial Iterator : Begin()" << endl;

	}
    
    void end() {
    	cout<<" Sequencetial Iterator : End() " <<endl;
    }
};

class HybridIterator : public Iterrator {
public:
	void begin() {

		cout<<" Hybrid Iterator : Begin()" << endl;

	}
    
    void end() {
    	cout<<" Hybrid Iterator : End() " <<endl;
    }
};


class Container {


 public : 
 Iterrator * it ; 
 Container(Iterrator *it) {
 	this->it = it;
 }
 	virtual void move() = 0;

};

class RandomContainer : public Container {

public :
	RandomContainer(Iterrator * it) : Container(it) {

	}

 void move() 
 {
 	it->begin();
 	it->end();

 }
};

class SequenceContainer : public Container {

public :
	SequenceContainer(Iterrator * it) : Container(it) {

	}

 void move() 
 {
 	it->begin();
 	it->end();

 }
};



int main() {

	Container * c = new SequenceContainer(new SequencetialItertator());

	c->move();
	return 0;
}