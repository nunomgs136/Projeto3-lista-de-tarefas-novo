
// Henrique Hodel Babler - RA: 24.123.079-6
// Nuno Martins Guilhermino da Silva - RA: 24.123.035-8


#include <stdio.h>
#include "bibli.h"
#include <string.h>

int main() {

    int cod;
    char arquivo[] = "tarefas";
    ListadeTarefas lt;
//transferir lista do arquivo binario
    cod = carregarLista(&lt,arquivo);

    if(cod == 1)
        lt.qtd = 0;

    int opcao;
    do{
        printMenu();
        scanf("%d",&opcao);

        if(opcao == 0){
        printf("Exportando tarefas");
        }
        else if(opcao == 1){
            criarTarefa(&lt);
        }else if(opcao == 2){
            deletarTarefa(&lt);
        }else if(opcao == 3){
            listaTarefas(lt);
          
        
        }else if(opcao == 4){
          alterarTarefa(&lt);
        }else if(opcao == 5){
          filtrar_prioridade(&lt);
        }else if(opcao == 6){
          filtrar_estado(&lt);
        }else if(opcao == 7){
          filtrar_categoria(&lt);
        }else if(opcao == 8){
          filtrar_categoria_prioridade(&lt);
        }else if(opcao == 9){
          exportar_prioridade(&lt);
        }else if(opcao == 10){
          exportar_categoria(&lt);
        }
          
        
        
        
        
        
        
        
        else{
            printf("Opcao nao existe\n");
        }
    }while(opcao != 0);
    cod = salvarLista(lt,arquivo);
    if(cod != 0)
        printf("Erro ao salvar as tarefas");

    return 0;
}

