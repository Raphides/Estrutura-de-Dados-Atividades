# Listas Encadeadas e suas operações

Vetores usuais em C normalmente agrupam elementos em sequência direta na memória. Esta estratégia nem sempre é a melhor, devido a complexidade relacionada a certas operações simples. Por exemplo, adicionar um elemento no meio de um vetor costuma custar O(n), mesmo sendo uma operação trivial. Pensando nisso, foram desenvolvidos outros métodos de listamento, como o de alocação de memória e o encadeamento de elementos.

As listas encadeadas são uma lista de nós, estruturas (*structs*) estas que possuem um valor associado e o endereço para o próximo nó. Cada nó pode estar em qualquer parte da memória e a única forma de localizar seus elementos é através dos endereços dentro dos nós. Esse tipo de lista gera as seguintes consequências:

```c

```

## Derivados
Muitas outras estruturas de dados são derivadas ou podem ter uma implementação alternativa através da lista encadeada simples. Entre eles estão

- Listas duplamente encadeadas: em que cada nó possui dois endereços anexados, um do próximo e outro do nó anterior.
- Listas Circulares: o nó-cauda da lista possui um endereço para o nó-cabeça.
- Pilhas e filas encadeadas: complexidades diferentes devido a implementação encadeada.
