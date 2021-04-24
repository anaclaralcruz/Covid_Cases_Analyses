// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include <vector>
#include <string>
#include "estadual.h"

using namespace std ;

class Nacional {
    public:
        // Construtor 
            /* input: vetor em que cada elemento eh uma linha do arquivo de entrada */
        Nacional(vector <string>);

        // Printa a media movel de cada estado
        void mediaMovelEstados();

        // Printa na tela a evolucao dos casos por estado
        void evolucaoDosObitosEstados();

        // Printa na tela a evolucao dos casos no brasil
        void evolucaoDosObitosBrasil();

        // Printa na tela o numero acumulado de obitos
        int getNumeroObitosNacional();

        //Printa na tela os estados com maior alta e maior baixa
        void maiorAltaMaiorBaixa();
        
    private:
        vector <Estadual> estados;
        vector <int> numeroObitosNacional ;
        // Calcula alta nos casos
        double calcularAlta();
        double calcularMedia(int);
        // Le uma string (linha do arquivo) e retorna um vetor com os dados
        vector <string> vetorDeDados (string linha) ;
};

