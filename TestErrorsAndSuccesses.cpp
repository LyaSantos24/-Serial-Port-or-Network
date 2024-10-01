//This file contains errors and successes throughout the development, just as a reference

rede / Mensagem para abrir porta


#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void startDoor(string ipAddress, int port, string texto)
{

	// Inicializar WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	int sendResult = send(sock, texto.c_str(), texto.size(), 0);

	//closesocket(sock);
	//WSACleanup();

	//return sock;

}

int main() {

	startDoor("192.168.123.100", 9100, "Abrir porta\n");

}


########################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std; 
using std::regex_replace;
using std::regex;


void printText(string ipAddress, int port, string texto)
{

	// Inicializar WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	//int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));


	//closesocket(sock);
	//WSACleanup();

	//return sock;

#define textBold "\x1b\x45\x01"
#define textBold_off "\x1b\x40"
#define textCenter "\x1b\x61\x01"
#define textCenter_off "\x1b\x40"
#define textRight "\x1b\x61\x02"
#define textRight_off "\x1b\x40"
#define textUnderline "\x1b\x2d\x02"
#define textUnderline_off "\x1b\x40"
#define fontExpanded "\x1b\x20\x10" 
#define fontExpanded_off "\x1b\x40"
#define fontSmall "\x1b\x4d\x01"
#define fontSmall_off "\x1b\x40"
#define fontDefault "\x1b\x4d\x00"
#define fontDefault_off "\x1b\x40"
#define fontDoubleHeight "\x1b\x21\x10"
#define fontDoubleHeight_off "\x1b\x40"
#define fontDoubleWidth "\x1b\x21\x20"
#define fontDoubleWidth_off "\x1b\x40"
#define fontDoubleHW "\x1b\x21\x30"
#define fontDoubleHW_off "\x1b\x40"
#define fontInvert "\x1d\x42\x01"
#define fontInvert_off "\x1b\x40"
#define trigGuill "\x1d\x56\x42"
#define trigGuill_off "\x1d\x56\x42"  
#define codebar_ean13 "\x1d\x6b\x02"
#define codebar_off "\x1b\x40"

    texto = regex_replace(texto, regex("\\<ne>"), textBold);
    texto = regex_replace(texto, regex("\\</ne>"), textBold_off);
    texto = regex_replace(texto, regex("\\<ce>"), textCenter);
    texto = regex_replace(texto, regex("\\</ce>"), textCenter_off);
    texto = regex_replace(texto, regex("\\<ad>"), textRight);
    texto = regex_replace(texto, regex("\\</ad>"), textRight_off);
    texto = regex_replace(texto, regex("\\<su>"), textUnderline);
    texto = regex_replace(texto, regex("\\</su>"), textUnderline_off);
    texto = regex_replace(texto, regex("\\<ex>"), fontExpanded);
    texto = regex_replace(texto, regex("\\</ex>"), fontExpanded_off);
    texto = regex_replace(texto, regex("\\<c>"), fontSmall);
    texto = regex_replace(texto, regex("\\</c>"), fontSmall_off);
    texto = regex_replace(texto, regex("\\<p>"), fontDefault);
    texto = regex_replace(texto, regex("\\</p>"), fontDefault_off);
    texto = regex_replace(texto, regex("\\<da>"), fontDoubleHeight);
    texto = regex_replace(texto, regex("\\</da>"), fontDoubleHeight_off);
    texto = regex_replace(texto, regex("\\<dl>"), fontDoubleWidth);
    texto = regex_replace(texto, regex("\\</dl>"), fontDoubleWidth_off);
    texto = regex_replace(texto, regex("\\<dal>"), fontDoubleHW);
    texto = regex_replace(texto, regex("\\</dal>"), fontDoubleHW_off);
    texto = regex_replace(texto, regex("\\<fi>"), fontInvert);
    texto = regex_replace(texto, regex("\\</fi>"), fontInvert_off);
    texto = regex_replace(texto, regex("\\<gui>"), trigGuill);
    texto = regex_replace(texto, regex("\\</gui>"), trigGuill_off);
    texto = regex_replace(texto, regex("\\<cbar>"), codebar_ean13);
    texto = regex_replace(texto, regex("\\</cbar>"), codebar_off);

   //
    
    //serial<< texto << endl;


	int sendResult = send(sock, texto.c_str(), texto.size(), 0);

}



int main() {

	printText("192.168.123.100", 9100, "<cbar>012345678901</cbar>");
  //  printText("<ne>Negrito</ne>\n<ce>Centralizado</ce>");
  //  printText("<ad>Direita</ad>\n<su>Sublinahdo</su>");
  //  printText("<ex>Expandido</ex>\n<c>Fonte Pequena</c>");
   // printText("<da>Altura Dupla</da>\n<dl>Largura Dupla</dl>");
   // printText("<dal>Altura e Largura Dupla</dal>\n<fi>Fonte Invertida</fi>");
   // printText("<gui>\n<cbar>0123456789012</cbar></gui>");
}





########################função print text em rede funcionou #################################okay


#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void startDoor(string ipAddress, int port, string texto)
{

	// Inicializar WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));


	//closesocket(sock);
	//WSACleanup();

	//return sock;

	//string codebar_ean13 = { 0x1D,0x6B,0 };


#define textBold "\x1b\x45\x01"
#define textBold_off "\x1b\x40"
#define textCenter "\x1b\x61\x01"
#define textCenter_off "\x1b\x40"
#define textRight "\x1b\x61\x02"
#define textRight_off "\x1b\x40"
#define textUnderline "\x1b\x2d\x02"
#define textUnderline_off "\x1b\x40"
#define fontExpanded "\x1b\x20\x10" 
#define fontExpanded_off "\x1b\x40"
#define fontSmall "\x1b\x4d\x01"
#define fontSmall_off "\x1b\x40"
#define fontDefault "\x1b\x4d\x00"
#define fontDefault_off "\x1b\x40"
#define fontDoubleHeight "\x1b\x21\x10"
#define fontDoubleHeight_off "\x1b\x40"
#define fontDoubleWidth "\x1b\x21\x20"
#define fontDoubleWidth_off "\x1b\x40"
#define fontDoubleHW "\x1b\x21\x30"
#define fontDoubleHW_off "\x1b\x40"
#define fontInvert "\x1d\x42\x01"
#define fontInvert_off "\x1b\x40"
#define trigGuill "\x1d\x56\x42"
#define trigGuill_off "\x1d\x56\x42"  
#define codebar_ean13 "\x1d\x6b\x02"
#define codebar_off "\x1b\x40"


	texto = regex_replace(texto, regex("\\<ne>"), textBold);
	texto = regex_replace(texto, regex("\\</ne>"), textBold_off);
	texto = regex_replace(texto, regex("\\<cbar>"), codebar_ean13);
	texto = regex_replace(texto, regex("\\</cbar>"), codebar_off);
	texto = regex_replace(texto, regex("\\<ce>"), textCenter);
	texto = regex_replace(texto, regex("\\</ce>"), textCenter_off);
	texto = regex_replace(texto, regex("\\<ad>"), textRight);
	texto = regex_replace(texto, regex("\\</ad>"), textRight_off);
	texto = regex_replace(texto, regex("\\<su>"), textUnderline);
	texto = regex_replace(texto, regex("\\</su>"), textUnderline_off);
	texto = regex_replace(texto, regex("\\<ex>"), fontExpanded);
	texto = regex_replace(texto, regex("\\</ex>"), fontExpanded_off);
	texto = regex_replace(texto, regex("\\<c>"), fontSmall);
	texto = regex_replace(texto, regex("\\</c>"), fontSmall_off);
	texto = regex_replace(texto, regex("\\<p>"), fontDefault);
	texto = regex_replace(texto, regex("\\</p>"), fontDefault_off);
	texto = regex_replace(texto, regex("\\<da>"), fontDoubleHeight);
	texto = regex_replace(texto, regex("\\</da>"), fontDoubleHeight_off);
	texto = regex_replace(texto, regex("\\<dl>"), fontDoubleWidth);
	texto = regex_replace(texto, regex("\\</dl>"), fontDoubleWidth_off);
	texto = regex_replace(texto, regex("\\<dal>"), fontDoubleHW);
	texto = regex_replace(texto, regex("\\</dal>"), fontDoubleHW_off);
	texto = regex_replace(texto, regex("\\<fi>"), fontInvert);
	texto = regex_replace(texto, regex("\\</fi>"), fontInvert_off);
	texto = regex_replace(texto, regex("\\<gui>"), trigGuill);
	texto = regex_replace(texto, regex("\\</gui>"), trigGuill_off);
	texto = regex_replace(texto, regex("\\<cbar>"), codebar_ean13);
	texto = regex_replace(texto, regex("\\</cbar>"), codebar_off);


	int sendResult = send(sock, texto.c_str(), texto.size(), 0);

}


int main() {

	startDoor("192.168.123.100", 9100, "<ne>Negrito</ne>\n<ce>Centralizado</ce>\n<ad>Direita</ad>\n<su>Sublinhado</su>\n<ex>Expandido</ex>\n<c>Fonte Pequena</c>\n<da>Altura Dupla</da>\n<dl>Largura Dupla</dl>\n<dal>Altura e Largura Dupla</dal>\n<fi>Fonte Invertida</fi>\n<gui>\n<cbar>0123456789012</cbar></gui>");



}



##################################serial com acento########################printtext########################################
#include <iostream>
#include <fstream>
#include <string>
#include <regex>



//voide printText(openDoor, string Text);

using namespace std;
using std::regex_replace;
using std::regex;

ofstream serial("COM3");

void printText(string texto) {

#define textBold "\x1b\x45\x01"
#define textBold_off "\x1b\x40"
#define textCenter "\x1b\x61\x01"
#define textCenter_off "\x1b\x40"
#define textRight "\x1b\x61\x02"
#define textRight_off "\x1b\x40"
#define textUnderline "\x1b\x2d\x02"
#define textUnderline_off "\x1b\x40"
#define fontExpanded "\x1b\x20\x10" 
#define fontExpanded_off "\x1b\x40"
#define fontSmall "\x1b\x4d\x01"
#define fontSmall_off "\x1b\x40"
#define fontDefault "\x1b\x4d\x00"
#define fontDefault_off "\x1b\x40"
#define fontDoubleHeight "\x1b\x21\x10"
#define fontDoubleHeight_off "\x1b\x40"
#define fontDoubleWidth "\x1b\x21\x20"
#define fontDoubleWidth_off "\x1b\x40"
#define fontDoubleHW "\x1b\x21\x30"
#define fontDoubleHW_off "\x1b\x40"
#define fontInvert "\x1d\x42\x01"
#define fontInvert_off "\x1b\x40"
#define trigGuill "\x1d\x56\x42"
#define trigGuill_off "\x1d\x56\x42"  
#define codebar_ean13 "\x1d\x6b\x02"
#define codebar_off "\x1b\x40"
#define acento "\x1b\x74\x06"
#define acento_off "\x1b\x74\x06" //acentução de ASCII 


    texto = regex_replace(texto, regex("\\<ne>"), textBold);
    texto = regex_replace(texto, regex("\\</ne>"), textBold_off);
    texto = regex_replace(texto, regex("\\<ce>"), textCenter);
    texto = regex_replace(texto, regex("\\</ce>"), textCenter_off);
    texto = regex_replace(texto, regex("\\<ad>"), textRight);
    texto = regex_replace(texto, regex("\\</ad>"), textRight_off);
    texto = regex_replace(texto, regex("\\<su>"), textUnderline);
    texto = regex_replace(texto, regex("\\</su>"), textUnderline_off);
    texto = regex_replace(texto, regex("\\<ex>"), fontExpanded);
    texto = regex_replace(texto, regex("\\</ex>"), fontExpanded_off);
    texto = regex_replace(texto, regex("\\<c>"), fontSmall);
    texto = regex_replace(texto, regex("\\</c>"), fontSmall_off);
    texto = regex_replace(texto, regex("\\<p>"), fontDefault);
    texto = regex_replace(texto, regex("\\</p>"), fontDefault_off);
    texto = regex_replace(texto, regex("\\<da>"), fontDoubleHeight);
    texto = regex_replace(texto, regex("\\</da>"), fontDoubleHeight_off);
    texto = regex_replace(texto, regex("\\<dl>"), fontDoubleWidth);
    texto = regex_replace(texto, regex("\\</dl>"), fontDoubleWidth_off);
    texto = regex_replace(texto, regex("\\<dal>"), fontDoubleHW);
    texto = regex_replace(texto, regex("\\</dal>"), fontDoubleHW_off);
    texto = regex_replace(texto, regex("\\<fi>"), fontInvert);
    texto = regex_replace(texto, regex("\\</fi>"), fontInvert_off);
    texto = regex_replace(texto, regex("\\<gui>"), trigGuill);
    texto = regex_replace(texto, regex("\\</gui>"), trigGuill_off);
    texto = regex_replace(texto, regex("\\<cbar>"), codebar_ean13);
    texto = regex_replace(texto, regex("\\</cbar>"), codebar_off);
    texto = regex_replace(texto, regex("\\<acento>"), acento);
    texto = regex_replace(texto, regex("\\</acento>"), acento_off);

    serial << texto << endl;

}

int main() {

    printText("<ne>Negrito</ne>\n<ce>Centralizado</ce>");
    printText("<ad>Direita</ad>\n<su>Sublinhado</su>");
    printText("<ex>Expandido</ex>\n<c>Fonte Pequena</c>\n<acento><p> Padrão</p></acento>");
    printText("<da>Altura Dupla</da>\n<dl>Largura Dupla</dl>");
    printText("<dal>Altura e Largura Dupla</dal>\n<fi>Fonte Invertida</fi>");

    printText("<gui>\n<cbar>0123456789012</cbar></gui>");
  
}


###################CODE128 REDE########################################################################


#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

//fstream serial("COM3");

SOCKET printCODE128(string ipAddress, int port, string codeTexto) {

#define codebar_code128 "\x1d\x6b\x49\x0f"

	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	//int sendResult = send(sock, codeTexto.c_str(), codeTexto.size(), 0);


	codeTexto = codebar_code128+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	//serial << codebar_code128 << texto << endl;
}

int main() {

	printCODE128("192.168.123.100", 9100, "012345678901234");

}



##########################PRINTTEXTFINAL COM ACENTO################################################

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void prinText(string ipAddress, int port, string texto)
{

	// Inicializar WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));


	//closesocket(sock);
	//WSACleanup();

	//return sock;

	//string codebar_ean13 = { 0x1D,0x6B,0 };


#define textBold "\x1b\x45\x01"
#define textBold_off "\x1b\x40"
#define textCenter "\x1b\x61\x01"
#define textCenter_off "\x1b\x40"
#define textRight "\x1b\x61\x02"
#define textRight_off "\x1b\x40"
#define textUnderline "\x1b\x2d\x02"
#define textUnderline_off "\x1b\x40"
#define fontExpanded "\x1b\x20\x10" 
#define fontExpanded_off "\x1b\x40"
#define fontSmall "\x1b\x4d\x01"
#define fontSmall_off "\x1b\x40"
#define fontDefault "\x1b\x4d\x00"
#define fontDefault_off "\x1b\x40"
#define fontDoubleHeight "\x1b\x21\x10"
#define fontDoubleHeight_off "\x1b\x40"
#define fontDoubleWidth "\x1b\x21\x20"
#define fontDoubleWidth_off "\x1b\x40"
#define fontDoubleHW "\x1b\x21\x30"
#define fontDoubleHW_off "\x1b\x40"
#define fontInvert "\x1d\x42\x01"
#define fontInvert_off "\x1b\x40"
#define trigGuill "\x1d\x56\x42"
#define trigGuill_off "\x1d\x56\x42"  
#define codebar_ean13 "\x1d\x6b\x02"
#define codebar_off "\x1b\x40"
#define acento "\x1b\x74\x06"
#define acento_off "\x1b\x74\x06" //acentução de ASCII 



	texto = regex_replace(texto, regex("\\<ne>"), textBold);
	texto = regex_replace(texto, regex("\\</ne>"), textBold_off);
	texto = regex_replace(texto, regex("\\<cbar>"), codebar_ean13);
	texto = regex_replace(texto, regex("\\</cbar>"), codebar_off);
	texto = regex_replace(texto, regex("\\<ce>"), textCenter);
	texto = regex_replace(texto, regex("\\</ce>"), textCenter_off);
	texto = regex_replace(texto, regex("\\<ad>"), textRight);
	texto = regex_replace(texto, regex("\\</ad>"), textRight_off);
	texto = regex_replace(texto, regex("\\<su>"), textUnderline);
	texto = regex_replace(texto, regex("\\</su>"), textUnderline_off);
	texto = regex_replace(texto, regex("\\<ex>"), fontExpanded);
	texto = regex_replace(texto, regex("\\</ex>"), fontExpanded_off);
	texto = regex_replace(texto, regex("\\<c>"), fontSmall);
	texto = regex_replace(texto, regex("\\</c>"), fontSmall_off);
	texto = regex_replace(texto, regex("\\<p>"), fontDefault);
	texto = regex_replace(texto, regex("\\</p>"), fontDefault_off);
	texto = regex_replace(texto, regex("\\<da>"), fontDoubleHeight);
	texto = regex_replace(texto, regex("\\</da>"), fontDoubleHeight_off);
	texto = regex_replace(texto, regex("\\<dl>"), fontDoubleWidth);
	texto = regex_replace(texto, regex("\\</dl>"), fontDoubleWidth_off);
	texto = regex_replace(texto, regex("\\<dal>"), fontDoubleHW);
	texto = regex_replace(texto, regex("\\</dal>"), fontDoubleHW_off);
	texto = regex_replace(texto, regex("\\<fi>"), fontInvert);
	texto = regex_replace(texto, regex("\\</fi>"), fontInvert_off);
	texto = regex_replace(texto, regex("\\<gui>"), trigGuill);
	texto = regex_replace(texto, regex("\\</gui>"), trigGuill_off);
	texto = regex_replace(texto, regex("\\<cbar>"), codebar_ean13);
	texto = regex_replace(texto, regex("\\</cbar>"), codebar_off);
	texto = regex_replace(texto, regex("\\<acento>"), acento);
	texto = regex_replace(texto, regex("\\</acento>"), acento_off);


	int sendResult = send(sock, texto.c_str(), texto.size(), 0);

}


int main() {

	prinText("192.168.123.100", 9100, "<ne>Negrito</ne>\n<ce>Centralizado</ce>\n<ad>Direita</ad>\n<su>Sublinhado</su>\n<ex>Expandido</ex>\n<c>Fonte Pequena</c>\n<acento><p> Padrão</p></acento>\n<da>Altura Dupla</da>\n<dl>Largura Dupla</dl>\n<dal>Altura e Largura Dupla</dal>\n<fi>Fonte Invertida</fi>\n<gui>\n<cbar>0123456789012</cbar></gui>");



}

##################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

//fstream serial("COM3");

SOCKET printCODE128(string ipAddress, int port, string codeTexto) {

#define codebar_code128 "\x1d\x6b\x49\x0f"



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	//int sendResult = send(sock, codeTexto.c_str(), codeTexto.size(), 0);


	codeTexto = codebar_code128+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	//serial << codebar_code128 << texto << endl;
}

int main() {

	printCODE128("192.168.123.100", 9100, "012345678901234");

}


########################code39 via rede################################################

#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

//fstream serial("COM3");

SOCKET printCODE39(string ipAddress, int port, string codeTexto) {

	string codebar_code39 = { 0x1D,0x6B,0x04,0x45,0x00 };



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	//int sendResult = send(sock, codeTexto.c_str(), codeTexto.size(), 0);


	codeTexto = codebar_code39+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	//serial << codebar_code128 << texto << endl;
}

int main() {

	printCODE39("192.168.123.100", 9100, "0123456789");

}


##############################CODE93 VIA REDE########################
#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;



SOCKET printCODE93(string ipAddress, int port, string codeTexto) {

	#define codebar_code93 "\x1d\x6b\x48\x0f"



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	


	codeTexto = codebar_code93+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	
}

int main() {

	printCODE93("192.168.123.100", 9100, "012345678901234");

}

######################CODE EAN8 via rede ##########################

#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;



SOCKET printEAN8(string ipAddress, int port, string codeTexto) {

	#define codebar_ean8 "\x1d\x6b\x03"



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));



	codeTexto = codebar_ean8+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	
}

int main() {

	printEAN8("192.168.123.100", 9100, "01234567");

}


#####################CODE EAN13 VIA REDE ######################

#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;



SOCKET printEAN13(string ipAddress, int port, string codeTexto) {

	#define codebar_ean13 "\x1d\x6b\x02"



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));



	codeTexto = codebar_ean13+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	
}

int main() {

	printEAN13("192.168.123.100", 9100, "0123456789012");

}


###########CODE ITF VIA REDE##################################

#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;



SOCKET printITF(string ipAddress, int port, string codeTexto) {

	#define codebar_ITF "\x1d\x6b\x46\x0f"



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));



	codeTexto = codebar_ITF+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	
}

int main() {

	printITF("192.168.123.100", 9100, "012345678901234");

}


########################## code UPCA via rede #############################

#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;



SOCKET printUPCA(string ipAddress, int port, string codeTexto) {

	string codebar_UPCA = { 0x1D,0x6B,0 };



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));



	codeTexto = codebar_UPCA+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	
}

int main() {

	printUPCA("192.168.123.100", 9100, "012345678910");

}


#################### code UPCE via rede#########################

#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;



SOCKET printUPCE(string ipAddress, int port, string codeTexto) {

	string codebar_UPCE = { 0x1D,0x6B,0 };



	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Não é possível iniciar Winsock, Err #" << wsResult << endl;
		return 0;
	}

	// Criar socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preencher uma estrutura de dica
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Conectar ao servidor
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));



	codeTexto = codebar_UPCE+codeTexto;

	send(sock, codeTexto.c_str(), codeTexto.size(), 0);

	
}

int main() {

	printUPCE("192.168.123.100", 9100, "012345678901");

}

####################################

//bibliotecas utilizadas
#include <iostream> 
#include <fstream>
#include <string>

#include <sstream>

using namespace std;
//std::vector ;

using byte = unsigned char;

byte lya[] = {\x1D, \x6B, \x49,\x07123EGGS};
std::string FONT_A = { '\x1b', '\x4d', '\x00' };

fstream serial("COM7");

void printUPCA(string texto) {

    

    string input = texto;
    serial << lya << input << endl;
}


int main() {

    printUPCA("123EGGS");




}


