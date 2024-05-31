#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
} time1, time2, result;

void main() {

    printf("Enter the first time:\n");
    printf("Enter hours: ");
    scanf("%d", &time1.hours);
    printf("Enter minutes: ");
    scanf("%d", &time1.minutes);
    printf("Enter seconds: ");
    scanf("%d", &time1.seconds);

    printf("Enter the second time:\n");
    printf("Enter hours: ");
    scanf("%d", &time2.hours);
    printf("Enter minutes: ");
    scanf("%d", &time2.minutes);
    printf("Enter seconds: ");
    scanf("%d", &time2.seconds);

    if(time2.seconds < time1.seconds) {
        time2.seconds += 60;
        time2.minutes -= 1;
    }
    result.seconds = time2.seconds - time1.seconds;

    if(time2.minutes < time1.minutes) {
        time2.minutes += 60;
        time2.hours -= 1;
    }
    result.minutes = time2.minutes - time1.minutes;

    result.hours = time2.hours - time1.hours;

    printf("The resulting time difference is: %02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);
}
