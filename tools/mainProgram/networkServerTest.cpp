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

static	const char* serverIp = "142.58.184.81";
static	int serverPort = 1234;
TCPServer* server = NULL;
TCPDataflow* connection = NULL;

void acceptConnection(){
	server = new TCPServer(serverPort, serverIp);
	while(true)
	{
		if (server->listeningConnection() == 0)
		{
			cout << "Waiting for a connection on IP: " << serverIp << " Port: " << serverPort << endl;
			connection = server->acceptingConnection();
			if(connection != NULL) 
			{
				ssize_t bufferLength;
				char requestedCommand[256];
				ostringstream outputStream;
				while((bufferLength = connection->recvData(requestedCommand, sizeof(requestedCommand))) > 0)
				{
					requestedCommand[bufferLength] = 0;
					cout << "Received: " << requestedCommand << endl;
					outputStream << "Server sent you back: " << requestedCommand << endl;
					string message = outputStream.str();
					connection->sendData(message.c_str(), message.size());
				}
				delete connection;
			}
		}
	}
}


int main(int argc, char** argv) {
	acceptConnection();
	return 0;
}