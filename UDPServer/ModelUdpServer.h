#pragma once

#include<iostream>
#include <WS2tcpip.h>	// Include the Winsock library (lib) file
#include "udpBase.h"	// Include udpBase header file

#pragma comment (lib, "ws2_32.lib")

class ModelUdpServer:public udpBase
{
	friend void main();	// for accessing recvMsg() in main()

public:
	explicit ModelUdpServer(const unsigned short port);	// explicit used due to warning in CppCheck
	~ModelUdpServer();
	int getSocket() const;

private:
	int u_socket;
	sockaddr_in serverHint;

	void recvMsg();	// throws warning saying "unused function" in CppCheck but called from main()
};

