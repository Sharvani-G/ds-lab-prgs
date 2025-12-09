#include <stdio.h>

#define MAX 100

int arr[MAX];
int top = -1;
int maxsize;

void push(int item) {
    if (top == maxsize - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        arr[top] = item;
    }
}

int pop() {
    if (top == -1) {
        printf("The stack is empty\n");
        return -1;
    } else {
        int item = arr[top];
        top--;
        return item;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", arr[i]);
        }
    }
}

int main() {
    printf("Enter stack size: ");
    scanf("%d", &maxsize);

    int ch, val;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: {
                int x = pop();
                if (x != -1)
                    printf("Popped: %d\n", x);
                break;
            }
            case 3:
                display();
                Break;
            case 4:
                return 0;

            default:
                printf("Invalid\n");
        }
    }
    return 0;
}

