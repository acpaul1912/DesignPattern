#include<iostream>
using namespace std;
class Vichel {

public:
	virtual void fare() = 0;
};

class car: public Vichel{
public:
	virtual void fare() {

		cout<<" Car fare is : " << 1000 <<endl;
	}
};

class bus: public Vichel{
public:
	virtual void fare() {

		cout<<" bus fare is : " << 2000 <<endl;
	}
};

class Train: public Vichel{
public:
	virtual void fare() {

		cout<<" Train fare is : " << 300 <<endl;
	}
};


class TranportToAirpot {

 	Vichel *ins;
    
	public :

	TranportToAirpot(Vichel *ins) :ins(ins){

	}
	~TranportToAirpot() {
		delete ins;
	}
	void fare() {
		ins->fare();
	}
};

int main() {

	TranportToAirpot t1 = TranportToAirpot(new bus());

	TranportToAirpot t2 = TranportToAirpot(new Train());

	t1.fare();
	t2.fare();
return 0;
}