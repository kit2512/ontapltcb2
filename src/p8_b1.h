#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
    char tenHang[50];
    int donGia, soLuong;
} Hang;

Hang *nhapHang(int *n)
{
    system("cls");
    printf("nhap so luong: ");
    scanf("%d", n);
    Hang *hangs = malloc(*n * sizeof(Hang));
    for (int i = 0; i < *n; i++)
    {
        printf("-----------------------\n");
        printf("mat hang thu %d\n", i + 1);
        printf("Ten hang   : ");
        fflush(stdin);
        gets(hangs[i].tenHang);
        printf("Don gia    : ");
        scanf("%d", &(hangs[i].donGia));
        printf("So Luong   : ");
        scanf("%d", &(hangs[i].soLuong));
    }
    return hangs;
}

void inHang(Hang *hangs, int n)
{
    system("cls");
    printf("                           SO LIEU BAN HANG                          \n");
    printf("| STT | Ten Hang               | Don gia  | So luong | Thanh tien    |\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %3d | %-22s | %-8d | %-8d | %13d |\n", i + 1, hangs[i].tenHang, hangs[i].donGia, hangs[i].soLuong, hangs[i].donGia * hangs[i].soLuong);
    }
}

int compareName(Hang h1, Hang h2) {
    return strcmp(h1.tenHang, h2.tenHang) > 0;
}

void sortHang(Hang* hangs, int n, int (*callback)(Hang, Hang), int reverse) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (reverse == 0 ? callback(hangs[i], hangs[j]) : !callback(hangs[i], hangs[j])) {
                Hang tmp = hangs[i];
                hangs[i] = hangs[j];
                hangs[j] = tmp;
            }
        }
    }
    inHang(hangs, n);
}

void bai1()
{
    int n;
    Hang *hangs;
    int option = -1;
    while (option != 0)
    {
        printf("1. Nhap hang\n");
        printf("2. In hang\n");
        printf("3. Sap xep theo ten\n");
        printf("0. Thoat");
        printf("Lua chon: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            hangs = nhapHang(&n);
            break;
        case 2:
            inHang(hangs, n);
            break;
        case 3:
            sortHang(hangs, n, compareName, 0);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("nhap sai");
            break;
        }
    }
}
