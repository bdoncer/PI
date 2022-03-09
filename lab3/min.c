#include <stdio.h>

int find_max(int *T, int l) {
    int max = T[0];
    int odp = 0;
    for (int i = 1; i < l; i++) {
        if (T[i] > max) {
            max = T[i];
            odp = i;
        }
    }
    return odp;
}
int A[1000000];
int main() {
    int N, K;
    scanf("%i %i", &N, &K);
    int ind, sum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%i", &a);
        A[i] = a;
    }

    for (int i = 0; i < K; i++) {
        ind = find_max(A, N);
        A[ind] = A[ind] / 2;
    }
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    printf("%i", sum);
    return 0;
}
