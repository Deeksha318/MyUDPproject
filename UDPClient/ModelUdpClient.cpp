#include "ModelUdpClient.h"
// Including udpBase header and cpp file here as well, or else program throws linker error
#include "..\UDPServer\udpBase.h"
#include "..\UDPServer\udpBase.cpp"

// Passing call to parameterized Base class constructor via Initializer
ModelUdpClient::ModelUdpClient(const unsigned short port)
	:udpBase(port),u_socket{-1}
{
	// Creating Socket of type datagram
	u_socket = socket(AF_INET, SOCK_DGRAM, 0);
	
	// Create a hint structure for the server
	server.sin_family = AF_INET;	 // AF_INET = IPv4 addresses
	server.sin_port = htons(u_port);	// conversion to bigendian
	inet_pton(AF_INET, "127.0.0.2", &server.sin_addr); // Convert from string to byte array	
}

ModelUdpClient::~ModelUdpClient()
{
	closesocket(u_socket);	// close socket
}

int ModelUdpClient::getSocket() const
{
	return u_socket;
}

void ModelUdpClient::sendDG(std::string msg)
{
	// Write out to that socket
	int sendOk = sendto(u_socket, msg.c_str(), msg.size() + 1, 0, (sockaddr*)&server, sizeof(server));

	if (sendOk == SOCKET_ERROR)
	{
		std::cout << "Error while sending " << WSAGetLastError() << std::endl;
	}
}
