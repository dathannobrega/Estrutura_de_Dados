#Trabalho ED2
Terceiro trabalho de ED2.
## Problema:  

Faça um programa que leia um arquivo texto (.txt) e organize, em ordem alfabética, as palavras e a suas frequências no texto em estruturas de dados. Espaços em brancos e sinais de pontuação devem ser descartados, e as palavras devem ser mantidas todas em minúsculo.

O processamento das palavras do texto (e suas frequências) deverá realizar-se de três formas distintas: 

1. Pesquisa Binária (usando vetor)
2. Árvore Binária de Busca sem balanceamento.
3. Árvore AVL

O programa deve permitir que:

A - O usuário escolha um arquivo texto para que este seja carregado nas estruturas de dados, considerando cada um dos 3 casos citados. Após a carga dos dados nas estruturas, deve ser exibido o tempo para cada uma. A função de inserção deverá ser modificada para que a contagem da frequência seja atualizada para as palavras já processadas.

B - O usuário escolha uma palavra para visualizar a frequência da mesma, caso a palavra tenha sido processada. O resultado da busca deve ser exibido para as três situações programadas, assim como o tempo de processamento da consulta.

C - O usuário faça busca por frequência. Neste caso, deve ser construída uma árvore AVL considerando-se a organização dos dados por frequência das palavras para que a busca seja eficiente.