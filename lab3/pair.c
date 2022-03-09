#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    int i_first = 0, j = 0, rep = 0, pairs = 0;
    long unsigned int N,K;
    scanf("%li %i",&N,&K);
    int* A = (int*) calloc(N, sizeof(int));
    for(int i=0;i<N;i++){
        scanf("%i",&A[i]);
    }
    qsort(A, N, sizeof(int), cmpfunc);
    for (int i = 0; i < N; i++) {
        rep = 1;
        i_first = i;
        j = i + 1;
        while (j < N && A[j] == A[i]) {
            rep++;
            j++;
        }
        i = j - 1;
        if (i_first - 1 >= 0 && A[i_first] - A[i_first - 1] <= K) {
            pairs += rep;
        } else if (i + 1 < N && A[i + 1] - A[i] <= K) {
            pairs += rep;
        }
    }
    printf("%i", pairs);
}