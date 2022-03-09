#include <stdio.h>
int main() {
    int n, k, wiersz, kolumna, ctr, suma = 0, suma_max = 0;
    int T[100][100];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &T[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            suma = 0;
            for (int prawo = 0; prawo < k; prawo++) {
                suma += T[i][(j + prawo) % n];
            }
            if (suma > suma_max) {
                suma_max = suma;
            }
            suma = 0;
            for (int dol = 0; dol < k; dol++) {
                suma += T[(i + dol) % n][j];
            }
            if (suma > suma_max) {
                suma_max = suma;
            }
            ctr = 0;
            wiersz = i;
            kolumna = j;
            suma = 0;
            while (ctr < k) {
                if (wiersz >= n && kolumna >= n) {
                    wiersz = 0;
                    kolumna = 0;
                }
                if (wiersz >= n)
                    wiersz = 0;
                if (kolumna >= n)
                    kolumna = 0;
                suma += T[wiersz][kolumna];
                wiersz += 1;
                kolumna += 1;
                ctr += 1;
            }
            if (suma > suma_max)
                suma_max = suma;
            ctr = 0;
            wiersz = i;
            kolumna = j;
            suma = 0;
            while (ctr < k) {
                if (wiersz >= n && kolumna < 0) {
                    wiersz = 0;
                    kolumna = n - 1;
                }
                if (wiersz >= n)
                    wiersz = 0;
                if (kolumna < 0)
                    kolumna = n - 1;
                suma += T[wiersz][kolumna];
                wiersz += 1;
                kolumna -= 1;
                ctr += 1;
            }
            if (suma > suma_max)
                suma_max = suma;
        }
    }
    printf("%d", suma_max);
}