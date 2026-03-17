#include <stdio.h>
int main()
{
    short delta = 9;
    printf("Kich thuoc bien Delta = %d\n", sizeof(delta));
    printf("Kich thuoc kieu int = %d\n", sizeof(int));
    printf("Kich thuoc kieu long = %d\n", sizeof(long));
    printf("Kich thuoc kieu float = %d\n", sizeof(float));
    printf("Kich thuoc kieu douable = %d\n", sizeof(double));
    printf("Kich thuoc kieu char = %d\n", sizeof(char));
}