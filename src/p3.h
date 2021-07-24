#include <stdio.h>
#include <math.h>

void bai1()
{
    int a, s = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("nhap so thu %d: ");
        scanf("%d", &a);
        s += a;
    }
    printf("tong 10 so la: %d", s);
}

void bai2()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n <= 1)
        printf("khong la so nguyen to");
    else if (n == 2 || n == 3)
        printf("la so nguyen to");
    else
    {
        int check = 1;
        for (int i = 2; i < n; i++)
        {
            if (n % 2 == 0)
            {
                check = 0;
                break;
            }
        }
        printf("%sla so nguyen to", check ? "" : "khong ");
    }
}

void bai3()
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\t", i);
        }
    }
}

void bai4()
{
    int s = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2)
        {
            s += i;
        }
    }
    printf("tong so le tu 1 den 100: %d", s);
}

void bai5()
{
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            printf("%d, ", i);
    }
}

void bai6()
{
    int a, b;
    printf("Nhap hai so a, b: ");
    scanf("%d %d", &a, &b);
    int a1 = 1, b1 = b;
    while (a1 != b1)
    {
        if (a1 > b1)
            a1 -= b1;
        else
            b1 -= a1;
    }
    printf("UCLN: %d\n", a1);

    int i = a;
    while ((i % a != 0) || (i % b != 0))
    {
        i++;
    }
    printf("BCNN: %d", i);
}

void bai6_2()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n <= 0)
        printf("khong la so hoan hao");
    else
    {
        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                s += i;
        }
        if (s == 2 * n)
            printf("la so hoan hao");
        else
            printf("khong la so hoan hao");
    }
}

void bai7()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    float s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += 1 / (float)i;
    }
    printf("tong la : %.2f", s);
}

void bai8()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n == 0)
        printf("0! = 1");
    else
    {
        int s = 1;
        for (int i = 0; i <= n; i++)
            s *= i;
        printf("%d! = %d", n, s);
    }
}

void bai9()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    float s = 0;
    for (int i = 1; i < n; i++)
    {
        int f = 1;
        for (int j = 1; j <= i; j++)
            f *= j;
        s += 1 / (float)f;
    }
    printf("Tong la: %.2f", s);
}

// cho bài 10
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void bai10()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("so fibonanci thu n la: %d", fib(n));
}

// cho bài 11
void convertToBinary(int n)
{
    if (n)
    {
        convertToBinary(n / 2);
        printf("%d", n % 2);
    }
}

void convertToHex(int n)
{
    if (n)
    {
        convertToHex(n / 8);
        printf("%d", n % 8);
    }
}

void convertToOctal(int n)
{
    if (n)
    {
        convertToOctal(n / 16);
        if (n % 16 <= 9)
            printf("%d", n % 16);
        else
            switch (n % 16)
            {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                break;
            }
    }
}

void bai11()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    convertToBinary(n);
    printf("\n");
    convertToHex(n);
    printf("\n");
    convertToOctal(n);
    printf("\n");
}

// cho bài 12 và 13
int factorial(int n)
{
    int f = 1;
    if (n == 0)
        return f;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

void bai12()
{
    float x, sin = 0, eps, e;
    int i = 0;
    printf("nhap x: ");
    scanf("%f", &x);
    printf("nhap eps: ");
    scanf("%f", &eps);
    e = 1;
    while (e > eps)
    {
        float r = pow(x, 2 * i + 1) / factorial(2 * i + 1);
        if (i % 2 == 0)
        {
            sin += r;
        }
        else
        {
            sin -= r;
        }
        e = fabs(r);
        i++;
    }
    printf("sinx = %.2f", sin);
}

void bai13()
{
    float x, result = 0, eps, e;
    int i = 0;
    printf("nhap x: ");
    scanf("%f", &x);
    printf("nhap eps: ");
    scanf("%f", &eps);
    e = 1;
    while (e > eps)
    {
        float r = pow(x, i) / factorial(i);
        result += r;
        e = fabs(r);
        i++;
    }
    printf("e^x = %.2f", result);
}

void bai14()
{
    float gdp2014;
    printf("nhap GDP nam 2014: ");
    scanf("%f", &gdp2014);
    float growthPercent;
    printf("nhap muc tang truong (theo phan tram): ");
    scanf("%f", &growthPercent);
    float newGDP = gdp2014;
    int year = 2014;
    printf("Nam\t GDP\n");
    while (newGDP / gdp2014 <= 2)
    {
        printf("%d\t %.2f\n", year++, newGDP);
        newGDP *= 1 + growthPercent / 100;
    }
}

void bai15()
{
    float deposit;
    printf("nhap so tien gui A: ");
    scanf("%f", &deposit);
    int n;
    printf("nhap so thang n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        deposit += deposit * 0.45 / 100;
    }
    printf("sau %d thang, so tien rut duoc la %.2f", n, deposit);
}
