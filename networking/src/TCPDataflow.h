/*
 * TCPDataflow.h
 *
 *  Created on: Oct 11, 2015
 *      Author: mjajalo
 */

#ifndef TCPDATAFLOW_H_
#define TCPDATAFLOW_H_


#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>
#include <string>

class TCPDataflow {
public:
	ssize_t sendData (const char* writeData, size_t dataSize);
	ssize_t recvData (char* readData, size_t dataSize, int timeout = 0);
	std::string getIP ();
	int getPort ();
	friend class TCPClient;
	~TCPDataflow ();
	TCPDataflow (int sockDesc, struct sockaddr_in* address);

private:
	std::string m_IP;
	int m_port;
	int m_socketDescripter;
	bool waitForReadEvent(int timeout);
	TCPDataflow ();
	TCPDataflow (const TCPDataflow &stream);
};

#endif /* TCPDATAFLOW_H_ */
