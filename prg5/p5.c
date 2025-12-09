#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node *inertbeg() {
    int item;
    printf("enter item");
    scanf("%d", &item);
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->info = item;
    if (start == NULL) {
        p->next = NULL;
        start = p;
    } else {
        p->next = start;
        start = p;
    }
}

struct node *insertend() {
    int item;
    printf("enter item");
    scanf("%d", &item);
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->info = item;
    if (start == NULL) {
        p->next = NULL;
        start = p;
    } else {
        struct node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        p->next = NULL;
        temp->next = p;
    }
}

struct node *dis() {
    if (start == NULL) {
        printf("ll is empty");
    } else {
        struct node *temp = start;
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

struct node *insertpos() {
    int pos, item;
    printf("enter pos");
    scanf("%d", &pos);
    printf("enter item");
    scanf("%d", &item);

    if (pos == 1) {
        inertbeg();
        return;
    }

    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->info = item;

    struct node *temp = start;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("invalid pos");
    } else {
        p->next = temp->next;
        temp->next = p;
    }
}

void deletbeg() {
    if (start == NULL) {
        printf("ll empty");
    } else {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
}

void deleteend() {
    if (start == NULL) {
        printf("ll empty");
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
    } else {
        struct node *temp = start;
        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}

void delpos() {
    int pos;
    printf("enter pos");
    scanf("%d", &pos);

    if (start == NULL) {
        printf("ll empty");
        return;
    }

    if (pos == 1) {
        deletbeg();
        return;
    }

    struct node *temp = start;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("invalid pos");
    } else {
        struct node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void createll() {
    int n, item;
    printf("enter number of nodes");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("enter item ");
        scanf("%d", &item);

        struct node *p = (struct node *) malloc(sizeof(struct node));
        p->info = item;
        p->next = NULL;

        if (start == NULL) {
            start = p;
        } else {
            struct node *temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = p;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Create LL\n2.Insert Beg\n3.Insert End\n4.Insert Pos\n5.Delete Beg\n6.Delete End\n7.Delete Pos\n8.Display\n9.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createll(); break;
            case 2: inertbeg(); break;
            case 3: insertend(); break;
            case 4: insertpos(); break;
            case 5: deletbeg(); break;
            case 6: deleteend(); break;
            case 7: delpos(); break;
            case 8: dis(); break;
            case 9: return 0;
            default: printf("Invalid");
        }
    }
}

