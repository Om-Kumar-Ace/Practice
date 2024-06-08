#include <stdio.h>
#include <math.h>

double calculateMean(int data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += data[i];
    }
    return sum / n;
}

double calculateStandardDeviation(int data[], int n) {
    double mean = calculateMean(data, n);
    double sumSquaredDifferences = 0.0;

    for (int i = 0; i < n; ++i) {
        sumSquaredDifferences += pow(data[i] - mean, 2);
    }

    return sqrt(sumSquaredDifferences / n);
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int data[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }

    double stddev = calculateStandardDeviation(data, n);
    printf("Standard Deviation = %.2lf\n", stddev);

    return 0;
}
