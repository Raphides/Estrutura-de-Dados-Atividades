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

Algorítmos de ordenação clássico que refencia "bolhas" devido ao seu comportamento de fazer o maior elemento submergir. Seu funcionamento é liderado por uma iteração através de todos os elementos do vetor. Cada elemento será comparado com o elemento posterior, trocando os dois de lugares caso o posterior seja menor. Esse laço atraveś de todo o vetor será repetido de novo e de novo até que nenhuma operação de troca seja feita em alguma das repetições, garantindo assim que o vetor foi ordenado com sucesso.

### Característticas
- Casos:
    - Melhor caso: já ordenado.
        - Complexidade: O(n), porque percorre-se o vetor 1 vez só para checar se o vetor foi ordenado. Como nenhuma troca terá sido feita, o algorítmo se encerrará.
    - Pior/Médio Caso: aleatório/ ordem invertida.
        - Complexidade: O(n²):
- Pode ser feita do início-fim (padrão) ou fim-início.
- Normalmente mantém a posição de elementos duplicados, tudo depende da condição implementada antes de chamar a função de *troca*. Implemente-a atentando-se aos operadores lógicos.
- Vantagens: 
    - Checha vetores já ordenados, previnindo algumas operações redundantes.
- Desvantagens:
    - Um vetor semi-ordenado com o primeiro elemento na última posição da iteração demorará O(n²) para ser ordenado com o Bubble.
    - Ainda possui operações redundantes. 

## Bubble Sort+

Melhoria do método Bubble Sort. Ele não muda a sua complexidade (taxa de crescimento) clássico de O(n²), mas elimina muitas operações redundantes.


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
