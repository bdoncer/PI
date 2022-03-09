#include <stdio.h>
#include <math.h>
#include <stdlib.h>
char * sciezka(int start, int end)
{
    char * res = malloc(sizeof (char)*50);
    char * path = 0;
    char * path2 = 0;
    int dl1 = 0;
    int dl2 = 0;
    for (int i = 0; i < 50; i++)
    {
        res[i] = 0;
    }
    if (end==1)
    {
        res[0] = '/';
        return res;
    }
    if (start==end)
    {
        return res;
    }
    if (fmod(sqrt(end), 1) == 0)
    {
        path = sciezka(start, (int)sqrt(end));
    }
    if (end%2 == 0)
    {
        path2 = sciezka(start,end/2);
    }
    for (int i = 0; i < 50; i++)
    {
        if (path != 0 && path[i] != 0)
            dl1++;
    }
    for (int i = 0; i < 50; i++)
    {
        if (path2 != 0 && path2[i] != 0)
            dl2++;
    }
    if (path == 0)
    {
        dl1 = 51;
    }
    if (path2 == 0)
    {
        dl2 = 51;
    }

    if (dl1 <= dl2 && !(path == 0))
    {
        for (int i = 0; i < 50; i++)
        {
            res[i] = path[i];
        }
        res[dl1] = '*';
        return res;
    }
    if (dl1 > dl2 && !(path2 == 0))
    {
        for (int i = 0; i < 50; i++)
        {
            res[i] = path2[i];
        }
        res[dl2] = '+';
        return res;
    }

    for (int i = 0; i < 50; i++)
    {
        res[i] = '+';
    }

    return res;
}
int main() {
    int start,end,dl=0;
    char * odp;
    scanf("%d %d", &start, &end);
    if (end == 1)
    {
        printf("/");
        return 0;
    }
    if (end == 0)
    {
        printf("-");
        return 0;
    }
    odp = sciezka(start,end);
    for (int i = 0; i < 50; i++)
    {
        if(odp[i] !=0)
        {
            dl++;
        }
    }
    if (dl == 50)
    {
        printf("NO");
        return 0;
    }

    for (int i = 0; i < 50; ++i)
    {
        printf("%c", odp[i]);
    }
}