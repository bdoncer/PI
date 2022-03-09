#include <stdio.h>
int main()
{
    int T[200][200];
    int res = 0;
    for (int i = 0;i<200;i++)
    {
        for (int j = 0;j<200;j++)
        {
            T[i][j] = 0;
        }
    }
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for (int x=x1;x<x2;x++)
        {
            for (int y=y1;y<y2;y++)
            {
                if (T[x+100][y+100] == 0)
                {
                    T[x+100][y+100] = 1;
                    res ++;
                }
                else
                {
                    T[x+100][y+100] = 0;
                    res --;
                }
            }
        }
    }
    printf("%d",res);

}