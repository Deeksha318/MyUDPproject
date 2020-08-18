#include "udpBase.h"

// Initialize port number using Initializer list
 udpBase::udpBase(const unsigned short port)
	 :u_port{port}
{
	// INITIALIZE WINSOCK

	// Structure to store the WinSock version which is filled in on the call to WSAStartup()
	WSADATA data;

	// To start WinSock, the required version must be passed to WSAStartup().
	// This server is going to use WinSock version 2.
	// A word is created that will store 2 and 2 in hex i.e. 0x0202
	WORD version = MAKEWORD(2, 2);

	// Start WinSock
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0)
	{
		// Problem in starting Winsock
		std::cout << "Cannot start Winsock! " << wsOk;
		return;
	}
}
