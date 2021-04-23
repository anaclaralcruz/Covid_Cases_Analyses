// TRANSFORMA UMA FRASE EM UMA LISTA DE PALAVRAS

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

string frase = "RJ 10 20 30 40"; 
vector <string> vetor;
string palavra;
long unsigned int i;

using namespace std;

int main(){
    for(i=0;i<frase.length();i++){
        if(frase[i] != ' '){
            palavra.push_back(frase[i]);
        }
        else{
            vetor.push_back(palavra);
            palavra = "";
        }
    }

}