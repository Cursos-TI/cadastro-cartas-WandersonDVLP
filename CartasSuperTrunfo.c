#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

/** Área para definição das variáveis para armazenar as propriedades das cidades.
 * Criado uma estrutura que pode ser instanciada, com isso evita-se repeticao de variaveis
 * que utilizam as mesmas informacoes.
 */
typedef struct {
    int Id;
    char Estado;
    float Area, PIB;
    char NomeCidade[50], Codigo[3];
    int Populacao, PontosTuristicos;
} SuperTrunfo;

int main() {
  // Criado duas instancias da estrutura SuperTrunfo para armazenar os dados das cartas.
    SuperTrunfo carta1, carta2;

  // Área para entrada de dados
  printf("\n--- BEM VINDO AO SUPER TRUNFO --- \n");

    /* Dados da primeira carta
    ----------------------------------------------------*/
    carta1.Id = 1;
    printf("Entre com os dados da primeira carta... \n");
    printf("\n");

    printf("Estado: ");
    scanf(" %c", &carta1.Estado);                           // Acrescentar um espaco ignora o \n no buffer

    printf("Codigo (3 caracteres): ");
    scanf(" %3s", carta1.Codigo);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta1.NomeCidade);                  // Permite espacos no nome

    printf("Populacao: ");
    scanf("%d", &carta1.Populacao);

    printf("Area: ");
    scanf("%f", &carta1.Area);

    printf("PIB: ");
    scanf("%f", &carta1.PIB);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.PontosTuristicos);
    printf("\n\n");

    /* Dados da segunda carta
    ----------------------------------------------------*/
    carta2.Id = 2;
    printf("Entre com os dados da segunda carta...\n");
    printf("\n");

    printf("Estado: ");
    scanf(" %c", &carta2.Estado);

    printf("Codigo: ");
    scanf(" %3s", carta2.Codigo);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta2.NomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta2.Populacao);

    printf("Area: ");
    scanf("%f", &carta2.Area);

    printf("PIB: ");
    scanf("%f", &carta2.PIB);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.PontosTuristicos);
    printf("\n");

  // Área para exibição dos dados da cidade
  
   // Carta - 1
    printf("\n --------------------------------------------- \n");

    printf("Carta - %d \n", carta1.Id);
    printf("Estado: %c \n", carta1.Estado);
    printf("Codigo: %s \n", carta1.Codigo);
    printf("Cidade: %s \n", carta1.NomeCidade);
    printf("Populacao: %d \n", carta1.Populacao);
    printf("Area: %.6f \n", carta1.Area);
    printf("PIB: %.6f \n", carta1.PIB);
    printf("Pontos turisticos: %d \n", carta1.PontosTuristicos);

    // Carta - 2
    printf("\n --------------------------------------------- \n");

    printf("Carta - %d \n", carta2.Id);
    printf("Estado: %c \n", carta2.Estado);
    printf("Codigo: %s \n", carta2.Codigo);
    printf("Cidade: %s \n", carta2.NomeCidade);
    printf("Populacao: %d \n", carta2.Populacao);
    printf("Area: %.6f \n", carta2.Area);
    printf("PIB: %.6f \n", carta2.PIB);
    printf("Pontos turisticos: %d \n", carta2.PontosTuristicos);
    printf("\n\n");


  return 0;
}