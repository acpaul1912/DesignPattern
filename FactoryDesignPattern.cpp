#include<iostream>
using namespace std;

class ConfigurationSipProduct{
public:
	virtual void  configuresipd() = 0;
};

class ConfigureAtcpdProduct{
public:
	virtual void   configureAtcpd() = 0;
};

//concretae product 

class sipProduct4600 :  public ConfigurationSipProduct {

	public: 

    void configuresipd() {

    	cout<<" 4600 sipd configuration complete "<<endl;
    }

};

class sipProduct6300 :  public ConfigurationSipProduct {

	public: 

    void configuresipd() {

    	cout<<" 6300 sipd configuration complete "<<endl;
    }

};

class atcpdProduct4600 :  public ConfigureAtcpdProduct {

	public: 

    void configureAtcpd() {

    	cout<<" 4600 atcpd configuration complete "<<endl;
    }

};

class atcpdProduct6300 :  public ConfigureAtcpdProduct {

	public: 

    void configureAtcpd() {

    	cout<<" 6300 atcpd configuration complete "<<endl;
    }

};

//Interface of abstract factory 
class AbConfiguration {

	public:
	virtual ConfigurationSipProduct*   FactoryConfigurationSipd() = 0;
	virtual ConfigureAtcpdProduct*  FactoryConfigurationAtcpd() = 0;

};


//build concreate factory for 4600
class ConcreateFactory4600: public AbConfiguration{

public:
  ConfigureAtcpdProduct* FactoryConfigurationAtcpd() {

  	return new atcpdProduct4600();

  }

   ConfigurationSipProduct* FactoryConfigurationSipd()  {

  	return new sipProduct4600();
  }
};

//build concreate factory for 4600
class ConcreateFactory6300: public AbConfiguration{

public:
  ConfigureAtcpdProduct* FactoryConfigurationAtcpd() {

  	return new atcpdProduct6300();

  }
  
  ConfigurationSipProduct* FactoryConfigurationSipd()  {

  	return new sipProduct6300();
  }

};

class BuildProducrtfactory {

public: 

	static AbConfiguration * Producrtfactory(int type) {

		switch(type) {

			case 1: 
					new ConcreateFactory4600();
 					break;
 			case 2: 
 					new ConcreateFactory6300();

		}
	}

};

int main() {

	int type ; 

	cin>>type;
 	AbConfiguration * ptr= BuildProducrtfactory::Producrtfactory(type);

 	ptr->FactoryConfigurationAtcpd()->configureAtcpd();

    ptr->FactoryConfigurationSipd()->configuresipd();

}