/*
 * 一元多项式的求和算法
 */

#include <stdio.h>
#include <math.h>

// 时间
#include <time.h>

#define MAXN 10
#define MAXK 1e7

// 运行时间
clock_t start, stop;
double duration;

// 循环累计求和
double f1(int n, double a[], double x) {
    double p = 0;
    for (int i = 0; i < n; ++i) {
        p += a[i] * pow(x, i);
    }
    return p;
}

// 秦九韶求和算法
double f2(int n, double a[], double x) {
    double p = 0;
    for (int i = n; i > 0; --i) {
        p = a[i-1] + x * p;
    }
    return p;
}

//
void run(double (*f)(int, double*, double), double a[], int case_n) {
    start = clock();
    for (int i = 0; i < MAXK; ++i) {
        (*f)(MAXN, a, 1.1);
    }
    stop = clock();

    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("ticks%d=%f\n", case_n, (double)(stop - start));
    printf("duration%d=%6.2e\n", case_n, duration);
}

int main(int argc, char *argv) {
    double coes[MAXN];
    for (int i = 0; i < MAXN; ++i) {
        coes[i] = (double)i + 1;
    }

    run(f1, coes, 1);
    run(f2, coes, 2);

    return 0;
}
