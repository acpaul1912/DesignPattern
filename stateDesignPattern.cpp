#include<iostream>
using namespace std;

class MusicPlayer ;
class MusicPlayerState {

	public:
		virtual void on(MusicPlayer *ins) { cout<<" Already on " <<endl;}
        virtual void off(MusicPlayer *ins) {cout<<" already off" <<endl;}

};

class OffMusicPalyerState ;

//Context 

class MusicPlayer {

MusicPlayerState *instance; 
	public: 

	MusicPlayer(MusicPlayerState *instance) {

		cout<<" Music Player " <<endl;
		this->instance = instance;
	}

	void On() {

       instance->on(this);
	}
	void Off() {
     
     instance->off(this);

	}

   void changeState(MusicPlayerState *instance);

   ~MusicPlayer() {
     
     delete instance;
   }

};

void MusicPlayer::changeState(MusicPlayerState *instance){
     	delete this->instance;
   	this->instance = instance;
   }


class OnMusicPalyerState : public MusicPlayerState {
    
	public :
    virtual void off(MusicPlayer *ins);
};

class OffMusicPalyerState : public MusicPlayerState {
    
	public :
    virtual void on(MusicPlayer *ins); 
};


void OnMusicPalyerState :: off(MusicPlayer *ins) {

       cout<< " off the player " <<endl;
       ins->changeState(new OffMusicPalyerState());
    }

void OffMusicPalyerState:: on(MusicPlayer *ins)
     {

       cout<< " On the player " <<endl;

       ins->changeState(new OnMusicPalyerState());
    }


int main() {

	MusicPlayer* mp = new MusicPlayer(new OffMusicPalyerState()) ;

	mp->Off();
	mp->On();
	mp->Off();
}