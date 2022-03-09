#include <stdio.h>

int mass(int weight,int* T,int i,int n,int sum)
{
    if (weight == 0)
    {
        return 1;
    }
    if (i >= n || weight - sum > 0 || weight + sum < 0)
    {
        return 0;
    }
    return mass(weight,T,i + 1,n,sum - T[i]) || \
    mass(weight + T[i],T,i + 1,n,sum - T[i]) || mass(weight - T[i], T,i + 1,n,sum - T[i]);
}
int main()
{
    int n,weight,x,sum = 0;
    scanf("%i",&n);
    scanf("%i",&weight);
    int T[100];
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        T[i] = a;
        sum += a;
    }
    x = mass(weight,T,0,n,sum);
    if(x == 0)
    {
        printf("NO");
    }
    if(x == 1)
    {
        printf("YES");
    }

    return 0;
}