#include<stdio.h>

int main(){
    float x;
    char c=' ';
    float min = 1.0E38;
    float max = -1.0E38;
    printf("Enter all no in single line :");
    while (c!='\n' )
    {
        scanf("%f%c",&x,&c);
        if (x>max )
            max=x;      
        if(x<min)
            min=x;        
    }
    printf("Max = %f : Min = %F ", max,min);
    return 0;
}