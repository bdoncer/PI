#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long int liczby[1000000];
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
long int pow2(int n)
{
    long int res = 1;
    while (n > 0)
    {
        res = res*2;
        n--;
    }
    return res;
}
int main()
{
    int N;
    int M;
    int res = 0;
    scanf("%d%d",&N,&M);
    if (M==1)
    {
        printf("0");
        return 0;
    }
    int liczby_ctr = 0;
    long int T[31];
    for (long int i =M; i<pow2(N);i+=M)
    {
        for (int j=0;j<31;j++)
        {
            T[j] = 0;
        }
        int k=0;
        int p = i;
        while (p>0)
        {
            T[k] = p%2;
            p /= 2;
            k++;
        }
        long int res;
        for (int ind = 0;ind<N;ind++)
        {
            if (T[ind] == 0)
            {
                res = i+pow2(ind);
            }
            if (T[ind] == 1)
            {
                res = i-pow2(ind);
            }
            if (res%M != 0)
            {
                liczby[liczby_ctr] = res;
                liczby_ctr ++;
            }
        }
    }
    qsort(liczby, (size_t) liczby_ctr, sizeof(long int), cmpfunc);
    int wynik = 0;
    if (liczby_ctr != 0)
    {
        wynik = 1;
    }
    for (int i = 1; i < liczby_ctr; i++)
    {
        if (liczby[i-1] != liczby[i])
            wynik += 1;
    }

    printf("%d",wynik);
}