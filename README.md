# MyUDPproject
MyUDPProject is a Client/Server Architecture developed using object oriented programming and inheritence.
Steps to execute:
1. Load UDPProject1.sln in Visual Studio.
2. Run UDPServer application and leave it up and running.
    UDPServer will wait for client to send messages. As soon as it receives 5 messages, it will close. 
    In case received messages are less then 5,server will wait for 5th message and close only after receiving it.
3. Run UDPClient application
    UdpClient is programmed to send 5 messages saying "DLR is great". Once server receives these 5 messages it will close.
