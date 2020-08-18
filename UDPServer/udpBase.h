#pragma once
#include <iostream>
#include <WS2tcpip.h>	// Include the Winsock library (lib) file

class udpBase
{
public: 
	~udpBase(){}
	explicit udpBase(const unsigned short port);	// explicit used due to warning in CppCheck

protected:
	short unsigned u_port;
};

