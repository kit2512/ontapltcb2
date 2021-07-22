#include <stdio.h>

void bai1()
{
    int arr[100];
    for (int i = 0; i < 10; i++)
    {
        printf("nhap a[%d]: ");
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void bai2()
{
    int arr[100];
    int n;
    printf("nhap so phan tu (<100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhap a[%d]: ");
        scanf("%d", &arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
}

void bai3()
{
    int arr[100];
    int n, sump = 0, sumn = 0, countp = 0, countn = 0;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhap a[%d]: ", i);
        scanf("%d", &arr[i]);
        if (arr[i] >= 0)
        {
            sump += arr[i];
            countp++;
        }
        else
        {
            sumn += arr[i];
            countn++;
        }
    }
    printf("tong day: %d\n", sump + sumn);
    printf("tong duong: %d\n", sump);
    printf("tong am: %d\n", sumn);
    printf("tb duong: %.2f\n", (float)sump / countp);
    printf("tb am: %.2f\n", (float)sumn / countn);
}

void bai4()
{
    int arr[100] = {0};
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhap a[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int min = arr[0], max = arr[0], indexMin = 0, indexMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            indexMin = i;
        }
        if (max < arr[i])
        {
            max = arr[i];
            indexMax = i;
        }
    }
    printf("Min : %d, index: %d\n", min, indexMin);
    printf("Max : %d, index: %d", max, indexMax);
}

void bai5()
{
    int arr[100] = {0};
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhap a[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int x, count = 0;
    printf("nhap x: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            count++;
    }
    printf("so lan xuat hien cua %d trong mang: %d", x, count);
}

void bai6()
{
    int arr[100] = {0};
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhap a[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            arr[i] = 0;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void bai7()
{
    int arr[100] = {0};
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhap a[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void bai8()
{
    int arr1[100] = {0}, arr2[100] = {0};
    int n1, n2;
    printf("nhap so phan tu mang 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("nhap a1[%d]: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("nhap so phan tu mang 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("nhap a2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }

    int result[100], nResult, index1 = 0, index2 = 0;
    while (index1 < n1 && index2 < n2)
    {
        if (arr1[index1] < arr2[index2])
            result[nResult++] = arr1[index1++];
        else
            result[nResult++] = arr2[index2++];
    }
    while (index1 < n1)
        result[nResult++] = arr1[index1++];
    while (index2 < n2)
        result[nResult++] = arr2[index2++];

    for (int i = 0; i < nResult; i++)
        printf("%d ", result[i]);
}

