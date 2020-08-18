#pragma once
#include<iostream>
#include <WS2tcpip.h>	// Include the Winsock library (lib) file
#include "..\UDPServer\udpBase.h"	// Include udpBase header file

#pragma comment (lib, "ws2_32.lib")

class ModelUdpClient:public udpBase
{
	friend void main();	// for accessing sendDG() in main()

public:
	explicit ModelUdpClient(const unsigned short port);	// explicit used due to warning in CppCheck
	~ModelUdpClient(); 
	int getSocket() const;

private:
	int u_socket;
	sockaddr_in server;

	void sendDG(std::string msg);	// throws warning saying "unused function" in CppCheck but called from main()

};

