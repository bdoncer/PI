#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main() {
    int N, R;
    int sum = 0;
    scanf("%i%i", &N,&R);
    int **F;
    F = (int **) calloc(N, sizeof(int *));
    for (int i = 0; i < N; ++i) {
        F[i] = (int *) calloc(N, sizeof(int));
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%i", &F[i][j]);
        }
    }
    int **W;
    W = (int **) calloc(N, sizeof(int *));
    for (int i = 0; i < N; ++i) {
        W[i] = (int *) calloc(N, sizeof(int));
    }
    for (int i_w = 0; i_w < N; i_w++) {
        for (int j_w = 0; j_w < N; j_w++) {
            sum = 0;
            for (int i_f = 0; i_f < N; i_f++) {
                for (int j_f = 0; j_f < N; j_f++)
                {
                    if (max(abs(i_w-i_f),abs(j_w-j_f))<=R)
                    {
                        sum += F[i_f][j_f];
                    }
                }
            }
            W[i_w][j_w] = sum;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; ++j) {
            printf("%i ",W[i][j]);
        }
        printf("\n");
    }


}