#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input, *output;
    int n = 0;
    int a[100];
    int b[100];
    int minAbs;
    int sumAbs = 0;
    int zeroFound = 0;
    int k = 0;

    input = fopen("../array.txt", "r");

    if (input == NULL) {
        printf("Error opening array.txt\n");
        return 1;
    }

    while (n < 100 && fscanf(input, "%d", &a[n]) == 1) {
        n++;
    }

    fclose(input);

    if (n == 0) {
        printf("The array is empty or the file is invalid.\n");
        return 1;
    }

    minAbs = abs(a[0]);

    for (int i = 0; i < n; i++) {
        if (abs(a[i]) < minAbs) {
            minAbs = abs(a[i]);
        }

        if (zeroFound) {
            sumAbs += abs(a[i]);
        }

        if (a[i] == 0 && !zeroFound) {
            zeroFound = 1;
        }
    }

    for (int i = 1; i < n; i += 2) {
        b[k++] = a[i];
    }

    for (int i = 0; i < n; i += 2) {
        b[k++] = a[i];
    }

    output = fopen("../result.txt", "w");

    if (output == NULL) {
        printf("Error creating result.txt\n");
        return 1;
    }

    fprintf(output, "Minimum absolute value: %d\n", minAbs);

    if (zeroFound) {
        fprintf(output,
                "Sum of absolute values after the first zero: %d\n",
                sumAbs);
    } else {
        fprintf(output, "There is no zero in the array.\n");
    }

    fprintf(output, "Transformed array: ");

    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", b[i]);
    }

    fprintf(output, "\n");

    fclose(output);

    printf("Results were written to result.txt\n");

    return 0;
}
