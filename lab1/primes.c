#import <stdio.h>

int is_growing(int x)
{
    int last, pre_last;
    while (x > 9)
    {
        last = x % 10;
        pre_last = (x / 10) % 10;
        if (last < pre_last)
        {
            return 0;
        }
        x = x / 10;
    }
    return 1;
}

int is_prime(int x)
{
    if (x == 1) return 0;
    if (x % 2 == 0 && x > 2) return 0;
    for(int i = 3; i < x / 2; i += 2)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int n;
    int i = 2;
    scanf("%i",&n);
    while (i < n)
    {
        if (is_growing(i) == 1 && is_prime(i) == 1)
        {
            printf("%i\n",i);
        }
        i++;
    }

    return 0;
}