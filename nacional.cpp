// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include "nacional.h"

#define HOJE    0
#define ONTEM   1

#define NUMERO_DE_DIAS_MEDIA_MOVEL  7 

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

void Nacional::mediaMovelEstados(){
    long unsigned indice ;
    cout << endl << "NOME\t" << "ANTES ONTEM\t" << "ONTEM\t\t" << "HOJE" << endl ;

    for (indice = 0 ; indice < estados.size() ; indice++){
        Estadual estado = estados[indice] ;
        cout << endl << estado.getNome() << "\t"
            << fixed << estado.getMediaMovelAntesOntem() << "\t"
                    << estado.getMediaMovelOntem() << "\t"
                    << estado.getMediaMovelHoje() << endl ;
    }

}



int Nacional::getNumeroObitosNacional(){
    int numero = 0 ;
    long unsigned int indice ;
    for (indice = 0 ; indice < numeroObitosNacional.size() ; indice++)
        numero += numeroObitosNacional[indice] ; 
    return numero;
}

void Nacional::evolucaoDosObitosEstados(){
    long unsigned indice ;
    vector <Estadual> emAlta ;
    vector <Estadual> emBaixa ;
    vector <Estadual> estavel ;
    
    for (indice = 0 ; indice < estados.size() ; indice++){
        Estadual estado = estados[indice] ;

        if (estado.getAltaNosCasos() > 1.15)
            emAlta.push_back(estado);
        if (estado.getAltaNosCasos() < 0.85)
            emBaixa.push_back(estado);
        else
            estavel.push_back(estado);
    }
        //Printar os resultados:
        cout << endl << "EM ALTA:  ";
        for (indice = 0 ; indice < emAlta.size() ; indice++)
            cout << emAlta[indice].getNome() << "  ";

        cout << endl << "EM BAIXA:  ";
        for (indice = 0 ; indice < emBaixa.size() ; indice++)
            cout << emBaixa[indice].getNome() << "  ";
        
        cout << endl << "ESTAVEL:  ";
        for (indice = 0 ; indice < estavel.size() ; indice++)
            cout << estavel[indice].getNome() << "  ";

}

void Nacional::evolucaoDosObitosBrasil(){
    cout << endl << "A media movel de obitos no pais esta " ;
    if (calcularAlta() > 1.15)
        cout << "EM ALTA" << endl ;
    if (calcularAlta() > 1.15)
        cout << "EM BAIXA" << endl ;
    else
        cout << "ESTAVEL" << endl ;
}


double Nacional::calcularAlta(){
    float mediaHoje = calcularMedia(HOJE);
    float mediaOntem = calcularMedia(ONTEM);
    return mediaHoje/mediaOntem ;
}

double Nacional::calcularMedia (int dia){
    double soma = 0;
    int indice ;
    for (indice = dia ; indice < NUMERO_DE_DIAS_MEDIA_MOVEL + dia ; indice++)
        soma += numeroObitosNacional[indice];
    return (soma/NUMERO_DE_DIAS_MEDIA_MOVEL);
}

void Nacional::maiorAltaMaiorBaixa(){
    long unsigned int indice ;
    long unsigned int indiceMaior = 0;
    long unsigned int indiceMenor = 0;
    string nomeEstadoMaior, nomeEstadoMenor ;
    double maiorAlta, maiorBaixa ;

    for (indice = 0 ; indice < estados.size() ; indice++){
        
        Estadual estado = estados[indice];
        Estadual estadoMaior = estados[indiceMaior];
        Estadual estadoMenor = estados[indiceMenor];

        if (estado.getAltaNosCasos() > estadoMaior.getAltaNosCasos())
            indiceMaior = indice;
        if (estado.getAltaNosCasos() < estadoMenor.getAltaNosCasos())
            indiceMenor = indice;

        estadoMaior = estados[indiceMaior];
        estadoMenor = estados[indiceMenor];

        nomeEstadoMaior = estadoMaior.getNome();
        nomeEstadoMenor = estadoMenor.getNome();

        maiorAlta = estadoMaior.getAltaNosCasos();
        maiorBaixa = estadoMenor.getAltaNosCasos();
    }
    
    cout << endl << "MAIOR ALTA: ";
    if (maiorAlta > 1)
        cout << nomeEstadoMaior << "\t+" << maiorAlta * 100 - 100 << "%" << endl  ;
    else
        cout << "Nenhum estado teve alta" ;

    cout << endl << "MAIOR BAIXA: " ;
    if (maiorBaixa < 1)
        cout << nomeEstadoMenor << "\t-" << 100 - (maiorBaixa * 100) << "%"<< endl ;
    else
        cout << "Nenhum estado teve baixa" ;
}

