#include<iostream>
using namespace std;

//Interface to be used by client 

class Esbc{

public: 
	virtual void startEsbc()=0;
	
};

// Aldreay implemenatation is there with SBC Adptee 

class SBC {

public: 
	void startSbc() {

		cout<< " System started and will in use in 2.0 second ..." <<endl;
	}
};

//Adpter design pattern 

//Apporach One  Object Adpeter using composition 


class AdpterEsbc: public Esbc {

   SBC sbc;

public:
    AdpterEsbc(SBC &sbc) : sbc(sbc) {

    }

   virtual void startEsbc() {

    	sbc.startSbc();
    }
};

//Apporach two  class  Adpeter using Inheritance 
class AdpterInheritanceEsbc: public Esbc , public SBC {  

public:
    AdpterInheritanceEsbc() : SBC() {

    }

   virtual void startEsbc() {

   	   	SBC::startSbc();
    }
};

//Client 
int main() {

	/*SBC sb ;
 
    //Adptee started just  first approach 
	sb.startSbc() ;

    Esbc* esb = new AdpterEsbc(sb);

    esb->startEsbc() ;*/

    //Apprach TWo 
    Esbc* esb= new AdpterInheritanceEsbc();

    esb->startEsbc();

    delete esb;
}


