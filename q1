#include <stdio.h>

int dataRack[100];
int startIdx = -1, endIdx = -1;
int capacity;

void insertItem() {
    int val;

    if (endIdx == capacity - 1) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    if (startIdx == -1) startIdx = 0;
    endIdx++;

    dataRack[endIdx] = val;
}

void deleteItem() {
    if (startIdx == -1 || startIdx > endIdx) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Removed: %d\n", dataRack[startIdx]);
    startIdx++;
}

void displayItems() {
    if (startIdx == -1 || startIdx > endIdx) {
        printf("Queue Empty\n");
        return;
    }

    for (int i = startIdx; i <= endIdx; i++) {
        printf("%d ", dataRack[i]);
    }
    printf("\n");
}

void peekItem() {
    if (startIdx == -1 || startIdx > endIdx) {
        printf("Queue Empty\n");
        return;
    }
    printf("Front: %d\n", dataRack[startIdx]);
}
int main() {
    int choice;

    printf("Enter queue capacity: ");
    scanf("%d", &capacity);

    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Peek 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertItem(); break;
            case 2: deleteItem(); break;
            case 3: displayItems(); break;
            case 4: peekItem(); break;
            case 5: return 0;
        }
    }
}
