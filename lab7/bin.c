#include <stdio.h>
int czy_spelnia(int *T) {
    for (int i = 0; i < 63; i++) {
        if (T[i] == 1 && T[i + 1] == 1) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int K, N, liczba = 0;
    int binarna[64];
    scanf("%d%d", &N, &K);
    while (1) {
        for (int j = 0; j < 64; j++) {
            binarna[j] = 0;
        }
        int i = 0;
        int a = liczba;
        while (a > 0) {
            binarna[i] = a % 2;
            a = a / 2;
            i++;
        }
        if (czy_spelnia(binarna) == 1) {
            K--;
            if (K == 0) {
                break;
            }
        }
        liczba++;
    }
    int sem = 0;
    for (int i = 63; i >= N; i--) {
        if (binarna[i] == 1) {
            sem = 1;
            printf("%d", -1);
            break;
        }
    }
    if (sem == 0) {
        for (int i = N - 1; i >= 0; i--) {
            printf("%d", binarna[i]);
        }
    }
}
