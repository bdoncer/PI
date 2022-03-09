#include <stdio.h>

int main()
{
    int N;
    int T[100][100];
    scanf("%d",&N);
    int a = 1,k = 0,w = 0,dol = N - 1,gora = 0,prawo = N - 1,lewo = 0;
    for (int i=0;i<(N/2+1);i++)
    {
        while (k <= prawo)
        {
            T[w][k] = a;
            k += 1;
            a += 1;
        }
        gora += 1;
        w += 1;
        k -= 1;
        while (w <= dol)
        {
            T[w][k] = a;
            w += 1;
            a += 1;
        }
        w -= 1;
        k -= 1;
        while (k >= lewo)
        {
            T[w][k] = a;
            k -= 1;
            a += 1;
        }
        w -= 1;
        k += 1;
        while (w >= gora)
        {
            T[w][k] = a;
            w -= 1;
            a += 1;
        }
        w += 1;
        k += 1;
        prawo -= 1;
        dol -= 1;
        lewo += 1;
    }
    for (w=0;w<N;w++)
    {
        for (k=0;k<N;k++)
        {
            if (k+1!=N)
            {
                printf("%d ",T[w][k]);
            }
            else
            {
                printf("%d\n",T[w][k]);
            }
        }
    }


}