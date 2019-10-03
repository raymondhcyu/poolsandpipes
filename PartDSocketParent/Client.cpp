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

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(server, (SOCKADDR*)& addr, sizeof(addr));
	cout << "Connected to server!" << endl;

	char buffer[1024] = { 'h', 'e', 'l', 'l', 'o', '.' };
	send(server, buffer, sizeof(buffer), 0);
	cout << "Message sent!" << endl;

	closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl << endl;

	getchar();
}