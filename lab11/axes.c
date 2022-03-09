#include <stdio.h>
#include <math.h>
double distance(double x1, double y1, double x2, double y2)
{
    double sum = (x2 - x1) * (x2 - x1)+(y2 - y1) * (y2 - y1);
    return sqrt(sum);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        double x[2*n];
        double y[2*n];
        for (int i = 0;i<2*n;i+=2)
        {
            scanf("%lf%lf",&x[i],&y[i]);
        }
        for (int i = 1;i<2*n;i+=2)
        {
            if (i == 2*n-1)
            {
                x[i] = (x[i-1]+x[0])/2;
                y[i] = (y[i-1]+y[0])/2;
            }
            else
            {
                x[i] = (x[i-1]+x[i+1])/2;
                y[i] = (y[i-1]+y[i+1])/2;
            }
        }
        int res=0;
        for (int i = 0;i<n;i++) //wybieram wierzcholek przez ktory przejdzie prosta
        {
            int sem = 0;
            for (int j=0;j<n;j++)
            {
                if (i!=j)
                {
                    int index1 = i+j;
                    int index2 = i-j;
                    if (index1 >= 2*n)
                    {
                        index1 = index1%(2*n);
                    }
                    if (index2 >= 2*n)
                    {
                        index2 = index2%(2*n);
                    }
                    if (index1 < 0)
                    {
                        index1 += 2*n;
                    }
                    if (index2 < 0)
                    {
                        index2 += 2*n;
                    }
                    if ((distance(x[i],y[i],x[index1],y[index1])!=distance(x[i],y[i],x[index2],y[index2]))||(distance(x[i+n],y[i+n],x[index1],y[index1])!=distance(x[i+n],y[i+n],x[index2],y[index2])))
                    {
                        sem = 1;
                        break;
                    }
                }
            }
            if (sem==0)
            {
                res++;
            }
        }
        printf("%d\n",res);
    }

}