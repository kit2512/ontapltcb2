#include <stdio.h>
#include <math.h>

void bai1()
{
    float a, b, c;
    printf("nhap a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (!a)
    {
        if (!b)
        {
            if (!c)
                printf("Phuong trinh vo so nghiem");
            else
                printf("Phuong trinh vo nghiem");
        }
        else
            printf("Phuong trinh co nghiem duy nhat x = %.2f", -c / b);
    }
    else
    {
        float delta = b * b - 4 * a * c;
        if (!delta)
        {
            printf("Phuong trinh co nghiem duy nhat x = %.2f", -b / (2 * a));
        }
        else if (delta > 0)
        {
            float x1 = (-b - sqrt(delta)) / (2 * a);
            float x2 = (-b + sqrt(delta)) / (2 * a);
            printf("Phuong trinh co hai nghiem phan biet x1 = %.2f, x2 = %.2f", x1, x2);
        }
        else
            printf("Phuong trinh vo nghiem");
    }
}

void bai2()
{
    // ax + by = c
    // dx + ey = f
    float a, b, c, d, e, f;
    printf("nhap he so a, b, c, d, e, f: ");
    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
    float D = a * e - b * d, Dx = c * e - f * b, Dy = a * f - c * d;
    if (D == 0)
        if (Dx == Dy && Dy == 0)
            printf("Phuong trinh vo so nghiem");
        else
            printf("Phuong trinh vo nghiem");
    else
    {
        float x = Dx / d;
        float y = Dy / d;
        printf("Phuong trinh co hai nghiem la x = %.2f, y = %.2f", x, y);
    }
}

void bai3()
{
    float diem;
    printf("Nhap diem tb: ");
    scanf("%f", &diem);
    if (diem < 5)
        printf("Yeu");
    else if (diem < 7)
        printf("Trung binh");
    else if (diem < 8)
        printf("Kha");
    else if (diem < 9)
        printf("Gioi");
    else
        printf("Xuat sac");
}

void bai4()
{
    float a, b, c;
    printf("Nhap ba canh a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0)
    {
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            if (a == b || b == c || c == a)
            {
                printf("tam giac vuong can");
            }
            else
                printf("tam giac vuong");
        }
        else if (a == b || b == c || c == a)
        {
            if (a == b && b == c)
                printf("tam giac deu");
            else
                printf("tam giac can");
        }
        else
            printf("tam giac thuong");
    }
}

void bai5()
{
    int m, y;
    printf("nhap m/y: ");
    scanf("%d/%d", &m, &y);
    int result;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        result = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        result = 30;
        break;
    case 2:
        result = (y % 100 == 0) ? (y % 400 == 0 ? 29 : 28) : ((y % 4 == 0) ? 29 : 28);
        break;
    default:
        printf("nhap sai");
    }
    printf("Thang %d nam %d %d ngay", result);
}
