#include<iostream>
using namespace std;

class Image {

public :	
	virtual void draw() = 0;
};

class OriginalImage : public Image{

public : 
	OriginalImage(string name){

	  cout<< "Real Image institated " << name <<endl;
	}
	virtual void draw() {

		cout<< " Real Image Draw " << endl;
    }
};

class ProxyImage : public Image {
	
	string  realIname ;
    Image * realImage = nullptr;

	public: 

    ProxyImage(string name):realIname(name)
    {
       cout<<" Proxy Object is created " <<endl;
    }
    
	virtual void draw() {
      
       if(!realImage) {

          realImage = new OriginalImage(realIname);
       }
       
       realImage->draw();		
    }


};


int main() {
	
	Image* I = new ProxyImage("achintya");
	//I->draw();
	return 0;
}
