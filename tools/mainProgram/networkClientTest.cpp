
#include "networkingHeaders/TCPClient.h"
#include "networkingHeaders/TCPDataflow.h"
#include "networkingHeaders/TCPServer.h"
#include "pthread.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

//#include

using namespace std;





static TCPClient* c_client = new TCPClient();
static TCPDataflow* c_dataflow = NULL;
static const char* ipAddr = "142.58.35.244";
static int port = 1234;




void* recvMessageFromServer (void* nothing);
void* sendMessageToServer (void* nothing);			//ready to be multithreaded just need to impliment it




class InterfaceObserver : public Observer {
	public:
		InterfaceObserver()	{}

		void notify(const string &message) {
			c_dataflow = c_client->connectToServer(ipAddr, port);
			if (c_dataflow)
			{
				c_dataflow -> sendData (message.c_str(), message.size());
				recvMessageFromServer(NULL);
			}

			delete c_dataflow;
		}
		void notify(const vector<string> &userInput) {

		}
};




void* sendMessageToServer (void* nothing)
{

	return NULL;
}

void* recvMessageFromServer (void* nothing)
{
	if(c_dataflow!= NULL)
	{
		char response[256];
		ssize_t bufferSize = c_dataflow -> recvData (response, sizeof (response));
		response [bufferSize] = 0;
		//UserInterface_printServerMessage(response);
		//cout << response << endl;

	}
	return NULL;
}

void clientTest_start() {
	UserInterface_addListener(new InterfaceObserver);
}
