/* SERVER

sauce: https://causeyourestuck.io/2016/01/17/socket-cc-windows/
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <winsock2.h>

using namespace std;

// Link libraries
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

int main()
{
	WSADATA WSAData;
	SOCKET server, client; // two sockets; server handle connections, to connect from client
	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY; // no IP address b/c it's server
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5555);

	bind(server, (SOCKADDR*)& serverAddr, sizeof(serverAddr)); // like connect, but for server
	listen(server, 0);

	cout << "I am the server and I'm listening for incoming connections..." << endl;

	char buffer[1024];
	char returnBuffer[1024] = {'X'}; // stuff to send back to client
	int clientAddrSize = sizeof(clientAddr);
	if ((client = accept(server, (SOCKADDR*)& clientAddr, &clientAddrSize)) != INVALID_SOCKET)
	{
		cout << "Client connected!" << endl;
		recv(client, buffer, sizeof(buffer), 0);
		cout << "Client says: " << buffer << endl;

		for (int i = 0; i < 3; i++)
		{
			if (buffer[i] == 'A')
			{
				cout << "A received! Doing some action..." << endl;
				cout << "Sending back acknowledgement bit " << returnBuffer[0] << endl;
				send(client, returnBuffer, sizeof(returnBuffer), 0);
			}
			else if (buffer[i] == 'B')
			{
				cout << "B received! Doing some action..." << endl;
				cout << "Sending back acknowledgement bit " << returnBuffer[0] << endl;
				send(client, returnBuffer, sizeof(returnBuffer), 0);
			}
			else if (buffer[i] == 'C')
			{
				cout << "C received! Doing some action..." << endl;
				cout << "Sending back acknowledgement bit " << returnBuffer[0] << endl;
				send(client, returnBuffer, sizeof(returnBuffer), 0);
			}
		}

		memset(buffer, 0, sizeof(buffer));
		closesocket(client);
		cout << "Client disconnected." << endl;
	}

	getchar();
}