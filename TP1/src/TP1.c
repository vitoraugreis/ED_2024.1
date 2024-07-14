#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_BUCKET 1000

int menu() {
    while(1){
        int opt;
        system("clear");
        printf("------------------------------\n");
        printf("1 - Testar algoritmo individual\n");
        printf("2 - Testar todos os algoritmos\n");
        printf("0 - Sair\n");
        printf("------------------------------\n");
        printf("Insira a opcao: ");
        scanf("%i", &opt);
        if (opt >= 0 && opt <=2 ) { return opt; }
    }
}

int algMenu() {
    while(1){
        int opt;
        system("clear");
        printf("------------------------------\n");
        printf("1 - BubbleSort\n");
        printf("2 - SelectionSort\n");
        printf("3 - InsertionSort\n");
        printf("4 - MergeSort\n");
        printf("5 - QuickSort\n");
        printf("6 - ShellSort\n");
        printf("7 - CoutingSort\n");
        printf("8 - BucketSort\n");
        printf("9 - RadixSort\n");
        printf("0 - Sair\n");
        printf("------------------------------\n");
        printf("Insira a opcao: ");
        scanf("%i", &opt);
        if (opt >= 0 && opt <=9 ) { return opt; }
    }
}

int vetMenu() {
    while(1){
        int opt;
        system("clear");
        printf("------------------------------\n");
        printf("1 - Vetor ordenado\n");
        printf("2 - Vetor aleatorio\n");
        printf("3 - Vetor inversamente ordenado\n");
        printf("0 - Sair\n");
        printf("------------------------------\n");
        printf("Insira a opcao: ");
        scanf("%i", &opt);
        if (opt >= 0 && opt <=3 ) { return opt; }
    }
}
// ----------------------------------------------------------------------------------------------------------------
void createVectorOrd(int *A, int n) {
    for(int i = 0; i<n; i++) { A[i] = i; }
    return;
}

void createVectorDesord(int *A, int n) {
    for(int i = 0; i<n; i++) { A[i] = n-1-i; }
    return;
}

void createVectorRand(float *A, int n) {
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0; i<n; i++) { A[i] = ((float)rand()/(float)(RAND_MAX)) * 50000;}
    return;
}

void copyVector(int *A, int *B, int n) {
    for (int i = 0; i<n; i++) { B[i] = A[i]; }
    return;
}

void printVector(int *A, int n) {
    for(int i = 0; i<n; i++) { printf("%i ", A[i]); }
    printf("\n");
    return;
}

void swap(float *xp, float *yp){
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
    return;
}

int verify(float *A, int n) {
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i-1]) {
            printf("Ordenação nao concluida.\n");
            return 0;
        }
    }
    return 1;
}

int findMax(int *A, int n) {
    int max = A[0];
    for (int i = 1; i<n; i++) {
        if (A[i] > max) { max = A[i]; }
    }
    return max;
}

int findMin(int *A, int n) {
    int min = A[0];
    for (int i = 1; i<n; i++) {
        if (A[i] < min) { min = A[i]; }
    }
    return min;
}

// ----------------------------------------------------------------------------------------------------------------
// bubbleSort
void bubbleSort(float *A, int n) {
    for (int i = 0; i<n-1; i++) {
        for (int j = 1; j<n-i; j++) {
            if (A[j] < A[j-1]) { swap(&A[j], &A[j-1]); }
        }
    }
    return;
}
// ----------------------------------------------------------------------------------------------------------------
// insertionSort
void insertionSort(float v[], int l, int r) {
    int i, j, aux;
    for (i = l+1; i<=r; i++) {
        aux = v[i];
        j = i-1;
        while (j >= l && v[j] > aux) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
    return;
}
// ----------------------------------------------------------------------------------------------------------------
// selectionSort
void selectionSort(float arr[], int l, int r) { 
    int i, j;
    for (i = l; i<r; i++) {
        int min = i;
        for (j = i+1; j<=r; j++) {
            if (arr[j] < arr[min]) { min = j; }
        }
        if (min != i) { swap(&arr[i], &arr[min]); }
    }
    return;
}
// ----------------------------------------------------------------------------------------------------------------
// mergeSort
void merge(float *A, int l, int m, int r) {
    int i, j, k;
    int sizeL = m-l+1;
    int sizeR = r-m;

    float L[sizeL], R[sizeR];
    for(i=0; i<sizeL; i++) { L[i] = A[l+i]; }
    for(j=0; j<sizeR; j++) { R[j] = A[m+j+1]; }

    i=0; j=0; k=l;
    while (i<sizeL && j<sizeR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<sizeL) {
        A[k] = L[i];
        i++; k++;
    }
    while (j<sizeR) {
        A[k] = R[j];
        j++; k++;
    }
    return;
}

void mergeSort(int *A, int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, m, r);
    }
    return;
}
// ----------------------------------------------------------------------------------------------------------------
// quickSort
void partition(float * A, int l, int r, int *i, int *j) {
    float x;
    *i = l; *j = r;
    x = A[(*i + *j)/2];
    do {
        while (x > A[*i]) { (*i)++; }
        while (x < A[*j]) { (*j)--; }
        if (*i <= *j) {
            swap(&A[*i], &A[*j]);
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
    return;
}

void quickSort(float * A, int l, int r) { 
    int i, j;
    partition(A, l, r, &i, &j);
    if (l < j) { quickSort(A, l, j); }
    if (r > i) { quickSort(A, i, r); }
    return;
}
// ----------------------------------------------------------------------------------------------------------------
// shellSort
void shellSort(float *A, int n) {
    for (int h = n/2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            float aux = A[i];
            int j;
            for (j = i; (j >= h) && (A[j-h] > aux); j -= h) { A[j] = A[j-h]; }
            A[j] = aux;
        }
    }
    return;
}
// ----------------------------------------------------------------------------------------------------------------
// countingSort
void coutingSort(int *A, int n) {
    int i, j;
    int max = findMax(A, n);
    int cont[max+1];

    for (i = 0; i<=max; i++) { cont[i] = 0; }
    for (i = 0; i<n; i++) { cont[A[i]]++; }

    i = 0;
    for (j = 0; j<=max; j++) {
        while (cont[j] > 0) {
            A[i] = j;
            i++; 
            cont[j]--;
        }
    }
}
// ----------------------------------------------------------------------------------------------------------------
// bucketSort
struct bucket {
    int qtd;
    int valores[TAM_BUCKET];
};

void bucketSort (int *A, int n) {
    int i, j, max, min, nBuckets, pos;
    struct bucket *bd;
    max = findMax(A, n); min = findMin(A, n);
    nBuckets = (max - min) / TAM_BUCKET+1;
    bd = (struct bucket*) malloc(nBuckets * sizeof(struct bucket));

    for (i=0; i<nBuckets; i++) { bd[i].qtd = 0; }
    for (i=0; i<n; i++) {
        pos = (A[i] - min) / TAM_BUCKET;
        bd[pos].valores[bd[pos].qtd] = A[i];
        bd[pos].qtd++;
    }

    pos = 0;

    for (i=0; i<nBuckets; i++) {
        insertionSort(bd[i].valores, 0, bd[i].qtd-1);
        for (j=0; j<bd[i].qtd; j++) {
            A[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
    return;
}
// ----------------------------------------------------------------------------------------------------------------
// radixSort
void expSort(int *A, int n, int exp) {
    int ord[n];
    int cont[10] = {0};

    for (int i = 0; i<n; i++) { cont[(A[i]/exp) % 10]++; }
    for (int i = 1; i<10; i++) { cont[i] += cont[i-1]; }
    for (int i = n-1; i>=0; i--) {
        ord[cont[(A[i]/exp) % 10] - 1] = A[i];
        cont[(A[i]/exp) % 10]--;
    }

    for (int i = 0; i<n; i++) { A[i] = ord[i]; }
}

void radixSort(int *A, int n) {
    int max = findMax(A, n);
    for (int exp = 1; max / exp > 0; exp *= 10) { expSort(A, n, exp); }
}
// ----------------------------------------------------------------------------------------------------------------
void testIndividual(FILE *arq, int optAlg, int optVet) {
    int inpSize = 10;
    while(inpSize <= 150000) {
        float A[inpSize];
        clock_t start, end;
        double tempoTotal;

        if(optVet == 1) { createVectorOrd(A, inpSize); }
        else if(optVet == 2) { createVectorRand(A, inpSize); }
        else { createVectorDesord(A, inpSize); }

        start = clock();
        switch (optAlg) {
            case 1:
                bubbleSort(A, inpSize);
                break;
            case 2:
                selectionSort(A, 0, inpSize-1);
                break;
            case 3:
                insertionSort(A, 0, inpSize-1);
                break;
            case 4:
                mergeSort(A, 0, inpSize-1);
                break;
            case 5:
                quickSort(A, 0, inpSize-1);
                break;
            case 6:
                shellSort(A, inpSize);
                break;
            case 7:
                coutingSort(A, inpSize);
                break;
            case 8:
                bucketSort(A, inpSize);
                break;
            case 9:
                radixSort(A, inpSize);
                break;
        }
        end = clock();

        if (!verify(A, inpSize)) {
            printf("ERRO: Vetor nao ordenado.\n");
            return; 
        }

        tempoTotal = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(arq, "%f\n", tempoTotal);

        if (inpSize < 250) { inpSize += 10; } 
        else if (inpSize < 1000) { inpSize += 50; }
        else if (inpSize < 5000) { inpSize += 100; }
        else if (inpSize < 15000) { inpSize += 500; }
        else if (inpSize < 25000) { inpSize += 1000; }
        else if (inpSize < 50000) { inpSize += 2500; }
        else { inpSize += 5000; }
    }
}

void testGeral(FILE* arq) {
    int inpSize = 10;
    while(inpSize <= 150000) {
        int A[inpSize], B[inpSize];
        clock_t start, end;
        double tempoTotal;

        createVectorRand(A, inpSize);

        for (int i = 1; i<=8; i++) {
            copyVector(A, B, inpSize);
            start = clock();
            switch(i){
                case 1:
                    bubbleSort(B, inpSize);
                    break;
                case 2:
                    selectionSort(B, 0, inpSize-1);
                    break;
                case 3:
                    insertionSort(B, 0, inpSize-1);
                    break;
                case 4:
                    mergeSort(B, 0, inpSize-1);
                    break;
                case 5:
                    quickSort(B, 0, inpSize-1);
                    break;
                case 6:
                    shellSort(B, inpSize);
                    break;
                case 7:
                    coutingSort(B, inpSize);
                    break;
                case 8:
                    radixSort(B, inpSize);
                    break;                 
            }
            end = clock();

            if (!verify(B, inpSize)) {
                printf("ERRO: Vetor nao ordenado.\n");
                return; 
            }
            tempoTotal = ((double) (end - start)) / CLOCKS_PER_SEC;
            fprintf(arq, "%f\t", tempoTotal);
        }
        fprintf(arq, "\n");
        if (inpSize < 250) { inpSize += 10; } 
        else if (inpSize < 1000) { inpSize += 50; }
        else if (inpSize < 5000) { inpSize += 100; }
        else if (inpSize < 15000) { inpSize += 500; }
        else if (inpSize < 25000) { inpSize += 1000; }
        else if (inpSize < 50000) { inpSize += 2500; }
        else { inpSize += 5000; }
    }
}
// ----------------------------------------------------------------------------------------------------------------

int main() {
    FILE *arquivo;
    arquivo = fopen("./docs/tempos.txt", "w");
    if (arquivo == NULL) { return 0; }

    int firtsOption = menu();
    if (!firtsOption) { return 0; }

    if (firtsOption == 1) {
        int secondOption = algMenu();
        if (!secondOption) { return 0; }
        int thirdOption = vetMenu();
        if (!thirdOption) { return 0; }
        testIndividual(arquivo, secondOption, thirdOption);
    } else {
        fprintf(arquivo, "BubbleST\tSelectST\tInsertST\tMergeSRT\tQuickSRT\tShellSRT\tCountSRT\tRadixSRT\n\n");
        testGeral(arquivo);
    }

    fclose(arquivo);
    return 0;
}