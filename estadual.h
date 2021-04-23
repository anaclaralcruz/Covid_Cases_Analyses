// Autora: Ana Clara Loureiro Cruz
// Data: 22-04-2021

/*  TRABALHO 1 - LING PROG  */
    // Analise da media movel dos casos de COVID no Brasil

#include <vector>
#include <string>
//#include <iostream>

using namespace std;

class Estadual {
    public:
        Estadual(vector <string>);   
        
        string getNome();
        double getMediaMovelAntesOntem();
        double getMediaMovelOntem();
        double getMediaMovelHoje();

    private:
        double mediaMovelHoje;
        double mediaMovelOntem;
        double mediaMovelAntesDeOntem;
        double calcularMedia(int);
        string nome;
        vector <int> numeroObitos;
};

