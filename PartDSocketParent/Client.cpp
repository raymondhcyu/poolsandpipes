/* CLIENT 

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
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData); // tells computer using sockets, using winsock2
	server = socket(AF_INET, SOCK_STREAM, 0); // initialize socket
	// AF_INET = IPv4, SOCK_STREAM = TCP

	// Socket addressing
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // replace ip with futur server ip address. If server AND client running on same computer, use localhost ip 127.0.0.1
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(server, (SOCKADDR*)& addr, sizeof(addr)); // connect to server
	cout << "Connected to server!" << endl;

	char buffer[1024] = { 'B', 'o', 'n', 'j', 'o', 'u', 'r', '!' }; // message to be sent
	send(server, buffer, sizeof(buffer), 0); // send message
	cout << "Message sent!" << endl;

	// Close and cleanup sockets
	closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl << endl;

	getchar();
}