#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;

struct node* create(struct node *start) {
    int n, item;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter item: ");
        scanf("%d", &item);

        struct node *p = malloc(sizeof(struct node));
        p->info = item;
        p->next = NULL;

        if(start == NULL)
            start = p;
        else {
            struct node *temp = start;
            while(temp->next != NULL) temp = temp->next;
            temp->next = p;
        }
    }
    return start;
}

void display(struct node *start) {
    if(start == NULL) {
        printf("List empty");
        return;
    }
    while(start != NULL) {
        printf("%d ", start->info);
        start = start->next;
    }
}

void sort(struct node *start) {
    struct node *p, *q;
    for(p = start; p != NULL; p = p->next)
        for(q = p->next; q != NULL; q = q->next)
            if(p->info > q->info) {
                int t = p->info;
                p->info = q->info;
                q->info = t;
            }
}

void reverse() {
    struct node *prev = NULL, *next = NULL, *curr = start1;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start1 = prev;
}

void concat() {
    if(start1 == NULL)
        start1 = start2;
    else {
        struct node *temp = start1;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = start2;
    }
}

int main() {
    int ch;

    while(1) {
        printf("\n1.Create List1\n2.Create List2\n3.Sort List1\n4.Reverse List1\n5.Concat L1 & L2\n6.Display List1\n7.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: start1 = create(start1); break;
            case 2: start2 = create(start2); break;
            case 3: sort(start1); break;
            case 4: reverse(); break;
            case 5: concat(); break;
            case 6: display(start1); break;
            case 7: return 0;
            default: printf("Invalid choice");
        }
    }
}

