/* Arquivo de IMPLEMENTACAO - Definicao da logica */

#include <stdio.h>
#include <stdlib.h>
#include "../include/Util.h" // --- Inclusao do cabecalho ---

void LimparTela(){

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void LinhaSeparadora(){
    puts("--------------------------------");
}

void PularLinha(){
    puts("");
}