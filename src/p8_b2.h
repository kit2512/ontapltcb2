#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct {
    char name[50];
    int tuoi;
    float diem;
} Sinhvien;

typedef struct linkedList {
    Sinhvien data;
    struct linkedList* next;
} * node;

node createNode(Sinhvien newSv) {
    node tmp = (node)malloc(sizeof(struct linkedList));
    tmp->data = newSv;
    tmp->next = NULL;
    return tmp;
}

node addHead(node head, Sinhvien newSv) {
    node tmp = createNode(newSv);
    if (head == NULL) head = tmp;
    else {
        tmp->next = head;
        head=tmp;
    }
    return head;
}

node addTail(node head, Sinhvien newSv) {
    if (head == NULL) head = addHead(head, newSv);
    else {
        node p = head, tmp = createNode(newSv);
        while (p->next != NULL) {
            p=p->next;
        }
        p->next = tmp;
    }
    return head;
}

node addAt(node head, int pos, Sinhvien newSv) {
    if (head == NULL || pos == 0) head = addHead(head, newSv);
    else {
        node p = head; int k = 1;
        while (k!= pos && p->next != NULL) {
            k++; p=p->next;
        }
        if (k!= pos) {
            head = addTail(head, newSv);
        } else {
            node tmp = createNode(newSv);
            tmp->next = p->next;
            p->next = tmp;
        }
    }
    return head;
}

node deleteHead(node head) {
    if (head == NULL) {
        printf("khong co gi de xoa\n");
        return head;
    }
    head = head->next;
    return head;
}

node deleteTail(node head) {
    if (head == NULL || head->next == NULL) {
        head = deleteHead(head);
    }
    else {
        node p = head;
        while(p->next->next != NULL) p = p->next;
        p->next = NULL;
    }
    return head;
}

node deleteAt(node head, int pos) {
    if (pos == 0 || head == NULL || head->next == NULL) head = deleteHead(head);
    else {
        int k=1; node p = head;
        while (k!=pos && p->next->next != NULL) {
            k++; p = p->next;
        }
        if (k!=pos) p->next = NULL;
        else {
            p->next = p->next->next;
        }
    }
    return head;
}

int firstIndexOfName(node head, char* name) {
    if (head == NULL) return -1;
    node p = head; int index = 0;
    while (p!= NULL) {
        if (strstr(p->data.name, name)) {
            return index;
        }
        index++; p=p->next;
    }
    return -1;
}

node addBeforeName(node head, char* name) {
    int pos = firstIndexOfName(head, name);
    if (pos == -1) {
        printf("khong tim thay ten\n");
    } else {
        printf("them sinh vien vao vi tri truoc vi tri %d\n", pos+1);
        Sinhvien newSv;
        printf("Ho ten    : "); fflush(stdin); gets(newSv.name);
        printf("Tuoi      : "); scanf("%d", &(newSv.tuoi));
        printf("Diem TB   : "); scanf("%f", &(newSv.diem));
        head = addAt(head, pos, newSv);
    }
    return head;
}

node deleteByName(node head, char* name) {
    int pos = firstIndexOfName(head, name);
    if (pos == -1) {
        printf("khong tim thay de xoa\n");
        return head;
    } else {
        deleteAt(head, pos);
    }
    return head;
}

void printList(node head) {
    int stt = 1;
    printf("Danh sach sinh vien\n");
    if (head == NULL) printf("NONE");
    else {
        node p = head;
        while(p != NULL) {
            printf("%-3d %-20s %-8d %-8.2f\n", stt++, p->data.name, p->data.tuoi, p->data.diem);
            p=p->next;
        }
    }
}

int listLength(node head) {
    if (head == NULL) return 0;
    else {
        int length = 1;
        node p = head;
        while (p->next != NULL) {
            length++;
            p = p->next;
        }
        return length;
    }
}

node nhapSinhVien(node head) {
    int stt = listLength(head)+1;
    Sinhvien newSv;
    do {
        system("cls");
        printf("sinh vien thu %d\n", stt++);
        printf("Ho ten    : "); fflush(stdin); gets(newSv.name);
        if (strlen(newSv.name) == 0) break;
        printf("Tuoi      : "); scanf("%d", &(newSv.tuoi));
        printf("Diem TB   : "); scanf("%f", &(newSv.diem));
        head = addTail(head, newSv);
    } while (1);
    return head;
}

void bai2() {
    node head = NULL;
    int option = -1;
    char* name;
    while (option!= 0) {
        printf("MENU\n");
        printf("1. Nhap sinh vien\n2. In sinh vien\n3. Them sinh vien theo ten\n4. Xoa sinh vien theo ten\n0.Thoat\nLua chon: ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            system("cls");
            head = nhapSinhVien(head);
            break;
        case 2:
            system("cls");
            printList(head);
            break;
        case 3:
            system("cls");
            printf("nhap ten sinh vien: "); fflush(stdin); gets(name);
            head = addBeforeName(head, name);
            break;
        case 4:
            system("cls");
            printf("nhap ten sinh vien muon xoa: "); fflush(stdin); gets(name);
            head = deleteByName(head, name);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("nhap sai\n");
            break;
        }
    }
}
