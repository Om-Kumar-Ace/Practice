#include <stdio.h>

struct Time{
    int hours;
    int minutes;
    int seconds;
} time1,time2,result;

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

    result.seconds = time1.seconds + time2.seconds;
    result.minutes = time1.minutes + time2.minutes + result.seconds / 60;
    result.seconds %= 60;

    result.hours = time1.hours + time2.hours + result.minutes / 60;
    result.minutes %= 60;

    printf("The resulting time is: %02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);

}
