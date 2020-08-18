#include <iostream>
#include <WS2tcpip.h>	// Include the Winsock library (lib) file
#include "ModelUdpServer.h"

#pragma comment (lib, "ws2_32.lib")

// Main entry point into the server
void main()
{
	ModelUdpServer objServer(50003);	//pass port number
	objServer.recvMsg();	//made accessible using friend

	closesocket(objServer.getSocket());		// Close socket

	// Shutdown winsock
	WSACleanup();
}