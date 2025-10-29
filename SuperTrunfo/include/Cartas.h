#include <stdio.h>
#include <stdlib.h>
#include "../include/Util.h"

#ifndef _CARTA_H
#define _CARTA_H

extern SuperTrunfo carta1, carta2;

// --- Uso para teste rapido de funcoes, traz os dados ja preenchidos
void ExibirCartas(SuperTrunfo carta);
void PreencherCarta(SuperTrunfo *carta, int id);
void ComparaCartas(float c1, float c2, const char *AtributoNome);
void ExibirCartaVencedora(SuperTrunfo vencedor, SuperTrunfo perdedor, const char *atributoNome, float valorAtributo1, float valorAtributo2, int isEmpate);
#endif