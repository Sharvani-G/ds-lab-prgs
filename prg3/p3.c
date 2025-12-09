#include<stdio.h>
#define MAX 5

int q[MAX];
int rear = -1, front = -1;

void insert() {
    int n;
    printf("Enter element: ");
    scanf("%d", &n);

    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else if (front == -1) {
        front = 0;
        rear = 0;
        q[rear] = n;
    } else {
        rear++;
        q[rear] = n;
    }
}

int delete() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int item = q[front];
        front++;
        return item;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d\n", q[i]);
        }
    }
}

int main() {

    int ch;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;

            case 2: {
                int x = delete();
                if (x != -1)
                    printf("Deleted: %d\n", x);
                break;
            }

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid\n");
        }
    }

    return 0;
}

