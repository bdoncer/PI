#include <stdio.h>
int div_and_mod(int* T,int znak,int end)
{
    int przenies1 = 0;
    int przenies2 = 0;
    for (int i = 0; i <= end; ++i)
    {
        przenies2 = (T[i]+przenies1*10)%2;
        T[i] = (T[i]+przenies1*10)/2;
        przenies1 = przenies2;
    }
    if (znak == -1 && przenies1 != 0)
    {
        int index = end;
        T[index]+=1;
        while (T[index] > 9)
        {
            T[index] = 0;
            T[index-1] ++;
            index --;
        }
    }
    int mod;
    if (przenies1 == 0)
    {
        mod = 0;
    }
    else
    {
        mod = 1;
    }
    return mod;

}
int main()
{
    char C[30];
    int T[30];
    int T2[30];
    int res1[100];
    int res2[100];
    int znak = 1;
    for (int i = 0; i < 30; ++i)
    {
        C[i] = 0;
        T[i] = 0;
        T2[i] = 0;
    }
    scanf("%s", C);
    for (int i = 0; i < 30; i++)
    {
        T[i] = C[i]-48;
        T2[i] = T[i];
    }
    int end = 0;
    for (int i = 0; i < 30; i++)
    {
        if (T[i] == -48)
        {
            end = i-1;
            break;
        }
        if (i == 29)
        {
            end = 29;
            break;
        }
    }

    int mod;
    for (int i = 0; i < 100; i++)
    {
        mod = div_and_mod(T,znak,end);
        res1[i] = mod;
        znak *= -1;
    }
    int i = 0;
    int sem = 0;
    while (i<=end)
    {
        if (T[i] != 0)
        {
            printf("NO");
            sem = 1;
            break;
        }
        i++;
    }
    if (sem == 0)
    {
        for (int i=0;i<100;i++)
        {
            if (res1[i] == 1)
            {
                printf("%d ",i);
            }
        }
    }
    znak = -1;
    for (int i = 0; i < 100; i++)
    {
        mod = div_and_mod(T2,znak,end);
        res2[i] = mod;
        znak *= -1;
    }
    i = 0;
    sem = 0;
    printf("\n");
    while (i <= end)
    {
        if (T2[i] != 0)
        {
            printf("NO");
            sem = 1;
            break;
        }
        i++;
    }
    if (sem == 0)
    {
        for (int i=0;i<100;i++)
        {
            if (res2[i] == 1)
            {
                printf("%d ",i);
            }
        }
    }
}
