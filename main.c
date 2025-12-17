#include <stdio.h>
#include <stdlib.h>
/**
 * @param int valores, tamanho
 * @param int selectionSort(), bubbleSort()
 */
int selectionSort(int valores[], int tamanho);
int bubbleSort(int valores[], int tamanho);
/**
 *  ==== FUNCAO MAIN ====
 */
int main()
{
    /**
     * @param int *array=NULL
     * @def array is a pointer to store every argument from user.
     */
    int *array = NULL;
    int valor, tamanho = 0;
    char prox_char;

    printf("Digite os valores separados por SPACE e, assim que feito, pressione ENTER.");
    do
    {
        if (scanf("%d", &valor) != 1)
        {
            break;
        }
        tamanho++;

        int *temp = realloc(array, tamanho * sizeof(int));

        if (temp == NULL)
        {
            printf("Erro na Alocacao de Memoria");
            free(array);
            return 1;
        }

        array = temp;
        array[tamanho - 1] = valor;
        prox_char = getchar();

    } while (prox_char != '\n' && prox_char != EOF);

    printf("\n--- Usando Selection Sort ---\n");
    selectionSort(array, tamanho);
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("\n--- Usando Bubble Sort ---\n");
    bubbleSort(array, tamanho);
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}

int selectionSort(int valores[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (valores[min] > valores[j])
            {
                min = j;
            }
        }
        int temp = valores[i];
        valores[i] = valores[min];
        valores[min] = temp;
    }
}

int bubbleSort(int valores[], int tamanho)
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
