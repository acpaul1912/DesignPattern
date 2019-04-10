#include<iostream>
#include<memory>
using namespace std;

class Button {

public: 
	virtual void paint() = 0 ;

};

class OSXButton : public Button {

public: 
	void paint() {
		cout<<" OSXButton  is painted " <<endl;
	}
};

class WinodwsButton  : public Button {

public: 
	void paint() {
		cout<<" WindowsButton   is painted " <<endl;
	}
};


class Scroll {

public:
	virtual void paint() = 0 ;
};


class OSXScroll : public Scroll {

public: 

	void paint() {

		cout<<" OSXScroll is scroll" <<endl;
	}
};

class WindowsScroll: public Scroll {

public: 
	void paint() {

		cout<<" WindowsScroll is Scroll" <<endl;
	}
};


class GUIFactory {

public:
	virtual Button * createButton() = 0;
	virtual Scroll* createScroll() = 0;
};

class WinodwsFactroy : public GUIFactory {

public: 
	Button * createButton()  {

		return new WinodwsButton();
	}

    Scroll* createScroll()  {

    	return new WindowsScroll();
    }
};


class OSXFactroy : public GUIFactory {

public: 
	Button * createButton()  {

		return new OSXButton();
	}

    Scroll* createScroll()  {

    	return new OSXScroll();
    }
};


int main () {

	GUIFactory * p = new WinodwsFactroy() ;
	Button * b = p->createButton();
	Scroll * s = p->createScroll();
	b->paint();
	s->paint();
}