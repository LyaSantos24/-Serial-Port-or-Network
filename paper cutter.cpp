//bibliotecas utilizadas
#include <iostream> 
#include <fstream>
#include <string>


using namespace std;

#define trigguil "\x1d\x56\x42"        // comando esc/pos printer para Visual C++ Windowns cortar papel

fstream serial("COM7");              //porta COM7
 



void trigGuill() {        

    serial << trigguil << endl;

}

int main(){                      // função principal

           
        trigGuill();   
                              // função Acionar Guilhotina

}
