#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* nextPtr;
};

struct Node *frontNode = NULL, *rearNode = NULL;

// Now value is passed as argument
void enqueueNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->info = val;
    temp->nextPtr = NULL;

    if (rearNode == NULL) {
        frontNode = rearNode = temp;
    } else {
        rearNode->nextPtr = temp;
        rearNode = temp;
    }

    printf("Inserted: %d\n", val);
}

void dequeueNode() {
    if (frontNode == NULL) {
        printf("Queue Empty\n");
        return;
    }

    struct Node* temp = frontNode;
    printf("Removed: %d\n", temp->info);

    frontNode = frontNode->nextPtr;
    free(temp);

    if (frontNode == NULL) rearNode = NULL;
}

void displayList() {
    if (frontNode == NULL) {
        printf("Queue Empty\n");
        return;
    }

    struct Node* travel = frontNode;
    printf("Queue: ");
    while (travel != NULL) {
        printf("%d ", travel->info);
        travel = travel->nextPtr;
    }
    printf("\n");
}

void peekNode() {
    if (frontNode == NULL) {
        printf("Queue Empty\n");
        return;
    }
    printf("Front: %d\n", frontNode->info);
}
int main() {
    int choice, val;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value once: ");
                scanf("%d", &val);
                enqueueNode(val);
                break;

            case 2:
                dequeueNode();
                break;

            case 3:
                displayList();
                break;

            case 4:
                peekNode();
                break;

            case 5:
                return 0;

            default:    
                printf("Invalid choice\n");
        }
    }
}
