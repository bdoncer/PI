#include <stdio.h>
int T[1000][1000];
int main() {
    int n, m;
    int res = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            T[i][j] = 0;
        }
    }
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        T[p][q] = 1;
    }

    for (int i = 1; i <= n; i++) //ktory wiersz sprawdzam
    {
        for (int j=i+1;j <= n;j++) //z ktorym elementem wierszu bede porownywala
        {
            for (int k=j+1;k<=n;k++) //ktory bedzie porownywany
            {
                if (T[i][j] == T[i][k] && T[i][j] == T[j][k])
                {
                    res++;
                }
            }
        }
    }
    printf("%d",res);
}