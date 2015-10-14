#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "TCPClient.h"

using namespace std;

int main(int argc, char** argv)
{
	const char* serverIp = "127.0.0.1";
	int serverPort = 1234;
	int len;
	string message;
	char line[256];
	TCPClient* client = new TCPClient();	//start up a new client
	TCPDataflow* connection = client->connectToServer(serverIp, serverPort);	//send a connection request
	if(connection)	// if connection was accepted
	{
		while(message != "quit")
		{
			cout << "What would you like to do?\n";
			getline (cin, message);
			connection -> sendData (message.c_str(), message.size());
			printf ("sent - %s\n", message.c_str());
			len = connection -> recvData (line, sizeof (line));	//receive the data, store the size of
			line [len] = 0;									//escape sequence
			cout << "response: " << line << endl;				//print back what you have received
			delete connection;
			connection = client -> connectToServer (serverIp, serverPort);		//keep requesting things until you send quit
		}
		delete connection;
	}

	exit(0);
}
