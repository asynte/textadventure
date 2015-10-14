#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include <netinet/in.h>
#include "TCPDataflow.h"

class TCPClient
{
public:
	TCPDataflow* connectToServer (const char* serverIP, int serverPort);

};

#endif /* TCPCLIENT_H_ */
