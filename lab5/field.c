#include <stdio.h>

int main() {
    int n;
    int T[100][100];
    int k, w, sem, pom = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &T[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            k = j+1;
            w = i+1;
            if (T[i][j] == 0)
            {
                while (k < n && T[i][k] == 0) {
                    k++;
                }
                while (w < n && T[w][j] == 0) {
                    w++;
                }
                w--;
                k--;
                for (int i2 = i; i2 <= w; i2++) {
                    if (pom == 1)
                    {
                        break;
                    }
                    for (int j2 = j; j2 <= k; j2++) {
                        sem = 0;
                        for (int i3 = i; i3 <= i2; i3++) {
                            for (int j3 = j; j3 <= j2; j3++) {
                                if (T[i3][j3] != 0) {
                                    sem = 1;
                                    break;
                                }
                            }
                        }
                        if (sem == 0 && ((i2-i+1) * (j2-j+1)) > res) {
                            res = ((i2-i+1) * (j2-j+1)) ;
                            if (res == n*n)
                            {
                                pom = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", res);
}