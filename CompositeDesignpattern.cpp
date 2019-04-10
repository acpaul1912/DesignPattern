#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

class graphics {
public:

	virtual void draw() = 0;
	virtual void add(graphics *g) {

	}
	virtual void remove(graphics *g){

	}

	virtual void getChild(int) {}

	virtual ~graphics() {}
};



//Leaf node 

class Reactangle : public graphics {

public: 
	virtual void draw() {

		cout<<" Reactangle Drawn " <<endl;
	}
};

class Square : public graphics {

public: 
	virtual void draw() {

		cout<<" Square Drawn " <<endl;
	}
};

class Text : public graphics {

public: 
	virtual void draw() {

		cout<<" Text Drawn " <<endl;
	}
};

//composite 

class Picture:  public graphics {

 vector<graphics *> glist;
public:

virtual void add(graphics *g){

	glist.push_back(g);
}

virtual void remove(graphics *g){

	auto str= std::find(glist.begin() , glist.end(), g);
   
    if(str != glist.end()) {

    	glist.erase(str);
    }

}

void draw() {

	for(auto a:glist) {
        
        cout<<"picture Drawn" <<endl;
		a->draw();
	}
}

};

int main() {

	graphics* r1= new Reactangle();
	graphics * s1= new  Square();

	graphics * p1 = new Picture();

	p1->add(r1);
	p1->add(s1);

    graphics * p2 = new Picture();
    p2->add(p1);

    p2->draw();

}