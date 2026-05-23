#include <stdio.h>
#include <math.h>
#include <omp.h>

double Riemann_Zeta(double s, int k) {
    double result = 0.0;
    for (int i = 1; i < k; i++) {
        for (int j = 1; j < k; j++) {
            result += (2 * (i & 1) - 1) / pow(i + j, s);
        }
    }
    return result * pow(2.0, s);
}

int main(void) {
    const unsigned int N = 100;
    double X[N];

    
    #pragma omp parallel for schedule(dynamic, 1)
    for (unsigned int k = 0; k < N; k++) {
        X[k] = Riemann_Zeta(2.0, k);
    }

    for (unsigned int k = 0; k < N; k++) {
        printf("%u %.15f\n", k, X[k]);
    }

    return 0;
}
