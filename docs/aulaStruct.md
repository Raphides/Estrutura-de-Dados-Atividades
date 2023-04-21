# Tipos e structs

## Tipos vs Variáveis
Definir um tipo não ocupa espaço no programa, enquanto definir uma varíavel ocupa.

## Struct
Recurso que possibilita a abstração de dados em C. Ao **declarar uma struct, você está essencialmente declarando um novo tipo de dado**.

Tipos de dados
|Tipo|Tamanho (em bytes)|
|-|-|
|char|1| 
|int|4|
|float|8|
|ponteiro|8 (x32) ou 16 (x64)|

O tamanho de uma *struct* é definida pela soma dos bytes de todos os seus


Declaração:

```c
//substitua os valores em <>

struct <nome_struct>
{
    <tipo1> <nome1>;
    <tipo2> <nome2>[<numero>];
    <tipo3>* <nome3>;

} <variaveis>;
```

Exemplo:

```c
struct Vetor
{
    int tamanho;
    int lotacao;
    char *valores;
} vetor1, vetor2;
```

O campo variáveis é um atalho para se declarar variáveis de struct de forma mais rápida, logo após a declaração da struct.

Usar Structs dessa forma não é sempre muito adequado, porque pra declarar outra varíavel de struct, precisamos escrever `struct Vetor vetor3;`

Normalmente structs são usados na definição de novos tipos:

```c
typedef struct
{
    int tamanho;
    int lotacao;
    char msg[4];
} vetor;
```

Nesse caso, a struct não é nomeada, permitindo que usemos ela somente ao usar seu tipo declarado.


## Structs, parâmetros e ponteiros

Ao fazer operações usando tipos derivados de structs, temos um sério problema com espaço se não entendermos sobre structs e parâmetros. Ao passar um valor de qualquer tipo por argumentos numa função, esses argumentos serão COPIADOS como uma varíavel local da função e excluídas logo depois. Isso causa 2 problemas:

1. Se uma struct for muito grande, copiar ela custa muito ao sistema.
2. Toda mudança gerada na struct copiada não é refletida na struct original.

Nesses casos, vale mais a pena usar ponteiros. Um ponteiro sempre será um número hexadecimal ocupando 8 bytes na memória. Copiar um ponteiro de uma struct pode ser muito mais barato, principalmente quando a struct tem um custo maior que 8 bytes. Além disso, é possível acessar a alterar a struct original através de seu ponteiro.



## Anotações de Vetor e Alocação

Alocar memória num ponteiro é **necessário** quando se quer adicionar endereços de memória sequenciais, como um vetor. Sema alocação, o programa gera um erro.

Dica: um vetor, seja alocado ou fixo, deve ter cuidado no tamanho de elementos. Se um vetor aguenta x elementos, ele só pode ter x - 1 elementos no máximo, já que o último caractere deve ser deixado vazio, pois vai ser automaticamente prenchido com um símbolo de fim de vetor.

Por motivos assim, é recomendado fazer operações com string usando funções da biblioteca string.h