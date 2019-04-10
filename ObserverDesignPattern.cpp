#include<iostream>
#include<vector>
using namespace std; 

class Observer {
	string name;
public:
	Observer(string name): name(name) {}
	virtual void update(int bid) = 0;

	string getname() {
		return name;
	}

};

class SubjectBid {

vector<Observer *> listObserver;
int highestBidValue ;

public:

	void attachedObserver(Observer * obs) {
		 listObserver.push_back(obs);
	}

	void detachedObserver(const Observer *obs) {

		//auto iVec = std::find(std::begin(listObserver),std::end(listObserver),obs);

		//if(iVec != listObserver.end()) {
		//	listObserver.erase(iVec);
		//}
	}

    void notify() {

    	for(auto a: listObserver) {
    		a->update(highestBidValue);
    	}
    }
 	
   
    void  setNewBidvalue(int highestBidValue) {
 
 			this->highestBidValue = highestBidValue;
 	notify();
    }


   void clear() {

   	 for(auto a: listObserver) {
   	 	delete a;
   	 }
   	 listObserver.clear();
   }

   ~SubjectBid() {
   	clear();
   }

};


class ObserverSbc: public Observer {

public: 

	ObserverSbc(string name) :Observer(name){
	
	}

	void update(int bid) {
	
		cout<< getname() << " " <<"New bid value: " <<bid <<endl;
	} 
};

int main() {

	ObserverSbc* s1= new ObserverSbc("SBC");
	ObserverSbc* s2= new ObserverSbc("CSM");
	ObserverSbc* s3= new ObserverSbc("USM");
	
	SubjectBid sub;

	sub.attachedObserver(s1);
	sub.attachedObserver(s2);sub.attachedObserver(s3);

	sub.setNewBidvalue(100);


	return 1;
}