// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector <string> readLines (string);
vector <string> vetorDeDados (string linha);
vector <string> nomesDosEstados (vector <string>);
int procurarEstado(string, vector <string>); 
