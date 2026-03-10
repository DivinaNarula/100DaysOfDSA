/* Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations */

#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

/* Check if deque is empty */
int empty() {
    return (front == -1);
}

/* Size of deque */
int size() {
    if (front == -1)
        return 0;
    return rear - front + 1;
}

/* Insert at front */
void push_front(int value) {
    if (front == 0) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = value;
}

/* Insert at rear */
void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

/* Delete from front */
void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

/* Delete from rear */
void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

/* Get front element */
int get_front() {
    if (empty()) {
        printf("Deque Empty\n");
        return -1;
    }
    return deque[front];
}

/* Get rear element */
int get_back() {
    if (empty()) {
        printf("Deque Empty\n");
        return -1;
    }
    return deque[rear];
}

/* Clear deque */
void clear() {
    front = rear = -1;
}

/* Display deque */
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. push_front\n");
        printf("2. push_back\n");
        printf("3. pop_front\n");
        printf("4. pop_back\n");
        printf("5. front\n");
        printf("6. back\n");
        printf("7. size\n");
        printf("8. clear\n");
        printf("9. display\n");
        printf("10. exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                printf("Front element: %d\n", get_front());
                break;

            case 6:
                printf("Rear element: %d\n", get_back());
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                clear();
                printf("Deque cleared\n");
                break;

            case 9:
                display();
                break;

            case 10:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}