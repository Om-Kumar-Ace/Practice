#include <stdio.h>
#include <math.h>

double calculateMean(int arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

double calculateVariance(int arr[], int n) {
    double mean = calculateMean(arr, n);
    double sumOfSquaredDifferences = 0.0;
    for (int i = 0; i < n; i++) {
        sumOfSquaredDifferences += pow(arr[i] - mean, 2);
    }
    return sumOfSquaredDifferences / n;
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    double variance = calculateVariance(arr, n);
    printf("Variance of the given numbers: %lf\n", variance);

    return 0;
}
