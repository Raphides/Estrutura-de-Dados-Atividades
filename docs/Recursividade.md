# Recursividade

É a prática de uma função chamar a si mesma, fazendo uma espécie de loop.

## Por que usar recursividade ao invés de laços (for/while)?
- Possibilita escrever códigos com laços mais complexos com menos código.
- Certos problemas com operações diferentes de parâmetros a cada loop costumam ser mais simples de serem feitas em recursão do que em laço.
- Respeita diretrizes de código clean. (uma função deve ter realmente só uma funcionalidade)
- Mais fácil de realizar testes e manutenção.

## Desvantagens:
- Diferente de um laço, uma recursão chama uma **função** várias vezes, logo **ocupa mais memória** do que chamar tudo numa mesma função (laços). Assim gera riscos de resultar em um Stack Overflow.

## Cuidados
Assim como os laços, a recursão pode gerar uma recursão infinita, portanto garanta que existe um ponto de parada.