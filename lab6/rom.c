#include <stdio.h>
int znajdz_wartosc(char a)
{
    int rzymskie_pdst[7] = {'I','V','X','L','C','D','M'};
    int arabskie_pdst[7] = {1,5,10,50,100,500,1000};
    for (int i = 0; i<7;i++)
    {
        if (a == rzymskie_pdst[i])
        {
            return arabskie_pdst[i];
        }
    }

}
void dziesietna_na_rzymska(int a)
{
    while (a != 0)
    {
        if (a >= 1000)
        {
            printf("%c",'M');
            a -= 1000;
        }
        else if (a >= 900)
        {
            printf("%c",'C');
            printf("%c",'M');
            a -= 900;
        }
        else if (a >= 500)
        {
            printf("%c",'D');
            a -= 500;
        }
        else if (a >= 400)
        {
            printf("%c",'C');
            printf("%c",'D');
            a -= 400;
        }
        else if (a >= 100)
        {
            printf("%c",'C');
            a -= 100;
        }
        else if (a >= 90)
        {
            printf("%c",'X');
            printf("%c",'C');
            a -= 90;
        }
        else if (a >= 50)
        {
            printf("%c",'L');
            a -= 50;
        }
        else if (a >= 40)
        {
            printf("%c",'X');
            printf("%c",'L');
            a -= 40;
        }
        else if (a >= 10)
        {
            printf("%c",'X');
            a -= 10;
        }
        else if (a >= 9)
        {
            printf("%c",'I');
            printf("%c",'X');
            a -= 9;
        }
        else if (a >= 5)
        {
            printf("%c",'V');
            a -= 5;
        }
        else if (a >= 4)
        {
            printf("%c",'I');
            printf("%c",'V');
            a -= 4;
        }
        else if (a >= 1)
        {
            printf("%c",'I');
            a -= 1;
        }


    }
}
int rzymska_na_dziesietna(char *T, int len) {
    int sum = 0;
    int i = 0;
    while (i < len) {
        int res1 = znajdz_wartosc(T[i]);
        int res2 = 0;
        if (i + 1 < len)
            res2 = znajdz_wartosc(T[i + 1]);
        if (res1 < res2) {
            sum += res2 - res1;
            i++;
        } else {
            sum += res1;
        }
        i++;
    }
    return sum;
}

int main() {
    char T1[20], T2[20];
    int i = 0,len1=0,len2=0;
    scanf("%s %s", T1, T2);
    while (T1[i] != '\0')
    {
        len1 ++;
        i++;
    }
    i = 0;
    while (T2[i] != '\0')
    {
        len2++;
        i++;
    }
    int liczba1 = rzymska_na_dziesietna(T1,len1);
    int liczba2 = rzymska_na_dziesietna(T2,len2);
    int res = liczba1 + liczba2;
    dziesietna_na_rzymska(res);

}