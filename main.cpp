// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include "files.h"
#include "estadual.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

#define ARQUIVO_DE_ENTRADA  "Teste.txt"

using namespace std ;

int main (){
    int opcaoMenu ;
    long unsigned int indice ;
    vector <string> informacoesDosEstados ;

    // Menu de entrada:
    cout << " ______________________________________________________" << endl;
    cout << "| 1 | Media movel de cada estado nos ultimos 7 dias   |" << endl;
    cout << "| 2 | Evolucao dos casos por estado                   |" << endl;
    cout << "| 3 | Evolucao dos casos no Brasil                    |" << endl;
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

    // Opcao 1
    if (opcaoMenu == 1){
        cout << endl << "NOME\t" << "ANTES ONTEM\t" << "ONTEM\t\t" << "HOJE" << endl ;

        for (indice = 0 ; indice < informacoesDosEstados.size() ; indice++){
            Estadual estado(vetorDeDados(informacoesDosEstados[indice]));
            cout << endl << estado.getNome() << "\t"
                         << fixed << estado.getMediaMovelAntesOntem() << "\t"
                         << estado.getMediaMovelOntem() << "\t"
                         << estado.getMediaMovelHoje() << endl ;
    }
    }

    // Opcao 2
    if (opcaoMenu == 2){
        vector <Estadual> emAlta ;
        vector <Estadual> emBaixa ;
        vector <Estadual> estavel ;

        for (indice = 0 ; indice < informacoesDosEstados.size() ; indice++){
            Estadual estado(vetorDeDados(informacoesDosEstados[indice]));

            if (estado.getAltaNosCasos() > 1.15)
                emAlta.push_back(estado);
            if (estado.getAltaNosCasos() < 0.85)
                emBaixa.push_back(estado);
            else
                estavel.push_back(estado);
    }
        cout << "EM ALTA:  ";
        for (indice = 0 ; indice < emAlta.size() ; indice++)
            cout << emAlta[indice].getNome() << "  ";

        cout << endl << "EM BAIXA:  ";
        for (indice = 0 ; indice < emBaixa.size() ; indice++)
            cout << emBaixa[indice].getNome() << "  ";
        
        cout << endl << "ESTAVEL:  ";
        for (indice = 0 ; indice < estavel.size() ; indice++)
            cout << estavel[indice].getNome() << "  ";

    }

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


    cout << endl;
    return 0;
}