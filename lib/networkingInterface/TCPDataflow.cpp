/*
 * TCPDataflow.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: mjajalo
 */

#include <arpa/inet.h>
#include "networkingHeaders/TCPDataflow.h"
#include <string>

#include <stdio.h>

TCPDataflow::~TCPDataflow()
{
	close(m_socketDescripter);
}

TCPDataflow::TCPDataflow()
{
	// TODO Auto-generated constructor stub

}

TCPDataflow::TCPDataflow (int sockDesc, struct sockaddr_in* address) :
		m_socketDescripter(sockDesc){
		char ip[50];
		inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr),
				ip, sizeof(ip)-1);
		m_IP = ip;
		m_port = ntohs(address->sin_port);
}

std::string TCPDataflow::getIP ()
{
	return m_IP;
}

int TCPDataflow::getPort ()
{
	return m_port;
}

ssize_t TCPDataflow::sendData (const char* writeData, size_t dataSize)
{
	return write (m_socketDescripter, writeData, dataSize);
}

ssize_t TCPDataflow::recvData (char* readData, size_t dataSize, int timeout)
{
	if (timeout <= 0)
	{
		return read(m_socketDescripter, readData, dataSize);
	}
	if (waitForReadEvent (timeout) == true)
	{
		return read(m_socketDescripter, readData, timeout);
	}
	return -2;
}

bool TCPDataflow::waitForReadEvent(int timeout)
{
	fd_set socketSet;
	struct timeval tv;
	tv.tv_sec = timeout;
	tv.tv_usec = 0;
	FD_ZERO(&socketSet);
	FD_SET(m_socketDescripter, &socketSet);
	if (select(m_socketDescripter + 1, &socketSet, NULL, NULL, &tv) > 0)
	{
		return true;
	}
	return false;
}
