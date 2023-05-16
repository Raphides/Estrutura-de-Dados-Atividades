# Determinação do Big O

O Big O de um algorítmo é determinado pela soma do complexidade dos seus termos internos. Logo é preciso ter acesso ao código fonte do algorítmo para determinar sua complexidade.

## Termos de Complexidade Constante

Operações que não são influenciadas por uma variável mutável. Exemplo: Sem saber o tamanho do vetor, ele torna-se mutável.

### O(1)

Cada operação de declaração, aritmética e assinalável é representado por um O(1).

```c
// O(c)
int exemplo(int a)
{
    int b; //O(1)
    b = 0; //O(1)
    a += b; //O(1) + O(1) = O(2)
    return a; //O(1)
    // c = 1 + 1 + 2 + 1 = 5
    // Total: O(5)
}
```

### Laços Constantes

Laços com um número de repetições constantes. Sua complexidade será a soma do O() dos termos vezes o número de repetições constantes.

```c
// O(c)
int vezes10(int a)
{
    int result = 0; // O(2)
    for (int i = 0; i < 10;i++) // O(10 * O(termos))
    {
        result += a; // O(2)
    } // O(10 * 2) = O(20)
    return a; //O(1)
    // c = 2 + 20 + 1 = 23
    // Total: O(23)
}
```

### Condicionais

Tendo dois ou mais caminhos distintos no código, devemos calcular o Big O de todos os caminhos e traduzí-los em melhor/pior/médio caso.

## Termos de Complexidade Mutável

Diferente do Big O constante, quando houver algo dependendo de uma variável mutável (representada por *n*), ignoraremos todos os outros termos de ordem menor. Por exemplo, ao ter um termo O(n²), outro O(n) e outro O(15), a complexidade do algorítmo será O(n²). Normalmente também excluímos o coeficiente do n de maior ordem, visto que raramente importará para o usuário.

### Laços de tamanho mutável

```c
// O(c)
int pot2(int a) //"a" deve ser positivo
{
    int result = 0; // O(2)
    for (int i = 0; i < a;i++) // O(n * O(termos))
    {
        result += a; // O(2)
    } // O(n * 2) = O(2n)
    return a; //O(1)
    // c = 2n + 2 + 1 = 2n + 3
    // Total: O(n)
}
```

### Laços consecutivos

```c
// O(c)
int soma_de_pot2(int a, int b) //"a" deve ser positivo
{
    int resultadoa = 0; // O(2)
    int resultadob = 0; // O(2)
    for (int i = 0; i < a;i++) // O(n * O(termos))
    {
        resultadoa += a; // O(2)
    } // O(n * 2) = O(2n)

    for (int j = 0; j < b;j++) // O(n * O(termos))
    {
        resultadob += b; // O(2)
    } // O(n * 2) = O(2n)
    return resultadoa + resultadob; // O(2)
    // c = 2n + 2n + 2 + 2 + 2 = 4n + 6
    // Total: O(n)
}
```

### Laços internos
```c
// O(c)
int exemplo(int n) //"a" deve ser positivo
{
    for (int i = 0; i < a;i++) // O(n * O(termos internos))
    {
        // termos internos
        ...

        for (int j = 0; j < b;j++) // O(n * O(termos mais internos))
        {
            // termos mais internos
            ...
        } // O(n * 2) = O(2n)
        
    } // O(n * termos internos) = O(n * termos internos constantes * O(n * termos mais internos)) = O(n²)

    
    return resultadoa + resultadob; // O(2)
    // c = 2n + 2n + 2 + 2 + 2 = 4n + 6
    // Total: O(n)
}
```

