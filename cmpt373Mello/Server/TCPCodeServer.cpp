#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TCPDataflow.h"
#include "TCPServer.h"
#include <sstream>
#include <string>
using namespace std;

//toDo: make it multithreaded, one thread to accept requests and put them in a queue, another to carry
//actually perform the actions in a queue, and another to deliver responses.


int main(int argc, char** argv) {
	const char* serverIp = "127.0.0.1";
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
					cout << "Received: " << line << endl;
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
