#ifndef _OBSERVER_LIST_H_
#define _OBSERVER_LIST_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Observer.h"

using namespace std;

class ObserverList
{
	private: 
		vector<Observer*> observers;

	public:
		void addObserver(Observer *obs);
		void removeObserver(const Observer *obs);
		void notifyObservers(const string&);
		void notifyObservers(const vector<string>&);

		const vector<Observer*>& getList(void);
};

#endif
