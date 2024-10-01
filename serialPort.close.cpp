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





//other version


////bibliotecas utilizadas
//#include <iostream> 
//#include <fstream>
//#include <string>


//using namespace std;
//fstream serial("COM7");           //porta COM7



// void closeDoor() {             
                      

  // serial.close();

 //  cout << "porta fechada" <<endl;


//}

//int main(){                      // função principal

 //   closeDoor();               //função fechar a porta

//}
