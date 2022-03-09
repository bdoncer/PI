#import <stdio.h>
int czy_koncowa(int* gra)
{
    for (int i = 0;i<10098;i++)
    {
        if (gra[i] != 0 && gra[i+1] != 0)
        {
            return 0;
        }
        if (gra[i] > 1 || gra[i+1] > 1)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int gra[10100];
    for(int i=0;i<10100;i++)
    {
        gra[i] = 0;
    }
    for (int i = 0;i<n;i++)
    {
        int nr_pola;
        int ile_pionkow;
        scanf("%d%d",&nr_pola,&ile_pionkow);
        gra[nr_pola+50] = ile_pionkow;
    }
    int ile_do_naprawy = 1;
    while (ile_do_naprawy != 0)
    {
        ile_do_naprawy = 0;
        for(int i = 2;i<10099;i++)
        {
            if (gra[i] >= 3)
            {
                gra[i-2] += gra[i]/3;
                gra[i+2] += gra[i]/3;
                gra[i] = gra[i]%3;

                if (gra[i-2] >= 3)
                {
                    ile_do_naprawy++;
                }
            }
        }
    }
    int index = -1;
    for (int i = 10099;i>=0;i--)
    {
        if (gra[i] != 0)
        {
            index = i;
            break;
        }
    }
    index --;
    while (czy_koncowa(gra) == 0)
    {
        int sem = 0;
        if (gra[index] > 0 && gra[index+1] > 0)
        {
            gra[index] -= 1;
            gra[index+1] -=1;
            gra[index+2] +=1;
            index += 2;
            sem = 1;
        }
        else if (gra[index] ==2  && gra[index-1] > 0)
        {
            index --;
            sem = 1;
        }
        else if (gra[index] ==2 && gra[index+1] == 0)
        {

            gra[index] -= 1;
            gra[index-1] +=1;
            gra[index-2] +=1;
            gra[index-1] -= 1;
            gra[index] -=1;
            gra[index+1] +=1;
            index += 1;
            sem = 1;
        }
        else if (gra[index] == 3)
        {
            gra[index]-=3;
            gra[index-2]++;
            gra[index+2]++;
            index += 2;
            sem = 1;
        }
        int a = -1;
        for (int i = 0;i<10100;i++)
        {
            if (gra[i] != 0)
            {
                a = i;
                break;
            }
        }
        if (index == a && sem ==0)
        {
            break;
        }
        if (sem == 0)
        {
            int b=-1;
            for (int i = 0;i<10100;i++)
            {
                if (gra[i] != 0 && i < index)
                {
                    b = i;
                }
            }
            index = b;
        }
    }
    for(int i=0;i<10099;i++)
    {
        if(gra[i] != 0)
        {
            printf("%d ",i-50);
        }
    }

}