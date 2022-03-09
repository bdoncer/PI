#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int c[N+3];
    int z[N+3];
    int n[N+3];
    int ctr_c = 0,ctr_z=0,ctr_n = 0;
    for (int i = 0;i<N;i++)
    {
        scanf("%d",&c[i]);
        ctr_c++;
    }
    for (int i = 0;i<N;i++)
    {
        scanf("%d",&z[i]);
        ctr_z++;
    }
    for (int i = 0;i<N;i++)
    {
        scanf("%d",&n[i]);
        ctr_n++;
    }
    c[N]=0;
    c[N+1]=0;
    c[N+2] = 0;
    z[N]=0;
    z[N+1]=0;
    z[N+2] = 0;
    n[N]=0;
    n[N+1]=0;
    n[N+2] = 0;
    int odp = 999999999;
    int res = 999999999;
    if (N<3)
    {
        printf("-1");
        return 0;
    }
    for(int r=0;r<N+3;r++)
    {
        for(int g=0;g<N+3;g++)
        {
            for(int b=0;b<N+3;b++)
            {

                if (r!=g && g!=b && r!=b)
                {
                    res = 0;
                    if (ctr_c == 0)
                        r = N;
                    if (ctr_z == 0)
                        g = N+1;
                    if (ctr_n == 0)
                        b = N+2;
                    res = res+z[r]+n[r]+c[g]+n[g]+c[b]+z[b];
                    for(int i=0;i<N+3;i++)
                    {
                        if (i != r && i!=g && i!=b)
                        {
                            if (c[i] >= z[i] && c[i] >= n[i])
                            {
                                res =res+ z[i]+n[i];
                            }
                            else if (z[i] >= c[i] && z[i] >= n[i])
                            {
                                res = res+ c[i]+n[i];
                            }
                            else if (n[i] >= z[i] && n[i] >= c[i])
                            {
                                res = res+ z[i]+c[i];
                            }
                        }
                    }
                }
            }
            if (res<odp)
            {
                odp = res;
            }
        }
    }
    printf("%d",odp);
}