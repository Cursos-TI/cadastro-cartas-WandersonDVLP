## Autor
- [Wanderson]

## ESTRUTURA DO PROJETO

# --- Pastas ---
    Bin:
        Contem o executavel compilado, pronto para rodar pelo terminal.

    Includes:
        Contem os cabecalhos do sistema para implementacao.

    src:
        Contem os arquivos de implementacao e logica do sistema.
        A funcao principal com o inicio do sistema (Main), encontra-se na no arquivo SuperTrunfo.c

## FAQ

# --- Compilacao ---
    Navegue ate o diretorio 'src' e execute o seguinte comando:
    
    ->  gcc *.c -o ../bin/SuperTrunfo.exe

    esse comando ira compilar todos os arquivos da pasta src, e criar um unico arquivo executavel na pasta bin, pronto para rodar.

# --- Execucao ---
    Para executar o programa no terminal va ate a pasta (bin) e execute o SuperTrunfo.exe.

# --- Excutar em modo de teste ---
    Na pasta src/SuperTrunfo.c descomente as instancias no region TESTE, e comente a instancia global da carta1 e carta2, isso fara com que o sistema
    identifique apenas as intancias do teste como globais, evitando conflitos.

    No arquivo src/Global realize o mesmo procedimento, dentro da funcao 'IniciaJogo()', comente a chamada da funcao 'PreencherCarta(parametros)', isso
    fara com que o sistema utilize as cartas ja preenchidas das intancias de teste.

    Caso queira visualizar as cartas de teste no momento da execucao, basta apenas descomentar a funcao de exibicao no region de teste do arquivo 'Global'.