#include <windows.h>
#include <string>
#include <IOSTREAM>
using namespace std;

typedef struct DataInfo
{
    string Port;  //Serial port number
    int BawdRate;//Baud rate
    int DataBits;  //Data bits
    char Parity;  //Check Digit
    int ReceiveBuffer;  //Buffer
    int StopBits;//Stop bit
}PrintDevice;

int   WriteData(string meg);
int InitPort(PrintDevice &device);
void InitializeDevicePar(PrintDevice &device);
HANDLE hPort=NULL;  //Handle

int main()
{
    PrintDevice device;
    InitializeDevicePar(device);  //Initialize printer parameters

    InitPort(device);  //Initialize the printer port

    string s;

    ////////////////////////////Print head information start//////////////////////////////////
    //Set Chinese bold + four times the size, "FS! N", n = 4 + 8+128, 
    s= "\\x1C\\x21\\x8C";
    WriteData(s);

    s="Shop-Shanghai Tripjet\\x0A";
    WriteData(s); //print

    //Cancel Chinese zoom setting
    DWORD iBytesLength;
    char chSetCode[] = "\\x1C\\x21\\x0";
    WriteFile(hPort, chSetCode, (DWORD)3L, &iBytesLength, NULL);
    //////////////////////////End of print head information///////////////////////////////////////

    //////////////////////////Start printing goods////////////////////////////////////////
    s="Shandong Apple\\t4.00\\t2x\\t8.00 Yuan\\x0A";
    WriteData(s); //print
    s="Fujian Orange\\t5.00\\t3x\\t15.00yuan\\x0A";
    WriteData(s); //print
    s="\\x0A";
    WriteData(s); //print
    //////////////////////////// End of printing goods//////////////////////////////////////
    s="Subtotal: RMB 23.00\\x0A";
    WriteData(s); //print

    //Feed the paper to the cutting position, and then cut the paper, "GS V m n", n=the number of lines to be fed
    s= "\\x1D\\x56\\x41\\x01";  //m=65 65 is full cut, 66 is half cut, n=1 0<=n<=255
    WriteData(s); //print

    CloseHandle(hPort);//Close the port

    return 0;
}
void InitializeDevicePar(PrintDevice &device)
{
    device.Port="COM4";
    device.BawdRate=9600;
    device.DataBits=8;
    device.StopBits=ONESTOPBIT;
    device.Parity=NOPARITY;  //NONE
    device.ReceiveBuffer=256;
}
int InitPort(PrintDevice &device)
{
    hPort = CreateFile(device.Port.c_str(), GENERIC_READ | GENERIC_WRITE,
        0, NULL, 
        OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, NULL );

    if (hPort == INVALID_HANDLE_VALUE) 
    {   // Failed to open the port
        return false;
    }
    else
    { 
        //Set the port buffer
        SetupComm(hPort, 1024, 1024); 

        // Set communication port timeout parameters
        COMMTIMEOUTS tmouts;
        tmouts.ReadIntervalTimeout = 100;
        tmouts.ReadTotalTimeoutMultiplier = 100;
        tmouts.ReadTotalTimeoutConstant = 100;
        tmouts.WriteTotalTimeoutConstant = 100;
        tmouts.WriteTotalTimeoutMultiplier = 100;
        SetCommTimeouts(hPort, &tmouts);

        //Set communication port communication parameters
        DCB dcb;
        BOOL bol = TRUE;

        //dcb.DCBlength = sizeof(dcb);
        bol=GetCommState(hPort, &dcb);
        dcb.BaudRate = device.BawdRate;
        dcb.ByteSize =device.DataBits;
        dcb.StopBits = device.StopBits;
        dcb.Parity = device.Parity;

        bol = SetCommState(hPort, &dcb); //Configure serial port
        // Clear the communication port cache
        PurgeComm(hPort, PURGE_TXCLEAR | PURGE_RXCLEAR | PURGE_TXABORT | PURGE_RXABORT);

        // Initialize overlapping IO objects
        OVERLAPPED m_OverlappedRead;
        OVERLAPPED m_OverlappedWrite;
        HANDLE m_hStopCommEvent;
        HANDLE m_hDataReady;
        memset(&m_OverlappedRead, 0, sizeof(OVERLAPPED));
        m_OverlappedRead.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
        memset(&m_OverlappedWrite, 0, sizeof(OVERLAPPED));
        m_OverlappedWrite.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

        // Initialize the event object
        m_hStopCommEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
        m_hDataReady = CreateEvent(NULL, FALSE, FALSE, NULL);

        //Initial print ESC @
        DWORD iBytesLength;
        char chInitCode[] = "\\x0D\\x1B\\x40";
        WriteFile(hPort, chInitCode, (DWORD)3L, &iBytesLength, NULL);
    }

    return 0;

}
int   WriteData(string meg)
{
    DWORD dwWrite;
    WriteFile(hPort, meg.c_str(), (DWORD)meg.length(), &dwWrite, NULL);
    return 0;
}
