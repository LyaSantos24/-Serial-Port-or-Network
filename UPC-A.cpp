#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream serial("COM3");

void printUPCA(string texto) {

    string UPCA = {0x1D,0x6B,0};

    serial << UPCA << texto << endl;
}

int main() {

    printUPCA("012345678910");

}
