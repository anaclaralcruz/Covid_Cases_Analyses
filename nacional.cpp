// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include "nacional.h"
//#include "estadual.h"

Nacional::Nacional(vector <string> informacoesDosEstados){
    long unsigned indice, indice2 ;

    for (indice = 0 ; indice < informacoesDosEstados.size() ; indice++){
        // Cria a lista de objetos da classe estado
        Estadual estado((vetorDeDados(informacoesDosEstados[indice]) ));
        estados.push_back(estado);

        // Checar a entrada
        if (indice == 0)
            numeroObitosNacional = estado.getNumeroObitos() ;
        else {
            if (numeroObitosNacional.size() != estado.getNumeroObitos().size())
                cout << "ERRO!!! SUA ENTRADA DE DADOS PARECE ESTAR CORROMPIDA. LEMBRE-SE SE ADICIONAR A MESMA QUANTIDADE DE MORTES POR DIA EM CADA ESTADO" << endl ;

        // Adiciona o numero de mortes do brasil em um vetor
            for (indice2 = 0 ; indice2 < estado.getNumeroObitos().size() ; indice2++)
                numeroObitosNacional[indice2] += estado.getNumeroObitos()[indice2];
            
        }
    }

    
}

vector <string> Nacional::vetorDeDados (string linha) {
    string dado;
    long unsigned int i ;
    vector <string> vetor;

    for(i=0;i<=linha.length();i++){
        if(linha[i] != ' ' && linha[i] != '\0'){
            dado.push_back(linha[i]);
        }
        else{
            vetor.push_back(dado);
            dado = "";
        }
    }
    return vetor;

}

int Nacional::getNumeroObitosNacional(){
    int numero = 0 ;
    long unsigned int indice ;
    for (indice = 0 ; indice < numeroObitosNacional.size() ; indice++)
        numero += numeroObitosNacional[indice] ; 
    return numero;
}