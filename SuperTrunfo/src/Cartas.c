
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Util.h"
#include "../include/Cartas.h"
#include "../include/Global.h"

void PreencherCarta(SuperTrunfo *carta, int id){
    carta->Id = id;

    puts("");
    printf("           CARTA - %d\n", id);
    LinhaSeparadora();
    puts("  Preencha os atributos da carta");
    printf("\n");

    printf("Estado: ");
    scanf(" %s", &carta->Estado);                                                   // Acrescentar um espaco ignora o \n no buffer

    printf("Codigo (3 caracteres): ");
    scanf(" %3s", carta->Codigo);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta->NomeCidade);                                         // Permite espacos no nome, para receber strings compostas

    printf("Populacao: ");
    scanf("%d", &carta->Populacao);

    printf("Area: ");
    scanf("%f", &carta->Area);

    printf("PIB: ");
    scanf("%f", &carta->PIB);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->PontosTuristicos);

    carta->DensidadePopulacional = CalculaDensidade(*carta);
    carta->DensidadePopulacional = CalculaPercapita(*carta);

    puts("");
}

void ExibirCartas(SuperTrunfo carta){
    printf("            Carta - %d \n", carta.Id);
    printf("--------------------------------------------- \n");
    printf("Estado: %s \n", carta.Estado);
    printf("Codigo: %s \n", carta.Codigo);
    printf("Cidade: %s \n", carta.NomeCidade);
    printf("Populacao: %d \n", carta.Populacao);
    printf("Area: %.3f \n", carta.Area);
    printf("PIB: %.3f \n", carta.PIB);
    printf("Pontos turisticos: %d \n", carta.PontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.DensidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta.PIBPerCapita);
    printf("\n");
}

void ExibirCartaVencedora(SuperTrunfo vencedor, SuperTrunfo perdedor, const char *atributoNome, float valorAtributo1, float valorAtributo2, int isEmpate){

    PularLinha();
    puts("       *** RESULTADO ***");
    LinhaSeparadora();

    if(isEmpate){
        printf("    (%s) X (%s) \n", vencedor.NomeCidade, perdedor.NomeCidade);
        PularLinha();
        puts("            ATRIBUTO ");
        LinhaSeparadora();
        printf("%s: %.2f X %.2f \n", atributoNome, valorAtributo1, valorAtributo2);
        PularLinha();
        LinhaSeparadora();
        puts("       *** EMPATE ***");
        LinhaSeparadora();
    }
    else {
        PularLinha();
        printf("    (%s) X (%s) \n", vencedor.NomeCidade, perdedor.NomeCidade);
        PularLinha();
        puts("           ATRIBUTO ");
        LinhaSeparadora();
        printf("%s: %.2f X %.2f \n", atributoNome, valorAtributo1, valorAtributo2);
        LinhaSeparadora();
        printf("VENCEDOR: carta - %d %s\n", vencedor.Id, vencedor.NomeCidade);
        LinhaSeparadora();
    }
}

void ComparaCartas(float c1, float c2, const char *AtributoNome){

    if(c1 == c2){
        ExibirCartaVencedora(carta1, carta2, AtributoNome, c1, c2, 1);
        return;
    }

    // --- strcmp -> Retorna 0 se as strings forem identicas ---
    if(strcmp(AtributoNome, "Densidade") == 0){
        if (c1 < c2)
        {
            ExibirCartaVencedora(carta1, carta2, AtributoNome, c1, c2, 0);
        }
        else {
            ExibirCartaVencedora(carta2, carta1, AtributoNome, c2, c1, 0);
        }
        return;
    }

    if (c1 > c2)
    {
        ExibirCartaVencedora(carta1, carta2, AtributoNome, c1, c2, 0);
    }
    else {
        ExibirCartaVencedora(carta2, carta1, AtributoNome, c2, c1, 0);
    }
}