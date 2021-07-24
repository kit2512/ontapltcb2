#include <stdio.h>
#include <math.h>

double bai1(float x, float y)
{
    return pow(x, y);
}

int bai2(int n)
{
    int f = 1;
    if (n == 0)
        return f;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int bai3(int n)
{
    return (n == 1 || n == 2) ? 1 : (bai3(n - 1) + bai3(n - 2));
}

// bài 4
void nhapMaTran(int arr[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("nhap A[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
}

void inMaTran(int arr[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void bai4()
{
    int arr1[100][100], arr2[100][100], result[100][100];
    int m, n, p;
    printf("nhap kich thuoc hai ma tran (mxn) * (n*p), nhap m, n, p: ");
    scanf("%d %d %d", &m, &n, &p);
    printf("Nhap ma tran 1: \n");
    nhapMaTran(arr1, m, n);
    printf("Nhap ma tran 2: \n");
    nhapMaTran(arr2, n, p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    inMaTran(result, m, p);
}

// bài 5 

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

void bai5() {
    int n; printf("nhap n: "); scanf("%d", &n);
    int coSo; printf("Chuyen sang he co so: "); scanf("%d",&coSo);
    switch (coSo)
    {
    case 2:
        printf("he co so 2: ");
        convertToBinary(n);
        break;
    case 8:
        printf("he co so 8: ");
        convertToHex(n);
        break;
    case 16:
        printf("he co so 16: ");
        convertToOctal(n);
        break;
    default:
        break;
    }
}

// bai 6

void nhapDaThuc(int* dt, int *n) {
    printf("nhap bac cua da thuc: "); scanf("%d", n);
    for (int i=0; i<=*n; i++) {
        printf("nhap he so cho x^%d: ", i);
        scanf("%d", &dt[i]);
    }
}

void inDaThuc(int *dt, int n) {
    for (int i=0; i<=n; i++) {
        if (dt[i] == 0) continue;
        if (i==0) printf("%d", dt[i]);
        else printf("%c%dx^%d", (dt[i] > 0) ? '+' : '-', abs(dt[i]), i);
    }
}

void tongDaThuc(int* p,int n, int* q,int m, int* t, int *nt) {
    *nt = n >= m ? n : m;
    for (int i=0; i<=*nt; i++)
        t[i] = p[i] + q[i];
}

void bai6() {
    int p[100] = {0}, q[100] = {0}, t[100] = {0};
    int n, m, nt;
    nhapDaThuc(p, &n);
    nhapDaThuc(q, &m);
    tongDaThuc(p, n, q, m, t, &nt);
    inDaThuc(t, nt);
}