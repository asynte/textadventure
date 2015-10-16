
#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
using namespace std;

class Observer {
	public:
		virtual void notify(const string&) = 0;
		virtual void notify(const vector<string>&) = 0;
};

#endif



