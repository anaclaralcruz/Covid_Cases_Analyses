// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

/* "main.cpp" ------------------------------------------------- */
/* Funcao principal que contem o menu do programa */

#include "files.h"
#include "nacional.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

#define ARQUIVO_DE_ENTRADA  "dados.txt"

using namespace std ;

int main (){
    int opcaoMenu ;
    vector <string> informacoesDosEstados ;

    // Menu de entrada:
    cout << " ______________________________________________________" << endl;
    cout << "| 1 | Media movel de cada estado nos ultimos 7 dias   |" << endl;
    cout << "| 2 | Evolucao dos obitos por estado                  |" << endl;
    cout << "| 3 | Evolucao dos obitos no Brasil                   |" << endl;
    cout << "| 4 | Estado com maior alta e maior baixa             |" << endl;
    cout << "| 5 | Numero de obitos acumulados                     |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "O que deseja? (digite o numero) -> ";
    cin >> opcaoMenu ;
    
    // Checar entrada
    if (opcaoMenu < 1 || opcaoMenu > 5){
        cout << endl << endl << endl << "ENTRADA INVALIDA, digite um numero de 1 a 5" << endl;
        main();
    }

    // Ler os dados do arquivo de entrada
    informacoesDosEstados = readLines(ARQUIVO_DE_ENTRADA);

    // Criar classe Nacional a partir dos dados de entrada
    Nacional brasil(informacoesDosEstados) ; 

    if (opcaoMenu == 1)
        brasil.mediaMovelEstados();
    if (opcaoMenu == 2)
        brasil.evolucaoDosObitosEstados();
    if (opcaoMenu == 3)
        brasil.evolucaoDosObitosBrasil();
    if (opcaoMenu == 4)
        brasil.maiorAltaMaiorBaixa();
    if (opcaoMenu == 5)
        brasil.getNumeroObitosNacional();
       
    cout << endl;
    return 0;
}