#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int info;
    struct node *next;
};

struct node *create(struct node *start) {
    struct node *p, *temp;
    int val;

    printf("Enter values (-999 to stop): ");
    scanf("%d", &val);

    while (val != -999) {
        p = (struct node *)malloc(sizeof(struct node));
        p->info = val;
        p->next = NULL;

        if (start == NULL) {
            p->prev = NULL;
            start = p;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = p;
            p->prev = temp;
        }
        scanf("%d", &val);
    }
    return start;
}

struct node *insert(struct node *start, int val) {
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = val;
    p->next = NULL;

    if (start == NULL) {
        p->prev = NULL;
        start = p;
    } else {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
        p->prev = temp;
    }
    return start;
}

struct node *delete(struct node *start, int ele) {
    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    while (temp != NULL && temp->info != ele)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found\n");
        return start;
    }

    if (temp == start) {
        start = temp->next;
        if (start != NULL)
            start->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    return start;
}

void dis(struct node *start) {
    struct node *temp = start;
    if (temp == NULL)
        printf("List is empty\n");
    else {
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct node *start = NULL;
    int choice, val;

    while (1) {
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = create(start);
                break;
            case 2:
                scanf("%d", &val);
                start = insert(start, val);
                break;
            case 3:
                scanf("%d", &val);
                start = delete(start, val);
                break;
            case 4:
                dis(start);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
