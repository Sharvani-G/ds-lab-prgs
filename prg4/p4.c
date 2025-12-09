#include <stdio.h>
#define MAX 5

int q[MAX], rear = -1, front = -1;

void insert(int item) {
    if (front == (rear + 1) % MAX) {
        printf("queue is full\n");
    } else if (front == -1) {
        front = 0;
        rear = 0;
        q[rear] = item;
    } else {
        rear = (rear + 1) % MAX;
        q[rear] = item;
    }
}

int pop() {
    int item;
    if (front == -1) {
        printf("queue is empty\n");
        return -1;
    } else if (front == rear) {
        item = q[front];
        front = -1;
        rear = -1;
        return item;
    } else {
        item = q[front];
        front = (front + 1) % MAX;
        return item;
    }
}

void dis() {
    if (front == -1) {
        printf("queue is empty\n");
    } else {
        int i = front;
        while (1) {
            printf("%d ", q[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2: {
                int x = pop();
                if (x != -1)
                    printf("Deleted: %d\n", x);
                break;
            }

            case 3:
                dis();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid\n");
        }
    }

    return 0;
}

