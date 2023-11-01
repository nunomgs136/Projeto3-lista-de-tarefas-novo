//
// Created by unifnsilva on 21/09/2023.
//
#include "bibli.h"
#include <stdio.h>
#include <string.h>
int criarTarefa(ListadeTarefas *lt){


    //inputs do struct
    printf("Digite a categoria da tarefa: ");
    scanf("%s",lt->tarefas[lt->qtd].categoria);
    printf("Digite o numero de prioridade de tarefa(0-10): ");
    scanf("%d", &lt->tarefas[lt->qtd].prioridade);
    //se a prioridade for fora da margem
    if(lt->tarefas[lt->qtd].prioridade < 0 || lt->tarefas[lt->qtd].prioridade > 10){
        printf("Numero invalido! Tente outro numero(0-10): ");
        scanf("%d",&lt->tarefas[lt->qtd].prioridade);
    }
    printf("Escreva a descricao da tarefa: ");
    scanf("%s",lt -> tarefas[lt->qtd].descricao);
    printf("Digite o estado da tarefa(C-completo, EA - em andamento, NI- não iniciado): ");
    scanf("%s", lt->tarefas[lt->qtd].estado);
    //mudança da quantidade
    lt->qtd +=1;

    return 0;}
int deletarTarefa(ListadeTarefas *lt){
    // input da posicao da tarefa
    int pos;
    printf("Digite a posicao da tarefa: ");
    scanf("%d",&pos);
    //procurar o numero da tarefa
    for(int i = 0; i < lt->qtd; i++){
        if(pos-1 == i){
            for(int j =i; j < lt->qtd;j++ ) {
                //transfere as informações da struct seguinte para a padrão
                lt->tarefas[j] = lt->tarefas[j + 1];
                //Diminui a quantidade para o comando listaTarefas não ler o q foi deletado
                lt->qtd--;

            }

        }

    }

    return 0;
    }


int listaTarefas(ListadeTarefas lt){
    for(int i = 0; i < lt.qtd;i++){

        printf("Tarefa %d\n",i+1);
        printf("Categoria: %s \n",lt.tarefas[i].categoria);
        printf("Prioridade: %d \n",lt.tarefas[i].prioridade);
        printf("Descricao: %s \n",lt.tarefas[i].descricao);
        printf("Estado: %s \n", lt.tarefas[i].estado);
        printf("\n");
    }

    return 0;}

void printMenu(){
    printf("Menu: \n");
    printf("0: Sair\n");
    printf("1. Criar Tarefa\n");
    printf("2. Deletar Tarefa(confira o numero na lista(opcao 3))\n");
    printf("3. Listar Tarefas\n");
    printf("4. Editar Tarefas\n");
    printf("5. Filtrar tarefas por prioridade\n");
    printf("6. Filtrar tarefas por estado\n");
    printf("7. Filtrar tarefas por categoria\n");
    printf("8. Filtrar tarefas por categoria e prioridade\n");

}
int salvarLista(ListadeTarefas lt, char nome[]){
    FILE *f = fopen(nome, "wb");

    fwrite(&lt, sizeof(ListadeTarefas),1,f);
    fclose(f);
    return 0;}
int carregarLista(ListadeTarefas *lt,char nome[]){
    FILE *f = fopen(nome, "rb");
    // checagem para ver se o arquivo tem erro ou nao
    if(f == NULL){
        printf("Erro ou arquivo inexistente\n");
        return 1;
    }

    fread(lt,sizeof(ListadeTarefas),1,f);
    fclose(f);
    return 0;}


void alteracao_tarefa(ListadeTarefas *lt,int pos){
    
    char escolha;
    int mudança_prioridade;
    char mudança_outros[100];
    char resposta[7];
    for(int i = 0; i < lt->qtd; i++){
      if(i == pos-1){
        printf("Qual informação gostaria de alterar? ");
        scanf("%s", &escolha);
        if(strcmp(&escolha,"categoria") == 0 || strcmp(&escolha, "Categoria") == 0){
        printf("Digite a nova categoria: ");
        scanf("%s", mudança_outros);
        strcpy( lt->tarefas[i].categoria,mudança_outros);
      }
        else if(strcmp(&escolha, "descricao")== 0 || strcmp(&escolha, "Descricao") == 0){
          printf("Digite a nova descricão: ");
          scanf("%s", mudança_outros);
          strcpy( lt->tarefas[i].descricao,mudança_outros);
        }
        else if(strcmp(&escolha, "prioridade") == 0 || strcmp(&escolha, "Prioridade") == 0){
          printf("Digite o novo número de prioridade(0-10): ");
          scanf("%d", &mudança_prioridade);
          lt->tarefas[i].prioridade = mudança_prioridade;

        }
        else  if(strcmp(&escolha, "estado") == 0 || strcmp(&escolha, "Estado") == 0){
          printf("Digite o novo estado(C, EP ou NI): ");
          scanf("%s", mudança_outros);
          strcpy( lt->tarefas[i].estado,mudança_outros);
        }
        printf("Gostaria de alterar outra informação? Y/N/Trocar: ");
        scanf("%s", resposta);
        if(strcmp(resposta,"Y") == 0 || strcmp(resposta,"y") == 0){
          alteracao_tarefa(lt,pos);
        }
        else if(strcmp(resposta, "N")== 0 || strcmp(resposta, "n") == 0){
          
        }
        else if(strcmp(resposta, "Trocar") == 0 || strcmp(resposta,"trocar") == 0){
          alterarTarefa(lt);
        }
    }
}
}
int alterarTarefa(ListadeTarefas *lt){
  int pos;
  
  printf("Digite qual tarefa gostaria de mudar(Consulte a lista de tarefas): ");
  scanf("%d",&pos);
  alteracao_tarefa(lt,pos);

return 0;
}
int filtrar_prioridade(ListadeTarefas *lt){
  int prioridade;
  printf("Digite a prioridade que deseja filtrar: ");
  scanf("%d", &prioridade);
  for(int i = 0; i < lt->qtd; i++){
    if(lt->tarefas[i].prioridade == prioridade){
      printf("Tarefa %d: \n", i+1);
      printf("Categoria: %s \n", lt->tarefas[i].categoria);
      printf("Descricao: %s \n",lt->tarefas[i].descricao);
      printf("Estado: %s \n", lt->tarefas[i].estado);
  }
}
  return 0;
}
int filtrar_estado(ListadeTarefas *lt){
  char estado[3];
  printf("Digite o estado que deseja filtrar: ");
  scanf("%s", estado);
  for(int i = 0; i < lt->qtd; i++){
    if(strcmp(lt->tarefas[i].estado, estado) == 0){
      printf("Tarefa %d: \n", i+1);
      printf("Categoria: %s \n", lt->tarefas[i].categoria);
      printf("Descricao: %s \n",lt->tarefas[i].descricao);
      printf("Prioridade: %d \n", lt->tarefas[i].prioridade);
    }
  }
  return 0;
}
int filtrar_categoria(ListadeTarefas *lt){
  char categoria[100];
  printf("Digite a categoria que gostaria de filtrar: ");
  scanf("%s", categoria);
  for(int i = 0; i < lt->qtd; i++){
    if(strcmp(lt->tarefas[i].categoria, categoria) == 0){
      printf("Tarefa %d: \n", i+1);
      printf("Descricao: %s \n",lt->tarefas[i].descricao);
      printf("Prioridade: %d \n", lt->tarefas[i].prioridade);
      printf("Estado: %s\n", lt->tarefas[i].estado);
      printf(" \n");
    }
  }
  return 0;
}
int filtrar_categoria_prioridade(ListadeTarefas *lt){
  char categoria[100];
  int prioridade;
  printf("Digite a categoria que deseja filtrar: ");
  scanf("%s", categoria);
  printf("Digite a prioridade que deseja filtrar(0-10): ");
  scanf("%d", &prioridade);
  for(int i = 0; i < lt->qtd; i++){
    if(strcmp(lt->tarefas[i].categoria, categoria) == 0 && lt->tarefas[i].prioridade == prioridade){
      printf("Tarefa %d: \n", i+1);
      printf("Descricao: %s \n",lt->tarefas[i].descricao);
      printf("Estado: %s\n", lt->tarefas[i].estado);
    }
  }
}
