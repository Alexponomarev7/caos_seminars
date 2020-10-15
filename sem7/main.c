#include <stdio.h>
#include <stdlib.h>

int N;
int * A;
int * B;
int * R;

extern void
summ();

extern void
everyday795(int A, int B);

int main()
{
    /* input format:
       N - number of elements
       A1 A2 A3 ... An
       B1 B2 B3 ... Bn
       X Y   // for everyday795
       Temp  // scanfed by everyday795
    */

    // part I
    scanf("%d", &N);
    A = calloc(N, sizeof(*A));
    B = calloc(N, sizeof(*B));
    R = calloc(N, sizeof(*R));

    for (int i=0; i<N; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i=0; i<N; ++i) {
        scanf("%d", &B[i]);
    }

    summ();
    for (int i=0; i<N; ++i) {
        printf("%d ", R[i]);
    }
    free(A);
    free(B);
    free(R);
    printf("\n");

    // part II
    int X, Y;
    scanf("%d%d", &X, &Y);
    everyday795(X, Y);


    return 0;
}
