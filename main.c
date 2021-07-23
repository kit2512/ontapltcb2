#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bai1()
{
    int a[100][100], b[100][100], c[100][100];
    int m, n;
    printf("nhap m, n: ");
    scanf("%d %d", &m, &n);
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
        {
            printf("nhap A[i][j]: ");
            scanf("%d", &a[i][j]);
            printf("nhap B[i][j]: ");
            scanf("%d", &b[i][j]);
            c[i][j] = a[i][j] + b[i][j];
        }
    FILE* f = fopen("CONG_MT.C", "w+");
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            fprintf(f, "%d ", c[i][j]);
        fprintf(f, "\n");
    }
    fclose(f);
    system("notepad CONG_MT.C");
}

void bai2()
{
    FILE* f = fopen("TICH_MT.C", "a+");
    int m, n, p;
    int a[100][100], b[100][100], c[100][100];
    fscanf(f, "%d %d %d", &m, &n, &p);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fscanf(f, "%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            fscanf(f, "%d", &b[i][j]);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    fprintf(f,"\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            fprintf(f, "%d ", c[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    system("notepad TICH_MT.C");
}

void bai3() {

}

int main()
{
    bai2();
}
