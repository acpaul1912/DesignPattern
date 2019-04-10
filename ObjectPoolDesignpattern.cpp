#include<iostream>
#include<list>
#include <stdlib.h> 
#include<string>
using namespace std;


class Context{

 	int key;
 	string name;

	
 public: 
 	Context(int key, string name):key(key),name(name){
           
	}

};

class ObjectPool{

	list<Context *>  pool;
	//static ObjectPool* _instance;

public:
	void retrunElement(Context *p) {

		insertElement(p);
	}
	void insertElement(Context *p){

		pool.push_back(p);
	}
	Context*  getElement(){

        if(pool.size() > 0) {
        Context* pt = pool.back();
        pool.pop_back();
        return pt;
    }
    else {
    	return nullptr;
    }
 }

 size_t PoolSize() {
 	return pool.size();
 }

 static ObjectPool* getObjectPool() {

 	static ObjectPool* _ins = new ObjectPool();

 	return _ins; 
 }

 ~ObjectPool() {

 	for(auto a :pool) {        
        delete a;      
 	}
 	pool.clear();
 }

 };

int main() {

	//boot up data population :

	for (int i = 0; i < 10 ; i++) {

		Context * p = new Context(i,"Objct"+ std::to_string(i)); 

		ObjectPool::getObjectPool()->insertElement(p);
	}

    // get one context 
    cout<< " PoolSize : " << ObjectPool::getObjectPool()->PoolSize() <<endl;
    Context *p1 = ObjectPool::getObjectPool()->getElement();

    cout<< " PoolSize : " << ObjectPool::getObjectPool()->PoolSize() <<endl;

    
    Context *p2 = ObjectPool::getObjectPool()->getElement();

    cout<< " PoolSize : " << ObjectPool::getObjectPool()->PoolSize() <<endl;

    ObjectPool::getObjectPool()->retrunElement(p1);
    p1= nullptr;

    cout<< " PoolSize : " << ObjectPool::getObjectPool()->PoolSize() <<endl;


    ObjectPool::getObjectPool()->retrunElement(p2);
    p2= nullptr;

    cout<< " PoolSize : " << ObjectPool::getObjectPool()->PoolSize() <<endl;

}