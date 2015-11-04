#ifndef _OBSERVER_LIST_CPP_
#define _OBSERVER_LIST_CPP_

#include "userInterfaceHeaders/ObserverList.h"



using namespace std;

void ObserverList::addObserver(Observer *obs) {
	observers.push_back(obs);
}


void ObserverList::notifyObservers(const string &str){
	for(auto itr = observers.begin(); itr != observers.end(); ++itr) {
		(*itr)->notify( str );
	}
}

void ObserverList::notifyObservers(const vector<string> &str){
	for(auto itr = observers.begin(); itr != observers.end(); ++itr) {
		(*itr)->notify( str );
	}
}




const vector<Observer*>& ObserverList::getList(void) {
	return observers;
}



void ObserverList::removeObserver(const Observer *obs) {
	auto start = remove( observers.begin(), observers.end(), obs );
	observers.erase( start, observers.end() ); 
}


#endif





