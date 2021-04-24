// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include "files.h"
#include "nacional.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

#define ARQUIVO_DE_ENTRADA  "Teste.txt"

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
    
    if (opcaoMenu < 1 || opcaoMenu > 5){
        cout << endl << endl << endl << "ENTRADA INVALIDA, digite um numero de 1 a 5" << endl;
        main();
    }

    // Ler os dados do arquivo de entrada
    informacoesDosEstados = readLines(ARQUIVO_DE_ENTRADA);

    // Criar classe Nacional a partir dos dados de entrada
    Nacional brasil(informacoesDosEstados) ; 

    // Opcao 1
    if (opcaoMenu == 1)
        brasil.mediaMovelEstados();

    // Opcao 2
    if (opcaoMenu == 2)
        brasil.evolucaoDosObitosEstados();

    // Opcao 3
    if (opcaoMenu == 3)
        brasil.evolucaoDosObitosBrasil();

/*

    //Opcao 4
    if (opcaoMenu == 4){
        long unsigned int indiceMaior = 0;
        long unsigned int indiceMenor = 0;
        string nomeEstadoMaior, nomeEstadoMenor ;
  //      Estadual estadoMaior(vetorDeDados(informacoesDosEstados[indiceMaior]));
  //      Estadual estadoMenor(vetorDeDados(informacoesDosEstados[indiceMenor]));

        for (indice = 0 ; indice < informacoesDosEstados.size() ; indice++){

            Estadual estado(vetorDeDados(informacoesDosEstados[indice]));
            Estadual estadoMaior(vetorDeDados(informacoesDosEstados[indiceMaior]));
            Estadual estadoMenor(vetorDeDados(informacoesDosEstados[indiceMenor]));

            if (altaEstado > estadoMaior.getAltaNosCasos())
                indiceMaior = indice;
            if (altaEstado < estadoMenor.getAltaNosCasos())
                indiceMenor = indice;

            nomeEstadoMaior = estadoMaior.getNome();
            nomeEstadoMenor = estadoMenor.getNome();

            maiorAlta = estadoMaior.getAltaNosCasos();
            maiorBaixa = estadoMenor.getAltaNosCasos();
        }

        cout << endl << "MAIOR ALTA: " << nomeEstadoMaior << endl ;
        cout << endl << "MAIOR BAIXA: " << nomeEstadoMenor << endl ;
    }

*/
    cout << endl;
    return 0;
}