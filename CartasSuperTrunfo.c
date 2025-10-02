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
    float Area, PIB, DensidadePopulacional, PIBPerCapita;
    char NomeCidade[50], Codigo[3];
    int Populacao, PontosTuristicos;
} SuperTrunfo;

/* Funcoes de calculos
 *****************************************************************/
float CalculaDensidade(SuperTrunfo c){
    if(c.Populacao == 0 || c.Area == 0) return 0;

    return c.Populacao / c.Area;
}

float CalculaPercapita(SuperTrunfo c){
    if(c.PIB == 0 || c.Populacao == 0) return 0;

    return c.PIB / c.Populacao;
}
/**************************************************************/

// Funcao para preenchimento dos dados
void PreencherCarta(SuperTrunfo *carta, int id){
    carta->Id = id;

    printf("Entre com os dados da carta %d\n", id);
    printf("\n");

    printf("Estado: ");
    scanf(" %c", &carta->Estado);                           // Acrescentar um espaco ignora o \n no buffer

    printf("Codigo (3 caracteres): ");
    scanf(" %3s", carta->Codigo);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta->NomeCidade);                  // Permite espacos no nome, para preencher strings compostas

    printf("Populacao: ");
    scanf("%d", &carta->Populacao);

    printf("Area: ");
    scanf("%f", &carta->Area);

    printf("PIB: ");
    scanf("%f", &carta->PIB);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->PontosTuristicos);
    printf("\n\n");
}

// Funcao para exibicao dos dados
void ExibirCartas(SuperTrunfo carta){
    printf("\n --------------------------------------------- \n");

    printf("Carta - %d \n", carta.Id);
    printf("Estado: %c \n", carta.Estado);
    printf("Codigo: %s \n", carta.Codigo);
    printf("Cidade: %s \n", carta.NomeCidade);
    printf("Populacao: %d \n", carta.Populacao);
    printf("Area: %.6f \n", carta.Area);
    printf("PIB: %.6f \n", carta.PIB);
    printf("Pontos turisticos: %d \n", carta.PontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", CalculaDensidade(carta));
    printf("PIB per Capita: R$ %.2f\n", CalculaPercapita(carta));
    printf("\n");
}

int main() {
  // Criado duas instancias da estrutura SuperTrunfo para armazenar os dados das cartas.
  SuperTrunfo carta1, carta2;

  printf("\n--- BEM VINDO AO SUPER TRUNFO --- \n");

  // Área para entrada de dados
  PreencherCarta(&carta1, 1);
  PreencherCarta(&carta2, 2);
    
  // Área para exibição dos dados da cidade
  ExibirCartas(carta1);
  ExibirCartas(carta2);
   
  return 0;
}