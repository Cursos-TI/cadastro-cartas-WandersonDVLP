#include <stdio.h>
#include <stdlib.h>

#ifndef _UTIL_H
#define _UTIL_H

typedef struct {
    int Id;
    char Estado[2];
    float Area, PIB, DensidadePopulacional, PIBPerCapita;
    char NomeCidade[50], Codigo[3];
    int Populacao, PontosTuristicos;
} SuperTrunfo;

void LimparTela();
void PularLinha();
void LinhaSeparadora();

#endif