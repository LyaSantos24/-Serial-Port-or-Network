//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS


#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")



using namespace std;
//const char szHost[] = "www.google.com";

int main(const int argc, const char* argv[]) {


    string ipAddress = "192.168.123.100";			
    int port = 9100;
   
    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2, 1);
    if (WSAStartup(DllVersion, &wsaData) != 0) 
     
        ExitProcess(EXIT_FAILURE);
        ExitProcess(EXIT_FAILURE);
  
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in hint;
   hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr); 

	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	
	string userInput;

	do
	{
		
		cout << "> ";
		getline(cin, userInput);

		if (userInput.size() > 0)		
		{
			
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
		
		}

	} while (userInput.size() > 0);


	closesocket(sock);
	WSACleanup();
}
