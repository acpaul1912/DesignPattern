#include<iostream>
#include<map>
using namespace std; 

/*
#define MAKE_PROTOTYPE(TYPE) \
   Product* TYPE _myProtoype = \
      Product::addProduct(#TYPE, new TYPE());
*/


class ProductInterface {

  static map<string,ProductInterface *> protoTypeMap ; 

  public:
 
    static map<string,ProductInterface *> getprotoTypeMap() { return protoTypeMap;}
    
  	virtual ProductInterface * clone()=0;

  	static void addProduct(string str,ProductInterface * ptr) {

  		protoTypeMap[str] = ptr;    
  	}

    static ProductInterface * makeProduct(string str) {

        auto findptr = protoTypeMap.find(str);

        if(findptr == protoTypeMap.end()) {

        	cout<<" Error , no prototype found from db" <<endl;
        	return nullptr;
        }
        else {

        	return findptr->second->clone();
        }

    }
 
  
};

map<string,ProductInterface *> ProductInterface::protoTypeMap;

class product1 : public ProductInterface {

	public : 

     ProductInterface * clone() { cout<< "Clone creatred for product 1" <<endl; return new product1(*this);}

};

class product2 : public ProductInterface {

	public : 

     ProductInterface * clone() { cout<< "Clone creatred for product 2" <<endl; return new product2(*this);}

};

class product3 : public ProductInterface {

	public : 

     ProductInterface * clone() { cout<< "Clone creatred for product 3" <<endl; return new product3(*this);}

};



//client code 

int main() {

    //Two proct create 

    product1* p1 = new product1() ;
    product2* p2 = new product2() ;

    ProductInterface::addProduct("product1" , p1);
    ProductInterface::addProduct("product2" , p2);

    //clone use prototype 

    ProductInterface *p11 = ProductInterface::makeProduct("product1");

    //add one more object 


    product3* p3 = new product3() ;
    ProductInterface::addProduct("product3" , p3);
    ProductInterface *p13 = ProductInterface::makeProduct("product3");
    
      ProductInterface *p14 = ProductInterface::makeProduct("product4");
}