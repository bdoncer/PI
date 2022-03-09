#include <stdio.h>
#include <math.h>
int czy_mozliwe(int* T1,int* T2,int N)
{
    for (int i = 0;i<31;i++)
    {
        if (T1[i] < T2[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int G,N;
    int zera[31];
    int jedynki[31];
    int bin2[31];
    scanf("%d%d",&N,&G);
    int T[N];
    for (int i = 0;i<N;i++)
    {
        scanf("%d",&T[i]);
    }
    int bin[31];
    for (int i = 0;i<31;i++)
    {
        bin[i] = 0;
    }
    for (int i = 0;i<31;i++)
    {
        zera[i] = 0;
        jedynki[i] = 0;
    }
    int i = 0;
    while (G)
    {
        bin[i] = G % 2;
        G /= 2;
        i++;
    }
    for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<31;j++)
        {
            bin2[j] = 0;
        }
        int p = 0;
        while (T[i])
        {
            bin2[p] = T[i] % 2;
            T[i] /= 2;
            p++;
        }
        int res = czy_mozliwe(bin,bin2,N);
        if (res == 1)
        {
            for (int k =0;k<31;k++)
            {
                if (bin2[k] == 0)
                {
                    zera[k] += 1;
                }
                else
                {
                    jedynki[k] += 1;
                }
            }
        }
    }
    int wynik = N+1;
    for (int i = 0;i<31;i++)
    {
        if (bin[i] == 0)
        {
            if (zera[i] < wynik)
            {
                wynik = zera[i];
            }
        }
        else
        {
            if (jedynki[i] < wynik)
            {
                wynik = jedynki[i];
            }
        }
    }
    printf("%d",wynik);

}