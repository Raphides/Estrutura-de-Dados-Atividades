# Algorítmos de Ordenação

## Índice
- [Introdução](#)
- [Bubble Sort](#bubble-sort)
- [Bubble Sort+](#bubble-sort-1)
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)


## Introdução
Algorítmos clássicos e comuns de ordenação de lista de dados. Cada algorítmo tem sua respectiva complexidade de espaço e tempo.


### Características de ordenações
- Podem ser em ordem ascendente ou descendente.
- Facilitam operações com índices e busca.


### Como avaliar um algorítmos de ordenação?

- Complexidade espacial dos melhores, médios e piores casos.
- Complexidade temporal dos melhores, médios e piores casos.
- Se ele mantém a ordem original dos elementos repetidos.


## Bubble Sort

## Bubble Sort+

Melhoria do método Bubble Sort. Ele não muda a sua complexidade (taxa de crescimento), mas muda consideravelmente o seu tempo de execução.



## Selection Sort

A ordenação por seleção faz uma série de operações para cada elemento do vetor, começando do primeiro até o último. Para cada elemento, o algorítmo comparará o próprio elemento com os próximos, localizando o menor deles. Trocaremos a posição do menor elemento encontrado com o elemento da iteração principal, depois iremos para a próxima iteração.

### Características
- Melhor caso: já estar ordenado.
    - Complexidade: O(n²)
- Pior caso: Ordem invertida.
    - Complexidade: O(n²)
- Os diferentes casos não possuem uma mudança na taxa de crescimento da complexidade. Sempre haverá duas iterações completas, logo O(n²).
- Vantagens:
    - Fácil de prever.
    - Mais rápido do que outros algorítmos mais complexos em listas menores.
- Desvantagens:
    - Não percebe se o vetor já está ordenado.
    - Muito demorado para algorítmos maiores.

## Insertion Sort

## Merge Sort

O Merge Sort é um dos algorítmos mais rápidos de ordenação de vetores.

## Quick Sort

O Quick Sort é um dos algorítmos mais rápidos de ordenação de vetores.