#include <stdio.h>
#include <math.h>

int max(int a,int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int is_perfect_number(int number)
{
    int sum = 1;
    int factor = 2;
    while (factor <= sqrt(number))
    {
        if (number % factor == 0)
        {
            sum += factor + number/factor;
        }
        factor++;
    }
    if (sum == number)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int main(void)
{
    int m, n, i, odp;
    int res = 0;
    scanf("%i",&m);
    scanf("%i",&n);
    i = max(m,2);
    while (i != n)
    {
        odp = is_perfect_number(i);
        if (odp == 1)
        {
            res ++;
        }
        i++;
    }
    printf("%i\n",res);
    i = max(m,2);
    while (i != n)
    {
        odp = is_perfect_number(i);
        if (odp == 1)
        {
            printf("%i ",i);
        }
        i++;
    }
    return 0;
}

