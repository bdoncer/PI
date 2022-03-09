#include <stdio.h>
#include <math.h>


int na_dec(int *T, int cyfry, int system)
{
    int dec = 0;
    for(int i = cyfry-1; i >= 0; i--)
    {
        dec += pow(system, cyfry - 1 - i) * T[i];
    }
    return dec;
}


int dol(int cyfry, int system)
{
    int min[cyfry];
    for(int i = 0; i < cyfry; i++)
    {
        if(i == 0){min[i] = 1;}else{min[i] = 0;}
    }
    int min_dec = na_dec(min, cyfry, system);
    return min_dec;
}


int gora(int cyfry, int system)
{
    int max[cyfry];
    for(int i = 0; i < cyfry; i++)
    {
        max[i] = system - 1;
    }
    int max_dec = na_dec(max, cyfry, system);
    return max_dec;
}


int czy_narcystyczna(int liczba, int cyfry, int system){
    char T[16];
    T[10] = 'A';
    T[11] = 'B';
    T[12] = 'C';
    T[13] = 'D';
    T[14] = 'E';
    T[15] = 'F';
    int result[cyfry];
    int i = cyfry - 1;
    int pom = liczba;
    while(pom > 0 )
    {
        result[i] = pom % system;
        pom /= system;
        i --;
    }
    int suma = 0;
    for(int x = 0; x < cyfry; x++)
    {
        suma += pow(result[x], cyfry);
    }
    if(suma == liczba)
    {
        for(int k = 0; k < cyfry; k++)
        {
            if(result[k] > 9)
            {
                printf("%c", T[result[k]]);
            }
            else
            {
                printf("%d", result[k]);
            }
        }
        printf(" ");
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    int m, b;
    scanf("%d %d", &m, &b);
    int x,y,a;
    int sem = 0;
    x = dol(m, b);
    y = gora(m, b);
    for(int i = x; i <= y; i++)
    {
        a = czy_narcystyczna(i, m, b);
        if(a==1)
        {
            sem = 1;
        }
    }
    if(sem==0)
    {
        printf("NO");
    }
}