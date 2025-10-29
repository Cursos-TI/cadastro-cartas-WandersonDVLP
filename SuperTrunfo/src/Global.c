// ===================================================================== //
// Implementacoes
// ===================================================================== //

#include <stdio.h>
#include <stdlib.h>
#include "../include/Menus.h"
#include "../include/Cartas.h"
#include "../include/Global.h"

void IniciaJogo(){

    PreencherCarta(&carta1, 1);
    PreencherCarta(&carta2, 2);

    #pragma region TESTE
    // ==========================================================================
    // Caso nao esteja usando o preenchimento manualmente, descomente esse codigo
    // para visualizar os valores para testar a funcao de comparacao e resultados.
    // --- FUNCTIONS ---
    // ExibirCartas(carta1);
    // ExibirCartas(carta2);
    // ==========================================================================
    #pragma endregion

    MenuEscolhaAtributos();
}

float CalculaDensidade(SuperTrunfo c){
    if(c.Populacao == 0 || c.Area == 0) return 0;

    return c.Populacao / c.Area;
}

float CalculaPercapita(SuperTrunfo c){
    if(c.PIB == 0 || c.Populacao == 0) return 0;

    return c.PIB / c.Populacao;
}

void Regras(){
    puts("");
    puts("      *** REGRAS ***");
    puts("--------------------------------");
    puts("Como jogar:");
    puts("Voce deve preencher os valores das cartas na ordem em que sao exibidos,");
    puts("preencha corretamente os dados para que possam ser comparados.");
    puts("--------------------------------");
    puts("Vencedor:");
    puts("O sistema ira lhe exibir os atributos disponiveis e voce devera");
    puts("selecionar um deles para serem comparados, o vencedor sera definido");
    puts("pelo atributo que tiver o maior valor (Exeto pela DENSIDADE, a qual vence");
    puts("aquele que obtiver a menor densidade.)");
    puts("--------------------------------");
    puts("Empate:");
    puts("Sera definido empate atributos que contenham valores iguais.");
    puts("--------------------------------");
    puts("Info:");
    puts("Os dados de DENSIDADE e PERCAPITA sao calculados automaticamente apos o preenchimento dos atributos das cartas.");
    puts("");

    Menu();
}