#include <stdio.h>
int main()
{
    int a = 1;
    int b = 1;
    int c,n;
    scanf("%i",&n);
    while (a*b <= n)
    {
        if (a*b == n)
        {
            printf("YES");
            return 0;
        }
        c = a + b;
        a = b;
        b = c;
    }
    printf("NO");
    return 0;
}
