# Projeto3-lista-de-tarefas-novo

Este código foi feito como a continuação de um projeto feito anteriormente no semestre em que precisava ser feita uma lista de tarefas. 
Informações para contextualizar: 

* Os dados das tarefas são armazenados através de um struct, na qual está contido uma varíavel para representar o número de tarefas armazenadas.
* Cada tarefa contém: um número de 0 até 10 para representar a prioridade(quanto maior, mais importante), uma descrição explicando a tarefa, a categoria para organização e o estado da tarefa(não iniciado, em andamento ou completo). Todos estes dados são inseridos pelo usuário durante a criação de uma nova tarefa.

As funções que estavam contidas na primeira parte do projeto são: 

OBS: Entre parênteses estão os nomes das funções usadas para realizar cada ação
  1. Criar Tarefa(criarTarefa) - Criação de tarefas e adição dentro da lista de tarefas
  2. Deletar Tarefa(deletarTarefa) - retira a tarefa da lista e transfere as informações da célula seguinte e diminui a váriavel de quantidade de células para não causar células vazias
  3. Listar Tarefas(listaTarefa) - Lista todas as tarefas armazenadas na lista
  
  Além destas, tiveram as seguintes funções que não são interativas:
  * salvarLista - Obtém as informações de todas as tarefas e são armazenadas em um arquivo binário
  * carregarLista - É feita a leitura das informações do arquivo binário e são transferidos de volta para o código principal
  * printMenu - É feita para imprimir o menu, ajudando a informar o usuário sobre cada função

 As funções que foram adicionadas nesta etapa do projeto são:
 
  4. Alterar Tarefa(alterarTarefa) - Possibilita a edição do conteúdo de alguma tarefa, é feito um loop caso o usuário queira alterar múltiplas informações
  5. Filtrar tarefa por prioridade(filtrar_prioridade) - Imprime todas as tarefas que a prioridade tem o mesmo número representando a prioridade ao que foi inserido pelo usuário
  6. Filtrar tarefa por estado(filtrar_estado) - Idem ao anterior, porém desta vez é comparado o estado da tarefa
  7. Filtrar tarefa por categoria(filtrar_categoria) - Idem, com a comparação sendo a categoria
  8. Filtrar tarefa por prioridade e categoria(filtrar_categoria_prioridade) - Idem aos anteriores, porém, neste caso, são comparados a prioridade e a categoria da tarefa ao mesmo tempo.
  9. Exportar tarefas por prioridade(exportar_prioridade) - São filtradas a tarefas a partir da prioridade fornecida pelo usuário e são transferidas para um arquivo txt
  10. Exportar tarefas por categoria(exportar_categoria) - Idem ao anterior, porém o filtro é feito a partir da categoria da tarefa. Além disso, o arquivo é organizado pela prioridade, sendo a maior listada primeira até a menor.
  11. Exportar tarefas por categoria e prioridade(exportar_categoria_prioridade) - São transferidos para o arquivo a partir dos filtros de categoria e prioridade
  
