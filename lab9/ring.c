#include <stdio.h>
void skakanko(int dl,int skok,int index,char* s,int *T)
{
    T[0] = s[index];
    int t = 1;
    int i = (index + skok) % dl;
    while (t < dl)
    {
        T[t] = s[i];
        i = (i+skok)%dl;
        t++;
    }
}
int ktore_lepsze(int* T1,int* T2,int dl)
{
    int i = 0;
    while (i < dl)
    {
        if (T1[i] < T2[i])
        {
            return 1;
        }
        if (T2[i] < T1[i])
        {
            return 2;
        }
        i++;
    }
    return 1;
}
int main()
{
    char s[50];
    for(int z=0;z<50;z++)
    {
        s[z] = -1;
    }
    scanf("%s",s);
    int dl = -1;
    int z = 0;
    while (s[z] != -1)
    {
        dl++;
        z++;
    }
    int pierwsze[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int min = 1000;
    for (int i = 0; i< dl;i++)
    {
        if (s[i]<min)
        {
            min = s[i];
        }
    }

    int best[50];
    for (int i = 0;i<50;i++)
    {
        best[i] = 500;
    }
    for (int i = 0; i< dl;i++)
    {
        if (s[i]==min)
        {
            int j = 0;
            while (pierwsze[j] < dl)
            {
                int T[50];
                for (int i = 0;i<50;i++)
                {
                    T[i] = 500;
                }
                skakanko(dl,pierwsze[j],i,s,T);
                int nr = ktore_lepsze(best,T,dl);
                if (nr == 2)
                {
                    int k = 0;
                    while (k<50)
                    {
                        best[k] = T[k];
                        k++;
                    }
                }
                j++;
            }
        }
    }
    int p = 0;
    while (p < dl)
    {
        printf("%c",best[p]);
        p++;
    }
}