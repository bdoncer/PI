#include <stdio.h>
#include <stdlib.h>

void merge(const int *t1, int *t2, long unsigned int N) {
    long unsigned int Nsq = N*N;
    int finger1 = 0;
    int finger2 = 0;
    int *pom;
    pom = (int*) calloc(Nsq, sizeof(int));
    for (int i = 0; i < N*N; i++) {
        pom[i] = t2[i];
        t2[i] = -1;
    }
    int ctr = 0;
    while (finger1 < N && finger2 < N * N) {
        if (t1[finger1] < pom[finger2]) {
            if (t1[finger1] != t2[ctr-1]) {
                t2[ctr] = t1[finger1];
                ctr++;
            }
            finger1++;
        }
        else if (t1[finger1] > pom[finger2]) {
            if (pom[finger2] != t2[ctr-1] && pom[finger2] != -1) {
                t2[ctr] = pom[finger2];
                ctr++;
            }
            finger2++;
        }
        else if (t1[finger1] == pom[finger2]) {
            if (t1[finger1] != t2[ctr-1]) {
                t2[ctr] = t1[finger1];
                ctr++;
            }
            finger1++;
            finger2++;
        }
    }
    while (finger1 < N) {
        if (t1[finger1] != t2[ctr-1]) {
            t2[ctr] = t1[finger1];
            ctr++;
        }
        finger1++;
    }
    while (finger2 < N * N) {
        if (pom[finger2] != t2[ctr-1] && pom[finger2] != -1) {
            t2[ctr] = pom[finger2];
            ctr++;
        }
        finger2++;
    }
    free(pom);
}

int main() {
    long unsigned int N;
    scanf("%li",&N);
    long unsigned int Nsq = N*N;
    int *t2;
    t2 = (int*) calloc(Nsq, sizeof (int));

    int **t1;
    t1 = (int**) calloc(N, sizeof(int*));
    for (int i = 0; i < N; ++i) {
        t1[i] = (int*) calloc(N, sizeof(int));
    }
    for(int i=0;i<N;i++){
        for (int j = 0; j < N; ++j) {
            scanf("%i",&t1[i][j]);
        }
    }
    for (int i = 0; i < N * N; i++) {
        t2[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        merge(t1[i], t2,N);
    }
    for (int i = 0; i < Nsq; i++) {
        if (t2[i] == -1) {
            break;
        }
        printf("%d ",t2[i]);
    }
}