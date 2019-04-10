#include<iostream> 
using namespace std; 

#include<queue> 

class command {
	
	public: 
	virtual void execute() = 0;
};

class light {
	
	public:

	void on() {
		cout<<" on the light "<<endl;
	}
	void off() {

	 	cout<<" Off the light " <<endl;
	}
};

class lightOnCommand : command {
	
	light * li;

	lightOnCommand(light *li): li(li) {

	}

	void exceute() {
		li->on();
	}
};

class lightOffCommand : command {
	
	light * li;

	lightOffCommand(light *li): li(li) {

	}

	void exceute() {
		li->off();
	}
};


class gate{
	
	public: 

	void openGate() {
	  cout<<"open gate " <<endl;
	}

	void closegate() {
		cout<<"close gate " <<endl;
	}
};

class gateOpenCommand: command {
	
	gate * gg;
public:
	gateOpenCommand(gate * gg):gg(gg) {

	}

	void exceute() {
		gg->openGate();
	}
};


class gateCloseCommand: public command {
	
	gate * gg;
public:
	gateCloseCommand(gate * gg):command(),gg(gg) {

	}

	void execute(){
		gg->closegate();
	}
};


class remote {
	
	queue<command*> qComand; 

	public:

		void addcommand(command* cmd) {

				qComand.push(cmd);
		}

		void ExecuteCommand() {

			(qComand.back())->execute();
		}

};

int main() {
	
		remote r;

		gate g;

		gateCloseCommand p(&g);

		r.addcommand(&p);

		r.ExecuteCommand();

}