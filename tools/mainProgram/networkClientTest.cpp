#include "dataInterfaceHeaders/npcDataInterface.h"
#include "dataInterfaceHeaders/objDataInterface.h"
#include "gameEngineHeaders/Character.h"
#include "gameEngineHeaders/Door.h"
#include "gameEngineHeaders/Monster.h"
#include "gameEngineHeaders/NPC.h"
#include "gameEngineHeaders/Object.h"
#include "gameEngineHeaders/Room.h"
#include "gameEngineHeaders/Widget.h"
#include "gameEngineHeaders/World.h"
#include "userAccountHeaders/Login.h"
#include "networkingHeaders/TCPClient.h"
#include "networkingHeaders/TCPDataflow.h"
#include "networkingHeaders/TCPServer.h"
#include "userInterfaceHeaders/Observer.h"
#include "userInterfaceHeaders/ObserverList.h"
#include "userInterfaceHeaders/Commands.h"
#include "userInterfaceHeaders/UserInterface.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

static TCPClient* c_client = new TCPClient();
static TCPDataflow* c_dataflow = NULL;
static const char* ipAddr = "142.58.184.66";
static int port = 1234;
static int port2 = 1232;

void* recvMessageFromServer (void* nothing);
void* sendMessageToServer (void* nothing);			//ready to be multithreaded just need to impliment it

void* sendMessageToServer (void* nothing)
{
	cout << "Type a command: ";
	string message = "";
	getline (cin, message); // UI needs to do something here
	while (message != "quit")
	{
		c_dataflow = c_client->connectToServer(ipAddr, port);
		if (c_dataflow)
		{
		 c_dataflow -> sendData (message.c_str(), message.size());
		 recvMessageFromServer(NULL);
		}
		delete c_dataflow;
		cout << "Type a command: ";
		getline (cin, message); // UI needs to do something here
	}
	return NULL;
}

void* recvMessageFromServer (void* nothing)
{
	if(c_dataflow!= NULL)
	{
		char response[256];
		ssize_t bufferSize = c_dataflow -> recvData (response, sizeof (response));
		response [bufferSize] = 0;
		cout << response << endl;

	}
	return NULL;
}

int main(int argc, char** argv)
{
	//const char* serverIp = "192.168.11.132";
	//int serverPort = 1234;
	//sendMessageToServer(serverIp, serverPort, "hi\n");

	pthread_t sendMessageThread;
	//pthread_t recvMessageThread;
	pthread_create(&sendMessageThread, NULL, &sendMessageToServer, NULL);
	//pthread_create(&recvMessageThread, NULL, &recvMessageFromServer, NULL);
	pthread_join(sendMessageThread, NULL);
	//pthread_join(recvMessageThread, NULL);
	exit(0);
}