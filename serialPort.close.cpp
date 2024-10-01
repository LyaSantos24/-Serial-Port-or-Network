#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void closeDoor(fstream serialPort) {

    serialPort.close();

}

void closeDoor(SOCKET sock) {

	closesocket(sock);

}
