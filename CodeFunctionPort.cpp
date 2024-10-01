//bibliotecas utilizadas
#include <iostream> 
#include <fstream>
#include <string>


using namespace std;

//Definindo os comandos de ESC/POS PRINTER 

#define textbold "\x1b\x45\x01"          //Negrito
#define textboldOff "\x1b\x45\x00"        //Negrito fechado
#define textcenter "\x1b\x61\x01"       //Centralizar
#define textcenterOff "\x1b\x40"        // Buffer de centralizado
#define textright "\x1b\x61\x02"        //texto a direita
#define textrightOff "\x1b\x40"        //buffer do texto a direira
#define textunderline "\x1b\x2d\x02"       //sublinhado 2
#define textunderlineOff "\x1b\x40"        //buffer do sublinhado
#define fontexpanded "\x1b\x20\x10"         //expandido
#define fontexpandedOff "\x1b\x40"         //buffer do expandido
#define fontsmall "\x1b\x4d\x01"           //fonte pequena
#define fontsmallOff "\x1b\x40"            //buffer da fonte pequena
#define fontdefault "\x1b\x4d\x00"           //fonte padrão
#define fontdefaultOff "\x1b\x40"              //buffer da fonte padrão
#define fontdoubleHeight "\x1b\x21\x10"          //altura dupla
#define fontdoubleHeightOff "\x1b\x40"         // buffer da altura dupla
#define fontdoubleWidth "\x1b\x21\x20"         //largura dupla
#define fontdoubleWidthOff "\x1b\x40"           // buffer da largura dupla
#define fontDoubleHW "\x1b\x21\x30"            //Altura e largura dupla
#define fontDoubleHWOff "\x1b\x40"            //buffer da altura e largura dupla
#define fontinvert "\x1d\x42\x01"         //fonte invertida
#define fontinvertOff "\x1b\x40"        //buffer da invertida


#define num_codebar_acima "\x1d\x48\x01"
#define num_codebar_abaixo "\x1d\x48\x02"
#define num_codebar_acima_abaixo "\x1d\x48\x03"
#define codebar_ean13 "\x1d\x6b\x02"                       
#define codebaroff "\x1b\x40"
#define codebar_ean8 "\x1d\x6b\x03"
#define codebar_upce "\x1d\x6b\x01"




fstream serial("COM7");         // ABRIR A PORTA COM7

void textBold() {                     // função em negrito

    serial << textbold << "xxxxxxx" << textboldOff << endl;

}

void textCenter() {              // função centralizado

    serial << textcenter << "xxxxxxx" << textcenterOff << endl;

}

void textRight() {                //  função texto a direita

    serial << textrightOff << endl;

    serial << textright << "xxxxxxxx" << textrightOff << endl;

}

void textUnderline() {             //função sublinhado

    serial << textunderline << "xxxxxxx" << textunderlineOff << endl;


}

void fontExpanded() {           //função expandido

    serial << fontexpanded << "xxxxxxxx" << fontexpandedOff << endl;

}

void fontSmall() {             //função fonte pequena ou font_b

    serial << fontsmall << "xxxxxxxx" << fontsmallOff << endl;

}

void fontDefault() {          // função fonte padrão

    serial << "xxxxxxx" << fontdefault << endl;

}

void fontDoubleHeight() {       //função altura dupla

    serial << fontdoubleHeight << "xxxxxxxxxx" << fontdoubleHeight << endl;

}

void fontDoubleWidth() {       // função largura dupla

    serial << fontdoubleWidth << "xxxxxxxx" << fontdoubleWidthOff << endl;

}

void fontdoubleHW() {          // função Altura e largura dupla

    serial << fontDoubleHW << "xxxxxxxx" << fontDoubleHWOff << endl;

}

void fontInvert() {      // função invertida

    serial << fontinvert << "xxxxxxxxxxx" << fontinvertOff << endl;

}

void printText(string texto) {     // função de entrada de replace das TAGS de formatação

    string input = texto;

    input.replace(input.find("<ne>"), 4, textbold);
    input.replace(input.find("</ne>"), 4, textboldOff);
    input.replace(input.find("<ce>"), 4, textcenter);
    input.replace(input.find("</ce>"), 5, textcenterOff);
    input.replace(input.find("<ad>"), 4, textright);
    input.replace(input.find("</ad>"), 5, textrightOff);
    input.replace(input.find("<su>"), 4, textunderline);
    input.replace(input.find("</su>"), 5, textunderlineOff);
    input.replace(input.find("<ex>"), 4, fontexpanded);
    input.replace(input.find("</ex>"), 5, fontexpandedOff);
    input.replace(input.find("<c>"), 3, fontsmall);
    input.replace(input.find("</c>"), 4, fontsmallOff);
    //input.replace(input.find("<p>"), 2, padrao);
    //input.replace(input.find("</p>"), 4, padraooff);
    input.replace(input.find("<da>"), 4, fontdoubleHeight);
    input.replace(input.find("</da>"), 5, fontdoubleHeightOff);
    input.replace(input.find("<dl>"), 4, fontdoubleWidth);
    input.replace(input.find("</dl>"), 5, fontdoubleWidthOff);
    input.replace(input.find("<dal>"), 5, fontDoubleHW);
    input.replace(input.find("</dal>"), 6, fontDoubleHWOff);
    input.replace(input.find("<fi>"), 4, fontinvert);
    input.replace(input.find("</fi>"), 5, fontinvertOff);
    //input.replace(input.find("<gui>"), 5, cortar1);
    //input.replace(input.find("</gui>"), 6, cortaroff);
    input.replace(input.find("<cbar>ean,"), 10, codebar_ean13);
    input.replace(input.find("</cbar>"), 7, codebaroff);
    input.replace(input.find("<cbarab>"), 8, num_codebar_abaixo);


    serial << input << endl;

}



void printEAN13(string texto) {

    string input = texto;
    serial << codebar_ean13 << input << endl;


}


void printEAN8(string texto) {

    string input = texto;
    serial << codebar_ean8 << input << endl;


}

void printUPCE(string texto) {

    string input = texto;
    serial << codebar_upce << input << endl;
}




int main() {               // função principal




    textBold();            // função negrito
    textCenter();      // função centralizar
    textRight();           // função texto a direita
    textUnderline();       // função sublinhado
    fontExpanded();        // função texto expandido
    fontSmall();            //função fonte pequena ou font_b
    fontDefault();            // função fonte padrão
    fontDoubleHeight();        //função altura dupla
    fontDoubleWidth();        // função largura dupla
    fontdoubleHW();            // função Altura e largura dupla
    fontInvert();


    printText("<ce><c>text</c> <da><ne>TEXT</ne></da> <dl><su>GERTEC</su></dl> <dal>de</dal> <fi><ex>PRINTER</ex></fi></ce> \n <ad><cbarab><cbar>ean,1234567891234</cbar></ad>");
    // função PrintText recebendo a função de replace das Tags

    printEAN13("0123456789012");
    printEAN8("01234567");
    printUPCE("012345678901");



    return 0;
}


