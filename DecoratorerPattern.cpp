#include<iostream>
using namespace std;

class InterfaceDeorator {

public: 
	virtual void Draw()=0;
};

class TextContain : public InterfaceDeorator {
static int x ;
public: 
	virtual void Draw() {
		cout<<"Plan  text x: " << x++ <<endl;
	}
};

int TextContain::x ;
class Decorator : public InterfaceDeorator {

  InterfaceDeorator * component;
  public : 
  Decorator(InterfaceDeorator * com) : component(com) {

  }  
  virtual void Draw() {
		
    component->Draw();
  }
 

};

//concretae decorartor 

class ScrollDecorator: public Decorator {
public:
	ScrollDecorator(InterfaceDeorator * com) : Decorator(com) {

	}
void Draw() {
	Decorator::Draw();
	cout<< " scroll property added " <<endl;
}
};

class ButtonDecorator: public Decorator {
public:
	ButtonDecorator(InterfaceDeorator * com) : Decorator(com) {

	}
void Draw() {
	Decorator::Draw();
	cout<< " Button property added " <<endl;
}
};

int main() {

	InterfaceDeorator * ptr = new ButtonDecorator(new TextContain());
	ptr->Draw();
    //test multiple 
	InterfaceDeorator * ptr1 =   new ButtonDecorator (new ButtonDecorator (new ButtonDecorator(new ScrollDecorator(new TextContain()))));
	ptr1->Draw();

    return 0;
}
