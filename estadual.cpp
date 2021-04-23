// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include "estadual.h"

#define OK                          0
#define ERRO_DIA_INVALIDO           1

#define HOJE                        0
#define ONTEM                       1
#define ANTES_DE_ONTEM              2

#define NUMERO_DE_DIAS_MEDIA_MOVEL  7 

Estadual::Estadual(vector <string> vetor){
    nome = vetor [0] ;
    for (long unsigned int indice = 1; indice < vetor.size() ; indice++)
        numeroObitos.push_back (stoi (vetor[indice]));

    mediaMovelAntesDeOntem = calcularMedia(ANTES_DE_ONTEM);
    mediaMovelOntem = calcularMedia(ONTEM);
    mediaMovelHoje = calcularMedia(HOJE);

    altaNosCasos = calcularAlta();
}

double Estadual::calcularMedia (int dia){
    double soma = 0;
    int indice ;
    for (indice = dia ; indice < NUMERO_DE_DIAS_MEDIA_MOVEL + dia ; indice++)
        soma += numeroObitos[indice];
    return (soma/NUMERO_DE_DIAS_MEDIA_MOVEL);
}

double Estadual::calcularAlta(){
    return mediaMovelHoje/mediaMovelOntem ;
}

string Estadual::getNome(){
    return nome;
}

double Estadual::getMediaMovelAntesOntem(){
    return mediaMovelAntesDeOntem;
}

double Estadual::getMediaMovelOntem(){
    return mediaMovelOntem;
}

double Estadual::getMediaMovelHoje(){
    return mediaMovelHoje;
}

double Estadual::getAltaNosCasos(){
    return altaNosCasos;
}

vector <int> Estadual::getNumeroObitos() {
    return numeroObitos ;
}