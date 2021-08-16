#include <stdlib.h>
#include <stdio.h>

// restringe random numbers to a maximum of 1000
#define RAND_MAX 1000

// NOTE Inicializa um vetor the inteiros aleatorios e retorna esse vetor
int* get_rand(int size) {
	int* arr = malloc(size * sizeof(int));
	for (int i=0; i<size; i++) {
		arr[i] = rand() % RAND_MAX; // basically clamp the rand return values to RAND_MAX
	}
	return arr;
}

// NOTE Troca valores de duas variaveis na memoria
void swap(int* num1, int* num2) {
	int temp = *num1;
    *num1 = *num2;
	*num2 = temp;
}

// NOTE this prints an array in a certain range
void write_out(int arr[], int beg, int end) {
	for (int i=beg; i<=end; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// NOTE Take the "end" variable and put all smaller elements to the left of it, and all bigger elements to the right
int partition(int arr[], int beg, int end) {
	int pivot = arr[end];
	// NOTE l_beg stands for "local beggining". It is the INDEX beggining of our partition
	int l_beg = beg - 1;

    // actual swapping here
	for (int i = beg; i <= end-1; i++)
    {
        if (arr[i] <= pivot)
        {
            l_beg++;
            swap(&arr[l_beg], &arr[i]);
        }
    }

    // move the pivot
    swap(&arr[l_beg + 1], &arr[end]);
    return (l_beg + 1);
}

// NOTE main function of quick sort.
void quick_sort(int *arr, int beg, int end) {
	if (beg<end) {
		int div = partition(arr, beg, end);
		// NOTE chamada recursiva para quick_sort, divide o array em uma especia de arvore, criando dois branches novos a cada chamada
		quick_sort(arr, beg, div - 1);
		quick_sort(arr, div + 1, end);
	}
}

int main() { 
	int* qs_arr = get_rand(20);
    write_out(qs_arr, 0, 19);

    quick_sort(qs_arr, 0, 19);
    write_out(qs_arr, 0, 19);

    return 0;
}
