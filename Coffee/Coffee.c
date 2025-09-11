#include <stdio.h>
#include <math.h>
#define PI 3.14159265

void solver() {
    double h, R, r, g, Vf, Vi;
    scanf("%lf %lf %lf",&r, &R, &h);
    Vi = (PI * h / 3) * ((r * r) + (R * R) + (R * r));
    double a = 0.0, b = h, m;
    do {
        m = (a + b) / (double)2;
        Vf = (PI * m / (double)3) * ((r * r) + ((r + (((R - r) / h) * m)) * (r + (((R - r) / h) * m))) + ((r + (((R - r) / h) * m)) * r));
        if (Vf < Vi/2)
            a = m;
        else
            b = m;
    } while (fabs(Vf - Vi/2) > 1e-7);
    printf("%lf\n",m);
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        solver();
    }
    return 0;
}