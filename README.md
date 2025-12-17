# Dynamic Sort Comparison (C)

Este repositório contém uma implementação robusta em C para captura dinâmica de dados e comparação de algoritmos de ordenação. O programa gerencia a memória dinamicamente, permitindo que o usuário insira uma quantidade arbitrária de números sem definir um tamanho fixo inicialmente.
## Lógica de Implementação
1. Entrada Dinâmica "Lazy"

### Diferente da abordagem comum de perguntar "Quantos números você deseja digitar?", este programa utiliza:

    realloc: Redimensiona o bloco de memória a cada nova entrada.

    Detecção de Buffer: Monitora o caractere \n (LF) para encerrar a captura assim que a tecla Enter é pressionada.

2. Algoritmos de Ordenação

O projeto implementa dois algoritmos clássicos para fins educacionais:

    Selection Sort: Seleciona repetidamente o menor elemento da parte não ordenada e o coloca no início.

    Bubble Sort: Percorre o array várias vezes, trocando elementos adjacentes se estiverem na ordem errada.

### Algoritmo	Melhor Caso	Médio	Pior Caso
Selection	O(n2)	O(n2)	O(n2)
Bubble	O(n)	O(n2)	O(n2)
