#include <stdio.h>

void bai1()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("mang duoc gan gia tri khi khai bao: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d", arr[i][j]);
        printf("\n");
    }
    printf("nhap gia tri cho mang:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d", arr[i][j]);
        printf("\n");
    }
}

void bai2()
{
    int arr1[100][100], arr2[100][100], result[100][100];
    int m, n;
    printf("nhap kich thuoc hai ma tran (mxn): ");
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("nhap a1[%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("nhap a2[%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            result[i][j] = arr1[i][j] + arr2[i][j];
    }
    printf("ma tran tong:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", result[i][j]);
        printf("\n");
    }
}

void bai3()
{
    int arr1[100][100], arr2[100][100], result[100][100];
    int m, n, p;
    printf("nhap kich thuoc hai ma tran (mxn) * (n*p), nhap m, n, p: ");
    scanf("%d %d %d", &m, &n, &p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("nhap a1[%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("nhap a2[%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

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

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

void bai4()
{
    int arr[100][100] = {0};
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int topLeft = 0, bottomRignt = n - 1;
    int count = 1;
    while (topLeft <= bottomRignt)
    {
        for (int i = topLeft; i <= bottomRignt; i++)
        {
            arr[topLeft][i] = count++;
        }
        for (int i = topLeft + 1; i <= bottomRignt; i++)
        {
            arr[i][bottomRignt] = count++;
        }
        for (int i = bottomRignt - 1; i >= topLeft; i--)
        {
            arr[bottomRignt][i] = count++;
        }
        for (int i = bottomRignt - 1; i > topLeft; i--)
        {
            arr[i][topLeft] = count++;
        }
        topLeft++; bottomRignt--;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}
