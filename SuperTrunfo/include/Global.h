// ===================================================================== //
// Declaracoes de funcoes globais para a aplicacao (ASSINATURA)
// ===================================================================== //

#include <stdio.h>
#include <stdlib.h>
#include "../include/Util.h"

#ifndef _GLOBAL_H
#define _GLOBAL_H

// ===================================================================== //
// --- (Apenas declaracao) Indica que as cartas serao definidas em um arquivo externo. ---
//--- Ex: Main ---
extern SuperTrunfo carta1, carta2;
// ===================================================================== //

void Regras();
void IniciaJogo();
float CalculaDensidade(SuperTrunfo c);
float CalculaPercapita(SuperTrunfo c);

#endif