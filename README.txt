Autora: Ana Clara Loureiro Cruz
UFRJ - DEL - ENGENHARIA ELETRONICA E DE COMPUTACAO
Trabalho de Ling Prog
Programa feito em c++

---------------------- PROJETO PARA ANALISAR CASOS DE COVID EM UM PAIS ---------------------

[Todo o amor e sentimentos as vitimas da pandemia e seus familiares]

Este programa tem como objetivo analisar os casos de covid num pais. Ele possui 
as seguintes funcionalidades:
1. Exibir a evolucao no numero de obitos a cada estado;
2. Exibir de forma agrupada os estados EM ALTA, EM BAIXA e ESTAVEIS;
3. Exibir o estado do pais em analise (EM ALTA, EM BAIXA ou ESTAVEL);
4. Exibir o estado com maior alta e maior baixa no ultimo dia;
5. Exibir os dados acumulados do numero de obitos.

---------------------------------- MANUAL DO PROGRAMA ---------------------------------------

ULTILIZACAO
    - Abrir pasta
    - Compilar e linkeditar o programa usando o comando "make"
    - Inicializar o executavel "./trabalho"
    (um menu aparecera na tela com as opcoes)
    - insira o numero correspondente a opcao que deseja, o resultado aparecera na tela.

ENTRADA DE DADOS:
    A entrada deve ser feita atraves de um Arquivo .txt em que cada linha contem os dados de um Estado
    No inicio de cada linha deve ser escrito a sigla de cada estado (ex.: RJ, SP, PB ...) 
    e em seguida, deve ser fornecido a quantidade de mortes em cada dia separadas por espaco,
    sendo a data mais recente inserida no inicio, da seguinte forma:

    [SIGLA] [NUMERO DE MORTES HOJE] [NUMERO DE MORTES ONTEM] [NUMERO DE MORTES ANTES DE ONTEM] ... [NUMERO DE MORTES MENOS RECENTE] '\n'
    [SIGLA 2] [NUMERO DE MORTES HOJE] [NUMERO DE MORTES ONTEM] ...
    .
    .
    .

    Um exemplo de arquivo de entrada esta anexado com o nome "dados.txt".
    Para alterar o nome do arquivo de entrada, a macro ARQUIVO_DE_ENTRADA no "main.cpp" deve ser alterada com o nome do arquivo.

------------------------- ARQUIVOS ---------------------------------------------------------------------------

"estadual.cpp"      Contem os metodos referentes a classe Estadual
"estadual.h"        Inicializa a classe Estadual
"files.cpp"         Contem as funcoes necessarias para manipular os dados de entrada
"files.h"           Inicializa as funcoes para manipulacao de arquivo
"main.cpp"          Programa principal que contem o menu do programa
"Makefile"          Realiza a compilacao e linkedicao do programa
"nacional.cpp"      Contem os metodos referentes a classe Nacional
"nacional.h"        Inicializa a classe Nacional
"dados.txt"         Arquivo onde os dados devem ser inseridos