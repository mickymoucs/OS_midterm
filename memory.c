#include <stdio.h>
#include <stdlib.h>

int globalVar1 = 1;
int globalVar2 = 2;
int globalVar3 = 3;
int globalVar4 = 4;

void CallMemory(int level,char Overflow) {
    int stack = level;
    printf("Stack variable address (level %d): %p\n", level, &stack);

    int* heap = (int*)malloc(sizeof(int));
    *heap = level;
    printf("Heap variable address (level %d): %p\n", level, heap);

    if (Overflow == 'y') {
        CallMemory(level + 1, Overflow);
    }
    else {
        if (level < 3) {
        CallMemory(level + 1, Overflow);
        }
    }
    free(heap);
}

int main() {
    printf("Global variable 1 address: %p\n", &globalVar1);
    printf("Global variable 2 address: %p\n", &globalVar2);
    printf("Global variable 3 address: %p\n", &globalVar3);
    printf("Global variable 4 address: %p\n", &globalVar4);

    char Overflow;
    printf("Show overflow? (y/n): ");
    scanf("%c", &Overflow);
    CallMemory(1, Overflow);
    return 0;
}
