#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to print permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Find the largest mobile element
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0, mobile_index = -1;

    for (int i = 0; i < n; i++) {
        if (dir[perm[i] - 1] == LEFT && i != 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }

        if (dir[perm[i] - 1] == RIGHT && i != n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main Johnson-Trotter function
void johnsonTrotter(int n) {
    int perm[n], dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int mobile_index = getMobile(perm, dir, n);

        if (mobile_index == -1)
            break;

        int mobile = perm[mobile_index];

        // Swap in its direction
        if (dir[mobile - 1] == LEFT)
            swap(&perm[mobile_index], &perm[mobile_index - 1]);
        else
            swap(&perm[mobile_index], &perm[mobile_index + 1]);

        // Find new index of mobile
        int new_index;
        for (int i = 0; i < n; i++) {
            if (perm[i] == mobile) {
                new_index = i;
                break;
            }
        }

        // Reverse direction of all elements greater than mobile
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[perm[i] - 1] *= -1;
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
