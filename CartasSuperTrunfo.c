#include <stdio.h>
#include <stdlib.h>

#pragma region Stucts
/** STRUCT
 * Cria uma estrutura que pode ser instanciada, com isso evita-se repeticao de propriedades
 * que utilizam as mesmas informacoes.
 */
typedef struct {
    int Id;
    char Estado;
    float Area, PIB, DensidadePopulacional, PIBPerCapita;
    char NomeCidade[50], Codigo[3];
    int Populacao, PontosTuristicos;
} SuperTrunfo;
#pragma endregion

// Cria duas instancias globais.
SuperTrunfo carta1, carta2;

void LimparTela(){
    system("cls");
}

#pragma region Declaracoes de Inicializacao
void Menu();
void SubMenu();
void IniciaJogo();
void MenuEscolhaAtributos();
void ComparaCartas(float c1, float c2, char AtributoNome[]);
#pragma endregion

#pragma region Funcoes calculos
float CalculaDensidade(SuperTrunfo c){
    if(c.Populacao == 0 || c.Area == 0) return 0;

    return c.Populacao / c.Area;
}

float CalculaPercapita(SuperTrunfo c){
    if(c.PIB == 0 || c.Populacao == 0) return 0;

    return c.PIB / c.Populacao;
}
#pragma endregion

#pragma region Funcoes de exibicao
// Essa funcao tambem exibe o empate caso ocorra
void ExibirCartaVencedora(SuperTrunfo c1, SuperTrunfo c2, char atributoNome[], float valorAtributo1, float valorAtributo2, int isEmpate){
    LimparTela();

    if(isEmpate){
        puts("");
        puts("      *** RESULTADO ***");
        puts("--------------------------------");
        printf("    (%s) X (%s) \n", c1.NomeCidade, c2.NomeCidade);
        puts("");
        puts("          ATRIBUTO ");
        puts("--------------------------------");
        printf("%s: %.2f X %s: %.2f \n", atributoNome, valorAtributo1, atributoNome, valorAtributo2);
        puts("");
        puts("--------------------------------");
        puts("       *** EMPATE ***");
        puts("--------------------------------");
    }
    else {
        puts("     *** RESULTADO ***");
        puts("--------------------------------");
        printf("    (%s) X (%s) \n", c1.NomeCidade, c2.NomeCidade);
        puts("");
        puts("         ATRIBUTO ");
        puts("--------------------------------");
        printf("%s: %.2f X %s: %.2f \n", atributoNome, valorAtributo1, atributoNome, valorAtributo2);
        puts("--------------------------------");
        printf("VENCEDOR: carta - %d %s\n", c1.Id, c1.NomeCidade);
        puts("--------------------------------");
    }

    SubMenu();
}

void ExibirCartas(SuperTrunfo carta){
    printf("            Carta - %d \n", carta.Id);
    printf("--------------------------------------------- \n");
    printf("Estado: %c \n", carta.Estado);
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

void Regras(){
    puts("");
    puts("      *** REGRAS ***");
    puts("--------------------------------");
    puts("Como jogar:");
    puts("Voce deve preencher os valores das cartas na ordem em que sao exibidos,");
    puts("preencha corretamente os dados para que possam ser comparados corretamente");
    puts("e nao haja problemas na comparacao dos dados para definir um vencedor ou,");
    puts("empate caso ocorra.");
    puts("--------------------------------");
    puts("Definicao do vencedor:");
    puts("O sistema ira lhe pedir para escolher 1 entre os atributos disponiveis,");
    puts("eles seram comparados automaticamente e os dados serao exibidos, mostrando");
    puts("o vencedor o perdedor, e o atributo que se destacou.");
    puts("--------------------------------");
    puts("Empate:");
    puts("Em caso de empate o mesmo ocorrera que na definicao do vencedor.");
    puts("--------------------------------");
    puts("Info:");
    puts("Os dados de densidade e percapita sao calculados automaticamente.");
    puts("");

    Menu();
}
#pragma endregion

#pragma region Menus

void SubMenu(){
    int escolha;

    puts("-------------------------------");
    puts("1 - Jogar novamente");
    puts("2 - Menu principal");
    puts("3 - Sair");
    scanf("%d", &escolha);
    puts("-------------------------------");

    switch (escolha)
    {
    case 1:
        LimparTela();
        IniciaJogo();
        break;

    case 2:
        Menu();
        break;

    case 3:
        exit;
        break;

    default:
        puts("Opcao Invalida !");
        SubMenu();
        break;
    }
}

void MenuEscolhaAtributos(){
    int escolha;

    LimparTela();
    ExibirCartas(carta1);
    ExibirCartas(carta2);

    puts("-------------------------------");
    puts("Qual atributo deseja comparar ?");
    puts("1 - Populacao");
    puts("2 - Area");
    puts("3 - PIB");
    puts("4 - Numeros de pontos turisticos");
    puts("5 - Densidade");
    printf("Escolha: ");
    scanf("%d", &escolha);
    puts("-------------------------------");

    switch (escolha)
    {
    case 1:
        ComparaCartas(carta1.Populacao, carta2.Populacao, "Populacao");
        break;

    case 2:
        ComparaCartas(carta1.Area, carta2.Area, "Area");
        break;

    case 3:
        ComparaCartas(carta1.PIB, carta2.PIB, "PIB");
        break;

    case 4:
        ComparaCartas(carta1.PontosTuristicos, carta2.PontosTuristicos, "Pontos turisticos");
        break;

    case 5:
        ComparaCartas(carta1.DensidadePopulacional, carta2.DensidadePopulacional, "Densidade");
        break;
    
    default:
        puts("Ocpao Invalida !");
        system("pause");
        MenuEscolhaAtributos();
        break;
    }
}

void Menu(){
    int escolha;

    puts("*** BEM VINDO AO SUPER TRUNFO ***");
    puts("");
    puts("1 - Inicia jogo");
    puts("2 - Regras");
    puts("3 - Sair");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        IniciaJogo();
        break;
    
    case 2:
        Regras();
        break;

    case 3:
        exit;
        break;

    default:
        puts("Opcao invalida !");
        system("pause");
        Menu();
        break;
    }
}
#pragma endregion

/** FUNCAO DE COMPARACAO
 * Recebe duas catas como parametro, e faz a comparacao das propriedades selecionadas pelo jogador
 */
void ComparaCartas(float c1, float c2, char AtributoNome[]){
    if(c1 == c2){
        ExibirCartaVencedora(carta1, carta2, AtributoNome, c1, c2, 1);
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

void PreencherCarta(SuperTrunfo *carta, int id){
    carta->Id = id;

    puts("");
    printf("           CARTA - %d\n", id);
    puts("---------------------------------");
    puts("Preencha os atributos da carta...");
    printf("\n");

    printf("Estado: ");
    scanf(" %c", &carta->Estado);                                                   // Acrescentar um espaco ignora o \n no buffer

    printf("Codigo (3 caracteres): ");
    scanf(" %3s", carta->Codigo);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta->NomeCidade);                                         // Permite espacos no nome, para preencher strings compostas

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

void IniciaJogo(){
    // Cadastro das cartas
    PreencherCarta(&carta1, 1);
    PreencherCarta(&carta2, 2);

    MenuEscolhaAtributos();
}

int main(){
    LimparTela();
    Menu();

    return 0;
}