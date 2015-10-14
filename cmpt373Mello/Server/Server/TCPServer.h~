/*
 * TCPServer.h
 *
 *  Created on: Oct 11, 2015
 *      Author: mjajalo
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include <netinet/in.h>
#include "TCPDataflow.h"


class TCPServer {
public:
	TCPServer(int serverPort, const char* serverAddress = "");
	virtual ~TCPServer();
	int listeningConnection();
	TCPDataflow* acceptingConnection();
private:
	int m_serverPort;
	std::string m_serverAddress;
	int m_listeningSocketDescripter;
	bool m_isListening;
};

#endif /* TCPSERVER_H_ */
