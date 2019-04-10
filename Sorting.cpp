#include<iostream>
#include<set>

using namespace std;

struct Sorting {
	
	bool operator()(string fri, string sec) const {

	   return fri.length() < sec.length() ; 
	}
};




int main() {

  std::set<string,Sorting> ss ;	

  ss.emplace("achintya");

  cout<< *ss.begin();

}