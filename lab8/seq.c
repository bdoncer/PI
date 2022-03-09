#include <stdio.h>
char ktora_wieksza(char x,char y)
{
    int a = x;
    int b = y;

    if (a > b)
    {
        return x;
    }
    return y;
}
int main()
{
    char znaki[50];
    int dlugosc = 0;
    for (int i = 0; i < 50; i++)
    {
        znaki[i] = 0;
    }
    scanf("%s", znaki);
    for (int i = 0; i < 50; i++)
    {
        if (znaki[i] > 0)
        {
            dlugosc += 1;
        }
    }
    int ile_najwiekszych = 0;
    int ostatni_index = -1;
    while (ostatni_index < dlugosc-1)
    {
        char biggest = 0;
        for (int i = ostatni_index+1; i < dlugosc; i++)
        {
            biggest = ktora_wieksza(biggest,znaki[i]);
        }
        for (int i = ostatni_index+1; i < dlugosc; i++)
        {
            if (znaki[i] == biggest)
            {
                ile_najwiekszych += 1;
                ostatni_index = i;
            }
        }
        for (int i= ile_najwiekszych;i>0;i--)
        {
            printf("%c",biggest);
        }
        ile_najwiekszych=0;
    }



}