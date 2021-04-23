// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include "files.h"
#include <string>

#define ERRO_ESTADO_NAO_ENCONTRADO  -1
//Le um arquivo e devolve as linhas separadas em um vetor 

vector <string> readLines (string arquivo){

  vector <string> vetor;
  string linha;

  ifstream file(arquivo);
  
  while (getline(file, linha)) {
    vetor.push_back(linha);
  }
  return vetor;
}

// Le uma string (linha do arquivo) e retorna um vetor com os dados

/*vector <string> vetorDeDados (string linha) {
    string dado;
    long unsigned int i ;
    vector <string> vetor;

    for(i=0;i<linha.length();i++){
        if(linha[i] != ' '){
            dado.push_back(linha[i]);
        }
        else{
            vetor.push_back(dado);
            dado = "";
        }
    }
    return vetor;

}*/

// Recebe uma lista do arquivo texto e devolve uma lista com o nome dos estados
vector <string> nomesDosEstados (vector <string> vetor){
    size_t indice;
    vector <string> listaDeEstados;
    string nomeDoEstado;

    for (indice =0; indice < vetor.size(); indice++){
        nomeDoEstado = vetor[indice];
        nomeDoEstado.resize(2);
        listaDeEstados.push_back(nomeDoEstado);
    }
    return listaDeEstados;
}


// Descobre o estado que esta sendo procurado pelo usuario

int procurarEstado(string estado, vector <string> nomes){
    long unsigned int indice;
    for (indice = 0 ; indice < nomes.size() ; indice++)
        if (nomes[indice] == estado)
            return indice ;
    return ERRO_ESTADO_NAO_ENCONTRADO ;
}