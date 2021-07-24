#include <stdio.h>
#include <math.h>

void bai1() {
    int x; printf("Nhap x: "); scanf("%d", &x);
    printf("x^2 = %d, x^3 = %d, x^4 = %d", pow(x, 2), pow(x, 3), pow(x, 4));
}

void bai2() {
    int y=0, m=0, d=0;
    printf("nhap ngay thang nam: "); scanf("%d %d %d", &d, &m, &y);
    printf("%d/%d/%d", d, m, y);
}

void bai3() {
    int a, b;
    char p;
    printf("nhap a, b: "); scanf("%d %d", &a, &b);
    printf("a + b = %d, a - b = %d, a * b = %d, a / b = %d", a+b, a-b, a*b, a/b);
}

void bai4() {
    float r; printf("nhap R: "); scanf("%f", &r);
    printf("dien tich: %.2f\nthe tich: %.2f", 4*M_PI*pow(r, 2), (4.0/3)*M_PI*pow(r, 3));
}