#include <stdio.h>
#include <stdlib.h>

// Protótipos com tipagem correta (void)
void selectionSort(int valores[], int tamanho);
void bubbleSort(int valores[], int tamanho);
void imprimirArray(int valores[], int tamanho);

int main()
{
    int *array = NULL;
    int valor, tamanho = 0;
    char prox_char;

    printf("Digite os valores (ex: 10 5 8 20) e pressione ENTER: ");

    do
    {
        // Tenta ler o número
        if (scanf("%d", &valor) != 1)
            break;

        tamanho++;
        int *temp = realloc(array, tamanho * sizeof(int));

        if (temp == NULL)
        {
            printf("Erro critico: Falha na alocacao de memoria.\n");
            free(array);
            return 1;
        }

        array = temp;
        array[tamanho - 1] = valor;

        // Captura o espaço ou o Enter
        prox_char = getchar();

    } while (prox_char != '\n' && prox_char != EOF);

    if (tamanho > 0)
    {
        printf("\n--- Array Original ---\n");
        imprimirArray(array, tamanho);

        // Escolha um para testar ou clone o array para testar ambos
        printf("\n--- Ordenando com Selection Sort ---\n");
        selectionSort(array, tamanho);
        imprimirArray(array, tamanho);
    }

    free(array);
    return 0;
}

void selectionSort(int valores[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (valores[j] < valores[min])
                min = j;
        }
        int temp = valores[i];
        valores[i] = valores[min];
        valores[min] = temp;
    }
}

void bubbleSort(int valores[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (valores[j] > valores[j + 1])
            {
                int temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = temp;
            }
        }
    }
}

void imprimirArray(int valores[], int tamanho)
{
    printf("Array: [ ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", valores[i]);
    printf("]\n");
}