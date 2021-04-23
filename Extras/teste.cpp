/// LER UM ARQUIVO LINHA A LINHA 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <string> vetor;
vector <string> rio;

int readLines (string arquivo)
{
  ifstream file(arquivo);
  string str;
  string dado;
  while (getline(file, str)) {
    vetor.push_back(str);
  }
//  while (getline(vetor[0],dado,' ')){
//    rio.push_back(dado);
//  }


  cout << vetor[0] << endl ;
}