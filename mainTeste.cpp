#include "nacional.h"
//#include "estadual.h"
#include "files.h"
#include <iostream>
#define ARQUIVO_DE_ENTRADA  "Teste.txt"

using namespace std ;

int main(){

    vector <string> informacoesDosEstados;

    informacoesDosEstados = readLines(ARQUIVO_DE_ENTRADA);
    Nacional brasil(informacoesDosEstados) ;

    cout << brasil.getNumeroObitosNacional() << endl ;


    return 0 ;
}