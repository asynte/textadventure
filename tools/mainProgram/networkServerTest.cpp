
#include "pthread.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include "networkingHeaders/TCPClient.h"
#include "networkingHeaders/TCPDataflow.h"
#include "networkingHeaders/TCPServer.h"
#include "userInterfaceHeaders/UserInterface.h"

using namespace std;

int main(int argc, char** argv) {

	const char* serverIp;
	if (argc > 1) {
		serverIp = argv[1];
	} else {
		serverIp = "142.58.184.105";
	}

	int serverPort = 1234;
	TCPDataflow* connection = NULL;
	TCPServer* server = NULL;
	server = new TCPServer(serverPort, serverIp);
	int count = 0;
	while(true)
	{
		if (server->listeningConnection() == 0)
		{
			cout << "Waiting for a connection on IP: " << serverIp << " Port: " << serverPort << endl;
			connection = server->acceptingConnection();
			if(connection != NULL)
			{
				ssize_t len;
				char line[256];
				while((len = connection->recvData(line, sizeof(line))) > 0)
				{
					count ++;
					line[len] = 0;

					ostringstream outputStream;
					outputStream << "Here's what you can " << line << ":\noption 1)\noption 2)\netc.. \n"<< "That was request: " << count << endl;
					string message = outputStream.str();
					connection->sendData(message.c_str(), message.size());
				}
				delete connection;
			}
		}
	}
	return 0;
}	
