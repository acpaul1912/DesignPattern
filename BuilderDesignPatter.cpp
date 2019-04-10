#include<iostream>
using namespace std;

class BuilderInterface {
public:
	virtual void ConvertWord(string w) {};
	virtual void ConvertParaghaph(string p) {};
};

class AscciText {
	
public:
	AscciText() {

		cout<<" AscciText is constructed " <<endl;
	}
string aWord , aParam;
};


class UNIText {
	
public:
	UNIText() {

		cout<<" UNIText is constructed " <<endl;
	}
string aWord , aParam;
};

class AsciiBuilder : public BuilderInterface { 

  AscciText *text ;
  public : 

  AsciiBuilder() {

  	 text = new AscciText();
  }

  void ConvertWord(string w) {

  	cout<<"  converted to Ascci: " << w <<endl;
  	text->aWord = w;

}

void ConvertParaghaph(string p) {

	cout<<"  converted to Ascci: " << p <<endl;
	text->aParam = p;
}

AscciText* getAscciText() { return text;}


};



class UNIBuilder : public BuilderInterface { 

  UNIText *text ;
  public : 

  UNIBuilder() {

  	 text = new UNIText();
  }

  void ConvertWord(string w) {

  	cout<<"  converted to UNI: " << w <<endl;
  	text->aWord = w;

}

void ConvertParaghaph(string p) {

	cout<<"  converted to UNI: " << p <<endl;
	text->aParam = p;
}

UNIText* getAscciText() { return text;}


};






class doucmemnt {
string word, pargarph;
public:
	doucmemnt(string word, string para):word(word),pargarph(para) {

		cout<< "Construtor is called  :" <<endl;
	}

string getWord() {
	return word;
}
string getParam() {

	return pargarph;
}
};




class Dirctor {

BuilderInterface * builder;
public: 

      Dirctor(BuilderInterface * builder) {

        this->builder = builder;

      }

      void convertText(doucmemnt d) {
            //document 
             builder->ConvertWord(d.getWord())     ;
             builder->ConvertParaghaph(d.getParam());                         
      }
};

int main() {

	doucmemnt d("Achintya","paul");

	AsciiBuilder ab;
 
    Dirctor dir(&ab);

    dir.convertText(d);

    ab.getAscciText();

    // UNIText

    UNIBuilder un;
    Dirctor dir1(&un);
     dir1.convertText(d);

    un.getAscciText();

}