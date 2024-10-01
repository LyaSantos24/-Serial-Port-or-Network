#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream serial("COM3");

void printEAN8(string texto) {

    #define codebar_ean8 "\x1d\x6b\x03"

    serial << codebar_ean8 << texto << endl;
}

int main(){

    printEAN8("01234567");

}
