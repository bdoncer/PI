#include <stdio.h>

int main()
{
    int n,i,j,sum_left=0,sum_right=0;
    scanf("%i",&n);
    int T[1000];
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        T[i] = a;
    }
    i = 0;
    j = n-1;
    while(i<j)
    {
        if (sum_left < sum_right)
        {
            sum_left += T[i];
            i++;
        }
        else
        {
            sum_right += T[j];
            j--;
        }
    }
    printf("%i",i);

}