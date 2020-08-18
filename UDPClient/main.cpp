#include <iostream>
#include <WS2tcpip.h>	// Include the Winsock library (lib) file
#include "ModelUdpClient.h"

void main()
{
	ModelUdpClient objClient(50003);	// pass port number

	std::string msg("DLR is great");
	for (int i = 0; i < 5; i++)		// sending msg 5 times using for loop
		objClient.sendDG(msg);		// made accessible using friend

	// Close the socket
	closesocket(objClient.getSocket());

	// Close down Winsock
	WSACleanup();
}