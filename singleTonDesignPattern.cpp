#include<iostream>
#include<memory>
#include<mutex>
#include<thread>
using namespace std; 


class SingleTon {

 SingleTon& operator=(const SingleTon& c)=delete;
 SingleTon(const SingleTon& c)=delete;

   public: 

   shared_ptr<SingleTon> static  getSingleTon() {
   		if(!instance) {

        m.lock();
   		if(!instance) {
            cout<<" 1st instance created " <<endl;
            instance = shared_ptr<SingleTon>(new SingleTon());   			
   		}
   		m.unlock();
   	    }
   		return instance;
   	}

private:
    static shared_ptr<SingleTon> instance ; 
	SingleTon() = default;
	static std::mutex m;
};
    
shared_ptr<SingleTon>  SingleTon::instance = nullptr;
std::mutex SingleTon:: m;

int main() {
   
  shared_ptr<SingleTon> si = SingleTon::getSingleTon();

}


