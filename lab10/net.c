#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recur_calc_gate(int gate_num, int input[100], int n, int m, int gates[3000][2]){
//    Biorę wejścia dla bramki, sprawdzam czy są wejściami bezpośrednimi, czy z innej bramki
    int in_1 = gates[gate_num][0];
    int in_1_input = in_1 <0;
    int in_2 = gates[gate_num][1];
    int in_2_input = in_2 < 0;
//    Biorę wartość z inputa lub odpalam rekurencję, odpowiednio zmieniam indexy bo są o 1 za małe/ za duże
    if (in_1_input){
        in_1++;
        in_1 = input[-in_1];
    } else{
        in_1--;
        in_1 = recur_calc_gate(in_1, input, n, m, gates);
    }
    if (in_2_input){
        in_2++;
        in_2 = input[-in_2];
    } else{
        in_2--;
        in_2 = recur_calc_gate(in_2, input, n, m, gates);
    }
//    Zwracam wartość logiczną XOR dla dwóch wejść
    return in_1^in_2;
}
void increase_num(int * num_bin, int n){
    for (int i = n-1; i >=0 ; --i) {
        if (num_bin[i] == 1){
            num_bin[i] = 0;
        } else{
            num_bin[i] = 1;
            break;
        }
    }
}
int equal(int num1[100], int num2[100], int n){
    for (int i = n-1; i >= 0; --i) {
        if (num1[i] != num2[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n = 0;
    int m = 0;
    int output = 0;
    int gates[3000][2];
    char a_char[100];
    char b_char[100];
    int a[100];
    int b[100];

    scanf("%i %i %i", &n, &m, &output);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%i", &gates[i][j]);
        }
    }
    for (int i = 0; i < 100; ++i) {
        a[i] = 0;
        b[i] = 0;
    }
    scanf("%s", a_char);
    scanf("%s", b_char);
//    Zamieniam sobie tablicę charów na inty żeby na pewno nic się przez to nie psuło
    for (int i = 0; i < n; ++i) {
        a[i] = (int)a_char[i]-48;
        b[i] = (int)b_char[i]-48;
    }
    int res = 0;
    res += recur_calc_gate(output-1, a, n, m, gates);
    while (!equal(a, b, n)){
//        Dodaję wartość bramki do sumy wyników
        increase_num(a, n);
        res += recur_calc_gate(output-1, a, n, m, gates);
    }
    printf("%i", res);
}