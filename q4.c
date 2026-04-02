#include <stdio.h>

int ringBox[100];
int head = -1, tail = -1;
int sizeLimit;

void enqueueCQ() {
    int val;

    if ((tail + 1) % sizeLimit == head) {
        printf("Queue Full\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    if (head == -1) head = 0;

    tail = (tail + 1) % sizeLimit;
    ringBox[tail] = val;
}

void dequeueCQ() {
    if (head == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Removed: %d\n", ringBox[head]);

    if (head == tail) {
        head = tail = -1;
    } else {
        head = (head + 1) % sizeLimit;
    }
}

void displayCQ() {
    if (head == -1) {
        printf("Queue Empty\n");
        return;
    }

    int i = head;
    while (1) {
        printf("%d ", ringBox[i]);
        if (i == tail) break;
        i = (i + 1) % sizeLimit;
    }
    printf("\n");
}

int main() {
    int choice;

    printf("Enter size of circular queue: ");
    scanf("%d", &sizeLimit);

    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueueCQ(); break;
            case 2: dequeueCQ(); break;
            case 3: displayCQ(); break;
            case 4: return 0;
        }
    }
}
