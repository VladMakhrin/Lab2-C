
#include <stdio.h>

int main() {
    const int MAX = 100;
    int n;
    float a[MAX];
    float minPositive;
    int position = -1;
    int countNegative = 0;

    printf("Enter the number of array elements from 1 to 100: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Error: number of elements must be between 1 and 100.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            countNegative++;
        }

        if (a[i] > 0 && (position == -1 || a[i] < minPositive)) {
            minPositive = a[i];
            position = i;
        }
    }

    if (position != -1) {
        printf("Minimum positive element: %.2f\n", minPositive);
        printf("Position: %d\n", position + 1);
    } else {
        printf("There are no positive elements in the array.\n");
    }

    printf("Number of negative elements: %d\n", countNegative);

    return 0;
}
