#include <stdio.h>
#include <stdlib.h>

#define LEFT -1     //These are to denote directions, left or right
#define RIGHT 1

void print(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// To get the largest element
int getMobile(int perm[], int dir[], int n) {
    int mobile = -1;
    int mobile_index = -1;

    for (int i = 0; i < n; i++) {
        int next = i + dir[i];

        if (next >= 0 && next < n) {
            if (perm[i] > perm[next] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }
    return mobile_index;
}

// Basic swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Reverse directions of elements greater than mobile
void reverseDirections(int perm[], int dir[], int n, int mobile_value) {
    for (int i = 0; i < n; i++) {
        if (perm[i] > mobile_value) {
            dir[i] = -dir[i];
        }
    }
}

void generatePermutations(int n) {
    int perm[n];
    int dir[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    print(perm, n);

    while (1) {
        int mobile_index = getMobile(perm, dir, n);

        if (mobile_index == -1)
            break;

        int swap_with = mobile_index + dir[mobile_index];

        // Swap numbers
        swap(&perm[mobile_index], &perm[swap_with]);

        // Swap directions
        swap(&dir[mobile_index], &dir[swap_with]);

        // Update index
        mobile_index = swap_with;

        int mobile_value = perm[mobile_index];

        // Reverse directions
        reverseDirections(perm, dir, n, mobile_value);

        print(perm, n);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {                         // For our program, we'll not be considering negative numbers for ease of computations
        printf("Invalid input\n");
        return 1;
    }

    generatePermutations(n);

    return 0;
}