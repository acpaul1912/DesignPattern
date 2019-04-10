#include<iostream>
#include<mutex>

using namespace std;

std::mutex l1;

class SingleTonpattern {

	static SingleTonpattern * _instance;

    SingleTonpattern() {}
    SingleTonpattern(const &single) = delete;
    SingleTonpattern operator=(const &single) = delete;
    ~SingleTonpattern() {
      
      delete _instance;
    }
public: 
	static SingleTonpattern * getInstance() {

        if(_instance == nullptr) {

            std::lock_guard<mutex> l(l1);
            if(_instance == nullptr)
       			_instance = new SingleTonpattern();
		}
		static int i ; 
		cout<<i++<<"_instance: "<< _instance<< endl;
		return _instance;
	}

  /* //static version 
   static SingleTonpattern* getInstances() {

   	 static SingleTonpattern* instance (new SingleTonpattern());
   	 static int i;
     cout<<i++<<"_instance: "<< instance<< endl;
   	 return instance;
   }
*/
};

SingleTonpattern * SingleTonpattern::_instance;



int main() {

      SingleTonpattern * ptr =  SingleTonpattern::getInstance();

      SingleTonpattern::getInstance();
      SingleTonpattern::getInstance();
      SingleTonpattern::getInstance();
      SingleTonpattern::getInstance();
      SingleTonpattern::getInstance();
     //static version 
      SingleTonpattern::getInstances();
      SingleTonpattern::getInstances();
      SingleTonpattern::getInstances();
      SingleTonpattern::getInstances();
      SingleTonpattern::getInstances();
      SingleTonpattern::getInstances();
      SingleTonpattern::getInstances();

}