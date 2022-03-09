#include <stdio.h>

int main() {
    int n, k;
    int T[100][100];
    int R[20000];
    int dl_boku,obwod = 0, ile = 0, i_res = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &T[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dl_boku = 2;
            while (i + dl_boku < n && j + dl_boku < n) {
                obwod = 0;
                for (int a = 1; a < dl_boku; a++) {
                    obwod += T[i + a][j] + T[i][j + a] + T[i + dl_boku][j + a] + T[i + a][j + dl_boku];
                }
                obwod += T[i][j] + T[i][j + dl_boku] + T[i + dl_boku][j + dl_boku] + T[i + dl_boku][j];
                if (obwod == k) {
                    ile++;
                    R[i_res] = i +(dl_boku/ 2);
                    R[i_res+1] = j +(dl_boku/ 2);
                    i_res += 2;
                }
                dl_boku += 2;
            }
        }
    }
    int i = 0;
    printf("%d\n", ile);
    while (i != i_res) {
        printf("%d %d\n", R[i], R[i + 1]);
        i += 2;
    }
}