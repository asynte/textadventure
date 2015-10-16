#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "networkingHeaders/TCPClient.h"

TCPDataflow* TCPClient::connectToServer (const char* serverIP, int serverPort)
{
	struct sockaddr_in socketAddressIn;
	memset (&socketAddressIn, 0, sizeof (socketAddressIn));	//clears the socketAddressIn structure
	socketAddressIn.sin_family = AF_INET;								//sets its family to internet
	socketAddressIn.sin_port = htons(serverPort);
	int socketDesc = socket(AF_INET, SOCK_STREAM, 0);

	if (socketDesc < 0)
	{
		std::cout<< " socket failed\n";
		return NULL;
	}

	if(::connect(socketDesc, (struct sockaddr*) &socketAddressIn, sizeof(socketAddressIn)) != 0)
	{
		std::cout << "connect failed\n";
		close (socketDesc);
		return NULL;
	}

	return new TCPDataflow (socketDesc, &socketAddressIn);
}

