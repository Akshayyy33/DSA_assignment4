#include <stdio.h>

int qA[100], qB[100];
int fA = -1, rA = -1, fB = -1, rB = -1;
int maxSize;

void pushStack(int val) {
    if (rA == maxSize - 1) {
        printf("Stack Full\n");
        return;
    }

    if (fA == -1) fA = 0;
    qA[++rA] = val;
}

void popStack() {
    if (fA == -1) {
        printf("Stack Empty\n");
        return;
    }

    while (fA < rA) {
        if (fB == -1) fB = 0;
        qB[++rB] = qA[fA++];
    }

    printf("Popped: %d\n", qA[fA]);

    fA = rA = -1;

    while (fB <= rB) {
        if (fA == -1) fA = 0;
        qA[++rA] = qB[fB++];
    }

    fB = rB = -1;
}

void peekStack() {
    if (fA == -1) {
        printf("Empty\n");
        return;
    }
    printf("Top: %d\n", qA[rA]);
}

void displayStack() {
    for (int i = fA; i <= rA; i++) {
        printf("%d ", qA[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    printf("Enter stack size: ");
    scanf("%d", &maxSize);

    while (1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                pushStack(val);
                break;
            case 2: popStack(); break;
            case 3: peekStack(); break;
            case 4: displayStack(); break;
            case 5: return 0;
        }
    }
}
