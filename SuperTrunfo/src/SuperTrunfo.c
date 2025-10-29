#include <stdio.h>
#include <stdlib.h>
#include "../include/Util.h"
#include "../include/Menus.h"
#include "../include/Cartas.h"
#include "../include/Global.h"

// --- Instancias globais ---
SuperTrunfo carta1, carta2;

#pragma region TESTE
    // ==============================================================================
    // Retorna duas cartas ja preenchidas para teste da funcao de comparacao,
    // nao sendo necessario o preenchimento manual das carta.
    // (Apenas comente as instancias globais acima e descomente as instancias abaixo.)
    //
    // Na funcao (Inicia Jogo) no arquivo Global, comente as funcoes (PreencherCarta()) de preenchimento manual.
    //
    // --- INSTANCIAS ---
    // SuperTrunfo carta1 = {
    //     .Id = 1,
    //     .Estado = "CA",
    //     .Codigo = "CA1",
    //     .NomeCidade = "Cidade A",
    //     .Populacao = 20,
    //     .Area = 500,
    //     .PIB = 35,
    //     .PontosTuristicos = 10,
    //     .DensidadePopulacional = 2,
    //     .PIBPerCapita = 80
    // };
    
    // SuperTrunfo carta2 = {
    //     .Id = 2,
    //     .Estado = "CB",
    //     .Codigo = "CB2",
    //     .NomeCidade = "Cidade B",
    //     .Populacao = 20,
    //     .Area = 600,
    //     .PIB = 28,
    //     .PontosTuristicos = 8,
    //     .DensidadePopulacional = 4,
    //     .PIBPerCapita = 70
    // };
    // ==============================================================================
#pragma endregion

int main(){
    LimparTela();
    Menu();
    return 0;
}