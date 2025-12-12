
#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *top = NULL;       // stack
struct node *front = NULL;     // queue
struct node *rear = NULL;

void push() {
    int item;
    printf("Enter item: ");
    scanf("%d", &item);

    struct node *p = malloc(sizeof(struct node));
    p->info = item;
    p->next = top;
    top = p;
}

void pop() {
    if(top == NULL)
        printf("Stack empty");
    else {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}

void enqueue() {
    int item;
    printf("Enter item: ");
    scanf("%d", &item);

    struct node *p = malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;

    if(front == NULL)
        front = rear = p;
    else {
        rear->next = p;
        rear = p;
    }
}

void dequeue() {
    if(front == NULL)
        printf("Queue empty");
    else {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}

void display_stack() {
    struct node *temp = top;
    printf("Stack: ");
    while(temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

void display_queue() {
    struct node *temp = front;
    printf("Queue: ");
    while(temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

int main() {
    int ch;

    while(1) {
        printf("\n1.Push\n2.Pop\n3.Display Stack\n4.Enqueue\n5.Dequeue\n6.Display Queue\n7.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display_stack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: display_queue(); break;
            case 7: return 0;
            default: printf("Invalid");
        }
    }
}

