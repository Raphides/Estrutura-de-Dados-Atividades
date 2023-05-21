# Alocação de Memória

Usado quando a memória que precisaremos usar só será conhecida em tempo de execução

## Níveis de Memória

|Local|Nível de memória|Descrição|
|-|-|-|
|Seg. Heap|Alta|Diponível para alocação dinâmica|
|Seg. Pilha|-|Pilha de variáveis locais|
|Seg. de Dados|-|Pilha de dados (globais)|
|Seg. de Código|Baixo|Pilha do código compilado|

Vetores fixos (`type name[quantity]`) serão armazenados no Segmento de Dados e consequentemente serão apagados no fim da execução do programa.

Já os vetores dinamicamente alocados serão armazenados no Seg. Heap

## Funções de alocação dinâmica
### C (dentro da biblioteca *stdlib*)

- malloc e calloc
Aloca a memória escolhida no Seg. Heap e 