#include <stdio.h>
#include <stdlib.h>
#include "../include/Util.h"
#include "../include/Menus.h"
#include "../include/Cartas.h"
#include "../include/Global.h"

// --- Funcao local para exibicao dos atributos selecionados pelo usuario ---
static void ExibirAtributos(int *Atributos, int tamanho){
    puts("");
    puts("   Atributos selecionados");
    puts("-----------------------------");
    for (int i = 0; i <= tamanho; i++)
    {
        printf("Atributo - %d \n", Atributos[i]);
    }
    puts("-----------------------------");
    puts("");
}

// --- Menu principal ---
void Menu(){
    int escolha;
    int valido = 0;

    do
    {
        puts("*** BEM VINDO AO SUPER TRUNFO ***");
        puts("");
        puts("1 - Iniciar jogo");
        puts("2 - Regras");
        puts("3 - Sair");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            LimparTela();
            IniciaJogo();
            break;
        
        case 2:
            LimparTela();
            Regras();
            break;

        case 3:
            exit;
            break;

        default:
            puts("Opcao invalida !");
            system("pause");
            break;
        }

        valido = 1;

    } while (valido != 1);
}

void SubMenu(){
    int escolha;

    puts("-------------------------------");
    puts("1 - Jogar novamente");
    puts("2 - Menu principal");
    printf("Escolha: ");
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

    default:
        puts("Opcao Invalida !");
        SubMenu();
        break;
    }
}

void MenuEscolhaAtributos(){
    int Escolhas[5], increment = -1;

    // retorna a quantidade de elementos do array, sem esse calculo ele retorna o tamanho do array em bytes.
    int max = sizeof(Escolhas)/ sizeof(Escolhas[0]);
    int Escolha = 0, ret = 0, SimNao;

    // --- Variavel de controle de escolha do SWITCH, enquanto a escolha nao for valida, o menu sera exibido dentro do loop ---
    int Valido = 0;

    do
    {
        // LimparTela();
        
        /**
         * Enquanto o usuario quizer selecionar atributos o loop continuara, ate que atinja o maximo de atributos ou
         * ele escolha sair.
         */
        while (SimNao != 2)
        {
            puts("-------------------------------");
            puts("Qual atributo deseja comparar ?");
            puts("1 - Populacao");
            puts("2 - Area");
            puts("3 - PIB");
            puts("4 - Numeros de pontos turisticos");
            puts("5 - Densidade");
            puts("-------------------------------");

            // --- Valida a escolha ---
            do
            {
                puts("");
                printf("Escolha: ");
                ret = scanf("%d", &Escolha);

                while (getchar() != '\n');
                if(ret != 1 || Escolha < 1 || Escolha > 5)
                    puts("Entrada invalida, tente novamente !");

                int repetido = 0;
                for (int i = 0; i <= increment; i++)
                {
                    if(Escolhas[i] == Escolha){
                        LimparTela();

                        repetido = 1;

                        puts("");
                        puts("########################## ATENCAO ##################################");
                        puts("Voce NAO pode selecionar o mesmo atributo duas vezes, escolha outro !");
                        puts("#####################################################################");
                        puts("");

                        ExibirAtributos(Escolhas, increment);
                    }
                }

                if (repetido)
                    ret = 0;
                
            } while (ret != 1 || Escolha < 1 || Escolha > 5);
            

            if(increment + 1 >= max){
                puts("Todos os atributos foram selecionados !");
                break;
            }

            Escolhas[++increment] = Escolha;

            puts("Deseja escolher outro atributo ?");
            puts("1 - sim");
            puts("2 - Comparar selecionados");
            scanf("%d", &SimNao);
            getchar();

            if(SimNao == 2)
                goto compare;
        }

        // --- Cria um rotulo que faz o programa pular para essa etapa. (NAO RECOMENDADO PARA USO EM PRODUCAO.)--- 
        compare:

        ExibirAtributos(Escolhas, increment);

        for (int i = 0; i <= increment; i++)
        {
            switch (Escolhas[i])
            {
                case 1:
                    ComparaCartas(carta1.Populacao, carta2.Populacao, "Populacao"); break;
                case 2:
                    ComparaCartas(carta1.Area, carta2.Area, "Area"); break;
                case 3:
                    ComparaCartas(carta1.PIB, carta2.PIB, "PIB"); break;
                case 4:
                    ComparaCartas(carta1.PontosTuristicos, carta2.PontosTuristicos, "Pontos turisticos"); break;
                case 5:
                    ComparaCartas(carta1.DensidadePopulacional, carta2.DensidadePopulacional, "Densidade");break;
                default:
                    puts("Ocpao Invalida !");
                    system("pause");
                    break;
            }
        }

        Valido = 1;

    } while (!Valido);
}