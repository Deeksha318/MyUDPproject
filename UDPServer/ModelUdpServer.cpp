#include "ModelUdpServer.h"

//Passing call to parameterized Base class constructor via Initializer
ModelUdpServer::ModelUdpServer(unsigned short port)	
	:udpBase(port),u_socket{-1}
{	
	// SOCKET CREATION AND BINDING

	// UDP socket creation
	u_socket = socket(AF_INET, SOCK_DGRAM, 0);
	
	// a server hint structure for the server initialized
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY;		// bind to any IP address available on the machine
	serverHint.sin_family = AF_INET;	// Address format: IPv4
	serverHint.sin_port = htons(u_port);	//Conversion to bigendian

	// Try and bind the socket to the IP and port
	if (bind(u_socket, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR)
	{
		std::cout << "Cannot bind socket! " << WSAGetLastError() << std::endl;
		return;
	}
}

ModelUdpServer::~ModelUdpServer()
{
	closesocket(u_socket);	//close socket
}

int ModelUdpServer::getSocket() const
{
	return u_socket;
}

void ModelUdpServer::recvMsg()
{
	//MAIN LOOP SETUP AND ENTRY

	sockaddr_in client; // client information (port / ip address)
	int clientLength = sizeof(client); //  size of client information

	char buf[1024];	//buffer for received message
	int count = 0;

	// Enter a loop
	while (true)
	{
		ZeroMemory(&client, clientLength); // Clear the client structure
		ZeroMemory(buf, 1024); // Clear receive buffer
		int bytesIn;
		if (count < 5)
		{
			// Wait for message
			bytesIn = recvfrom(u_socket, buf, 1024, 0, (sockaddr*)&client, &clientLength);
			count++;
		}
		else
			break;

		if (bytesIn == SOCKET_ERROR)
		{
			std::cout << "Error receiving from client " << WSAGetLastError() << std::endl;
			continue;
		}

		// Display message and client info
		char clientIp[256]; // Create enough space to convert the address byte array
		ZeroMemory(clientIp, 256); // to string of characters

		// Convert from byte array to chars for output
		inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);

		// Display the message / who sent it
		std::cout << "Message received from " << clientIp << " : " << buf << std::endl;
	}
}
