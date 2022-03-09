#include <stdio.h>
#include <math.h>

int is_prime(a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }

    if (a <= 1)
        return 0;
    return 1;
}

int is_square(a) {
    int sum = 0;
    while (a != 0) {
        sum += pow(a % 10, 2);
        a = a / 10;
        if (a == 0 && sum != 1 && sum != 4) {
            a = sum;
            sum = 0;
        }
    }
    if (sum == 1) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    int L, U, K, x, y;
    scanf("%i %i %i", &L, &U, &K);
    int k_counter = 0;
    int sem = 0;
    for (int i = L; i <= U; i++) {
        x = is_prime(i);
        y = is_square(i);
        if (x == 1 && y == 1) {
            k_counter++;
            if (k_counter == K) {
                printf("%i", i);
                sem = 1;
            }
        }

    }
    if (sem == 0) {
        printf("%i", -1);
    }

}