#include <stdio.h>
#include <math.h>
long long int suma(long long int a)
{
    if (a == 0)
        return 0;
    if (a % 2 == 0)
    {
        return (a / 2)*(a/2) + suma(a / 2);
    }
    if (a % 2 == 1)
    {
        return ((a + 1) / 2)*((a + 1) / 2) + suma(a / 2);
    }

}
int main()
{
    long long int N;
    scanf("%lld",&N);
    long long int res = suma(N);
    printf("%lld",res);
    return 0;

}