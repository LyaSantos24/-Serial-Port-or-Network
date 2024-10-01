#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

fstream openDoor(string portName) {

    fstream serialPort;
    serialPort.open(portName);
    return serialPort;

}

SOCKET openDoor(string ipAddress, int port, string texto) {
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return;
	}

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	int sendResult = send(sock, texto.c_str(), texto.size(), 0);

	return sock;
}



//Other version code OpenDoor better

//bibliotecas utilizadas
//#include <iostream> 
//#include <fstream>
//#include <string>


//using namespace std;

  //fstream serial("COM7");        // abrir a porta COM7


//void openDoor() {

  //serial.is_open();

   //cout << "porta aberta" << endl; 


//}

//int main() {              			 // função principal

    
  // openDoor();  							 // função abrir porta
	
   // return 0;
//}


