#include <stdio.h>
int main()
{
    int n,k,l,suma = 0,suma_max = 0;
    int T[100][100];
    int P[100][100];
    scanf("%d%d%d",&n,&k,&l);
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++)
        {
            scanf("%d",&T[i][j]);
        }
    }
    for (int i = 0;i<k;i++)
    {
        for (int j = 0;j<l;j++)
        {
            scanf("%d",&P[i][j]);
        }
    }
    for (int i = 0;i+k<n;i++)
    {
        for (int j = 0;j+l<n;j++)
        {
            suma = 0;
            for (int p = 0;p<k;p++)
            {
                for (int q = 0;q<l;q++)
                {
                    if (P[p][q] == 1)
                    {
                        suma += T[p+i][q+j];
                    }
                }
            }
            if (suma > suma_max)
            {
                suma_max = suma;
            }
        }
    }
    printf("%d",suma_max);
}