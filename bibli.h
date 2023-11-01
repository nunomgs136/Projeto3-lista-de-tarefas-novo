//
// Created by unifnsilva on 12/09/2023.
//
#include <stdio.h>
#ifndef UNTITLED2_BIBLIOTECA_H
#define UNTITLED2_BIBLIOTECA_H
typedef struct{
    int prioridade;
    char categoria[100];
    char descricao[300];
    char estado[12];

}Tarefa;
//limitar tarefas até 100
typedef struct{
    Tarefa tarefas[100];
    int qtd;
}ListadeTarefas;


int criarTarefa(ListadeTarefas *lt);
int deletarTarefa(ListadeTarefas *lt);
int listaTarefas(ListadeTarefas lt);

void printMenu();
int salvarLista(ListadeTarefas lt, char nome[]);
int carregarLista(ListadeTarefas *lt,char nome[]);
int alterarTarefa(ListadeTarefas *lt);
void alteracao_tarefa(ListadeTarefas *lt, int pos);
int filtrar_prioridade(ListadeTarefas *lt);
int filtrar_estado(ListadeTarefas *lt);
int filtrar_categoria(ListadeTarefas *lt);
int filtrar_categoria_prioridade(ListadeTarefas *lt);
#endif //UNTITLED2_BIBLIOTECA_H
