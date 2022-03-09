#include <stdio.h>
#define len 200
int add(int *t1, int x, int i) {
    while (x != 0) {
        int tmp = t1[i] + x;
        t1[i] = tmp % 10;
        x = tmp / 10;
        i--;
    }
}

int multiply(int *t1, int x) {
    int pom[len];
    for (int i = 0; i < len; i++) {
        pom[i] = 0;
    }
    int i = len-1;
    while (x != 0) {
        int tmp = x % 10;
        int ctr = 0;
        while (i-ctr >= 0 && t1[len-ctr-1] != -1) {
            int nwm = tmp * t1[len-ctr-1];
            add(pom, nwm, i - ctr);
            ctr++;
        }
        i--;
        x = x / 10;
    }
    i = 0;
    while (pom[i] == 0)
    {
        pom[i] = -1;
        i++;
    }
    for (int i = 0; i < len; i++) {
        t1[i] = pom[i];
    }
}

int main() {
    int T[len];
    T[len-1] = 1;
    for (int i = 0; i< len-1;i++)
    {
        T[i] = -1;
    }
    int n;
    scanf("%d",&n);
    for (int i= 2; i<=n;i++)
        multiply(T,i);

    for (int i = 0; i< len;i++)
    {
        if (T[i] != -1)
            printf("%d", T[i]);
    }
}