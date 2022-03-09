#include <stdio.h>
#include <math.h>
int is_okay(unsigned long long int N,unsigned long long int res)
{
    unsigned long long int suma = 0;
    while (res != 0)
    {
        suma += res;
        res = res/10;
    }
    if (suma == N)
    {
        return 1;
    }
    return 0;
}
int main()
{
    unsigned long long int N;
    scanf("%lld",&N);
    int dlugosc=log10(N)+1;
    unsigned long long int liczba=0;
    for (int i=dlugosc;i>=0;i--)
    {
        liczba = liczba*10;
        liczba += 1;
    }
    unsigned long long int res = 0;
    unsigned long long int a = N;
    while (N != 0)
    {
        res = res * 10 + N/liczba;
        N = N%liczba;
        liczba = liczba / 10;
    }
    if (is_okay(a,res) == 1)
    {
        printf("%lld",res);
    }
    else
    {
        printf("%d",-1);
    }
    return 0;

}