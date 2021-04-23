// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include "files.h"
#include "estadual.h"

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std ;

int main (){
    // Menu de entrada:
    long unsigned int indice;
    string nomeDoEstado;
    vector <string> listaNomesDosEstados;
    vector <string> informacoesDosEstados;
    string str;
    str.erase();

    int numero;
    vector <string> linha;

    informacoesDosEstados = readLines("Teste.txt");
    listaNomesDosEstados = nomesDosEstados(informacoesDosEstados);

    cout << listaNomesDosEstados[0];
    for (indice = 1; indice < listaNomesDosEstados.size(); indice++)
        cout << '\t' << listaNomesDosEstados[indice];

    cout << endl << "Digite o Estado que deseja conferir: ";
    cin >> nomeDoEstado ;

    numero = procurarEstado(nomeDoEstado, listaNomesDosEstados);
    cout << informacoesDosEstados[numero] << endl;

  //  string palavra ;
    //palavra = vetorDeDados(informacoesDosEstados[numero]);


    Estadual estado(vetorDeDados(informacoesDosEstados[numero]));
    cout << estado.getMediaMovelHoje() << endl;
    cout << estado.getMediaMovelOntem() << endl ;

    return 0;

}