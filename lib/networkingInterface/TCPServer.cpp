#include "networkingHeaders/TCPServer.h"
#include "networkingHeaders/TCPDataflow.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

TCPServer::TCPServer(int serverPort, const char* serverAddress) {
	m_serverPort = serverPort;
	m_serverAddress = serverAddress;
	m_listeningSocketDescripter = 0;
	m_isListening = false;
}

int TCPServer::listeningConnection(){
	if(m_isListening == true){
		return 0;
	}
	m_listeningSocketDescripter = socket (PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in socketAddressIn;
	memset (&socketAddressIn, 0, sizeof (socketAddressIn));
	socketAddressIn.sin_family = PF_INET;
	socketAddressIn.sin_addr.s_addr = INADDR_ANY;
	socketAddressIn.sin_port = htons (m_serverPort);

	int bindedAndOrListening = bind (m_listeningSocketDescripter, (struct sockaddr*) &socketAddressIn, sizeof(socketAddressIn));
	if (bindedAndOrListening < 0)
	{
		std::cout << "failed at binding\n";
		return bindedAndOrListening;
	}
	bindedAndOrListening = listen (m_listeningSocketDescripter, 5);
	if (bindedAndOrListening  != 0)
	{
		std::cout << "failed at listening\n";
		return bindedAndOrListening ;
	}

	m_isListening = true;
	return bindedAndOrListening;
}

TCPDataflow* TCPServer::acceptingConnection()
{
	if (m_isListening == false)
	{
		return NULL;
	}
	struct sockaddr_in socketAddressIn;
	socklen_t sizeOfAddress = sizeof (socketAddressIn);
	memset (&socketAddressIn, 0, sizeof (socketAddressIn));
	int socketDescripter = ::accept (m_listeningSocketDescripter, (struct sockaddr*) &socketAddressIn, &sizeOfAddress);
	if(socketDescripter < 0)
	{
		return NULL;
	}
	return new TCPDataflow (socketDescripter, &socketAddressIn);
}

TCPServer::~TCPServer() {
	// TODO Auto-generated destructor stub
}

